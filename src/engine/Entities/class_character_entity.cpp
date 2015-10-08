#include "class_character_entity.h"

Entity::Entity()
{

}

Entity::~Entity()
{

}

void Entity::draw()
{
    sf::Texture::bind(&texture);

    glTranslated(abs_pos.x,abs_pos.y,0);

    glBegin(GL_QUADS);
        glTexCoord2d(0,0); glVertex2d(0,0); //Bas Gauche
        glTexCoord2d(0,1); glVertex2d(0,size.y); //Haut Gauche
        glTexCoord2d(1,1); glVertex2d(size.x,size.y);//Haut Droite
        glTexCoord2d(1,0); glVertex2d(size.x,0);//Bas Droite
    glEnd();

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
