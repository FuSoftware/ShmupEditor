#ifndef ENTITY
#define ENTITY

#include <iostream>
#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>

#include "../Widgets/qenginewidget.h"
#include "../fonctions/fonctions_opengl.h"

class QEngineWidget;

class Entity
{
public:
    Entity(QEngineWidget *parent = 0);
    ~Entity();

    void draw();
    void load_texture(std::string path);
    void setParent(QEngineWidget *parent);

    void setSize(int w, int h);
    void setSize(sf::Vector2<int> size);

    void setHitboxDrawable(bool ok);

protected:
    sf::Vector2<float> abs_pos;
    sf::Vector2<int> size;

    sf::Vector2<float> parent_size;

    sf::Texture texture;

    QEngineWidget *parent_window;

    bool hitbox_drawable;
};

#endif // ENTITY

