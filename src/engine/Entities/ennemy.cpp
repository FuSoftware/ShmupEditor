#include "ennemy.h"

Ennemy::Ennemy(QEngineWidget *parent) : Entity(parent)
{
}

Ennemy::Ennemy(std::string filepath, QEngineWidget *parent) : Entity(parent)
{
    std::cout << "Loading JSON File " << filepath  << std::endl;

    Json::Value root = loadJSONFile(filepath.c_str());

    loadFromJson(root);
}

Ennemy::~Ennemy()
{
    std::cout << "Destroying " << name  << std::endl;
}

void Ennemy::loadFromJson(Json::Value root)
{
    name = root["name"].asString();

    texture = loadTexture(root["sprite"].asString());
    //bullet_sprite = loadTexture(root["bullet_sprite"].asString());

    spawn_time = root["spawn_time"].asInt();


    setSize(root["size"]["w"].asInt(),root["size"]["h"].asInt());

    int i = 0;

    sf::Vector2<float> vector;

    while(root["path"][i].isObject())
    {
        vector.x = root["path"][i]["x"].asFloat();
        vector.y = root["path"][i]["y"].asFloat();

        positions.push_back(new TimedVector(vector,parent_size,root["path"][i]["t"].asInt(),V_REL));
        i = i+1;
    }

    this->root = root;

    spawned = false;
    current_pos_vec = 0;

}

void Ennemy::move()
{
    if(current_pos_vec+1 >= positions.size())
    {
        delete this;
    }

    int d_time = positions.at(current_pos_vec+1)->getTime() - positions.at(current_pos_vec)->getTime();
    float d_x = positions.at(current_pos_vec+1)->getX() - positions.at(current_pos_vec)->getX();
    float d_y = positions.at(current_pos_vec+1)->getY() - positions.at(current_pos_vec)->getY();

    int frames = d_time / (1000/FPS);

    this->abs_pos.x += d_x/frames;
    this->abs_pos.y += d_y/frames;


    if(timer.getElapsedTime().asMilliseconds() > positions.at(current_pos_vec+1)->getTime())
    {
        //Increments what pos are to read
        current_pos_vec+=1;
    }
}

bool Ennemy::hasSpawned()
{
    return spawned;
}

bool Ennemy::isAlive()
{
    return this->alive;
}

void Ennemy::spawn()
{
    /*Spawn*/
    spawned = true;
    alive = true;
    timer.restart();

    abs_pos.x =  positions.at(current_pos_vec)->getX();
    abs_pos.y =  positions.at(current_pos_vec)->getY();

    std::cout << name << " spawned at " << abs_pos.x << "," << abs_pos.y << std::endl;
}

int Ennemy::getSpawnTime()
{
    return this->spawn_time;
}

