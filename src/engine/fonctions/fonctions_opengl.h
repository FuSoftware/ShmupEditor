#ifndef FONCTIONS_OPENGL_H
#define FONCTIONS_OPENGL_H

#include <SFML/OpenGL.hpp>
#include <SFML/Graphics.hpp>
#include <iostream>

sf::Texture loadTexture(std::string filepath);
void draw_circle(double radius);
void draw_square(double w, double h, bool center);

#endif // FONCTIONS_OPENGL_H
