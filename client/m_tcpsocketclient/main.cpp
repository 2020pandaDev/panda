#include <DApplication>
#include <DMainWindow>
#include <DWidgetUtil>
#include <client.h>
DWIDGET_USE_NAMESPACE

int main(int argc, char *argv[])
{
    DApplication a(argc, argv);


    client w;
    w.setMinimumSize(500, 500);
    w.show();

    return a.exec();
}
