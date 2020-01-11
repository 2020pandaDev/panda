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

#ifndef LOGIN_H
#define LOGIN_H
#include <DMainWindow>
#include <QHBoxLayout>
#include <QGridLayout>
#include <QLabel>
#include <QLineEdit>
#include <QPushButton>
#include <DSuggestButton>
#include <QCheckBox>
#include <DTitlebar>
#include "clabel.h"
#include "m_loginregister.h"
#include "systemsetting.h"
#include "clientsocket.h"



DWIDGET_USE_NAMESPACE


class LoginWindow:public DMainWindow
{
    Q_OBJECT
public:
    explicit LoginWindow(QWidget *parent = 0);

private:
    void initUI();

private:
    QWidget *m_mainWidget;
    QGridLayout *m_gridLayout;
    QLabel *m_userPng_label;

    CLabel *m_registerAccount_label;
    CLabel *m_findPassword_label;

    QCheckBox *m_forgetPassword_CheckBox;
    QCheckBox *m_autoLogin_CheckBox;
    DSuggestButton *m_login_suggestButton;

    QVBoxLayout *center_layout;
public:
    QLineEdit *m_usrName_lineEdit;
    QLineEdit *m_password_lineEdit;

private:
    m_loginregister *m_pLoginReg;
    SystemSetting *m_pSystemSet;

private:
    bool m_bConnected;
    // socket通信
    ClientSocket *m_tcpSocket;
private:
    bool checkUserAndPwd();

protected Q_SLOTS:
    void menuItemInvoked(QAction *action);
private slots:
    void changeCurrentPage(CLabel *label);
    // 服务器信息返回处理
    void SltTcpStatus(const quint8 &state);

    void on_checkBoxPasswd_clicked(bool checked);

    void on_checkBoxAutoLogin_clicked(bool checked);


};

#endif // LOGIN_H
