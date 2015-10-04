#-------------------------------------------------
#
# Project created by QtCreator 2015-09-04T22:42:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Schmup_Editor
TEMPLATE = app

### TO ALLOW SFML LIBRARY ###
INCLUDEPATH += $$PWD/../lib/SFML-2.3-mingw32/include
DEPENDPATH += $$PWD/../lib/SFML-2.3-mingw32/include

CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/SFML-2.3-mingw32/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/SFML-2.3-mingw32/lib -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d

### FILES ###

SOURCES += main.cpp\
        mainwindow.cpp \
    json/json_internalarray.inl \
    json/json_internalmap.inl \
    json/json_reader.cpp \
    json/json_value.cpp \
    json/json_valueiterator.inl \
    json/json_writer.cpp \
    fonctions.cpp \
    fonctions_json.cpp \
    Widgets/ennemy_editor.cpp \
    Widgets/qpathcreator.cpp \
    Widgets/qsfmlcanvas.cpp \
    Objects/timedvector.cpp

HEADERS  += mainwindow.h \
    json/assertions.h \
    json/autolink.h \
    json/config.h \
    json/features.h \
    json/forwards.h \
    json/json.h \
    json/json_batchallocator.h \
    json/json_tool.h \
    json/reader.h \
    json/value.h \
    json/version.h.in \
    json/writer.h \
    fonctions.h \
    fonctions_json.h \
    constantes.h \
    Widgets/ennemy_editor.h \
    Widgets/qpathcreator.h \
    Widgets/qsfmlcanvas.h \
    Objects/timedvector.h

DISTFILES += \
    json/sconscript
