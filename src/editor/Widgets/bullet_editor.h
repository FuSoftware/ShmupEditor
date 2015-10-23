#ifndef BULLETEDITOR_H
#define BULLETEDITOR_H

#include <QtWidgets>
#include <iostream>
#include "./fonctions.h"
#include "./fonctions_json.h"

enum Data{
    D_NAME = 0,
    D_SIZE_W,
    D_SIZE_H,
    D_LIST_END
};

enum Layouts{
    L_SPRITE = 0,
    L_NAME,
    L_SIZE,
    L_LIST_END
};


class BulletEditor: public QWidget
{
    Q_OBJECT
public:
    BulletEditor(QWidget *parent = 0);
    BulletEditor(QString file, QWidget *parent = 0);

    void loadUI();
    void loadFile(QString file);
    void loadSprite(QString file);

public slots:
        void loadSprite();
        void save();

private:

    bool sprite_loaded;

    QLabel *labelSprite;
    QPushButton *pushButtonSprite;
    QLabel *labelSpritePath;

    QLabel *labelData[D_LIST_END];
    QLineEdit *lineEditData[D_LIST_END];

    QHBoxLayout *layoutDataChild[D_LIST_END];
};

#endif // BULLETEDITOR_H
