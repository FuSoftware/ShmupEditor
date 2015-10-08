#ifndef QENGINEWIDGET_H
#define QENGINEWIDGET_H

#include <iostream>
#include <vector>

#include "./Objects/timedvector.h"
#include "qsfmlcanvas.h"

#include <SFML/Window.hpp>
#include <SFML/Graphics.hpp>
#include <SFML/OpenGL.hpp>

#include <GL/gl.h>
#include <GL/glu.h>

#include "fonctions/fonctions_conversion.h"

class Entity;
class Player;
class Bullet;

using namespace sf;

class QEngineWidget : public QSFMLCanvas
{
    Q_OBJECT
public :
    QEngineWidget(QWidget* Parent, const QPoint& Position, const QSize& Size);
    ~QEngineWidget();
    void OnInit();
    void OnUpdate();

    void load_background(std::string path);
    void addPlayer(Player *player);
    void addEnnemy(Entity *ennemy);

    void addBullet(Bullet *bullet);

    void draw();
    void checkKeys();
    void drawBackground();

    int getWidth();
    int getHeight();

    void debugBullets();

private:
    int width;
    int height;

    bool continuer;

    sf::Text text;
    sf::Event evenements;

    sf::Texture background_picture;

    std::vector<Player*>players;
    int player_max_index;

    std::vector<Entity*> ennemies;
    int ennemy_max_index;

    std::vector<Bullet*> bullets;
    int bullet_max_index;
};

#endif // QENGINEWIDGET_H
