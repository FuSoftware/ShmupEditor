#ifndef PROJECT_H
#define PROJECT_H

#include <QObject>

#include <QtWidgets>

#include "fonctions_json.h"

class Project : public QObject
{
    Q_OBJECT
public:
    Project(QObject *parent = 0);
    Project(std::string configFile, QObject *parent = 0);

    void loadConfig(Json::Value root);
    void loadFiles(Json::Value files_root);

    QDir getDir();

signals:

public slots:

private:
    /*Local variables*/
    QDir rootFolder;
    QFile *configFile;

    /*Project configuration*/
    std::vector<std::string> ennemy_files;
    std::vector<std::string> level_files;
    std::vector<std::string> path_files;
    std::vector<std::string> pattern_files;
    std::vector<std::string> player_files;
    std::vector<std::string> sprite_files;


};

#endif // PROJECT_H

/*Project folder structure :

  config.json
  ./ennemies    - Contains all the ennemies' json files
  ./levels      - Contains all the levels' json files
  ./paths       - Contains all the user-created paths
  ./patterns    - Contains all the bullet patterns
  ./players     - Contains all the .json file of the different players
  ./sprites     - Contains all the pictures used for the game

  */

/*Config file structure :



  */
