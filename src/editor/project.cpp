#include "project.h"

Project::Project(QObject *parent) : QObject(parent)
{

}

Project::Project(std::string configFilePath, QObject *parent) : QObject(parent)
{
    this->configFile = new QFile(configFilePath.c_str());
    QFileInfo fileInfo(configFile->fileName());

    if(configFile->exists ())
    {
        //The file exists
        if (!configFile->open(QIODevice::ReadOnly))
        {
            //The file can't be read
            qDebug()<<"Failed to open configuration file"<<configFile->fileName();
        }
        else
        {
            //Continue loading
            this->rootFolder = fileInfo.absoluteDir();
        }
    }
}

void Project::loadConfig(Json::Value root)
{
    if(root["files"].isObject())
    {
        loadFiles(root["files"]);
    }
}

void Project::loadFiles(Json::Value files_root)
{
    /*Ennemies*/
    for(int i=0;i<files_root["ennemies"].size();i++)
    {
        ennemy_files.push_back(files_root["ennemies"][i].asString());
    }

    /*Levels*/
    for(int i=0;i<files_root["levels"].size();i++)
    {
        level_files.push_back(files_root["levels"][i].asString());
    }

    /*Paths*/
    for(int i=0;i<files_root["paths"].size();i++)
    {
        path_files.push_back(files_root["paths"][i].asString());
    }

    /*Patterns*/
    for(int i=0;i<files_root["patterns"].size();i++)
    {
        pattern_files.push_back(files_root["patterns"][i].asString());
    }

    /*Players*/
    for(int i=0;i<files_root["players"].size();i++)
    {
        player_files.push_back(files_root["players"][i].asString());
    }

    /*Sprites*/
    for(int i=0;i<files_root["sprites"].size();i++)
    {
        sprite_files.push_back(files_root["sprites"][i].asString());
    }
}

QDir Project::getDir()
{
            return this->rootFolder;
}
