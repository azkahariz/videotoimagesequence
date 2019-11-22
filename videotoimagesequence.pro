#-------------------------------------------------
#
# Project created by QtCreator 2019-11-22T14:05:22
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = videotoimagesequence
TEMPLATE = app

INCLUDEPATH += ~/opencv-3.4.4/build/include

LIBS += -L"~/opencv-3.4.4/build/lib"

LIBS += -lopencv_calib3d

LIBS += -lopencv_core

LIBS += -lopencv_features2d

LIBS += -lopencv_flann

LIBS += -lopencv_highgui

LIBS += -lopencv_imgcodecs

LIBS += -lopencv_imgproc

LIBS += -lopencv_ml

LIBS += -lopencv_objdetect

LIBS += -lopencv_photo

LIBS += -lopencv_shape

LIBS += -lopencv_stitching

LIBS += -lopencv_superres

LIBS += -lopencv_video

LIBS += -lopencv_videoio

LIBS += -lopencv_videostab

LIBS += -lopencv_xfeatures2d


SOURCES += main.cpp

HEADERS  +=

FORMS    +=
