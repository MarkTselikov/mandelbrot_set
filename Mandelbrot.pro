#-------------------------------------------------
#
# Project created by QtCreator 2017-01-03T00:54:12
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Mandelbrot
TEMPLATE = app


SOURCES += main.cpp\
        mainwindow.cpp \
    mandelbrotcreator.cpp

HEADERS  += mainwindow.h \
    mandelbrotcreator.h

FORMS    += mainwindow.ui
