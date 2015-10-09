#include "ennemybullet.h"

EnnemyBullet::EnnemyBullet(float orig_x, float orig_y, float dest_x, float dest_y, double speed) : Bullet(orig_x,orig_y,dest_x,dest_y,speed)
{

}

EnnemyBullet::EnnemyBullet(sf::Vector2<float> origin, sf::Vector2<float> dest, double speed) : Bullet(origin,dest,speed)
{

}

EnnemyBullet::~EnnemyBullet()
{

}

