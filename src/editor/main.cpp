#include "mainwindow.h"
#include "Widgets/qpathcreator.h"
#include "Widgets/ennemy_editor.h"
#include <QApplication>
#include <iostream>

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    MainWindow w;
    w.show();

    //EnnemyEditor e;
    //e.show();

    //QPathCreator *pathCreator = new QPathCreator(0);
    //pathCreator->show();

    return a.exec();
}
