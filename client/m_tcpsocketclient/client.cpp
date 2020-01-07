#include "client.h"
#include <QDateTime>
#include <QDebug>
#include <QMessageBox>

client::client(QWidget *parent) : DMainWindow(parent)
{
    this->isconnetion = false;
    initClientSocket("10.61.11.143",6565);
    connected();
    sendysend();
    readyread();
    disconnected();
}

void client::initClientSocket(const QString &hostName, quint16 port)
{
    //初始化sendMesSocket
    this->m_tcpsocket = new QTcpSocket();
    //终止之前的连接，重置套接字
    m_tcpsocket->abort();
    //给定IP和端口号，连接服务器
    this->m_tcpsocket->connectToHost(hostName,port); //QHostAddress::LocalHost等于127.0.0.1，所以两者都可以互相替换
}

void client::connected()
{
    //成功连接服务器的connected()信号连接到slot_connected() (注意：不是connect()信号)
    connect(m_tcpsocket,&QTcpSocket::connected,this,&client::slot_connected);
}

void client::disconnected()
{
    //与服务器断开连接的disconnected()信号连接到slot_disconnect()
    connect(m_tcpsocket,&QTcpSocket::disconnected,this,&client::slot_disconnect);
}

void client::readyread()
{
    //有新数据到达时的readyread()信号连接到slot_recvmessage()
    connect(m_tcpsocket,&QTcpSocket::readyRead,this,&client::slot_recvmessage);
}

void client::sendysend()
{
    QString sendMessage = "信号连接";
    if(!sendMessage.isEmpty())
    {
        //发送消息到服务器
        this->m_tcpsocket->write(sendMessage.toLatin1());
        //本地显示发送的消息
        QString localDispalyMessage = tr("send to server: ") + sendMessage \
                + QDateTime::currentDateTime().toString(" yyyy-M-dd hh:mm:ss") + tr("\n");
        qDebug()<<localDispalyMessage;
    }
}

//处理成功连接到服务器的槽
void client::slot_connected()
{
    this->isconnetion = true;
    qDebug()<<"与服务器连接成功：" + QDateTime::currentDateTime().toString("yyyy-M-dd hh:mm:ss");
}

//接收来自服务器的消息的槽
void client::slot_recvmessage()
{
    //接收来自服务器的消息
    QByteArray byteArray = this->m_tcpsocket->readAll();
    QString recvMessage = tr("recv from server: ") + byteArray + QDateTime::currentDateTime().toString(" yyyy-M-dd hh:mm:ss") + tr("\n");
    qDebug()<< recvMessage;
}

void client::slot_disconnect()
{
    QMessageBox::warning(this,"警告","与服务器的连接中断",QMessageBox::Ok);
    //关闭并随后删除socket
    m_tcpsocket->close();
    m_tcpsocket->deleteLater();
}
