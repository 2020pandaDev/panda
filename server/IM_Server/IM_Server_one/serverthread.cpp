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

    emit sendSocketDescriptor(m_socketDescriptor);//发送 socket 描述符号
    exec();//事件循环
}












