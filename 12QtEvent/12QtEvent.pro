#-------------------------------------------------
#
# Project created by QtCreator 2022-05-12T10:03:55
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = 12QtEvent
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    mylabel.cpp

HEADERS  += widget.h \
    mylabel.h

FORMS    += widget.ui

CONFIG += c++11
