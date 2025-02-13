#-------------------------------------------------
#
# Project created by QtCreator 2016-06-16T15:12:38
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = FaceDetect
TEMPLATE = app

INCLUDEPATH += /usr/local/include/opencv \
    /usr/local/opt/opencv \
    /usr/local/opt/opencv/include/opencv4


LIBS += -L/usr/local/lib -lopencv_core -lopencv_imgcodecs -lopencv_highgui -lopencv_imgproc -lopencv_videoio -lopencv_ml -lopencv_video -lopencv_features2d -lopencv_calib3d -lopencv_objdetect -lopencv_flann

SOURCES += src/main.cpp\
        src/mainwindow.cpp \
        src/facedetector.cpp

HEADERS  += src/mainwindow.h \
        src/facedetector.h

FORMS    += src/mainwindow.ui
