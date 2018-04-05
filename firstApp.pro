#-------------------------------------------------
#
# Project created by QtCreator 2018-03-18T11:01:07
#
#-------------------------------------------------

QT       += core gui charts     # this is used to indicate what liblaries (Qt modules) are being used in the project


greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = firstApp     # this is the name of the app
TEMPLATE = app      # template describes the type to build (app, liblary or subdirectories..)

# The following define makes your compiler emit warnings if you use
# any feature of Qt which has been marked as deprecated (the exact warnings
# depend on your compiler). Please consult the documentation of the
# deprecated API in order to know how to port your code away from it.
DEFINES += QT_DEPRECATED_WARNINGS

# You can also make your code fail to compile if you use deprecated APIs.
# In order to do so, uncomment the following line.
# You can also select to disable deprecated APIs only up to a certain version of Qt.
#DEFINES += QT_DISABLE_DEPRECATED_BEFORE=0x060000    # disables all the APIs deprecated before Qt 6.0.0


SOURCES += \
        main.cpp \
        mainwindow.cpp \
    pi.cpp \
    subject.cpp \
    qcustomplot.cpp \
    regulator.cpp \
    obiekt.cpp \
    subject.cpp \
    plotdelegate.cpp \
    configparser.cpp \
    config.cpp \
    arx.cpp \
    siso.cpp \
    loggerPF.cpp \
        pi.cpp \
    savemeas.cpp

HEADERS += \
        mainwindow.h \
    pi.h \
    subject.h \
    observer.h \
    qcustomplot.h \
    regulator.h \
    obiekt.h \
    subject.h \
    plotdelegate.h \
    configparser.h \
    config.h \
    arx.h \
    siso.h \
    loggerPF.h \
        pi.h \
    savemeas.h

FORMS += \
        mainwindow.ui

DISTFILES += \
    PSS_Config.xml
