#-------------------------------------------------
#
# Project created by QtCreator 2011-05-25T10:53:33
#
#-------------------------------------------------

QT       += core widgets

TARGET = QtDemo_Dual
TEMPLATE = app

INCLUDEPATH +=../../JHCap2
LIBS += -lJHCap

QMAKE_CXXFLAGS_RELEASE += -O3 -Ofast
#DEFINES +=DEBUG
TRANSLATIONS=usbVideo_zh_CN.ts
SOURCES += main.cpp \
        mainwindow.cpp \
    aboutdialog.cpp \
    settingdialog.cpp \
    capturethread.cpp

HEADERS  += \
    mainwindow.h \
    aboutdialog.h \
    settingdialog.h \
    capturethread.h

FORMS    += mainwindow.ui \
    aboutdialog.ui \
    settingdialog.ui

OTHER_FILES +=

RESOURCES += \
    res.qrc

RC_FILE = app.rc





























