#include "qpathcreator.h"

QPathCreator::QPathCreator(QWidget *parent) : QWidget(parent)
{
    loadUI();
}

QPathCreator::QPathCreator(QString file, QWidget *parent) : QWidget(parent)
{
    loadUI();
    load(file);
    path = file;
}


void QPathCreator::loadUI()
{
    QVBoxLayout *layoutMain = new QVBoxLayout;
    QHBoxLayout *layoutPath = new QHBoxLayout;
    QHBoxLayout *layoutFooter = new QHBoxLayout;

    scrollCoord = new QScrollArea(this);
    widgetArea = new QWidget(scrollCoord);

    pushButtonSave = new QPushButton("Save",this);

    layoutCoordinates = new QVBoxLayout();

    scrollCoord->setWidgetResizable(true);
    scrollCoord->setWidget(widgetArea);
    scrollCoord->setHorizontalScrollBarPolicy(Qt::ScrollBarAlwaysOff);
    scrollCoord->setSizePolicy(QSizePolicy::MinimumExpanding,QSizePolicy::MinimumExpanding);

    QVBoxLayout *layoutCoordinatesB = new QVBoxLayout;
    layoutCoordinatesB->addLayout(layoutCoordinates);
    layoutCoordinatesB->addStretch(1);

    QSize canvasSize(480,640);

    pathCanvas = new QPathCanvas(this,QPoint(0,0),canvasSize);
    pathCanvas->setMinimumSize(canvasSize);

    sliderTime = new QSlider(this);
    sliderTime->setOrientation(Qt::Horizontal);

    QPushButton *pushButtonSaveAs = new QPushButton("Save as",this);
    QHBoxLayout *layout = new QHBoxLayout;

    layout->addWidget(pushButtonSave);
    layout->addWidget(pushButtonSaveAs);

    widgetArea->setLayout(layoutCoordinatesB);

    layoutPath->addWidget(pathCanvas);
    layoutPath->addWidget(scrollCoord);

    layoutFooter->addWidget(sliderTime);
    layoutFooter->addLayout(layout);

    layoutMain->addLayout(layoutPath);
    layoutMain->addLayout(layoutFooter);

    setLayout(layoutMain);

    /*Test*/
    /*
    std::vector< TimedVector* > coordinates;
    coordinates.push_back(new TimedVector(Vector2<float>(10.,10.),20));
    coordinates.push_back(new TimedVector(Vector2<float>(200.,160.),320));
    coordinates.push_back(new TimedVector(Vector2<float>(100.,300.),486));

    generateCoordWidgets(coordinates);*/

    connect(pathCanvas,SIGNAL(coordAdded(TimedVector*)),this,SLOT(addCoordWidget(TimedVector*)));
    connect(pathCanvas,SIGNAL(coordDeleted(int)),this,SLOT(deleteCoordWidget(int)));
    connect(pathCanvas,SIGNAL(coordEdited(int,TimedVector*)),this,SLOT(editCoordWidget(int,TimedVector*)));

    connect(pushButtonSave,SIGNAL(clicked()),this,SLOT(save()));
    connect(pushButtonSaveAs,SIGNAL(clicked()),this,SLOT(saveAs()));
}

void QPathCreator::addCoordWidget(TimedVector *coordinates)
{
    coordinateWidgets.push_back((new QCoordWidget(coordinateWidgets.size(),coordinates,this)));
    layoutCoordinates->addWidget(coordinateWidgets.at(coordinateWidgets.size()-1));

    scrollCoord->setMinimumWidth(coordinateWidgets.at(coordinateWidgets.size()-1)->width()*3);

}

void QPathCreator::deleteCoordWidget(int index)
{
    delete coordinateWidgets.at(index);

    for(int i=0;i<coordinateWidgets.size();i++)
    {
        coordinateWidgets.at(i)->setIndex(i);
    }
}

void QPathCreator::editCoordWidget(int index, TimedVector *coordinates)
{
    coordinateWidgets.at(index)->changeData(index, coordinates);
}

void QPathCreator::load(QString file)
{
    Json::Value root = loadJSONFile(file.toStdString().c_str());
    load(root);
}

void QPathCreator::load(Json::Value root)
{
    TimedVector *coordinates = new TimedVector();
    sf::Vector2<float> vec;

    for(int i=0;i<root.size();i++)
    {
        vec.x = root[i]["x"].asFloat();
        vec.y = root[i]["y"].asFloat();

        coordinates->setVector(vec,V_REL);
        coordinates->setTime(root[i]["t"].asInt());
        addCoordWidget(coordinates);
    }
}

void QPathCreator::save()
{
    saveFile(false);
}

void QPathCreator::saveAs()
{
    saveFile(true);
}

void QPathCreator::saveFile(bool newFile)
{
    /*Saves the paths as a .json file*/
    std::vector< TimedVector* > coordinates = pathCanvas->getCoordinates();
    Json::Value root;

    if(path.isEmpty() || newFile)
    {
        path = QFileDialog::getSaveFileName(this, "Enregistrer un fichier", QString(), "JSON File (*.json)");
    }

    for(int i=0;i<coordinates.size();i++)
    {
        /*The coords are changed from y to (1-y) due to the engine using inverted y coords*/
        root[i]["x"] = coordinates.at(i)->getX(V_REL);
        root[i]["y"] = 1.-coordinates.at(i)->getY(V_REL);
        root[i]["t"] = coordinates.at(i)->getTime();
    }

    saveJSONFile(root,path.toStdString().c_str());
}
