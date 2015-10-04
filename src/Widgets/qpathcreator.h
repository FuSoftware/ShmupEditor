#ifndef QPATHCREATOR_H
#define QPATHCREATOR_H

#include <iostream>
#include <vector>

#include <SFML/Window.hpp>

#include "./Objects/timedvector.h"
#include "qsfmlcanvas.h"

#define CIRCLE_D 3

using namespace sf;

class QPathCreator : public QSFMLCanvas
{
    Q_OBJECT
public :
    QPathCreator(QWidget* Parent, const QPoint& Position, const QSize& Size);
    ~QPathCreator();
    void OnInit();
    void OnUpdate();

    void drawLines();
    void drawCoordinates();
    void addCoordinate(Vector2<float> vector);

private :
    sf::Sprite mySprite;
    sf::Window *virtualWindow; //Used for mouse coordinates

    std::vector< TimedVector* > coordinates;

    int point_time;
    bool cursor_in_field;

};

#endif // QPATHCREATOR_H
