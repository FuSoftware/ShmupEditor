#include "fonctions.h"
#include "constantes.h"

#include <QDir>

void checkFolder(std::string path)
{
    QDir dirCache1(path.c_str());
    if (!dirCache1.exists()) {
        dirCache1.mkpath(".");
    }
}
