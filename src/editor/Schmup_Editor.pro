#-------------------------------------------------
#
# Project created by QtCreator 2015-09-04T22:42:39
#
#-------------------------------------------------

QT       += core gui

greaterThan(QT_MAJOR_VERSION, 4): QT += widgets

TARGET = Shmup_Editor
TEMPLATE = app

### TO ALLOW SFML LIBRARY ###
win32:{
INCLUDEPATH += $$PWD/../lib/SFML-2.3-mingw32/include
DEPENDPATH += $$PWD/../lib/SFML-2.3-mingw32/include
CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/SFML-2.3-mingw32/lib -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/SFML-2.3-mingw32/lib -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
}

unix:{
INCLUDEPATH += /usr/include
DEPENDPATH += /usr/include
CONFIG(release, debug|release): LIBS += -L/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -L/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
}

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
    Widgets/qsfmlcanvas.cpp \
    Objects/timedvector.cpp \
    Widgets/qpathcanvas.cpp \
    Widgets/qpathcreator.cpp \
    Widgets/qcoordwidget.cpp \
    Widgets/qpathviewer.cpp \
    project.cpp

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
    Widgets/qsfmlcanvas.h \
    Objects/timedvector.h \
    Widgets/qpathcanvas.h \
    Widgets/qpathcreator.h \
    Widgets/qcoordwidget.h \
    Widgets/qpathviewer.h \
    project.h

DISTFILES += \
    json/sconscript
