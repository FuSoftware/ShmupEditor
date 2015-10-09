#include "bullet.h"

Bullet::Bullet(float orig_x, float orig_y, float dest_x, float dest_y, double speed)
{
    setSize(BULLET_WIDTH,BULLET_HEIGHT);

    sf::Vector2<float> v_orig;
    sf::Vector2<float> v_dest;

    v_orig.x = orig_x;
    v_orig.y = orig_y;
    v_dest.x = dest_x;
    v_dest.y = dest_y;

    setOrigin(v_orig);
    setDestination(v_dest);
    setSpeed(speed);

    this->setHitboxDrawable(true);
}

Bullet::Bullet(sf::Vector2<float> origin, sf::Vector2<float> dest, double speed)
{
    setSize(BULLET_WIDTH,BULLET_HEIGHT);
    setOrigin(origin);
    setDestination(dest);
    setSpeed(speed);

    std::cout << "Spawned bullet" << std::endl;
}

Bullet::~Bullet()
{

}

void Bullet::move()
{
    abs_pos.x = abs_pos.x + 0;
    abs_pos.y = abs_pos.y + BULLET_SPEED;
}

bool Bullet::isOutOfBounds()
{
    if(abs_pos.x > parent_window->getWidth())
    {
        return true;
    }
    else if(abs_pos.y > parent_window->getHeight())
    {
        return true;
    }
    else if(abs_pos.x < 0)
    {
        return true;
    }
    else if(abs_pos.y < 0)
    {
        return true;
    }
    else
    {
        return false;
    }
}

void Bullet::setOrigin(sf::Vector2<float> origin)
{
    this->origin = origin;
    this->abs_pos = origin;
}

void Bullet::setDestination(sf::Vector2<float> dest)
{
    this->dest = dest;
}

void Bullet::setSpeed(double speed)
{
    this->bullet_speed = speed;
}
