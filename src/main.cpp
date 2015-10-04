#include "mainwindow.h"
#include "Widgets/qpathcreator.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);
    MainWindow w;
    w.show();

    //EnnemyEditor e;
    //e.show();

    /*
    QFrame* MainFrame = new QFrame;
    MainFrame->setWindowTitle("Qt SFML");
    MainFrame->resize(400, 400);
    MainFrame->show();

    QPathCreator *pathCreator = new QPathCreator(MainFrame,QPoint(20,20),QSize(360,360));
    pathCreator->show();
    */


    return a.exec();
}
