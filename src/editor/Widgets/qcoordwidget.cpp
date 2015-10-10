#include "qcoordwidget.h"

QCoordWidget::QCoordWidget(int id, TimedVector *vector, QWidget *parent) : QWidget(parent)
{
    this->vector = vector;
    this->id = id;

    generateWidget();
}

void QCoordWidget::changeData(int id, TimedVector *vector)
{
    this->vector = vector;
    this->id = id;

    setIndex(id);

    for(int i=0;i<3;i++)
    {
        lineEditCoord[i]->setText(QString::number(vector->getCoord(i)));
    }
}

void QCoordWidget::setIndex(int index)
{
    labelID->setText(QString::number(index) + QString(". "));
}

void QCoordWidget::generateWidget()
{
    std::string labels[3] = {"x","y","t"};

    labelID = new QLabel(this);

    setIndex(id);

    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(labelID);

    for(int i=0;i<3;i++)
    {
        lineEditCoord[i] = new QLineEdit(QString::number(vector->getCoord(i)),this);
        layout->addWidget(new QLabel(QString(labels[i].c_str()) + QString(":")));

        layout->addWidget(lineEditCoord[i]);
    }
    setLayout(layout);
}

