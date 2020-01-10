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

#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DGuiApplicationHelper>
#include "login.h"
#include "myapp.h"

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    DGuiApplicationHelper::instance()->setPaletteType(DGuiApplicationHelper::LightType);
    //a.setTheme("light");
    a.setOrganizationName("deepin");
    a.setApplicationName("Panda");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/image/logo.svg"));
    a.setProductName("Panda");
    a.setApplicationDescription("This is a Remote Assist application.");
    a.loadTranslator();
    MyApp::InitApp(a.applicationDirPath());
    //myHelper::setStyle("default");

    LoginWindow login;
    login.setFixedSize(440, 340);
    login.show();

    Dtk::Widget::moveToCenter(&login);

    return a.exec();
}


