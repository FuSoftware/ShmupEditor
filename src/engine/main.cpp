#include <QApplication>

#include <cstdio>
#include <cstdlib>

#include "tests.h"

#define LOG_FILE "F:/GitHub/SchmupEditor/data/log.txt"

int main(int argc, char *argv[])
{
    QApplication a(argc, argv);

    /*Log File*/
    std::freopen(LOG_FILE, "a", stdout);
    std::clog << std::endl;
    std::cout << std::endl;


    test_player_ennemy();

    return a.exec();
}
