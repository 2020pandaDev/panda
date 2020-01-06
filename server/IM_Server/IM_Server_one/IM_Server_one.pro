QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = IM_Server_one
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    server.cpp \
    serverthread.cpp \
    ctcpsv.cpp \
    mysql.cpp \
    worker.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    server.h \
    serverthread.h \
    ctcpsv.h \
    mysql.h \
    worker.h
