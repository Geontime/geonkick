######################################################################
# Automatically generated by qmake (3.0) Fri Dec 30 16:28:51 2016
######################################################################

QMAKE_CXXFLAGS += -std=c++1y
TEMPLATE = app
QT = core gui widgets
TARGET = geonckick
INCLUDEPATH += .
INCLUDEPATH += ../api/src/

LIBS += -L../api/ -lgeonkick -ljack

FORMS += MainWindow.ui

# Input
HEADERS += globals.h \
           gkickapi.h \
           gkickoscillator.h \
           envelope_point.h \
           oscillator_envelope.h \
           gkick_knob.h \
           oscillator_widget.h \
           mainwindow.h
SOURCES += envelope_point.cpp \
           gkickapi.cpp \
           gkickoscillator.cpp \
           oscillator_envelope.cpp \
           gkick_knob.cpp \
           oscillator_widget.cpp \
           mainwindow.cpp \
           main.cpp

