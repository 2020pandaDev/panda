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
#include <QDebug>

Login::Login(QWidget *parent) : DWidget(parent)
{
    m_pLoginReg = new m_loginregister;
    initUI();
    connect(m_login_suggestButton, &DSuggestButton::clicked, this,
    [=]()
    {

    });
}

void Login::initUI()
{
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
    m_password_lineEdit->setEchoMode(QLineEdit::Password);
    m_registerAccount_label->setText("注册帐号");
    m_registerAccount_label->setStyleSheet("font-size:15px;color:blue");

    connect(m_registerAccount_label, SIGNAL(signalLabelPress(CLabel*)), this, SLOT(changeCurrentPage(CLabel*)));
    m_password_lineEdit->setPlaceholderText("密码");
    m_findPassword_label->setText("找回密码");
    m_findPassword_label->setStyleSheet("font-size:15px;color:blue");
    m_forgetPassword_CheckBox->setText("记住密码");
    m_autoLogin_CheckBox->setText("自动登陆");
    m_login_suggestButton->setText("登陆");

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
    setLayout(center_layout);
}

void Login::changeCurrentPage(CLabel *label)
{
    m_pLoginReg->show();
}



