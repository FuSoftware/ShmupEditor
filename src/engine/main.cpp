#include <QApplication>

#include <QFrame>
#include "Entities/class_character_player.h"

#include "Widgets/qenginewidget.h"

#define BORDER 20

#define WIN_W 800
#define WIN_H 600

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*Création fenêtre*/
    QFrame* MainFrame = new QFrame;
    MainFrame->setWindowTitle("Engine Widget");
    MainFrame->resize(WIN_W, WIN_H);
    MainFrame->show();

    QEngineWidget *engine = new QEngineWidget(MainFrame,QPoint(BORDER,BORDER),QSize(WIN_W-2*BORDER,WIN_H-2*BORDER));
    engine->load_background(std::string(TEXTURE_FOLDER) + std::string("background.jpg"));
    engine->show();

    /*Création joueur*/
    Player *player = new Player(engine->getWidth()/2,0);
    player->load_texture(std::string(TEXTURE_FOLDER)+std::string("perso_haut.png"));
    engine->addPlayer(player);

    return a.exec();
}
