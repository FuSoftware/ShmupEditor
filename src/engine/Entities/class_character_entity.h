#ifndef CLASS_CHARACTER_ENTITY
#define CLASS_CHARACTER_ENTITY

#include <iostream>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include "./Widgets/qenginewidget.h"

class QEngineWidget;

class Entity
{
public:
    Entity();
    ~Entity();

    void draw();
    void load_texture(std::string path);
    void setParent(QEngineWidget *parent);

    void setSize(int w, int h);
    void setSize(sf::Vector2<int> size);

protected:
    sf::Vector2<float> abs_pos;
    sf::Vector2<int> size;

    sf::Texture texture;

    QEngineWidget *parent_window;
};

#endif // CLASS_CHARACTER_ENTITY

