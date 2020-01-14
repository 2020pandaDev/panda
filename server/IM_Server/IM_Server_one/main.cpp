#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <DLabel>
#include "mysql.h"
#include "server.h"
DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication::loadDXcbPlugin();
    DApplication a(argc, argv);
    a.setAttribute(Qt::AA_UseHighDpiPixmaps);
    a.setTheme("light");
    a.setOrganizationName("deepin");
    a.setApplicationName("服务器已启动");
    a.setApplicationVersion("1.0");
    a.setProductIcon(QIcon(":/images/logo.svg"));
    a.setProductName("panda Application");
    a.setApplicationDescription("This is a panda server application.");


    Server ser;
    DMainWindow w;
    w.setMinimumSize(500, 500);
    DLabel *label = new DLabel(&w);
    label->setFrameStyle(QFrame::NoFrame | QFrame::Raised);
    label->setPixmap(QPixmap(":/images/pd.jpeg"));
    label->setGeometry(w.width()/7,w.height()/5,500,400);
    label->adjustSize();
    w.show();



    Dtk::Widget::moveToCenter(&w);

    return a.exec();
}
