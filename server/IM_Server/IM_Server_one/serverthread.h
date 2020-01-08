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
    QTcpSocket * m_tcpSocket;
    QByteArray m_recData;
    static QMap<QString,QTcpSocket*> userSocket;
   

public slots:
    void sendByteData(QByteArray&);
    void insertSocket(QString);

signals:
    void work(QByteArray&);
    void dataPaser();
    void regist(QStringList&);
    void login(QStringList&);
    void chat(QMap<QString,QTcpSocket*>);
    void assist();
    void dowithCAPTCHA(QStringList&);
    void createDB();

};

#endif // SERVERTHREAD_H
