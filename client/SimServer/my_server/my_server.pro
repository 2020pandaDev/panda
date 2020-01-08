QT += core gui
QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = my_server
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    server.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    server.h \
    unit.h
