#ifndef WORKER_H
#define WORKER_H
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QString>
#include "mysql.h"
#include "dataparsing.h"
class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);
    Dataparsing* m_dataParse = nullptr;
    QVariantMap m_returnDataToClient;
    QByteArray m_sendData;

signals:
    void createDB();
    void sendInfo(QByteArray&);
    void insertSocket(QString);
    void deleteSocket(QString);

public slots:
    void dowork(QByteArray& message);
    QVariantMap registe(QStringList & registerInfo);
    QStringList updateUserList();
    QVariantMap loginIn(QStringList & userInfoList);
    QVariantMap privateChat(QVariantMap&);
	void createTable();
    QVariantMap doingCAPTCHA(QStringList &CAPTCHAInfo);
    QVariantMap helpingOther(QStringList &HelpingInfo);
    void sendReturnData(QByteArray&);////给客户端发送消息
    QVariantMap Signout(QStringList &SignoutInfo);

private:
    QMap<QString ,QString> userinfo;
    QMap<QString ,QString> userVerification;

};

#endif // WORKER_H
