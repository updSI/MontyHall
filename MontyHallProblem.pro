#-------------------------------------------------
#
# Project created by QtCreator 2015-04-29T15:28:50
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = MontyHallProblem
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    Door.cpp

HEADERS  += mainwindow.h \
    Door.h

FORMS    += mainwindow.ui

RESOURCES += \
    slike.qrc
