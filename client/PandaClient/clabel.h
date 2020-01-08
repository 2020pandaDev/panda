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

#ifndef CLABEL_H
#define CLABEL_H

#include <QWidget>
#include <QLabel>
#include <QHBoxLayout>
#include <QMouseEvent>
#include <QPainter>

class CLabel : public QWidget
{
    Q_OBJECT

public:

    explicit CLabel(QWidget *parent = 0);
    ~CLabel();

    void setPixmap(const QPixmap &);
    void setText(const QString &);
    void setMouseEnterFlag(bool);
    void setMousePressFlag(bool);

protected:

    void enterEvent(QEvent *);
    void leaveEvent(QEvent *);
    void mousePressEvent(QMouseEvent *);
    void paintEvent(QPaintEvent *);

signals:

    void signalLabelPress(CLabel *);

private:

    void initVariable();
    void initSetupUi();
    void createFrame();
    void createWidget();
    void createLayout();
    void paintWidget(int, QPainter *);
    bool getMouseEnterFlag();
    bool getMousePressFlag();

    bool m_mouseEnterFlag;
    bool m_mousePressFlag;

    QHBoxLayout *m_pHLayout;
    QLabel *m_pLabelIcon;
    QLabel *m_pLabelText;
};

#endif //CLABEL_H
