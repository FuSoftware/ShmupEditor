#include "pattern_editor.h"

PatternEditor::PatternEditor(QWidget *parent) : QWidget(parent)
{
    loadUI();
}

void PatternEditor::loadUI()
{
    QVBoxLayout *layoutMain = new QVBoxLayout;

    /*Name*/
    layouts.push_back(new QHBoxLayout);
    lineEdits.push_back(new QLineEdit(this));

    layouts.at(LAY_NAME)->addWidget(new QLabel("Name : "));
    layouts.at(LAY_NAME)->addWidget(lineEdits.at(LI_NAME));
    layoutMain->addLayout(layouts.at(LAY_NAME));

    /*NBullets*/
    layouts.push_back(new QHBoxLayout);
    comboBoxs.push_back(new QComboBox(this));
    comboBoxs.at(CO_NBULLETS)->setEditable(true);
    comboBoxs.at(CO_NBULLETS)->addItem("1");
    comboBoxs.at(CO_NBULLETS)->addItem("10");
    comboBoxs.at(CO_NBULLETS)->addItem("20");

    layouts.at(LAY_NBULLETS)->addWidget(new QLabel ("Bullet Number :",this));
    layouts.at(LAY_NBULLETS)->addWidget(comboBoxs.at(CO_NBULLETS));
    layouts.at(LAY_NBULLETS)->addWidget(new QLabel ("bullets",this));
    layoutMain->addLayout(layouts.at(LAY_NBULLETS));

    /*Speed*/
    layouts.push_back(new QHBoxLayout);
    comboBoxs.push_back(new QComboBox(this));
    comboBoxs.at(CO_SPEED)->setEditable(true);
    comboBoxs.at(CO_SPEED)->addItem("10");
    comboBoxs.at(CO_SPEED)->addItem("50");
    comboBoxs.at(CO_SPEED)->addItem("100");

    layouts.at(LAY_SPEED)->addWidget(new QLabel ("Speed :",this));
    layouts.at(LAY_SPEED)->addWidget(comboBoxs.at(CO_SPEED));
    layouts.at(LAY_SPEED)->addWidget(new QLabel ("px/s",this));
    layoutMain->addLayout(layouts.at(LAY_SPEED));

    /*Bullet list*/
    groupBoxBullets = new QGroupBox("Bullet List");
    layoutGroupBox = new QVBoxLayout;
    groupBoxBullets->setLayout(layoutGroupBox);
    layoutMain->addWidget(groupBoxBullets);

    /*Buttons*/
    QPushButton *buttonGenerateList = new QPushButton("Generate",this);
    layoutMain->addWidget(buttonGenerateList);

    setLayout(layoutMain);

    connect(buttonGenerateList,SIGNAL(clicked()),this,SLOT(generateBulletList()));
}

void PatternEditor::updatePreview()
{

}

void PatternEditor::generateBulletList()
{
    double angle_increment = (360/comboBoxs.at(CO_NBULLETS)->currentText().toInt());

    for(int i=0;i<comboBoxs.at(CO_NBULLETS)->currentText().toInt();i++)
    {
        addBullet(angle_increment*i, comboBoxs.at(CO_SPEED)->currentText().toDouble());
        layoutGroupBox->addLayout(generateBulletLayout(bullets.at(i), i));
    }
}


void PatternEditor::addBullet(double angle, double speed)
{
    bullets.push_back(new PatternBullet(angle,speed));
}

QHBoxLayout* PatternEditor::generateBulletLayout(PatternBullet* bullet, int index)
{
    QHBoxLayout* layout = new QHBoxLayout;

    lineEditsBulletsAngle.push_back(new QLineEdit(QString::number(bullet->getAngle()),this));
    lineEditsBulletsSpeed.push_back(new QLineEdit(QString::number(bullet->getSpeed()),this));

    layout->addWidget(new QLabel(QString("Bullet ") + QString::number(index),this));

    layout->addWidget(lineEditsBulletsAngle.at(index));
    layout->addWidget(new QLabel("°",this));

    layout->addWidget(lineEditsBulletsSpeed.at(index));
    layout->addWidget(new QLabel("px/s",this));

    return layout;
}

