#include "ennemy_editor.h"

EnnemyEditor::EnnemyEditor(QWidget *parent) : QWidget(parent)
{
    sprite_loaded = false;
    path_loaded = false;

    layoutMain = new QHBoxLayout;
    layoutParam = new QVBoxLayout;

    layoutLeft = new QVBoxLayout;
    labelSprite = new QLabel("No Sprite",this);

    QSize widgetSize(128,128);
    pathViewer = new QPathViewer(positions,this,QPoint(0,0),widgetSize);
    pathViewer->setMinimumSize(widgetSize);

    layoutFile = new QHBoxLayout;
    pushButtonOpenFile = new QPushButton("Sprite",this);
    labelFilePath = new QLabel("Select a file",this);

    layoutPath = new QHBoxLayout;
    pushButtonLoadPath = new QPushButton("Path",this);
    labelPathFilePath  = new QLabel("Select the path file",this);

    pushButtonSave = new QPushButton("Save",this);

    /*Grid Layout*/
    gridLayoutParam = new QGridLayout;
    labelName = new QLabel("Name :",this);
    lineEditName = new QLineEdit(this);
    labelSpawnTime = new QLabel("Spawn Time :",this);
    lineEditSpawnTime = new QLineEdit(this);
    labelHealth = new QLabel("Health Points :",this);
    lineEditHealth = new QLineEdit(this);
    labelSize = new QLabel("Size :",this);

    QHBoxLayout *layoutSize = new QHBoxLayout;

    for(int i=0;i<2;i++)
    {
        lineEditSize[i] = new QLineEdit(this);
        layoutSize->addWidget(lineEditSize[i]);
    }

    gridLayoutParam->addWidget(labelName,0,0);
    gridLayoutParam->addWidget(lineEditName,0,1);
    gridLayoutParam->addWidget(labelSpawnTime,1,0);
    gridLayoutParam->addWidget(lineEditSpawnTime,1,1);
    gridLayoutParam->addWidget(labelHealth,2,0);
    gridLayoutParam->addWidget(lineEditHealth,2,1);
    gridLayoutParam->addWidget(labelSize,3,0);
    gridLayoutParam->addLayout(layoutSize,3,1);

    layoutLeft->addWidget(labelSprite);
    layoutLeft->addWidget(pathViewer);

    layoutFile->addWidget(pushButtonOpenFile);
    layoutFile->addWidget(labelFilePath);

    layoutPath->addWidget(pushButtonLoadPath);
    layoutPath->addWidget(labelPathFilePath);

    layoutParam->addLayout(layoutFile);
    layoutParam->addLayout(layoutPath);
    layoutParam->addLayout(gridLayoutParam);
    layoutParam->addStretch();
    layoutParam->addWidget(pushButtonSave);

    layoutMain->addLayout(layoutLeft);
    layoutMain->addLayout(layoutParam);

    setLayout(layoutMain);

    connect(pushButtonOpenFile,SIGNAL(clicked()),this,SLOT(loadSprite()));
    connect(pushButtonLoadPath,SIGNAL(clicked()),this,SLOT(loadPath()));
    connect(pushButtonSave,SIGNAL(clicked()),this,SLOT(save()));

    resize(0,0);

}

EnnemyEditor::~EnnemyEditor()
{

}

void EnnemyEditor::loadSprite()
{
    /*Loads a Sprite's file path*/
    QString file = QFileDialog::getOpenFileName(this, "Open File", QString(), "Pictures (*.png *.jpg *.jpeg)");

    QPixmap pixmap(file);//Loads the sprite's pixmap

    if(!pixmap.isNull())
    {
        labelSprite->setPixmap(pixmap.scaled(128,128, Qt::KeepAspectRatio, Qt::SmoothTransformation));//Sets it to 128*128 max, with ratio
        labelFilePath->setText(file);//Shows the path on the widget
        lineEditSize[0]->setText(QString::number(labelSprite->pixmap()->width()));
        lineEditSize[1]->setText(QString::number(labelSprite->pixmap()->height()));
        sprite_loaded = true;
    }
    else
    {
        labelFilePath->setText("Failed to load sprite");
        sprite_loaded = false;
    }
}

void EnnemyEditor::loadPath()
{
    positions.clear();

    /*Loads a Path's file path*/
    QString file = QFileDialog::getOpenFileName(this, "Open File", QString(), "JSON File (*.json)");

    Json::Value root = loadJSONFile(file.toStdString().c_str());

    sf::Vector2<float> vector;
    sf::Vector2<float> parent_size;
    parent_size.x = 128;
    parent_size.y = 128;


    int i = 0;

    if(!root.isNull())
    {
        while(root[i].isObject())
        {
            vector.x = root[i]["x"].asFloat();
            vector.y = 1-root[i]["y"].asFloat(); //Needs to invert the y coord due to the engine's (0,0) point being (0,max_h) here
            positions.push_back(new TimedVector(vector,parent_size,root[i]["t"].asInt(),V_REL));

            i=i+1;
        }
        path = root;
        pathViewer->setPath(positions);

        labelPathFilePath->setText(file);//Shows the path on the widget
        path_loaded = true;
    }
    else
    {
        path_loaded = false;
    }
}

void EnnemyEditor::save()
{
    /*Checks the values before saving*/
    bool isSpawnTimeNumeric = false;
    lineEditSpawnTime->text().toInt(&isSpawnTimeNumeric);

    bool isHealthNumeric = false;
    lineEditHealth->text().toInt(&isHealthNumeric);

    bool isSizeNumeric[2];
    for(int i=0;i<2;i++){lineEditSize[i]->text().toInt(&isSizeNumeric[i]);}

    if(lineEditName->text().isEmpty())
    {
        /*If Name is empty*/
        QMessageBox::warning(this, "Incorrect Value", "Please specify a name for your Entity.");
    }
    else if(lineEditSpawnTime->text().isEmpty())
    {
        /*If SpawnTime is empty*/
        QMessageBox::warning(this, "Incorrect Value", "Please fill the SpawnTime value.");
    }
    else if(!isSpawnTimeNumeric)
    {
        /*If SpawnTime isn't numeric*/
        QMessageBox::warning(this, "Incorrect Value", "Please check that the SpawnTime is an integer.");
    }
    else if(lineEditHealth->text().isEmpty())
    {
        /*If Health is empty*/
        QMessageBox::warning(this, "Incorrect Value", "Please fill the Health value.");
    }
    else if(!isHealthNumeric)
    {
        /*If Health isn't numeric*/
        QMessageBox::warning(this, "Incorrect Value", "Please check that the Health is an integer.");
    }
    else if(!sprite_loaded)
    {
        /*If the sprite isn't loaded*/
        QMessageBox::warning(this, "Incorrect Value", "Please load a sprite before saving.");
    }
    else if(!path_loaded)
    {
        /*If the sprite isn't loaded*/
        QMessageBox::warning(this, "Incorrect Value", "Please load a path before saving.");
    }
    else if(lineEditSize[0]->text().isEmpty() || lineEditSize[1]->text().isEmpty())
    {
        /*If Health is empty*/
        QMessageBox::warning(this, "Incorrect Value", "Please fill the Size values.");
    }
    else if(!isSizeNumeric[0] || !isSizeNumeric[1])
    {
        /*If Health isn't numeric*/
        QMessageBox::warning(this, "Incorrect Value", "Please check that the Sizes are integers.");
    }
    else
    {
        /*Saves*/
        QString folder_path = QFileInfo(labelFilePath->text()).absoluteDir().absolutePath();
        QString file_path = QFileDialog::getSaveFileName(this, "Save File", folder_path + "/" + lineEditName->text() + ".json", "Json File (*.json)");

        Json::Value root;

        root["name"] = lineEditName->text().toStdString();
        root["spawn_time"] = lineEditSpawnTime->text().toInt();
        root["sprite"] = labelFilePath->text().toStdString();
        root["health"] = lineEditHealth->text().toInt();
        root["path"] = path;
        root["size"]["w"] = lineEditSize[0]->text().toInt();
        root["size"]["h"] = lineEditSize[1]->text().toInt();

        saveJSONFile(root,file_path.toStdString().c_str());
    }

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
    }

    */
}

