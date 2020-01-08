#ifndef SERVER_H
#define SERVER_H

#include <DMainWindow>
#include <DWidget>
#include <DTextBrowser>
#include <QTcpServer>
#include <QTcpSocket>
#include <QUdpSocket>
#include <QVector>
DWIDGET_USE_NAMESPACE
class server : public DMainWindow
{
    Q_OBJECT
public:
    explicit server(QWidget *parent = nullptr);

signals:

public slots:
    void slot_newconnect();
    void slot_recvmessage();
    void slot_disconnect();
    void slot_sendmessage();
    void SltSendMessage(const quint8 &type, const QJsonValue &jsonVal);

private:
    DWidget *m_widget;
    DTextBrowser *m_textbrower;
    QTcpServer *m_tcpserver;  //taojiezi
    QTcpSocket *m_tcpsocket;
    unsigned char msg[10];
    // 客户端管理
    QVector <QTcpSocket *> m_clients;
private:
    void ParseReister(const QJsonValue &dataVal);
    void ParseLogin(const QJsonValue &dataVal);
};

#endif // SERVER_H
