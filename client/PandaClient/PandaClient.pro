#-------------------------------------------------
#
# Project created by QtCreator 2018-08-18T06:54:09
#
#-------------------------------------------------

QT       += core gui network dbus

CONFIG +=c++11

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = PandaClient
TEMPLATE = app

CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget

OTHER_FILES += myapp.rc


# The following define makes your compiler emit warnings if you use
# any feature of Qt which as been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0

SOURCES += main.cpp\
           m_loginregister.cpp\
           login.cpp\
           clabel.cpp \
           systemsetting.cpp\
           myapp.cpp \  
           clientsocket.cpp\
           tcpclient.cpp \
           userinterface.cpp \
           personaldialog.cpp

HEADERS  += m_loginregister.h\
            login.h\
            clabel.h\
            systemsetting.h\
            myapp.h\
            clientsocket.h\
            unit.h\
            tcpclient.h \
            userinterface.h \
            personaldialog.h\
            global.h


FORMS += \
        tcpclient.ui \
        userinterface.ui \
        personaldialog.ui

DISTFILES += \
    images/bold.png \
    images/color.png \
    images/tilt.png \
    images/Underline.png \
    images/bold_copy.png \
    images/Underline.png \
    images/bold_copy.png \
    images/bold.png \
    images/color.png \
    images/tilt.png \
    images/Underline.png \
    images/color.png \
    images/tilt.png \
    images/bold.png \
    images/bold_copy.png

RESOURCES += \
    images.qrc
