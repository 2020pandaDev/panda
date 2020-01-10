#ifndef WORKER_H
#define WORKER_H
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QString>
#include "mysql.h"
#include "dataparsing.h"
#include <QTcpSocket>
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    Dataparsing* m_dataParse = nullptr;
    QVariantMap m_returnDataToClient;
    QByteArray m_sendData;
    static QMap<QString, QTcpSocket *> m_userSocket;

signals:
    void createDB();
    void sendInfo(QByteArray&);


public slots:
    void dowork(QByteArray& message);
    QVariantMap registe(QStringList & registerInfo);
    QVariantMap updateUserList();
    QVariantMap loginIn(QStringList & userInfoList);
    QVariantMap privateChat(QVariantMap&);
	void createTable();
    QVariantMap doingCAPTCHA(QStringList &CAPTCHAInfo);
    QVariantMap helpingOther(QStringList &HelpingInfo);
    void sendReturnData(QByteArray&);////给客户端发送消息
    QVariantMap Signout(QStringList &SignoutInfo);
    QTcpSocket* recSocket(QTcpSocket*);

private:
    QMap<QString ,QString> userinfo;
    QMap<QString ,QString> userVerification;
    QTcpSocket* m_socket = nullptr;


};

#endif // WORKER_H
