#-------------------------------------------------
#
# Project created by QtCreator 2014-11-10T14:39:23
#
#-------------------------------------------------

QT -= gui

TEMPLATE = lib

HEADERS +=\
    vein-event_global.h \
    ve_eventsystem.h \
    ve_eventhandler.h \
    ve_storagesystem.h \
    ve_scriptengine.h \
    ve_eventdata.h \
    ve_commandevent.h \
    ve_validator.h

#dependencies
VEIN_DEP_HELPER = 1

exists( ../../project-paths.pri ) {
  include(../../project-paths.pri)
}

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

unix {
    target.path = /usr/lib
    INSTALLS += target
}

QMAKE_CXXFLAGS += -Wall -Wfloat-equal -std=c++0x

OTHER_FILES += \
    ../../TODO
