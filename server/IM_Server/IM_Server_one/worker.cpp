#include "worker.h"

Worker::Worker(QObject *parent) : QObject(parent)
{

}

void Worker::dowork()
{
            qDebug()<<" dpwork";
            qDebug()<<"work thread:"<<QThread::currentThreadId();
}
