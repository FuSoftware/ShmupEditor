#ifndef ENNEMYEDITOR_H
#define ENNEMYEDITOR_H

#include <QtWidgets>
#include <iostream>
#include "./fonctions.h"
#include "./fonctions_json.h"

#include "./Objects/timedvector.h"

class EnnemyEditor : public QWidget
{
    Q_OBJECT
public:
    EnnemyEditor(QWidget *parent = 0);
    ~EnnemyEditor();

signals:

public slots:
    void loadSprite();
    void save();

private:
    std::vector<TimedVector*> positions;
    QString sprite_path;
    QString name;
    int speed;
    int spawn_time;
    int health;
    bool sprite_loaded;

    QHBoxLayout *layoutMain;

    QLabel *labelSprite;

    QVBoxLayout *layoutParam;

    QGridLayout *gridLayoutParam;
    QLabel *labelName;
    QLineEdit *lineEditName;
    QLabel *labelSpawnTime;
    QLineEdit *lineEditSpawnTime;
    QLabel *labelHealth;
    QLineEdit *lineEditHealth;


    QPushButton *pushButtonSave;

    QHBoxLayout *layoutFile;
    QPushButton *pushButtonOpenFile;
    QLabel *labelFilePath;


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
