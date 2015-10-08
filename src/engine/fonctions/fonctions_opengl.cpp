#include "fonctions_opengl.h"

sf::Texture loadTexture(std::string filepath)
{
    sf::Texture texture;

    if (!texture.loadFromFile(filepath))
    {
        std::cout << "Could not load" << filepath;
    }
    return texture;
}
