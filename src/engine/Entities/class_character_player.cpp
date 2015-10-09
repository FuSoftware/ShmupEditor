#include "class_character_player.h"

#include "bullet.h"


Player::Player(int pos_x, int pos_y, std::string file)
{
    abs_pos.x = pos_x;
    abs_pos.y = pos_y;

    input_buffer = 0;

    loadFromJson(file);

    shoot_buffer = 0;

    this->setHitboxDrawable(true);
}

Player::~Player()
{

}

void Player::move(Direction direction)
{
    bool move = true;

        if(move)
        {
            switch(direction)
            {
            case HAUT:
                abs_pos.y = abs_pos.y+speed;
                break;
            case BAS:
                abs_pos.y = abs_pos.y-speed;
                break;
            case GAUCHE:
                abs_pos.x = abs_pos.x-speed;
                break;
            case DROITE:
                abs_pos.x = abs_pos.x+speed;
                break;
            }
        }
}

void Player::shoot()
{
    sf::Vector2<float> dest;
    dest.x = abs_pos.x + (size.x/4);
    dest.y = parent_window->getHeight();

    if(shoot_buffer == 0)
    {
        Bullet *bullet = new Bullet(abs_pos,
                                    dest,
                                    1.0);

        bullet->load_texture(std::string(TEXTURE_FOLDER) + std::string("bullet_green.png"));

        parent_window->addBullet(bullet);
    }
    else if(shoot_buffer == SHOOT_DIVIDER)
    {
        shoot_buffer = -1;
    }

    shoot_buffer++;
}

void Player::loadFromJson(std::string file)
{
    root = loadJSONFile(file.c_str());

    setSpeed(root["speed"].asInt());
    load_texture(root["sprite"].asString());

    sf::Vector2<int> vec(root["size"][0].asInt(),root["size"][1].asInt());
    setSize(vec);

}

void Player::setSpeed(int speed)
{
    this->speed = speed;
}

/*!
{
    "health" : 1,
    "name" : "Sprite",
    "spawn_time" : 0,
    "sprite" : "F:/GitHub/SchmupEditor/data/sprites/sprite.png",
    "size" : [
    25,
    25
   ],
   "speed" : 5
}
*/
