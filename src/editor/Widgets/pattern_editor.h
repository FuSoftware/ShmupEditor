#ifndef PATTERNEDITOR_H
#define PATTERNEDITOR_H

#include <QtWidgets>
#include <iostream>
#include <vector>

#include "../Objects/patternbullet.h"


/*Defines if the target is the player (with offset) or a static point)*/
enum TargeType{
    T_PLAYER,
    T_FIXED
};

enum PatternEditorLayouts{
    LAY_NAME = 0,
    LAY_NBULLETS,
    LAY_SPEED,
};

enum PatternEditorLineEdits{
    LI_NAME = 0,
};

enum PatternEditorComboBoxs{
    CO_NBULLETS = 0,
    CO_SPEED
};

/*=========================================*/

class PatternEditor : public QWidget
{
    Q_OBJECT
public:
    PatternEditor(QWidget *parent = 0);

    void loadUI();
    void updatePreview();
    void addBullet(double angle, double speed);

    QHBoxLayout* generateBulletLayout(PatternBullet* bullet, int index);

signals:

public slots:
    void generateBulletList();

private:
    QList<QHBoxLayout*> layouts;
    QList<QLineEdit*> lineEdits;
    QList<QComboBox*> comboBoxs;

    QGroupBox *groupBoxBullets;
    QVBoxLayout *layoutGroupBox;

    std::vector<PatternBullet*> bullets;
    QList<QLineEdit*> lineEditsBulletsAngle;
    QList<QLineEdit*> lineEditsBulletsSpeed;

};

#endif // PATTERNEDITOR_H
