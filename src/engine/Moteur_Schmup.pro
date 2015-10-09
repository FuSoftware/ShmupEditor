#-------------------------------------------------
#
# Project created by QtCreator 2015-02-19T01:28:17
#
#-------------------------------------------------

QT       += core gui widgets

QMAKE_CXXFLAGS += -std=c++11

TARGET = Moteur_Schmup
TEMPLATE = app

### TO ALLOW SFML LIBRARY ###
INCLUDEPATH += $$PWD/../lib/SFML-2.3-mingw32/include
DEPENDPATH += $$PWD/../lib/SFML-2.3-mingw32/include

### FILES ###

#OpenGL Linux
#LIBS += -L/lib -lGLEW
#LIBS += -L/lib -lGL
#LIBS += -L/lib -lGLU

#OpenGL Windows
win32:{
LIBS += -lopengl32
LIBS += -lglu32

CONFIG(release, debug|release): LIBS += -L$$PWD/../lib/SFML-2.3-mingw32/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
CONFIG(debug, debug|release): LIBS += -L$$PWD/../lib/SFML-2.3-mingw32/lib/ -lsfml-audio-d -lsfml-graphics-d -lsfml-network-d -lsfml-window-d -lsfml-system-d
}
unix:{
LIBS += -L/lib/ -lGL
LIBS += -L/lib/ -lGLU
LIBS += -L/lib/ -lsfml-audio -lsfml-graphics -lsfml-network -lsfml-window -lsfml-system
}




HEADERS += constantes.h \
    Entities/class_character_player.h \
    fonctions/fonctions_conversion.h \
    fonctions/fonctions_opengl.h \
    Widgets/qenginewidget.h \
    Widgets/qsfmlcanvas.h \
    Objects/timedvector.h \
    Entities/class_character_entity.h \
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
    fonctions/fonctions.h \
    fonctions/fonctions_json.h \
    Objects/collisionengine.h \
    Entities/ennemybullet.h \
    Entities/bullet.h

SOURCES += main.cpp \
    Entities/class_character_entity.cpp \
    Entities/class_character_player.cpp \
    fonctions/fonctions_conversion.cpp \
    fonctions/fonctions_opengl.cpp \
    Widgets/qenginewidget.cpp \
    Widgets/qsfmlcanvas.cpp \
    Objects/timedvector.cpp \
    json/json_internalarray.inl \
    json/json_internalmap.inl \
    json/json_reader.cpp \
    json/json_value.cpp \
    json/json_valueiterator.inl \
    json/json_writer.cpp \
    fonctions/fonctions.cpp \
    fonctions/fonctions_json.cpp \
    Objects/collisionengine.cpp \
    Entities/ennemybullet.cpp \
    Entities/bullet.cpp

DISTFILES += \
    json/sconscript
