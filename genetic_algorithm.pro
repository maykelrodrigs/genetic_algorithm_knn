QT += core
QT -= gui

CONFIG += c++11

TARGET = genetic_algorithm
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    genetic_algorithm.cpp \
    individual.cpp \
    sample.cpp

HEADERS += \
    genetic_algorithm.h \
    individual.h \
    sample.h \
    libxls/brdb.c.h \
    libxls/brdb.h \
    libxls/ole.h \
    libxls/xls.h \
    libxls/xlsstruct.h \
    libxls/xlstool.h \
    libxls/xlstypes.h

