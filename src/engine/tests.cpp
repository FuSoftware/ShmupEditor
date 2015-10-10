#include "tests.h"

void test_player_ennemy()
{
    std::cout << "Loading Test 1 - Player + Ennemy" << std::endl;

    std::cout << "Loading Engine" << std::endl;
    QEngineWidget *engine = new QEngineWidget(0,QPoint(0,0),QSize(WIN_W,WIN_H));
    engine->load_background(std::string(TEXTURE_FOLDER) + std::string("background.jpg"));
    engine->show();

    /*Création joueur*/
    std::cout << "Loading Player" << std::endl;
    Player *player = new Player(engine->getWidth()/2,0);
    engine->addPlayer(player);

    /*Spawns an ennemy*/
    std::cout << "Loading Ennemies" << std::endl;
    Ennemy *ennemy = new Ennemy(TEST_FILE_ENNEMY,engine);
    engine->addEnnemy(ennemy);
}

