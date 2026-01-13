QT += core
QT -= gui

CONFIG += c++11

LIBS += -lJHCap -lopencv_core -lopencv_highgui -lopencv_imgproc

TARGET = opencv_qt
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += opencv.cpp

