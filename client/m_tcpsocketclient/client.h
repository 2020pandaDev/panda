#ifndef CLIENT_H
#define CLIENT_H

#include <DMainWindow>
#include <QTcpSocket>
DWIDGET_USE_NAMESPACE
class client : public DMainWindow
{
    Q_OBJECT
public:
    explicit client(QWidget *parent = nullptr);

signals:

public slots:
    void slot_connected(); //处理成功连接到服务器的槽
  //  void slot_sendmessage(); //发送消息到服务器的槽
    void slot_recvmessage(); //接收来自服务器的消息的槽
    void slot_disconnect(); //取消与服务器连接的槽
private:
    bool isconnetion; //判断是否连接到服务器的标志位
    QTcpSocket *m_tcpsocket; //发送消息套接字
public:
    void initClientSocket(const QString &hostName, quint16 port);
    void connected();
    void disconnected();
    void readyread();
    void sendysend();
};

#endif // CLIENT_H
