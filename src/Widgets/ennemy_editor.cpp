#include "ennemy_editor.h"

EnnemyEditor::EnnemyEditor(QWidget *parent) : QWidget(parent)
{
    sprite_loaded = false;

    layoutMain = new QHBoxLayout;
    layoutParam = new QVBoxLayout;

    labelSprite = new QLabel("No Sprite",this);

    layoutFile = new QHBoxLayout;
    pushButtonOpenFile = new QPushButton("File",this);
    labelFilePath = new QLabel("Select a file",this);

    pushButtonSave = new QPushButton("Save",this);

    /*Grid Layout*/
    gridLayoutParam = new QGridLayout;
    labelName = new QLabel("Name :",this);
    lineEditName = new QLineEdit(this);
    labelSpawnTime = new QLabel("Spawn Time :",this);
    lineEditSpawnTime = new QLineEdit(this);
    labelHealth = new QLabel("Health Points :",this);
    lineEditHealth = new QLineEdit(this);

    gridLayoutParam->addWidget(labelName,0,0);
    gridLayoutParam->addWidget(lineEditName,0,1);
    gridLayoutParam->addWidget(labelSpawnTime,1,0);
    gridLayoutParam->addWidget(lineEditSpawnTime,1,1);
    gridLayoutParam->addWidget(labelHealth,2,0);
    gridLayoutParam->addWidget(lineEditHealth,2,1);

    layoutFile->addWidget(pushButtonOpenFile);
    layoutFile->addWidget(labelFilePath);

    layoutParam->addLayout(layoutFile);
    layoutParam->addLayout(gridLayoutParam);
    layoutParam->addStretch();
    layoutParam->addWidget(pushButtonSave);

    layoutMain->addWidget(labelSprite);
    layoutMain->addLayout(layoutParam);

    setLayout(layoutMain);

    connect(pushButtonOpenFile,SIGNAL(clicked()),this,SLOT(loadSprite()));
    connect(pushButtonSave,SIGNAL(clicked()),this,SLOT(save()));

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
        labelSprite->setPixmap(pixmap.scaled(256,256, Qt::KeepAspectRatio, Qt::SmoothTransformation));//Sets it to 256*256px max, with ratio
        labelFilePath->setText(file);//Shows the path on the widget
        sprite_loaded = true;
    }
    else
    {
        labelFilePath->setText("Failed to load sprite");
        sprite_loaded = false;
    }
}

void EnnemyEditor::save()
{
    /*Checks the values before saving*/
    bool isSpawnTimeNumeric = false;
    lineEditSpawnTime->text().toInt(&isSpawnTimeNumeric);

    bool isHealthNumeric = false;
    lineEditHealth->text().toInt(&isHealthNumeric);

    std::cout << "SpawnTime : " << isSpawnTimeNumeric << std::endl;
    std::cout << "Health    : " << isHealthNumeric << std::endl;

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

