#include "m_loginregister.h"
#include "unit.h"
#include "myapp.h"
#include "m_loginregister.h"
#include<QJsonArray>
#include<QJsonDocument>
#include<QJsonObject>
#include <QMessageBox>
m_loginregister::m_loginregister(DWidget* parent) :
    DMainWindow(parent)
{
    registerwidget = new QWidget;
    glayout = new QGridLayout(this);
//    m_tcpSocket = new ClientSocket();
    textLabel = new DLabel;

    m_bConnected = false;
    textLabel->setText(tr(""));
//    m_tcpSocket->ConnectToHost(MyApp::m_strHostAddr, MyApp::m_nMsgPort);

    //用户名框
    m_namelineedit = new QLineEdit;
    m_namelineedit->setFixedSize(250,40);
    m_namelineedit->setPlaceholderText("(输入用户名)");
    m_namelineedit->setAlignment(Qt::AlignHCenter);
    QFont ft1;
    ft1.setLetterSpacing(QFont::AbsoluteSpacing,3);
    m_namelineedit->setFont(ft1);
    QRegExp regx("[a-zA-Z0-9]{1,10}");
    m_namelineedit->setValidator(new QRegExpValidator(regx,this));
    m_namelineedit->setClearButtonEnabled(true);

    //密码框
    m_passwordlineedit = new QLineEdit;
    m_passwordlineedit->setPlaceholderText("(输入密码)");
    m_passwordlineedit->setAlignment(Qt::AlignHCenter);
    m_passwordlineedit->setFixedSize(250,40);
    m_passwordlineedit->setFont(ft1);
    QRegExp rx("[a-zA-Z0-9!,;:=+?@#%^&*]{6,18}$");
    m_passwordlineedit->setValidator(new QRegExpValidator(rx,this));
    m_passwordlineedit->setEchoMode(QLineEdit::Password);
    m_passwordlineedit->setClearButtonEnabled(true);

    m_try_pwdlineedit = new QLineEdit;
    m_try_pwdlineedit->setPlaceholderText("请确认密码");
    m_try_pwdlineedit->setAlignment(Qt::AlignHCenter);
    m_try_pwdlineedit->setFixedSize(250,40);
    m_try_pwdlineedit->setFont(ft1);
    m_try_pwdlineedit->setValidator(new QRegExpValidator(rx,this));
    m_try_pwdlineedit->setEchoMode(QLineEdit::Password);
    m_try_pwdlineedit->setClearButtonEnabled(true);

    //两个按钮
    m_okbutton = new DSuggestButton(this);
    m_cancelbutton = new DSuggestButton(this);
    m_okbutton->setFixedSize(130,35);
    m_okbutton->setText(tr("确认"));
    m_cancelbutton->setFixedSize(130,35);
    m_cancelbutton->setText(tr("取消"));

    //布局
    glayout->addWidget(m_namelineedit,0,0,1,1,Qt::AlignCenter);
    glayout->addWidget(m_passwordlineedit, 1, 0,1,1,Qt::AlignCenter);
    glayout->addWidget(m_try_pwdlineedit,2,0,1,1,Qt::AlignCenter);
    glayout->addWidget(textLabel,3,0,1,1,Qt::AlignCenter);
    glayout->addWidget(m_okbutton, 4, 0, 1, 1,Qt::AlignCenter);
    glayout->addWidget(m_cancelbutton, 5, 0, 1, 1,Qt::AlignCenter);
    glayout->setHorizontalSpacing(30);
   // glayout->setAlignment(Qt::AlignCenter);
    registerwidget->setLayout(glayout);

    setheadtitle(":/image/panda.png","注册");
   setCentralWidget(registerwidget);

    // * 判断输入机制
    connect(m_okbutton,&DSuggestButton::clicked,this,
            [=]() {
        if(CheckPwd())
        {
            // 构建 Json 对象
            QJsonObject json;
            json.insert("Type", Register);
            json.insert("usrName", m_namelineedit->text());
            json.insert("password", m_passwordlineedit->text());

                m_tcpSocket->SltSendMessage(Register, json);
        }

    });
    // * 关闭槽函数
    connect(m_cancelbutton,&DSuggestButton::clicked,this,
            [=]() {
            this->close();
    });
  }


m_loginregister::~m_loginregister()
{

}

void m_loginregister::SetSocket(ClientSocket *tcpSocket)
{
    m_tcpSocket = tcpSocket;

connect(m_tcpSocket, SIGNAL(signalStatus(quint8)), this, SLOT(SltTcpStatus(quint8)));
}


/**
 * @brief LoginWidget::SltTcpStatus
 * 读取服务器返回的登陆信息状态
 * @param state
 */
void m_loginregister::SltTcpStatus(const quint8 &state)
{
    switch (state) {
    case DisConnectedHost: {
        m_bConnected = false;
        qDebug()<<"服务器已断开";
    }
        break;
    case ConnectedHost:
    {
        m_bConnected = true;
        qDebug()<<"已连接服务器";
    }
        break;
    case RegisterOk:
    {
        QMessageBox::information(this, "注册信息", "该账号注册成功！请点击登录！");
        this->close();
        //return;
    }
        break;
    case RegisterFailed:
    {
        QMessageBox::information(this, "注册信息", "注册失败，请重试!");
    }
        break;
    default:
        break;
    }
}


//注册判断机制
bool m_loginregister::CheckPwd()
{
    QString nickName = m_namelineedit->text();//用户昵称
    QString firstPassWrd = m_passwordlineedit->text();//用户密码
    QString secondPassWrd = m_try_pwdlineedit->text();//确认密码
    QRegExp rx;
    if(0 == nickName.size())
    {

        QMessageBox::information(this,"注册信息","昵称不能为空!");
        return false;
    }
    if(nickName.size() > 10)
    {
        //            warnStr += "昵称长度超过10位;";
        QMessageBox::information(this,"注册信息","昵称长度超过10位!");
        return false;
    }

    rx.setPatternSyntax(QRegExp::RegExp);
    //对大小写字母敏感，即区分大小写
    rx.setCaseSensitivity(Qt::CaseSensitive);
    //匹配格式为所有大小写字母和数字组成的字符串，位数不限
    rx.setPattern(QString("[a-zA-Z0-9!@#%^&*()_]{6,18}$"));
    if(firstPassWrd.isEmpty())  //检测密码输入框是不是为空
    {
        QMessageBox::information(this,"注册信息","密码不能为空!");
        return false;
    }
    else if(!rx.exactMatch(firstPassWrd))
    {
        QMessageBox::information(this,"注册信息","密码位数为6-18位!");
       return false;

    }
    else if(firstPassWrd.size()<6 || firstPassWrd.size()>18)
    {
        QMessageBox::information(this,"注册信息","密码长度范围必须是[6,18]!");
        return false;

    }
    if(secondPassWrd.isEmpty())  //检测密码输入框是不是为空
    {
        QMessageBox::information(this,"注册信息","密码不能为空!");
        return false;
    }
    if(0 != firstPassWrd.compare(secondPassWrd) )
    {
        QMessageBox::information(this,"注册信息","两次密码不一致!");
       return false;
    }
    return true;
}


//标题函数
void m_loginregister::setheadtitle(const QString &Lefticon, const QString &Righticon)
{
    tit = this->titlebar();
    if (tit) {
        tit->setMenuVisible(false);
    }
    image = new QImage;
    lefticon = new DLabel(this);
    lefticon->setPixmap(QPixmap::fromImage(*image));
    lefticon->setScaledContents(true);
    lefticon->setFixedSize(18,18);
    righticon = new DLabel(this);
    QHBoxLayout* mylayout = new QHBoxLayout();
    mylayout->addSpacing(250);
    mylayout->addWidget(lefticon,0,Qt::AlignCenter);
    mylayout->addWidget(righticon,0,Qt::AlignCenter);
    mylayout->setContentsMargins(0,0,60,0);
    //mylayout->setAlignment(Qt::AlignHCenter);
    headtitle = new DWidget(this);
    headtitle->setLayout(mylayout);
    tit->setCustomWidget(headtitle);
    lefticon->setPixmap(QPixmap(Lefticon));
    righticon->setText(Righticon);
}
