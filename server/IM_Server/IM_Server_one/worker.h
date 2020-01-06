#ifndef WORKER_H
#define WORKER_H
#include <QDebug>
#include <QObject>
#include <QThread>

class Worker : public QObject
{
    Q_OBJECT
public:
    explicit Worker(QObject *parent = nullptr);

signals:

public slots:
    void dowork();
};

#endif // WORKER_H
