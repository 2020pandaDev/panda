#include "server.h"
#include "worker.h"
#include "mysql.h"
Server::Server(QObject *parent) : QObject(parent)
{
    m_ctcpsv =new CTcpSv(this);
    m_ctcpsv->listen(QHostAddress::Any,6565);//监听
    connect(m_ctcpsv,&CTcpSv::sendSocket,this,&Server::incomingConnection);//客户端连接调用
}

void Server::incomingConnection(qintptr socketDescriptor)
{

    ServerThread* thread = new ServerThread(socketDescriptor);
    Worker* worker = new Worker ();//线程工作类
    worker->moveToThread(thread);//线程工作类移动到子线程下

    //信号与槽函数在同一个线程，则用直连方式Qt::DirectConnection，若信号是跨线程的，则使用排队连接方式
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()), Qt::DirectConnection);//
    connect(worker, &Worker::finish, worker, &Worker::deleteLater);
    connect(worker, &Worker::destroyed, thread, &ServerThread::quit);
    connect(thread, &ServerThread::sendSocketDescriptor, worker, &Worker::recSocketDescriptor, Qt::DirectConnection);
    thread->start();
}
