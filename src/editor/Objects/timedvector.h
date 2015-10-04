#ifndef TIMEDVECTOR_H
#define TIMEDVECTOR_H

#include <SFML/Graphics.hpp>

#include <iostream>

class TimedVector
{
public:
    TimedVector();
    TimedVector(sf::Vector2<int> vector);
    TimedVector(sf::Vector2<int> vector, int time);

    TimedVector(sf::Vector2<float> vector);
    TimedVector(sf::Vector2<float> vector, int time);

    TimedVector(int x, int y);
    TimedVector(int x, int y, int time);

    TimedVector(float x, float y);
    TimedVector(float x, float y, int time);

    void setVector(sf::Vector2<float> vector);
    void setVectorCoord(float x, float y);
    void setTime(int time);

    sf::Vector2<float> getVector();
    int getTime();
    float getX();
    float getY();

    sf::Vector2<float> vector;

private:
    int time;

};

#endif // TIMEDVECTOR_H
