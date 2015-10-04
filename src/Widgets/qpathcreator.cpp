#include "qpathcreator.h"

QPathCreator::QPathCreator(QWidget* Parent, const QPoint& Position, const QSize& Size) : QSFMLCanvas(Parent, Position, Size)
{

}

QPathCreator::~QPathCreator()
{

}

void QPathCreator::OnInit()
{
    /*Intitialisation*/
    coordinates.push_back(new TimedVector(Vector2<float>(10.,10.)));
    coordinates.push_back(new TimedVector(Vector2<float>(200.,160.)));
    coordinates.push_back(new TimedVector(Vector2<float>(100.,300.)));

    point_time = 0;
    cursor_in_field = false;
}

void QPathCreator::OnUpdate()
{
    /*Update*/
    sf::Mouse mouse;

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
                coordinates.push_back(new TimedVector(mouse.getPosition(*renderWindow)));
                break;
            case sf::Mouse::Right:
                if(coordinates.size() > 0){coordinates.pop_back();}
                break;
            default:
                break;
            }
            break;
        case sf::Event::MouseWheelScrolled:
            switch(event.mouseWheelScroll.wheel)
            {
            case sf::Mouse::VerticalWheel:
                std::cout << "wheel type: vertical" << std::endl;
                break;
            case sf::Mouse::HorizontalWheel:
                std::cout << "wheel type: horizontal" << std::endl;
                break;
            default:
                std::cout << "wheel type: unknow" << std::endl;
                break;
            }

            std::cout << "wheel movement: " << event.mouseWheelScroll.delta << std::endl;
            std::cout << "mouse x: " << event.mouseWheelScroll.x << std::endl;
            std::cout << "mouse y: " << event.mouseWheelScroll.y << std::endl;
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
        coordinates.push_back(new TimedVector(mouse.getPosition(*renderWindow)));
    }

    /*Drawing*/
    renderWindow->clear(); //Clears the screen
    drawCoordinates();
    drawLines();

    /*Deletes the last coordinate (the mouse's one)*/
    if(cursor_in_field)
    {
        coordinates.pop_back();
    }
}

void QPathCreator::drawLines()
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

void QPathCreator::drawCoordinates()
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

void QPathCreator::addCoordinate(Vector2<float> vector)
{
    coordinates.push_back(new TimedVector(vector));
}

