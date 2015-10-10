#include "qpathviewer.h"

QPathViewer::QPathViewer(std::vector< TimedVector* > coordinates, QWidget* Parent, const QPoint& Position, const QSize& Size) : QSFMLCanvas(Parent, Position, Size, 1000/FPS)
{
    setPath(coordinates);
}

QPathViewer::~QPathViewer()
{

}

void QPathViewer::OnInit()
{
    /*Intitialisation*/

}

void QPathViewer::OnUpdate()
{
    /*Update*/
    drawPath();

}

void QPathViewer::drawPath()
{
    renderWindow->clear();
    drawLines();
    drawCoordinates();
}

void QPathViewer::setPath(std::vector< TimedVector* > coordinates)
{
    this->coordinates = coordinates;
}

void QPathViewer::drawLines()
{
    for(int i=1;i<coordinates.size();i++)
    {
        Vertex line[] =
        {
            Vertex(coordinates.at(i-1)->getVector()),
            Vertex(coordinates.at(i)->getVector())
        };

        renderWindow->draw(line, 2, Lines);
    }
}

void QPathViewer::drawCoordinates()
{
    /*Draw stored coordinates*/
    for(int i=0;i<coordinates.size();i++)
    {
        CircleShape shape(CIRCLE_D);

        Vector2<float> pos = Vector2<float>(coordinates.at(i)->getX()-CIRCLE_D,coordinates.at(i)->getY()-CIRCLE_D);

        shape.setPosition(pos);

        // change la couleur de la forme pour du vert
        shape.setFillColor(Color(100, 250, 50));

        renderWindow->draw(shape);
    }
}
