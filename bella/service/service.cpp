#include "service.h"
#include <QWidget>
#include <QDebug>

service::service(QWidget *parent)
    : QMainWindow(parent)
{
    h = new helpWindow(parent);
    setCentralWidget(h);
    connect(this, &service::showWindow,
    this, [ = ]() {
        if (!h->isVisible()) {
           h->show();
        }
     });

    connect(this,&service::getValidSignal,this,[=](){
        h->getStrId();
    });
}
service::~service()
{

}

void service::Show()
{
    Q_EMIT showWindow();

}

void service::getValid()
{
    Q_EMIT getValidSignal();

}
