#ifndef WORKER_H
#define WORKER_H
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QString>
#include "mysql.h"

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:
    void createDB();

public slots:
    void dowork();
    void registe(QStringList & registerInfo);
    void loginIn(QStringList & userInfoList);
    void privateChat(QVariantMap&);
	void createTable();
	void doingCAPTCHA(QStringList &CAPTCHAInfo);
    void privateChat(QVariantMap&);
    void createTable();
private:
    QMap<QString ,QString> userinfo;
    

};

#endif // WORKER_H
