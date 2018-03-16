#-------------------------------------------------
#
# Project created by QtCreator 2015-12-13T21:02:32
#
#-------------------------------------------------

QT       += core gui network

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets printsupport

TARGET = DownloadHttp
TEMPLATE = app


SOURCES += main.cpp\
        widget.cpp \
    downloader.cpp \
    currebcy_pair.cpp \
    qcustomplot.cpp \
    graf.cpp

HEADERS  += widget.h \
    downloader.h \
    currebcy_pair.h \
    qcustomplot.h \
    graf.h

FORMS    += widget.ui \
    graf.ui
