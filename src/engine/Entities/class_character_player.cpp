#include "class_character_player.h"

#include "class_bullet.h"


Player::Player(int pos_x, int pos_y)
{
    abs_pos.x = pos_x;
    abs_pos.y = pos_y;

    input_buffer = 0;

    setSize(PLAYER_WIDTH,PLAYER_HEIGHT);

    shoot_buffer = 0;
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
                abs_pos.y = abs_pos.y+MOVE_INCREMENT;
                break;
            case BAS:
                abs_pos.y = abs_pos.y-MOVE_INCREMENT;
                break;
            case GAUCHE:
                abs_pos.x = abs_pos.x-MOVE_INCREMENT;
                break;
            case DROITE:
                abs_pos.x = abs_pos.x+MOVE_INCREMENT;
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

