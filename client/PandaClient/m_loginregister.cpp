#include "m_loginregister.h"


m_loginregister::m_loginregister(DWidget* parent) :
    DMainWindow(parent)
{
    registerwidget = new QWidget;
    glayout = new QGridLayout(this);

    //用户名框
    m_namelineedit = new QLineEdit;
    m_namelineedit->setFixedSize(250,40);
    m_namelineedit->setPlaceholderText("用户名(八位内字符数字组成)");
    m_namelineedit->setAlignment(Qt::AlignHCenter);
    QFont ft1;
    ft1.setLetterSpacing(QFont::AbsoluteSpacing,3);
    m_namelineedit->setFont(ft1);
    QRegExp regx("[a-zA-Z0-9]{5,9}");
    m_namelineedit->setValidator(new QRegExpValidator(regx,this));

    //密码框
    m_passwordlineedit = new QLineEdit;
    m_passwordlineedit->setPlaceholderText("(密码位数>8)");
    m_passwordlineedit->setAlignment(Qt::AlignHCenter);
    m_passwordlineedit->setFixedSize(250,40);
    m_passwordlineedit->setFont(ft1);
    QRegExp rx("[a-zA-Z0-9!@#%^&*()_]{8,}$");
    m_passwordlineedit->setValidator(new QRegExpValidator(rx,this));
    m_passwordlineedit->setEchoMode(QLineEdit::Password);

    m_try_pwdlineedit = new QLineEdit;
    m_try_pwdlineedit->setPlaceholderText("请确认密码");
    m_try_pwdlineedit->setAlignment(Qt::AlignHCenter);
    m_try_pwdlineedit->setFixedSize(250,40);
    m_try_pwdlineedit->setFont(ft1);
    m_try_pwdlineedit->setValidator(new QRegExpValidator(rx,this));
    m_try_pwdlineedit->setEchoMode(QLineEdit::Password);

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
    glayout->addWidget(m_okbutton, 3, 0, 1, 1,Qt::AlignCenter);
    glayout->addWidget(m_cancelbutton, 4, 0, 1, 1,Qt::AlignCenter);
    glayout->setHorizontalSpacing(30);
    glayout->setAlignment(Qt::AlignCenter);
    registerwidget->setLayout(glayout);

    setheadtitle(":/images/panda.png","注册");
    setCentralWidget(registerwidget);
    m_namelineedit->setStyleSheet(QString(":focus{ background-color: black; }"));
    m_passwordlineedit->setStyleSheet(QString(":focus{ background-color: black; }"));
    m_try_pwdlineedit->setStyleSheet(QString(":focus{ background-color: black; }"));

    connect(m_okbutton,&DSuggestButton::clicked,this,
            [=]() {
            if(m_namelineedit->text().isEmpty() || m_passwordlineedit->text().isEmpty()
                    || m_try_pwdlineedit->text().isEmpty()){
                QMessageBox::information(this,"注册信息","请输入用户名或密码！");
                if(m_namelineedit->text().isEmpty()){m_namelineedit->setStyleSheet("color: rgb(255, 78, 25);");}
            }else{
            if(m_passwordlineedit->text() != m_try_pwdlineedit->text()){
                    QMessageBox::information(this,"注册信息","密码不一致！\n请仔细确认密码！");
                    m_passwordlineedit->setStyleSheet("color: rgb(255, 78, 25);");
                    m_try_pwdlineedit->setStyleSheet("color: rgb(255, 78, 25);");
                }else{
                        QMessageBox::information(this,"注册信息","注册成功 0.0");
                     }
                  }
    });

    connect(m_cancelbutton,&DSuggestButton::pressed,this,
            [=]() {
            this->close();
    });

}

m_loginregister::~m_loginregister()
{

}

//标题函数
void m_loginregister::setheadtitle(const QString &Lefticon, const QString &Righticon)
{
    tit = this->titlebar();
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
