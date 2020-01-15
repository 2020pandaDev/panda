#include "helpwindow.h"
#include <QTimer>
#include <QTime>

helpWindow::helpWindow(QWidget * parent)
    :QWidget(parent)
{   
   // QWidget *widget =new QWidget();
    v=new QVBoxLayout();
    m_label=new QLabel("");
    m_btn=new QPushButton("验证码");

    connect(m_btn,&QPushButton::clicked,this,&helpWindow::generateValid);
    //QString text=generateValid();
    //m_btn->setText(text);
    v->addWidget(m_label);
    v->addWidget(m_btn);
    setLayout(v);
  //  widget->setLayout(v);


}

QString helpWindow::generateValid()
{
    qsrand(QTime(0, 0, 0).secsTo(QTime::currentTime()));
    int num = qrand()%(1000000);
    QString strId=QString::number(num);
    m_btn->setText(strId);
    return strId;
}

QString helpWindow::getStrId()
{
    QString strid;
    strid=generateValid();
    return strid;
}
