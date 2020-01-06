#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H
#include <QThread>
#include <QTcpSocket>
class ServerThread : public QThread
{
    Q_OBJECT
public:
    ServerThread(qintptr socketDescriptor);
    virtual void run();
    qintptr  m_socketDescriptor;
    QTcpSocket * m_tcpSocket;
    QByteArray m_recData;
public slots:
    void read();


};

#endif // SERVERTHREAD_H
