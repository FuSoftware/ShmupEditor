#include "timedvector.h"

TimedVector::TimedVector()
{
    TimedVector(sf::Vector2<float>(0,0),sf::Vector2<float>(0,0), 0);
}

TimedVector::TimedVector(sf::Vector2<float> vector, sf::Vector2<float> parent, VectorType type)
{
    setParent(parent);
    setVector(vector,type);
    setTime(0);
}

TimedVector::TimedVector(sf::Vector2<float> vector, sf::Vector2<float> parent, int time, VectorType type)
{
    setParent(parent);
    setVector(vector,type);
    setTime(time);
}

void TimedVector::setVector(sf::Vector2<float> vector, VectorType type)
{
    if(type == V_REL)
    {
        this->vector_rel = vector;
        generateAbs();
    }
    else
    {
        this->vector_abs = vector;
        generateRel();
    }
}

void TimedVector::setParent(sf::Vector2<float> parent)
{
    this->parent_size = parent;
}

void TimedVector::generateAbs()
{
    this->vector_abs.x = this->vector_rel.x * this->parent_size.x;
    this->vector_abs.y = this->vector_rel.y * this->parent_size.y;
}

void TimedVector::generateRel()
{
    this->vector_rel.x = this->vector_abs.x / this->parent_size.x;
    this->vector_rel.y = this->vector_abs.y / this->parent_size.y;
}

void TimedVector::setVectorCoord(float x, float y)
{
    this->vector_abs = sf::Vector2<float>(x,y);
    generateRel();
}

void TimedVector::setTime(int time)
{
    this->time = time;
}

sf::Vector2<float> TimedVector::getVector(VectorType type)
{
    if(type == V_REL){return this->vector_rel;}
    else{return this->vector_abs;}
}

int TimedVector::getTime()
{
    return this->time;
}

float TimedVector::getX(VectorType type)
{
    if(type == V_REL){return this->vector_rel.x;}
    else{return this->vector_abs.x;}
}

float TimedVector::getY(VectorType type)
{
    if(type == V_REL){return this->vector_rel.y;}
    else{return this->vector_abs.y;}
}

float TimedVector::getCoord(int i, VectorType type)
{
    switch(i)
    {
    case 0:
        return getX(type);
        break;
    case 1:
        return getY(type);
        break;
    case 2:
        return (float)this->time;
        break;
    default:
        return 0;
        break;
    }
}
