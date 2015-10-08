#ifndef CLASS_CHARACTER_PLAYER
#define CLASS_CHARACTER_PLAYER

#include <iostream>
#include "constantes.h"
#include "class_character_entity.h"

#define SHOOT_DIVIDER 5

class Player : public Entity
{
public:
    Player(int pos_x, int pos_y);
    ~Player();

    void move(Direction direction);
    void shoot();

private:
    int input_buffer;
    int shoot_buffer;
};

#endif // CLASS_CHARACTER_PLAYER

