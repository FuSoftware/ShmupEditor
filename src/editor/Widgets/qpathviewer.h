#ifndef QPATHVIEWER_H
#define QPATHVIEWER_H

#include <iostream>
#include <vector>

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>

#include "../constantes.h"

#include "qsfmlcanvas.h"

#include "../Objects/timedvector.h"

#define CIRCLE_D 3

using namespace sf;


class QPathViewer: public QSFMLCanvas
{
    Q_OBJECT
public :
    QPathViewer(std::vector< TimedVector* > coordinates, QWidget* Parent, const QPoint& Position, const QSize& Size);
    ~QPathViewer();
    void OnInit();
    void OnUpdate();

    void drawPath();
    void setPath(std::vector< TimedVector* > coordinates);

    void drawLines();
    void drawCoordinates();

private:
    std::vector< TimedVector* > coordinates;
};

#endif // QPATHVIEWER_H
