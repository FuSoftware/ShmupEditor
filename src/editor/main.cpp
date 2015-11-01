#include "mainwindow.h"
#include <QApplication>
#include <iostream>

#include "Widgets/pattern_editor.h"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    //MainWindow w;
    //w.show();

    PatternEditor e;
    e.show();

    return a.exec();
}
