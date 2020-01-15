#include "service.h"
#include <QApplication>
#include <QtDBus/QDBusConnection>
#include <QtDBus/QDBusError>
#include <QDebug>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);


    service w;
    if (!QDBusConnection::sessionBus().registerService(HELP_SERVICE_NAME)
            || !QDBusConnection::sessionBus().registerObject(HELP_SERVICE_NAME, &w,
            QDBusConnection::ExportAllSlots |
            QDBusConnection::ExportAllSignals | QDBusConnection::ExportScriptableSlots)) {
        qDebug() << "registerService Failed, Another activator maybe be running!"
                 << QDBusConnection::sessionBus().lastError();
    }
    //service w;
    w.show();
    return a.exec();
}
