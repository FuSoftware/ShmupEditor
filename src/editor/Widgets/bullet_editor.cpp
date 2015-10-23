#include "bullet_editor.h"

BulletEditor::BulletEditor(QWidget *parent) : QWidget(parent)
{
    loadUI();
}


BulletEditor::BulletEditor(QString file, QWidget *parent) : QWidget(parent)
{
    loadUI();
    loadFile(file);
}

void BulletEditor::loadUI()
{
    sprite_loaded = false;
    QHBoxLayout *mainLayout = new QHBoxLayout;
    QVBoxLayout *layoutData = new QVBoxLayout;

    QPushButton *pushButtonSave = new QPushButton("Save",this);

    pushButtonSprite = new QPushButton("Sprite File",this);
    labelSpritePath = new QLabel("...",this);

    labelSprite = new QLabel("No sprite loaded",this);

    labelData[D_NAME] = new QLabel("Name :",this);
    labelData[D_SIZE_W] = new QLabel("Size :",this);

    lineEditData[D_NAME] = new QLineEdit(this);
    lineEditData[D_SIZE_W] = new QLineEdit(this);
    lineEditData[D_SIZE_H] = new QLineEdit(this);

    layoutDataChild[L_NAME] = new QHBoxLayout;
    layoutDataChild[L_SIZE] = new QHBoxLayout;
    layoutDataChild[L_SPRITE] = new QHBoxLayout;

    layoutDataChild[L_SPRITE]->addWidget(pushButtonSprite);
    layoutDataChild[L_SPRITE]->addWidget(labelSpritePath);

    layoutDataChild[L_NAME]->addWidget(labelData[D_NAME]);
    layoutDataChild[L_NAME]->addWidget(lineEditData[D_NAME]);
    layoutDataChild[L_SIZE]->addWidget(labelData[D_SIZE_W]);
    layoutDataChild[L_SIZE]->addWidget(lineEditData[D_SIZE_W]);
    layoutDataChild[L_SIZE]->addWidget(lineEditData[D_SIZE_H]);

    layoutData->addLayout(layoutDataChild[L_SPRITE]);
    layoutData->addLayout(layoutDataChild[L_NAME]);
    layoutData->addLayout(layoutDataChild[L_SIZE]);
    layoutData->addWidget(pushButtonSave);

    mainLayout->addWidget(labelSprite);
    mainLayout->addLayout(layoutData);

    connect(pushButtonSave,SIGNAL(clicked()),this,SLOT(save()));
    connect(pushButtonSprite,SIGNAL(clicked()),this,SLOT(loadSprite()));

    setLayout(mainLayout);
}

void BulletEditor::loadFile(QString file)
{
    Json::Value root = loadJSONFile(file.toStdString().c_str());

    loadSprite(QString(root["sprite"].asCString()));

    lineEditData[D_NAME]->setText(root["name"].asCString());
    lineEditData[D_SIZE_W]->setText(QString::number(root["size"]["w"].asInt()));
    lineEditData[D_SIZE_H]->setText(QString::number(root["size"]["h"].asInt()));

}

void BulletEditor::loadSprite()
{
    /*Loads a Sprite's file path*/
    QString file = QFileDialog::getOpenFileName(this, "Open File", QString(), "Pictures (*.png *.jpg *.jpeg)");
    loadSprite(file);
}

void BulletEditor::loadSprite(QString file)
{
    QPixmap pixmap(file);//Loads the sprite's pixmap

    if(!pixmap.isNull())
    {
        labelSprite->setPixmap(pixmap.scaled(128,128, Qt::KeepAspectRatio, Qt::SmoothTransformation));//Sets it to 128*128 max, with ratio
        labelSpritePath->setText(file);//Shows the path on the widget
        lineEditData[D_SIZE_W]->setText(QString::number(labelSprite->pixmap()->width()));
        lineEditData[D_SIZE_H]->setText(QString::number(labelSprite->pixmap()->height()));
        sprite_loaded = true;
    }
    else
    {
        labelSpritePath->setText("Failed to load sprite");
        sprite_loaded = false;
    }
}

void BulletEditor::save()
{
    /*Checks the values before saving*/

    bool isSizeNumeric[2];
    lineEditData[D_SIZE_W]->text().toInt(&isSizeNumeric[0]);
    lineEditData[D_SIZE_H]->text().toInt(&isSizeNumeric[1]);

    if(lineEditData[D_NAME]->text().isEmpty())
    {
        /*If Name is empty*/
        QMessageBox::warning(this, "Incorrect Value", "Please specify a name for your Entity.");
    }
    else if(!sprite_loaded)
    {
        /*If the sprite isn't loaded*/
        QMessageBox::warning(this, "Incorrect Value", "Please load a sprite before saving.");
    }
    else if(lineEditData[D_SIZE_W]->text().isEmpty() || lineEditData[D_SIZE_H]->text().isEmpty())
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
        QString folder_path = QFileInfo(labelSpritePath->text()).absoluteDir().absolutePath();
        QString file_path = QFileDialog::getSaveFileName(this, "Save File", folder_path + "/" + lineEditData[D_NAME]->text() + ".bullet", "Json Bullet File (*.bullet)");

        Json::Value root;

        root["name"] = lineEditData[D_NAME]->text().toStdString();
        root["sprite"] = labelSpritePath->text().toStdString();
        root["size"]["w"] = lineEditData[D_SIZE_W]->text().toInt();
        root["size"]["h"] = lineEditData[D_SIZE_H]->text().toInt();

        saveJSONFile(root,file_path.toStdString().c_str());
    }
}

