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

public slots:
    void dowork(QByteArray& message);
    void registe(QStringList & registerInfo);
    void loginIn(QStringList & userInfoList);
    void privateChat(QVariantMap&);
	void createTable();
	void doingCAPTCHA(QStringList &CAPTCHAInfo);
    void sendReturnData(QByteArray&);

private:
    QMap<QString ,QString> userinfo;
    QMap<QString ,QString> userVerification;
    

};

#endif // WORKER_H
