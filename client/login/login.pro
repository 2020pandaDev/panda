QT += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = login
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

SOURCES += \
        main.cpp \
    m_loginregister.cpp

RESOURCES +=         resources.qrc

HEADERS += \
    m_loginregister.h
