/*
 * Copyright (C) 2019 ~ 2019 Deepin Technology Co., Ltd.
 *
 * Author:     zhanglei <zhanglei_cm@deepin.com>
 *
 * Maintainer: zhanglei <zhanglei_cm@deepin.com>
 *
 * This program is free software: you can redistribute it and/or modify
 * it under the terms of the GNU General Public License as published by
 * the Free Software Foundation, either version 3 of the License, or
 * any later version.
 *
 * This program is distributed in the hope that it will be useful,
 * but WITHOUT ANY WARRANTY; without even the implied warranty of
 * MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
 * GNU General Public License for more details.
 *
 * You should have received a copy of the GNU General Public License
 * along with this program.  If not, see <http://www.gnu.org/licenses/>.
 */

#include "login.h"
#include "unit.h"
#include "myapp.h"
#include "userinterface.h"
#include <QDebug>
#include <QMessageBox>


LoginWindow::LoginWindow(QWidget *parent) : DMainWindow(parent)
{
    m_pLoginReg = new m_loginregister;
    m_pSystemSet = new SystemSetting;
    initUI();
    /////////////
    DTitlebar *titlebar = this->titlebar();

    if (titlebar) {
        titlebar->setMenu(new QMenu(titlebar));
        titlebar->setSeparatorVisible(true);
        titlebar->menu()->addAction("设置");
        connect(titlebar->menu(), &QMenu::triggered, this, &LoginWindow::menuItemInvoked);
    }

    m_bConnected = false;

    // socket通信
    m_tcpSocket = new ClientSocket();
   // ui->labelWinTitle->setText(tr("正在连接服务器..."));
    m_tcpSocket->ConnectToHost(MyApp::m_strHostAddr, MyApp::m_nMsgPort);

    connect(m_tcpSocket, SIGNAL(signalStatus(quint8)), this, SLOT(SltTcpStatus(quint8)));

    connect(m_login_suggestButton, &DSuggestButton::clicked, this,
    [=]()
    {
        QString strUserID = m_usrName_lineEdit->text();
        QString strPwd = m_password_lineEdit->text();

        if (strUserID.isEmpty() || strPwd.isEmpty())
        {
            QMessageBox::information(this, "Panda客户端", "用户名或密码不能为空，请重新输入!");
            return;
        }
        if(!checkUserAndPwd())
            return;
        if (!m_bConnected) {
            m_tcpSocket->ConnectToHost(MyApp::m_strHostAddr, MyApp::m_nMsgPort);
            QMessageBox::information(this, "Panda客户端", "未连接服务器，请等待！");
            return;
        }

        // 构建 Json 对象
        QJsonObject json;
        json.insert("Type", Login);
        json.insert("usrName", strUserID);
        json.insert("password", strPwd);

        m_tcpSocket->SltSendMessage(Login, json);
    });


}

void LoginWindow::initUI()
{
    m_mainWidget = new QWidget;
    center_layout = new QVBoxLayout;
    // 构建控件 头像、用户名、密码输入框等
    m_gridLayout = new QGridLayout;
    m_userPng_label = new QLabel;
    m_usrName_lineEdit = new QLineEdit;
    m_password_lineEdit = new QLineEdit;
    m_registerAccount_label = new CLabel;
    m_findPassword_label = new CLabel;

    m_forgetPassword_CheckBox = new QCheckBox;
    m_autoLogin_CheckBox = new QCheckBox;
    m_login_suggestButton = new DSuggestButton;

    m_login_suggestButton->setFixedHeight(35);
    //m_usrName_lineEdit->setFixedWidth(200);

    // 设置头像
    QPixmap pixmap(":/images/QQ.svg");
    m_userPng_label->setFixedSize(90, 90);
    m_userPng_label->setPixmap(pixmap);
    m_userPng_label->setScaledContents(true);

    // 设置文本
    m_usrName_lineEdit->setPlaceholderText("用户名");
    QRegExp regx_user("[a-zA-Z0-9]{1,10}");
    m_usrName_lineEdit->setValidator(new QRegExpValidator(regx_user,this));

    QRegExp rx_password("[a-zA-Z0-9!,;:=+?@#%^&*]{6,18}$");
    m_password_lineEdit->setValidator(new QRegExpValidator(rx_password,this));
    m_password_lineEdit->setEchoMode(QLineEdit::Password);
    m_registerAccount_label->setText("注册账号");
    m_registerAccount_label->setStyleSheet("font-size:15px;color:blue");

    connect(m_registerAccount_label, SIGNAL(signalLabelPress(CLabel*)), this, SLOT(changeCurrentPage(CLabel*)));
    m_password_lineEdit->setPlaceholderText("密码");
    m_findPassword_label->setText("找回密码");
    m_findPassword_label->setStyleSheet("font-size:15px;color:blue");
    m_forgetPassword_CheckBox->setText("记住密码");
    m_autoLogin_CheckBox->setText("自动登陆");
    m_login_suggestButton->setText("登录");

    m_usrName_lineEdit->setClearButtonEnabled(true);
    m_password_lineEdit->setClearButtonEnabled(true);

    m_gridLayout->addWidget(m_userPng_label, 0, 0, 3, 1);
    m_gridLayout->addWidget(m_usrName_lineEdit, 0, 1, 1, 2);
    m_gridLayout->addWidget(m_password_lineEdit, 1, 1, 1, 2);
    m_gridLayout->addWidget(m_registerAccount_label, 0, 3, 1, 1);
    m_gridLayout->addWidget(m_findPassword_label, 1, 3, 1, 1);
    m_gridLayout->addWidget(m_forgetPassword_CheckBox, 2, 1, 1, 1);
    m_gridLayout->addWidget(m_autoLogin_CheckBox, 2, 2, 1, 1);
    m_gridLayout->addWidget(m_login_suggestButton, 3, 1, 1, 2);

    center_layout->setContentsMargins(10, 0, 0, 10);
    center_layout->addLayout(m_gridLayout);
    m_mainWidget->setLayout(center_layout);
    setCentralWidget(m_mainWidget);
}

void LoginWindow::changeCurrentPage(CLabel *label)
{
    m_pLoginReg->SetSocket(m_tcpSocket);
    m_pLoginReg->setWindowFlags( m_pLoginReg->windowFlags() & ~Qt::WindowMaximizeButtonHint);
    m_pLoginReg->show();
}

void LoginWindow::menuItemInvoked(QAction *action)
{
    if (action->text() == "设置") {
        m_pSystemSet->show();

    }
}

void LoginWindow::SltTcpStatus(const quint8 &state)
{
    qDebug()<<"state"<<state;
    switch (state) {
    case DisConnectedHost: {
        m_bConnected = false;
        qDebug()<<"服务器已断开";
       // ui->labelWinTitle->setText(tr("服务器已断开"));
    }
        break;
    case ConnectedHost:
    {
        m_bConnected = true;
        qDebug()<<"已连接服务器";
      //  ui->labelWinTitle->setText(tr("已连接服务器"));
    }
        break;
        // 登陆验证成功
    case LoginSuccess:
    {
        qDebug()<<"登录成功";
        disconnect(m_tcpSocket, SIGNAL(signalStatus(quint8)), this, SLOT(SltTcpStatus(quint8)));

       // QMessageBox::information(this, "Panda客户端", "登录成功；!");

        // 登录成功后，保存当前用户
        MyApp::m_strUserName = m_usrName_lineEdit->text();
        MyApp::m_strPassword = m_password_lineEdit->text();
        MyApp::SaveConfig();
        //显示聊天框
        UserInterface *m_pUserInterface = new UserInterface;
        qDebug()<<"login socket"<<m_tcpSocket;
        m_pUserInterface->SetSocket(m_tcpSocket, MyApp::m_strUserName);
        m_pUserInterface->show();
        this->close();


        // 显示主界面
//        MainWindow *mainWindow = new MainWindow();
//        if (!QFile::exists(MyApp::m_strHeadFile)) {
//            myHelper::Sleep(100);
//            QJsonObject jsonObj;
//            jsonObj.insert("from", MyApp::m_nId);
//            jsonObj.insert("id",  -2);
//            jsonObj.insert("msg", myHelper::GetFileNameWithExtension(MyApp::m_strHeadFile));
//            m_tcpSocket->SltSendMessage(GetFile, jsonObj);
//            myHelper::Sleep(100);
//        }

        // 居中显示
       // myHelper::FormInCenter(mainWindow);
     //  mainWindow->SetSocket(m_tcpSocket, MyApp::m_strUserName);
     //   mainWindow->show();
      //  this->close();
    }
        break;
    case LoginPasswdError:
    {
        QMessageBox::information(this, "Panda客户端", "登录失败，请检查用户名和密码!");
    }
        break;
    case UserNotFind:
    {
        QMessageBox::information(this, "Panda客户端", "登录失败，请检查用户名和密码!");
    }
        break;
    case LoginRepeat:
    {
        QMessageBox::information(this, "Panda客户端", "登录失败，该账户已登录!");
    }
        break;
    default:
        break;
    }

    // 还原初始位置，重新登录
  //  ui->widgetInput->setVisible(true);
 //   ui->labelUserHead->move(40, 115);
}

//注册判断机制
bool LoginWindow::checkUserAndPwd()
{
    QString nickName = m_usrName_lineEdit->text();//用户昵称
    QString firstPassWrd = m_password_lineEdit->text();//用户密码
    QRegExp rx;
    if(0 == nickName.size())
    {

        QMessageBox::information(this,"登录信息","用户名不能为空!");
        return false;
    }
    if(nickName.size() > 10)
    {
        QMessageBox::information(this,"登录信息","用户名长度超过10位!");
        return false;
    }

    rx.setPatternSyntax(QRegExp::RegExp);
    //对大小写字母敏感，即区分大小写
    rx.setCaseSensitivity(Qt::CaseSensitive);
    //匹配格式为所有大小写字母和数字组成的字符串，位数不限
    rx.setPattern(QString("[a-zA-Z0-9!@#%^&*()_]{6,18}$"));
    if(firstPassWrd.isEmpty())  //检测密码输入框是不是为空
    {
        QMessageBox::information(this,"登录信息","密码不能为空!");
        return false;
    }
    else if(!rx.exactMatch(firstPassWrd))
    {
        QMessageBox::information(this,"登录信息","密码位数为6-18位!");
       return false;

    }
    else if(firstPassWrd.size()<6 || firstPassWrd.size()>18)
    {
        QMessageBox::information(this,"登录信息","密码长度范围必须是[6,18]!");
        return false;

    }

    return true;
}
// 记住密码
void LoginWindow::on_checkBoxPasswd_clicked(bool checked)
{
    if (!checked) m_forgetPassword_CheckBox->setChecked(false);
}

// 自动登陆
void LoginWindow::on_checkBoxAutoLogin_clicked(bool checked)
{
    if (checked) m_autoLogin_CheckBox->setChecked(true);
}


