#-------------------------------------------------
#
# Project created by QtCreator 2014-11-10T14:39:23
#
#-------------------------------------------------

QT -= gui

TEMPLATE = lib

exists( ../../project-paths.pri ) {
  include(../../project-paths.pri)
}

QT += qml

TARGET = vein-event

DEFINES += VEINEVENT_LIBRARY

SOURCES += \
    ve_eventsystem.cpp \
    ve_eventhandler.cpp \
    ve_storagesystem.cpp \
    ve_scriptengine.cpp \
    ve_eventdata.cpp \
    ve_commandevent.cpp \
    ve_validator.cpp

PUBLIC_HEADERS = \
    vein-event_global.h \
    ve_eventdata.h

HEADERS +=\
    $$PUBLIC_HEADERS \
    ve_eventsystem.h \
    ve_eventhandler.h \
    ve_storagesystem.h \
    ve_scriptengine.h \
    ve_commandevent.h \
    ve_validator.h

unix {
    header_files.files = $$PUBLIC_HEADERS
    header_files.path = /usr/include
    INSTALLS += header_files
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CXXFLAGS += -Wall -Wfloat-equal -std=c++0x

OTHER_FILES += \
    ../../TODO
