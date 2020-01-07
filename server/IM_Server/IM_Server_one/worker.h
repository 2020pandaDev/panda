#ifndef WORKER_H
#define WORKER_H
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QString>
#include <mysql.h>


class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:

public slots:
    void dowork();
    void registe(QStringList & registerInfo);
    void loginIn(QStringList & userInfoList);
    void privateChat(QVariantMap&);
	void doingCAPTCHA(QStringList &CAPTCHAInfo);
private:
    QMap<QString ,QString> userinfo;
    QMap<QString ,QString> userVerification;
    MySql *sql;

};

#endif // WORKER_H
