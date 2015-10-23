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
    QPathCreator(QString file, QWidget *parent = 0);
    void loadUI();

    void load(QString file);
    void load(Json::Value root);
    void saveFile(bool newFile);

signals:

public slots:
    void addCoordWidget(TimedVector *coordinates);
    void deleteCoordWidget(int index);
    void editCoordWidget(int index, TimedVector *coordinates);

    void save();
    void saveAs();


private:
    QString path;

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
