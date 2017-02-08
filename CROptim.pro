TEMPLATE = app
CONFIG += console c++11
CONFIG -= app_bundle
CONFIG -= qt

SOURCES += main.cpp \
    node.cpp \
    element.cpp \
    cps4.cpp \
    boundary.cpp \
    cfileio.cpp \
    cmodel.cpp \
    elset.cpp \
    nodeset.cpp


HEADERS += \
    node.h\
    element.h \
    cps4.h \
    auxil.h \
    boundary.h \
    cfileio.h \
    cmodel.h \
    elset.h \
    nodeset.h

DISTFILES += \
    input.in \

