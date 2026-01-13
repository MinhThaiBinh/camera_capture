#-------------------------------------------------
#
# Project created by QtCreator 2012-06-18T18:37:15
#
#-------------------------------------------------

QT       += widgets core

TARGET = OneCamera_QtDemo
TEMPLATE = app

#DEFINES +=DEBUG

INCLUDEPATH +=../../JHCap2
LIBS += -lJHCap

QMAKE_CXXFLAGS_RELEASE += -O3 -Ofast

SOURCES += main.cpp \
        mainwindow.cpp \   
        capturethread.cpp \
    iocontrol.cpp

HEADERS  += mainwindow.h \
            capturethread.h \
    iocontrol.h

FORMS    += mainwindow.ui \
    iocontrol.ui


