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



DWIDGET_USE_NAMESPACE


class Login:public DMainWindow
{
    Q_OBJECT
public:
    explicit Login(QWidget *parent = 0);

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

protected Q_SLOTS:
    void menuItemInvoked(QAction *action);
private slots:
    void changeCurrentPage(CLabel *label);


};

#endif // LOGIN_H
