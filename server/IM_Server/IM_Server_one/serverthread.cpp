#include "serverthread.h"
#include <QDebug>
#include <QtNetwork>
ServerThread::ServerThread(qintptr socketDescriptor)
{
//    m_tcpSocket = new QTcpSocket ();
    m_socketDescriptor = socketDescriptor;
//    m_tcpSocket->setSocketDescriptor(m_socketDescriptor);
//    m_tcpSocket->moveToThread(this);
//    connect(m_tcpSocket,&QTcpSocket::readyRead,this,&ServerThread::read);
//    connect(m_tcpSocket,&QTcpSocket::readyRead,[ = ](){
//       m_recData = m_tcpSocket->readAll();
//       qDebug()<<"m_recData :"<<m_recData;
//    });

}

void ServerThread::run()
{
      m_tcpSocket = new QTcpSocket ();


      // run()函数中创建的栈对象保证了可靠的销毁。注意这个变量的依附性，当前线程变量仅在调用它的线程中有效。

       if (!m_tcpSocket->setSocketDescriptor(m_socketDescriptor)) { // 相当于tcpSocket的初始化，参数是为了保证不会为同一个客户端创建多个QTcpSocket对象
          // emit error(tcpSocket.error());
           return;
       }
   // connect(m_tcpSocket,&QTcpSocket::readyRead,this,&ServerThread::read);
    connect(m_tcpSocket,&QTcpSocket::readyRead,[=](){
       m_recData = m_tcpSocket->readAll();
       qDebug()<<"m_recData :"<<m_recData;
    });
//       QByteArray block = ""; // 参见Fortune Server
//       QDataStream out(&block, QIODevice::WriteOnly);
//          out.setVersion(QDataStream::Qt_4_0);
//          out << (quint16)0;
//          out.device()->seek(0);
//          out << (quint16)(block.size() - sizeof(quint16));


       m_tcpSocket->write("ni hao");
       m_tcpSocket->flush();
       exec();


//       while(true){

//          qDebug()<<"write :";
//       }

      /* m_tcpSocket->disconnectFromHost(); // 这个函数是异步执行的
       m_tcpSocket->waitForDisconnected();*/ // 注意到这又是个waitFor...()函数，它会阻塞当前线程直到连接断开

}

void ServerThread::read()
{
    QTcpSocket *socket = qobject_cast<QTcpSocket*>(sender());
    m_recData = socket->readAll();
    qDebug()<<"m_recData solt :"<<m_recData;
}



