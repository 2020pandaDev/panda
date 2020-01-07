#ifndef SERVERTHREAD_H
#define SERVERTHREAD_H
#include <QThread>
#include <QTcpSocket>
class ServerThread : public QThread
{
    Q_OBJECT
public:
    ServerThread(qintptr socketDescriptor);
    virtual void run() override;
    qintptr  m_socketDescriptor;
    QTcpSocket * m_tcpSocket;
    QByteArray m_recData;
    static QMap<QString,QTcpSocket*> userSocket ;



signals:
    void work1();
    void regist(QStringList&);
    void login(QStringList&);
    void chat(QMap<QString,QTcpSocket*>*);
    void assist();

};

#endif // SERVERTHREAD_H
