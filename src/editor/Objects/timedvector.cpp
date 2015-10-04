#include "timedvector.h"

TimedVector::TimedVector()
{
    TimedVector(sf::Vector2<float>(0,0), 0);
}

TimedVector::TimedVector(sf::Vector2<int> vector)
{
    sf::Vector2<float> floatVector = sf::Vector2<float>((float)vector.x,(float)vector.y);
    setVector(floatVector);
    setTime(0);
}

TimedVector::TimedVector(sf::Vector2<int> vector, int time)
{
    sf::Vector2<float> floatVector = sf::Vector2<float>((float)vector.x,(float)vector.y);
    setVector(floatVector);
    setTime(time);
}

TimedVector::TimedVector(sf::Vector2<float> vector)
{
    setVector(vector);
    setTime(0);
}

TimedVector::TimedVector(sf::Vector2<float> vector, int time)
{
    setVector(vector);
    setTime(time);
}

TimedVector::TimedVector(int x, int y)
{
    TimedVector(x,y,0);
}

TimedVector::TimedVector(int x, int y, int time)
{
    sf::Vector2<int> buffer = sf::Vector2<int>(x,y);
    TimedVector(buffer,time);
}

TimedVector::TimedVector(float x, float y)
{
    TimedVector(x,y,0);
}

TimedVector::TimedVector(float x, float y, int time)
{
    sf::Vector2<float> buffer = sf::Vector2<float>(x,y);
    TimedVector(buffer,time);
}

void TimedVector::setVector(sf::Vector2<float> vector)
{
    this->vector = vector;
}

void TimedVector::setVectorCoord(float x, float y)
{
    this->vector = sf::Vector2<float>(x,y);
}

void TimedVector::setTime(int time)
{
    this->time = time;
}

sf::Vector2<float> TimedVector::getVector()
{
    return this->vector;
}

int TimedVector::getTime()
{
    return this->time;
}

float TimedVector::getX()
{
    return this->vector.x;
}

float TimedVector::getY()
{
    return this->vector.y;
}
