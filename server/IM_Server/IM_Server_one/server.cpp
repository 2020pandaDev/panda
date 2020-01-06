#include "server.h"


Server::Server(QObject *parent) : QObject(parent)
{
    m_ctcpsv =new CTcpSv(this);
    m_ctcpsv->listen(QHostAddress::Any,10852);
    connect(m_ctcpsv,&CTcpSv::sendSocket,this,&Server::incomingConnection);
}

void Server::getNewSocket()
{

}

ServerThread *Server::createUserThread(QTcpSocket *)
{

}

void Server::incomingConnection(qintptr socketDescriptor)
{

    ServerThread* thread = new ServerThread(socketDescriptor);
    Worker* m_worker = new Worker ();
    m_worker->moveToThread(thread);

    //信号与槽函数在同一个线程，则用直连方式Qt::DirectConnection，若信号是跨线程的，则使用排队连接方式
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()), Qt::DirectConnection);
    connect(thread, SIGNAL(work1()), m_worker, SLOT(dowork()), Qt::DirectConnection);

    //信号与槽函数在同一个线程，则用直连方式Qt::DirectConnection，若信号是跨线程的，则使用排队连接方式
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()), Qt::DirectConnection);

    thread->start();
}
