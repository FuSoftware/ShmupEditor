#include "qenginewidget.h"

#include "Entities/class_character_entity.h"
#include "Entities/class_character_player.h"
#include "Entities/bullet.h"

QEngineWidget::QEngineWidget(QWidget* Parent, const QPoint& Position, const QSize& Size) : QSFMLCanvas(Parent, Position, Size, (1000/FPS))
{
    player_max_index = 0;
    ennemy_max_index = 0;
    bullet_max_index = 0;

    this->height = Size.height();
    this->width = Size.width();

    /*Création de la fenêtre*/
    continuer = true;
}

QEngineWidget::~QEngineWidget()
{

}

void QEngineWidget::OnInit()
{
    /*Intitialisation*/

    /*Gestion OpenGL*/
    glEnable(GL_TEXTURE_2D);

    glMatrixMode( GL_PROJECTION );
    glLoadIdentity( );

    qDebug() << "Setting coordinates " << this->width << "," << this->height;

    gluOrtho2D(0, this->width, 0, this->height);
    glBlendFunc(GL_SRC_ALPHA,GL_ONE_MINUS_SRC_ALPHA);
    glEnable(GL_BLEND);
}

void QEngineWidget::OnUpdate()
{
    /*Update*/
    // handle events
    sf::Event event;
    while (this->getRenderWindow()->pollEvent(event))
    {
        switch(event.type)
        {
        case sf::Event::Closed:
            continuer = false;
            break;
        case sf::Event::Resized:
            glViewport(0, 0, event.size.width, event.size.height);
            break;
        default:
            break;
        }
    }
    checkKeys();
    draw();
}

void QEngineWidget::load_background(std::string path)
{
    if (!background_picture.loadFromFile(path))
    {
        std::cout << "Could not load" << path << std::endl;
    }
}

void QEngineWidget::addPlayer(Player *player)
{
    player->setParent(this);
    players.push_back(player);
}


void QEngineWidget::addEnnemy(Entity *ennemy)
{
    ennemy->setParent(this);
    ennemies.push_back(ennemy);
}

void QEngineWidget::addBullet(Bullet *bullet)
{
    bullet->setParent(this);
    bullets.push_back(bullet);
}


void QEngineWidget::draw()
{
    unsigned int i = 0;
    unsigned int j = 0;

    glClear(GL_COLOR_BUFFER_BIT);

    /*Background*/
    drawBackground();


    /*Players*/

    for(i=0;i<players.size();i++)
    {
        //Draws the players
        players.at(i)->draw();
    }

    /*Ennemies*/
    /*
    if(ennemy_max_index > 0)
    {
        for(int i=0;i<ennemy_max_index;i++)
        {
            ennemies[i]->draw();
        }
    }
    */

    /*Bullets*/
    for(i=0;i<bullets.size();i++)
    {
        if(!bullets.at(i)->isOutOfBounds())
        {
            //Draws the bullet if it's still supposed to be alive
            bullets.at(i)->move();
            bullets.at(i)->draw();
        }
        else
        {
            //Deletes the bullet if it reaches an ennemy or leaves the screen
            delete bullets.at(i); // Free the memory of the bullet to delete

            for(j = i; j < bullets.size()-1;j++)
            {
                bullets.at(j) = bullets.at(j+1); // Ensures no blank space is left in the bullet vector
            }
            bullets.pop_back();
            std::cout << "Deleted bullet " << i << std::endl;
        }
    }
}

void QEngineWidget::checkKeys()
{
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Up) ) players.at(0)->move(HAUT);
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Down) ) players.at(0)->move(BAS);
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Left) ) players.at(0)->move(GAUCHE);
    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Right) ) players.at(0)->move(DROITE);

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Space) ) players.at(0)->shoot();

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::BackSpace) ) debugBullets();

    if ( sf::Keyboard::isKeyPressed(sf::Keyboard::Escape) ) continuer = 0;
}

void QEngineWidget::drawBackground()
{
    sf::Texture::bind(&background_picture);

    draw_square(width,height,false);
}

int QEngineWidget::getWidth()
{
    return width;
}

int QEngineWidget::getHeight()
{
    return height;
}

void QEngineWidget::debugBullets()
{
    std::cout << "Bullets alive : " << bullets.size() << std::endl;
}

void QEngineWidget::spawnEnnemies()
{
    //Compare current time to each ennemy's spawn time

    //Spawns the ennemy
}

