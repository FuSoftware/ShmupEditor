#ifndef CLASS_CHARACTER_PLAYER
#define CLASS_CHARACTER_PLAYER

#include <iostream>
#include "constantes.h"
#include "class_character_entity.h"
#include "../fonctions/fonctions_json.h"

#define SHOOT_DIVIDER 5

class Player : public Entity
{
public:
    Player(int pos_x, int pos_y, std::string file = TEST_FILE_PLAYER);
    ~Player();

    void move(Direction direction);
    void shoot();

    void loadFromJson(std::string file);

    void setSpeed(int speed);

private:
    int input_buffer;
    int shoot_buffer;

    int speed;

    Json::Value root;
};

#endif // CLASS_CHARACTER_PLAYER

