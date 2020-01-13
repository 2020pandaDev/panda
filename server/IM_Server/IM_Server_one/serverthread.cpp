#include "serverthread.h"
#include <QDebug>
#include <QtNetwork>
#include <QMap>
#include <QStringList>

ServerThread::ServerThread(qintptr socketDescriptor)
{
    m_socketDescriptor = socketDescriptor;
    qDebug() << "main thread:" << currentThreadId();
}




void ServerThread::run()
{

    emit sendSocketDescriptor(m_socketDescriptor);
//       m_tcpSocket->disconnectFromHost(); // 这个函数是异步执行的
//       m_tcpSocket->waitForDisconnected(); // 注意到这又是个waitFor...()函数，它会阻塞当前线程直到连接断开
       exec();

}












