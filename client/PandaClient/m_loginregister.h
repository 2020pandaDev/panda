#ifndef M_ONELOGIN_H
#define M_ONELOGIN_H

#include<DMainWindow>
#include <QPainter>
#include <QPalette>
#include <DLineEdit>
#include <QHBoxLayout>
#include <DLabel>
#include <QIcon>
#include <QMovie>
#include <DMessageBox>
#include<DSuggestButton>
#include<QImage>
#include <QRegExpValidator>
#include<QFont>
#include<DApplication>
#include<DTitlebar>
#include<QSpacerItem>
DWIDGET_USE_NAMESPACE

class m_loginregister: public DMainWindow
{
    Q_OBJECT
public:
    m_loginregister(DWidget* parent = nullptr);
    ~m_loginregister();
private slots:
    void setheadtitle(const QString &Lefticon,const QString &Righticon);
private:
    QWidget *registerwidget;
    QGridLayout *glayout;
    QVBoxLayout *vlayout;
    QLineEdit *m_namelineedit;
    QLineEdit *m_passwordlineedit;
    QLineEdit *m_try_pwdlineedit;
    DSuggestButton *m_okbutton;
    DSuggestButton *m_cancelbutton;

    bool isSee = false;

    //标题
    QImage *image;
    DTitlebar *tit;
    DWidget *headtitle;
    DLabel * lefticon;
    DLabel * righticon;

};

#endif // M_ONELOGIN_H
