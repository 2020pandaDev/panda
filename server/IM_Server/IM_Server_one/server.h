#ifndef SERVER_H
#define SERVER_H

#include <QObject>
#include "serverthread.h"
#include <QTcpSocket>
#include "ctcpsv.h"
#include "worker.h"

class Server : public QObject
{
    Q_OBJECT
public:
    explicit Server(QObject *parent = nullptr);

    void getNewSocket();
    ServerThread* createUserThread(QTcpSocket*);
    void incomingConnection(qintptr socketDescriptor);
   /*******************/
   CTcpSv* m_ctcpsv = nullptr;




signals:

public slots:


};

#endif // SERVER_H
