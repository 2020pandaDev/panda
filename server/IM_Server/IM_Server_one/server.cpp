#include "server.h"
#include "worker.h"
#include "mysql.h"

Server::Server(QObject *parent) : QObject(parent)
{
    MySql mySql("./user.db","QSQLITE","t_user");
    if (!mySql.CreateConnection())
    {
        qDebug() << "数据库创建失败!";

    }
    mySql.createTable();


    m_ctcpsv =new CTcpSv(this);
    m_ctcpsv->listen(QHostAddress::Any,6565);
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
    Worker* worker = new Worker ();
    worker->moveToThread(thread);

//    Dataparsing* dataparse= new  Dataparsing();

    //信号与槽函数在同一个线程，则用直连方式Qt::DirectConnection，若信号是跨线程的，则使用排队连接方式
    QObject::connect(thread, SIGNAL(finished()), thread, SLOT(deleteLater()), Qt::DirectConnection);
    connect(thread, SIGNAL(work1()), worker, SLOT(dowork()), Qt::DirectConnection);
    connect(thread, &ServerThread::regist, worker, &Worker::registe, Qt::DirectConnection);
//    connect(thread, SIGNAL(login()), worker, SLOT(loginIn()), Qt::DirectConnection);
    connect(thread, &ServerThread::dowithCAPTCHA, worker, &Worker::doingCAPTCHA, Qt::DirectConnection);
//    connect(thread, SIGNAL(work1()), worker, SLOT(dowork()), Qt::DirectConnection);
//    connect(thread, SIGNAL(work1()), worker, SLOT(dowork()), Qt::DirectConnection);
    thread->start();
}
