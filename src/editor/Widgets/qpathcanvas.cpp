#include "qpathcanvas.h"

QPathCanvas::QPathCanvas(QWidget* Parent, const QPoint& Position, const QSize& Size) : QSFMLCanvas(Parent, Position, Size, 1000/FPS)
{

}

QPathCanvas::~QPathCanvas()
{

}

void QPathCanvas::OnInit()
{
    /*Intitialisation*/

    point_time = 0;
    cursor_in_field = false;
    grid_divider = GRID_DIVIDER;

    BG_Tex.loadFromFile(PATH_BG);
    BG_Sprite.setTexture(BG_Tex);

    parent_size.x = this->width();
    parent_size.y = this->height();
}

void QPathCanvas::OnUpdate()
{
    /*Update*/
    sf::Mouse mouse;
    sf::Vector2<float> mouse_pos;
    mouse_pos.x = (float)mouse.getPosition(*renderWindow).x;
    mouse_pos.y = (float)mouse.getPosition(*renderWindow).y;

    /*Events*/
    sf::Event event;

    // tant qu'il y a des évènements à traiter...
    while (renderWindow->pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::MouseButtonPressed:
            switch(event.mouseButton.button)
            {
            case sf::Mouse::Left:
                coordinates.push_back(new TimedVector(mouse_pos,parent_size));
                emit coordAdded(coordinates.at(coordinates.size()-1));
                break;
            case sf::Mouse::Right:
                if(coordinates.size() > 0){coordinates.pop_back();emit coordDeleted(coordinates.size()-1);}
                break;
            default:
                break;
            }
            break;
        default:
            break;
        }
    }

    /*Checks if the cursor is in the window*/
    if(mouse.getPosition(*renderWindow).x < renderWindow->getSize().x && mouse.getPosition(*renderWindow).x >= 0 && mouse.getPosition(*renderWindow).y < renderWindow->getSize().y && mouse.getPosition(*renderWindow).y >= 0)
    {
        cursor_in_field = true;
    }
    else
    {
        cursor_in_field = false;
    }

    /*Get mouse pos to show on screen*/
    if(cursor_in_field)
    {
        coordinates.push_back(new TimedVector(mouse_pos,parent_size));
    }

    /*Drawing*/
    renderWindow->clear(); //Clears the screen

    /*Draws BG*/
    drawBG();

    /*Draws shapes*/
    drawGrid();
    drawCoordinates();
    drawLines();

    /*Deletes the last coordinate (the mouse's one)*/
    if(cursor_in_field)
    {
        coordinates.pop_back();
    }
}

void QPathCanvas::drawLines()
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

void QPathCanvas::drawCoordinates()
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

void QPathCanvas::addCoordinate(Vector2<float> vector)
{
    coordinates.push_back(new TimedVector(vector,parent_size));
}

void QPathCanvas::drawGrid()
{
    int x = this->width() / grid_divider;
    int y = this->height()/ grid_divider;

    sf::Vector2<float> vector;
    sf::Vector2<float> vector2;

    for(int j=0;j<2;j++)
    {
        for(int i=0;i<grid_divider;i++)
        {
            if(j==0)
            {
                vector.x = i*x;
                vector.y = 0;
                vector2.x = i*x;
                vector2.y = this->height();
            }
            else
            {
                vector.x = 0;
                vector.y = i*y;
                vector2.x = this->width();
                vector2.y = i*y;
            }

            Vertex line[] =
            {
                Vertex(vector),
                Vertex(vector2)
            };

            renderWindow->draw(line, 2, Lines);
        }
    }
}

void QPathCanvas::drawBG()
{
    this->getRenderWindow()->draw(BG_Sprite);
}

std::vector< TimedVector* > QPathCanvas::getCoordinates()
{
    return this->coordinates;
}
