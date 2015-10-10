#ifndef ENNEMYBULLET_H
#define ENNEMYBULLET_H

#include"bullet.h"

class EnnemyBullet : public Bullet
{
public:
    EnnemyBullet(float orig_x, float orig_y, float dest_x, float dest_y, double speed);
    EnnemyBullet(sf::Vector2<float> origin, sf::Vector2<float> dest, double speed);
    ~EnnemyBullet();

private:
};

#endif // ENNEMYBULLET_H
