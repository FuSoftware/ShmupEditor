#ifndef QPathCanvas_H
#define QPathCanvas_H

#include <iostream>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "./Objects/timedvector.h"
#include "qsfmlcanvas.h"

#include "../constantes.h"

#define CIRCLE_D 3

#define GRID_DIVIDER 10

using namespace sf;

class QPathCanvas : public QSFMLCanvas
{
    Q_OBJECT
public :
    QPathCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size);
    ~QPathCanvas();
    void OnInit();
    void OnUpdate();

    void drawLines();
    void drawCoordinates();
    void addCoordinate(Vector2<float> vector);

    void drawGrid();
    void drawBG();

    std::vector< TimedVector* > getCoordinates();

signals:
    void coordAdded(TimedVector *coordinates);
    void coordDeleted(int index);
    void coordEdited(int index, TimedVector *coordinates);

private :
    sf::Sprite BG_Sprite;
    sf::Texture BG_Tex;
    sf::Window *virtualWindow; //Used for mouse coordinates

    std::vector< TimedVector* > coordinates;

    sf::Vector2<float> parent_size;

    int point_time;
    bool cursor_in_field;
    int grid_divider;

};

#endif // QPathCanvas_H
