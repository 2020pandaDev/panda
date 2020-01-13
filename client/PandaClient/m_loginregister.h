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
#include<QTcpSocket>
#include<QMessageBox>
#include "clientsocket.h"
DWIDGET_USE_NAMESPACE

class m_loginregister: public DMainWindow
{
    Q_OBJECT
public:
    m_loginregister(DWidget* parent = nullptr);
    ~m_loginregister();
    void SetSocket(ClientSocket *tcpSocket);
private slots:
    // 服务器信息返回处理
    void SltTcpStatus(const quint8 &state);
    void setheadtitle(const QString &Lefticon,const QString &Righticon);
    bool CheckPwd();
private:
    QWidget *registerwidget;
    QGridLayout *glayout;
    QVBoxLayout *vlayout;
    QLineEdit *m_namelineedit;
    QLineEdit *m_passwordlineedit;
    QLineEdit *m_try_pwdlineedit;
    DSuggestButton *m_okbutton;
    DSuggestButton *m_cancelbutton;
    DLabel  *textLabel;

    bool isSee = false;
    bool flag;
    bool m_bConnected;
    // socket通信
    ClientSocket *m_tcpSocket;
    QString m_strHostAddr        = "10.61.11.140";
    int     m_nMsgPort           = 8000;
    int     m_nFilePort          = 60002;
    int     m_nGroupPort         = 60003;

    //标题
    QImage *image;
    DTitlebar *tit;
    DWidget *headtitle;
    DLabel * lefticon;
    DLabel * righticon;



};

#endif // M_ONELOGIN_H
