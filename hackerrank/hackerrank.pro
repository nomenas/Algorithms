TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += \
    inputfromfile.cpp \
    iostreamformating_piramide.cpp \
    iostreamformating_printingfloat.cpp \
    timeconversion.cpp

DEFINES += FILEINPUT

DISTFILES += \
    input.dat
