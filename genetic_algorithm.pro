QT += core
QT -= gui

CONFIG += c++11

TARGET = genetic_algorithm
CONFIG += console
CONFIG -= app_bundle

TEMPLATE = app

SOURCES += main.cpp \
    genetic_algorithm.cpp \
    individual.cpp

HEADERS += \
    genetic_algorithm.h \
    individual.h
