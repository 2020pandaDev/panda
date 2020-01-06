#include "m_loginregister.h"
#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include<QTranslator>

DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    DGuiApplicationHelper::instance()->setPaletteType(DGuiApplicationHelper::LightType);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
  //  a.setTheme("light");
    a.setOrganizationName("deepin");
    a.setApplicationName("panda application");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/images/panda.png"));
    a.setProductName("Dtk Application");
    a.setApplicationDescription("This is a panda template application.");

    m_loginregister t;
    t.setFixedSize(480, 480);
    t.show();

    Dtk::Widget::moveToCenter(&t);

    return a.exec();
}
