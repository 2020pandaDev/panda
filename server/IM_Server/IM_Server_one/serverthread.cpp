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
QMutex ServerThread::m_Mutex;
QMap<QString, QTcpSocket *> ServerThread::userSocket;


void ServerThread::run()
{

    m_tcpSocket = new QTcpSocket();

  // run()函数中创建的栈对象保证了可靠的销毁。注意这个变量的依附性，当前线程变量仅在调用它的线程中有效。
    if (!m_tcpSocket->setSocketDescriptor(m_socketDescriptor)) { // 相当于tcpSocket的初始化，参数是为了保证不会为同一个客户端创建多个QTcpSocket对象
        // emit error(tcpSocket.error());
        return;
    }
    connect(m_tcpSocket, &QTcpSocket::readyRead, [ = ]() {
        m_recData = m_tcpSocket->readAll();
        qDebug() << "m_recData :" << m_recData;
        qDebug() << "run thread:" << currentThreadId();  
        emit work(m_recData);
    });






//       m_tcpSocket->disconnectFromHost(); // 这个函数是异步执行的
//       m_tcpSocket->waitForDisconnected(); // 注意到这又是个waitFor...()函数，它会阻塞当前线程直到连接断开
       exec();

}

void ServerThread::sendByteData(QByteArray &retuernData)
{
    qDebug() << "sendByteData thread:" << QThread::currentThreadId();
    m_tcpSocket->write(retuernData);
    m_tcpSocket->flush();
}

void ServerThread::insertSocket(QString userName)
{
    qDebug() << "insertSocket thread:" << QThread::currentThreadId();
    QMutexLocker m_lock(&m_Mutex);
    userSocket.insert(userName, m_tcpSocket);
}

void ServerThread::deleteSocket(QString userName)
{
    qDebug() << "insertSocket thread:" << QThread::currentThreadId();
    if (userName.contains(userName)) {
        userSocket.remove(userName);
    } else {
        qDebug() << "this Socket no exist :";
    }
}








