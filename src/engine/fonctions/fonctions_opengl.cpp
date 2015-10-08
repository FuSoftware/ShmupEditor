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

void draw_circle(double radius)
{
    static const int circle_points = 100;
    static const double angle = (2.0f * 3.1416) / circle_points;

    // this code (mostly) copied from question:
    glBegin(GL_POLYGON);
        double angle1=0.0;
        glVertex2d(radius * cos(0.0) , radius * sin(0.0));
        for (int i=0; i<circle_points; i++)
        {
            glVertex2d(radius * cos(angle1), radius *sin(angle1));
            angle1 += angle;
        }
    glEnd();
}

void draw_square(double w, double h, bool center)
{
    /*This is used when centering the drawing*/

    /* Drawing*/
    if(center)
    {
        w = w/2;
        h = h/2;

        glBegin(GL_QUADS);
            glTexCoord2d(0,1); glVertex2d(-w,-h); //Bas Gauche
            glTexCoord2d(1,1); glVertex2d(w,-h);//Bas Droite
            glTexCoord2d(1,0); glVertex2d(w,h);//Haut Droite
            glTexCoord2d(0,0); glVertex2d(-w,h); //Haut Gauche
        glEnd();
    }
    else
    {
        glBegin(GL_QUADS);
            glTexCoord2d(0,1); glVertex2d(0,0); //Bas Gauche
            glTexCoord2d(1,1); glVertex2d(w,0);//Bas Droite
            glTexCoord2d(1,0); glVertex2d(w,h);//Haut Droite
            glTexCoord2d(0,0); glVertex2d(0,h); //Haut Gauche
        glEnd();
    }
}
