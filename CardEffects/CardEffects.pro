#-------------------------------------------------
#
# Project created by QtCreator 2015-12-27T12:12:56
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = CardEffects
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    gameengine.cpp \
    commandparser.cpp \
    action.cpp \
    cardobj.cpp \
    player.cpp \
    cardarea.cpp

HEADERS  += mainwindow.h \
    gameengine.h \
    commandparser.h \
    action.h \
    cardobj.h \
    player.h \
    cardarea.h

FORMS    += mainwindow.ui

RC_FILE = CardEffects.rc

#RESOURCES = CardEffects.qrc
