#include "patternbullet.h"

PatternBullet::PatternBullet(double angle, double speed)
{
    setAngle(angle);
    setSpeed(speed);
}

void PatternBullet::setAngle(double a)
{
    this->angle = a;
}

void PatternBullet::setSpeed(double s)
{
    this->speed = s;
}

double PatternBullet::getAngle()
{
    return this->angle;
}

double PatternBullet::getSpeed()
{
    return this->speed;
}

