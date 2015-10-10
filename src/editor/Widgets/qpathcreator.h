#ifndef QPATHCREATOR_H
#define QPATHCREATOR_H

#include <QtWidgets>

#include "qpathcanvas.h"
#include "qcoordwidget.h"

#include "./fonctions_json.h"

class QPathCreator : public QWidget
{
    Q_OBJECT
public:
    QPathCreator(QWidget *parent = 0);

signals:

public slots:
    void addCoordWidget(TimedVector *coordinates);
    void deleteCoordWidget(int index);
    void editCoordWidget(int index, TimedVector *coordinates);

    void save();


private:
    QPathCanvas* pathCanvas;
    QVBoxLayout* layoutCoordinates;
    std::vector<QCoordWidget*> coordinateWidgets;
    QSlider *sliderTime;
    QPushButton *pushButtonSave;

    QScrollArea *scrollCoord;
    QWidget *widgetArea;

    QSpacerItem *spacer;
    bool spacer_loaded;
};

#endif // QPATHCREATOR_H
