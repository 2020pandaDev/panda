#ifndef WORKER_H
#define WORKER_H
#include <QDebug>
#include <QObject>
#include <QThread>
#include <QString>


class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:

public slots:
    void dowork();
    void registe(QStringList & registerInfo);
    void privateChat(QVariantMap&);
private:
    QMap<QString ,QString> userinfo;
};

#endif // WORKER_H
