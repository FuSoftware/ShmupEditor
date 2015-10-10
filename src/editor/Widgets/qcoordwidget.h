#ifndef QCOORDWIDGET_H
#define QCOORDWIDGET_H

#include <QtWidgets>
#include "../Objects/timedvector.h"

class QCoordWidget : public QWidget
{
    Q_OBJECT
public:
    QCoordWidget(int id, TimedVector *vector, QWidget *parent = 0);

    void changeData(int id, TimedVector *vector);
    void setIndex(int index);
    void generateWidget();

signals:

public slots:

private:
    QLabel *labelID;
    QLineEdit *lineEditCoord[3];

    TimedVector *vector;
    int id;


};

#endif // QCOORDWIDGET_H
