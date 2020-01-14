/*
 * Copyright (C) 2020 ~ 2020 Deepin Technology Co., Ltd.
 *
 * Author:     liujianan <liujianan@qq.com.com>
 *
 * Maintainer: liujianan <liujianan@qq.com.com>
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
#include "systemsetting.h"
#include "myapp.h"
#include "global.h"

SystemSetting::SystemSetting(DWidget* parent) :
    DMainWindow(parent)
{
    setheadtitle(":/image/panda.png","登录配置");
    QFont ft1;
    ft1.setLetterSpacing(QFont::AbsoluteSpacing,3);

    configwidget = new QWidget;
    configlayout = new QGridLayout;
    group = new QGroupBox;
    hlayout = new QHBoxLayout;
    vlayout = new QVBoxLayout;
    group->setTitle("服务器设置");


    addr = new DLabel;
    addr->setText(tr("服务器地址配置:"));
    message = new DLabel;
    message->setText(tr("消息服务器端口:"));
    file = new DLabel;
    file->setText(tr("文件服务器端口:"));

    lineEditHostAddr = new QLineEdit;
    QRegExp rx("((25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])[\\.]){3}(25[0-5]|2[0-4][0-9]|1[0-9][0-9]|[1-9][0-9]|[0-9])");
    lineEditHostAddr->setPlaceholderText("输入正确的ip地址");
    lineEditHostAddr->setFont(ft1);
    lineEditHostAddr->setFixedSize(200,35);
    lineEditHostAddr->setValidator(new QRegExpValidator(rx,this));
    //lineEditHostAddr->setInputMask(QString("000.000.000.000;_"));


    lineEditHostMsgPort = new QLineEdit;
    lineEditHostMsgPort->setFixedSize(200,35);
    lineEditHostMsgPort->setPlaceholderText("输入正确端口");
    QRegExp regx("[0-9]{1,5}");
    lineEditHostMsgPort->setValidator(new QRegExpValidator(regx,this));
    lineEditHostMsgPort->setFont(ft1);

    lineEditHostFilePort = new QLineEdit;
    lineEditHostFilePort->setFixedSize(200,35);
    lineEditHostFilePort->setPlaceholderText("输入正确端口");
    lineEditHostFilePort->setValidator(new QRegExpValidator(regx,this));
    lineEditHostFilePort->setFont(ft1);


    m_okbutton = new DSuggestButton(this);
    m_cancelbutton = new DSuggestButton(this);
    m_okbutton->setFixedSize(130,35);
    m_okbutton->setText(tr("确认"));
    m_cancelbutton->setFixedSize(130,35);
    m_cancelbutton->setText(tr("取消"));

    //布局
    configlayout->addWidget(addr,0,0,1,1);
    configlayout->addWidget(lineEditHostAddr,0,1,1,1);

    configlayout->addWidget(message,1,0,1,1);
    configlayout->addWidget(lineEditHostMsgPort, 1, 1,1,1);

    configlayout->addWidget(file,2,0,1,1);
    configlayout->addWidget(lineEditHostFilePort,2,1,1,1);

    hlayout->addStretch(0);
    hlayout->addWidget(m_okbutton);
    hlayout->addWidget(m_cancelbutton);
    configlayout->setContentsMargins(10,10,80,50);
    configlayout->setHorizontalSpacing(0);
    group->setLayout(configlayout);
    vlayout->addWidget(group);
    vlayout->addLayout(hlayout);

    configwidget->setLayout(vlayout);
    setCentralWidget(configwidget);
    setFixedSize(440, 340);

    // 加载之前的配置
   lineEditHostAddr->setText(MyApp::m_strHostAddr);
   lineEditHostMsgPort->setText(QString::number(MyApp::m_nMsgPort));
   lineEditHostFilePort->setText(QString::number(MyApp::m_nFilePort));


    //两个按钮响应函数
    connect(m_okbutton,&DSuggestButton::clicked,this,
            [=]() {
            on_btnSaveSetting_clicked();
    });
    connect(m_cancelbutton,&DSuggestButton::pressed,this,
            [=]() {
            this->close();
    });

}

//标题函数
void SystemSetting::setheadtitle(const QString &Lefticon, const QString &Righticon)
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

// 保存ip地址配置
void SystemSetting::changeEvent(QEvent *e)
{
    QWidget::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        //ui->retranslateUi(this);
        break;
    default:
        break;
    }
}

 //保存ip地址配置
void SystemSetting::on_btnSaveSetting_clicked()
{
    QString strHost = lineEditHostAddr->text();

    // 判断是否ip地址
    if (!myHelper::IsIP(strHost))
    {
        QMessageBox::information(this, "配置", "IP地址设置有误");
        return;
    }

    int nMsgPort = lineEditHostMsgPort->text().toInt();
    if (nMsgPort > 65535 || nMsgPort < 100) {
        QMessageBox::information(this, "配置", "端口设置有误(端口范围为[100-65535])");
        return;
    }

    int nFilePort =lineEditHostFilePort->text().toInt();
    if (nFilePort > 65535 || nFilePort < 100) {
        QMessageBox::information(this, "配置", "端口设置有误!(端口范围为[100-65535])");
        return;
    }

    if (nMsgPort == nFilePort) {
        QMessageBox::information(this, "配置", "2个端口不能设置一样!");
        return;
    }

    MyApp::m_strHostAddr = strHost;
    MyApp::m_nMsgPort    = nMsgPort;
    MyApp::m_nFilePort   = nFilePort;

    // 保存配置
    MyApp::SaveConfig();
     QMessageBox::information(this, "配置", "配置保存成功，重启生效!");
}
