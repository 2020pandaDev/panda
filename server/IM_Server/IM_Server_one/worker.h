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
    void finish();


public slots:
    void doWork(QByteArray& message);
    QVariantMap registe(QStringList & registerInfo);
    QVariantMap updateUserList();
    QVariantMap loginIn(QStringList & userInfoList);
    QVariantMap privateChat(QVariantMap&);
    QVariantMap doingCAPTCHA(QStringList &CAPTCHAInfo);
    QVariantMap helpingOther(QStringList &HelpingInfo);

    QVariantMap Signout(QStringList &SignoutInfo);
    QVariantMap groupChat(QVariantMap &groupChatInfo);
    void recSocketDescriptor(qintptr);

private:
    QMap<QString ,QString> userinfo;
    QMap<QString ,QString> userVerification;
    QTcpSocket* m_tcpSocket = nullptr;
    QByteArray m_recData;


};

#endif // WORKER_H
