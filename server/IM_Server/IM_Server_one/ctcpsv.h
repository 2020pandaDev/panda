#ifndef CTCPSV_H
#define CTCPSV_H
#include <QTcpServer>
#include <QTcpSocket>
class CTcpSv : public QTcpServer
{
    Q_OBJECT
public:
    CTcpSv(QObject *parent = nullptr);
    virtual void incomingConnection(qintptr socketDescriptor);

signals:
    void sendSocket(qintptr);

};

#endif // CTCPSV_H
