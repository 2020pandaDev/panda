QT += core gui
QT += core gui network
greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = m_tcpsocketclient
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    client.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    client.h
