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

signals:
    void createDB();
    void sendInfo(QByteArray&);
    void insertSocket(QString);

public slots:
    void dowork(QByteArray& message);
    QVariantMap registe(QStringList & registerInfo);
    QVariantMap loginIn(QStringList & userInfoList);
    void privateChat(QVariantMap&);
	void createTable();
    QVariantMap doingCAPTCHA(QStringList &CAPTCHAInfo);
    void sendReturnData(QByteArray&);////给客户端发送消息

private:
    QMap<QString ,QString> userinfo;
    QMap<QString ,QString> userVerification;
    

};

#endif // WORKER_H
