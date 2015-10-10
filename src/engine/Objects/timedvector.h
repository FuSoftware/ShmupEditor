#ifndef TIMEDVECTOR_H
#define TIMEDVECTOR_H

#include <SFML/Graphics.hpp>

#include <iostream>

enum VectorType
{
    V_ABS = 0,
    V_REL
};

class TimedVector
{
public:
    TimedVector();

    TimedVector(sf::Vector2<float> vector, sf::Vector2<float> parent, VectorType type = V_ABS);
    TimedVector(sf::Vector2<float> vector, sf::Vector2<float> parent, int time, VectorType type = V_ABS);

    void setVector(sf::Vector2<float> vector, VectorType type);
    void setVectorCoord(float x, float y);
    void setTime(int time);

    void setParent(sf::Vector2<float> parent);

    void generateAbs();
    void generateRel();

    sf::Vector2<float> getVector(VectorType type = V_ABS);
    int getTime();
    float getX(VectorType type = V_ABS);
    float getY(VectorType type = V_ABS);

    float getCoord(int i, VectorType type = V_ABS);

private:
    int time;

    sf::Vector2<float> vector_abs;
    sf::Vector2<float> vector_rel;
    sf::Vector2<float> parent_size;

    bool relative;

};

#endif // TIMEDVECTOR_H
