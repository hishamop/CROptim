TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    cmodel.cpp \
    node.cpp \
    element.cpp \
    nodeset.cpp \
    cfileio.cpp \
    cps4.cpp \
    elset.cpp \
    mapping.cpp \
    boundary.cpp \
    face.cpp

HEADERS += \
    cmodel.h \
    cfileio.h \
    node.h \
    element.h \
    cps4.h \
    nodeset.h \
    elset.h \
    mapping.h \
    boundary.h \
    auxil.h \
    face.h
DISTFILES += \
    input.in \

