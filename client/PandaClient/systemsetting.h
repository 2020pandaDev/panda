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
#ifndef SYSTEMSETTING_H
#define SYSTEMSETTING_H

#include<DWidget>
#include<DMainWindow>
#include<QMessageBox>
#include<DLineEdit>
#include<DLabel>
#include<DSuggestButton>
#include<QGridLayout>
#include <QGroupBox>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QRegExpValidator>
#include <QFont>
#include <QImage>
#include <DTitlebar>
#include <QMessageBox>


DWIDGET_USE_NAMESPACE

class SystemSetting : public DMainWindow
{
    Q_OBJECT

public:
    explicit SystemSetting(DWidget* parent = nullptr);

private slots:
    void setheadtitle(const QString &Lefticon,const QString &Righticon);
    void on_btnSaveSetting_clicked();
protected:
    void changeEvent(QEvent *e);

private:

    QWidget *configwidget;
    QGroupBox *group;
    QHBoxLayout *hlayout;
    QVBoxLayout *vlayout;

    QGridLayout *configlayout;
    DSuggestButton *m_okbutton;
    DSuggestButton *m_cancelbutton;

    QLineEdit *lineEditHostAddr;
    QLineEdit *lineEditHostMsgPort;
    QLineEdit *lineEditHostFilePort;
    DLabel *addr;
    DLabel *message;
    DLabel *file;

    //标题
    QImage *image;
    DTitlebar *tit;
    DWidget *headtitle;
    DLabel * lefticon;
    DLabel * righticon;

};

#endif // SYSTEMSETTING_H
