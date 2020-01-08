QT += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

<<<<<<< HEAD
QT += sql

=======
>>>>>>> init server
TARGET = IM_Server_one
TEMPLATE = app
CONFIG += c++11 link_pkgconfig
PKGCONFIG += dtkwidget
<<<<<<< HEAD
QT += sql
=======

>>>>>>> init server
SOURCES += \
        main.cpp \
    server.cpp \
    serverthread.cpp \
    ctcpsv.cpp \
<<<<<<< HEAD
    mysql.cpp \
    worker.cpp \
    dataparsing.cpp
=======
    mysql.cpp
>>>>>>> init server

RESOURCES +=         resources.qrc

HEADERS += \
    server.h \
    serverthread.h \
    ctcpsv.h \
<<<<<<< HEAD
    mysql.h \
    worker.h \
    dataparsing.h
=======
    mysql.h
>>>>>>> init server
