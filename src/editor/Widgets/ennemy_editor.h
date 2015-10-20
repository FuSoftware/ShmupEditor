#ifndef ENNEMYEDITOR_H
#define ENNEMYEDITOR_H

#include <QtWidgets>
#include <iostream>
#include "./fonctions.h"
#include "./fonctions_json.h"

#include "qpathviewer.h"

#include "./Objects/timedvector.h"

class EnnemyEditor : public QWidget
{
    Q_OBJECT
public:
    EnnemyEditor(QWidget *parent = 0);
    EnnemyEditor(QString file, QWidget *parent = 0);
    ~EnnemyEditor();

    void loadUI();
    void loadFile(std::string file);
    void loadSprite(QString file);
    void loadPath(QString file);
    void loadPath(Json::Value root);

signals:

public slots:
    void loadSprite();
    void loadPath();
    void save();

private:
    Json::Value path;
    std::vector<TimedVector*> positions;
    QString sprite_path;
    QString name;
    int speed;
    int spawn_time;
    int health;
    bool sprite_loaded;
    bool path_loaded;

    QHBoxLayout *layoutMain;

    QVBoxLayout *layoutLeft;
    QLabel *labelSprite;
    QPathViewer *pathViewer;

    QVBoxLayout *layoutParam;

    QGridLayout *gridLayoutParam;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelSpawnTime;
    QLineEdit *lineEditSpawnTime;
    QLabel *labelHealth;
    QLineEdit *lineEditHealth;
    QLabel *labelSize;
    QLineEdit *lineEditSize[2];

    QPushButton *pushButtonSave;

    QHBoxLayout *layoutFile;
    QPushButton *pushButtonOpenFile;
    QLabel *labelFilePath;

    QHBoxLayout *layoutPath;
    QPushButton *pushButtonLoadPath;
    QLabel *labelPathFilePath;


};

/*Ennemy JSON Format :

{
  "name":"Fairy",
  "spawn_time":200,
  "pos": [
    {
      "x": 0,
      "y": 0,
      "time":60
    },
    {
      "x": 320,
      "y": 240,
      "time": 320
    }
  ],
  "sprite": "F:/Qt/Schmup_Data/sprites/sprite.jpeg",
  "health":100
}

*/

#endif // ENNEMYEDITOR_H
