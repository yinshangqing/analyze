#-------------------------------------------------
#
# Project created by QtCreator 2017-08-12T11:37:31
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = analyze
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    analyzefun.cpp \
    parmeter.cpp

HEADERS  += widget.h \
    analyzefun.h \
    stdafx.h \
    parmeter.h

FORMS    += widget.ui \
    analyzefun.ui \
    parmeter.ui

RESOURCES += \
    image.qrc


RC_FILE = myico.rc
