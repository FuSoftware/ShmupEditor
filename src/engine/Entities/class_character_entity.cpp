#include "class_character_entity.h"

Entity::Entity()
{
    this->setHitboxDrawable(false);
}

Entity::~Entity()
{

}

void Entity::draw()
{
    sf::Texture::bind(&texture);

    glTranslated(abs_pos.x,abs_pos.y,0);

    draw_square(size.x,size.y,true);

    if(hitbox_drawable)
    {
        sf::Texture::bind(0);
        glColor3ub(0,0,255);
        draw_circle(0.2);
        glColor3ub(255,255,255);
    }

    glTranslated(-abs_pos.x,-abs_pos.y,0);
}

void Entity::load_texture(std::string path)
{
    if (!texture.loadFromFile(path))
    {
        std::cout << "Could not load" << path << std::endl;
    }
}

void Entity::setParent(QEngineWidget *parent)
{
    parent_window = parent;
}

void Entity::setSize(int w, int h)
{
    sf::Vector2<int> v_size;
    v_size.x = w;
    v_size.y = h;
    setSize(v_size);
}

void Entity::setSize(sf::Vector2<int> size)
{
    this->size = size;
}

void Entity::setHitboxDrawable(bool ok)
{
    this->hitbox_drawable = ok;
}
