#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H
#include <QThread>
#include <QTcpSocket>
#include "mysql.h"
class ServerThread : public QThread
{
    Q_OBJECT
public:
    ServerThread(qintptr socketDescriptor);
    virtual void run() override;
    qintptr  m_socketDescriptor;
public slots:
signals:
    void sendSocketDescriptor(qintptr);
};

#endif // SERVERTHREAD_H
