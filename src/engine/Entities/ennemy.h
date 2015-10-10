#ifndef ENNEMY_H
#define ENNEMY_H

#include "entity.h"
#include "../json/json.h"
#include "../fonctions/fonctions_json.h"

#include "../constantes.h"

#include "../Objects/timedvector.h"

class Ennemy : public Entity
{
public:
    Ennemy(QEngineWidget *parent = 0);
    Ennemy(std::string filepath, QEngineWidget *parent = 0);
    ~Ennemy();

    void loadFromJson(Json::Value root);
    void move();

    bool hasSpawned();
    bool isAlive();
    void spawn();

    int getSpawnTime();

private:
    sf::Clock timer;

    std::string name;

    int spawn_time;

    sf::Texture bullet_sprite;

    std::vector<TimedVector*> positions;

    bool spawned;
    bool alive;
    int current_pos_vec;

    Json::Value root;

};

#endif // ENNEMY_H

/*!
{
    "name" : "name",
    "sprite" : "path",
    "bullet_sprite" : "path",

    "path":[
    {x,y,t},
    {x,y,t},
    ...
    {x,y,t}
    ]
}
  */
