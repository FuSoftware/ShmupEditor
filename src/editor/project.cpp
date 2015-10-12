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
            qDebug()<<"Failed to open configuration file "<<configFile->fileName();
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

    /*Musics*/
    for(int i=0;i<files_root["musics"].size();i++)
    {
        music_files.push_back(files_root["musics"][i].asString());
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

void Project::save()
{
    Json::Value root;

    /*Ennemies*/
    for(int i=0;i<ennemy_files.size();i++)
    {
        root["ennemies"][i] = ennemy_files.at(i);
    }

    /*Levels*/
    for(int i=0;i<level_files.size();i++)
    {
        root["levels"][i] = level_files.at(i);
    }

    /*Musics*/
    for(int i=0;i<music_files.size();i++)
    {
        root["musics"][i] = music_files.at(i);
    }

    /*Paths*/
    for(int i=0;i<path_files.size();i++)
    {
        root["paths"][i] = path_files.at(i);
    }

    /*Patterns*/
    for(int i=0;i<pattern_files.size();i++)
    {
        root["patterns"][i] = pattern_files.at(i);
    }

    /*Players*/
    for(int i=0;i<player_files.size();i++)
    {
        root["players"][i] = player_files.at(i);
    }

    /*Sprites*/
    for(int i=0;i<sprite_files.size();i++)
    {
        root["sprites"][i] = sprite_files.at(i);
    }

    saveJSONFile(root,configFile->fileName().toStdString().c_str());
}

void Project::addFile(std::string path, int type)
{
    QFile *buffer = new QFile(path.c_str());
    QFileInfo fileInfo(buffer->fileName());

    if(buffer->exists ())
    {
        //The file exists
        if (!buffer->open(QIODevice::ReadOnly))
        {
            //The file can't be read
            qDebug()<<"Failed to open file "<< buffer->fileName();
        }
        else
        {
            switch(type)
            {
            case F_ENNEMY:
                ennemy_files.push_back(path);
                buffer->copy(rootFolder.absolutePath() + "/ennemies/" + fileInfo.fileName());
                break;
            case F_LEVEL:
                level_files.push_back(path);
                buffer->copy(rootFolder.absolutePath() + "/levels/" + fileInfo.fileName());
                break;
            case F_MUSIC:
                music_files.push_back(path);
                buffer->copy(rootFolder.absolutePath() + "/musics/" + fileInfo.fileName());
                break;
            case F_PATH:
                path_files.push_back(path);
                buffer->copy(rootFolder.absolutePath() + "/paths/" + fileInfo.fileName());
                break;
            case F_PATTERN:
                pattern_files.push_back(path);
                buffer->copy(rootFolder.absolutePath() + "/patterns/" + fileInfo.fileName());
                break;
            case F_PLAYER:
                player_files.push_back(path);
                buffer->copy(rootFolder.absolutePath() + "/players/" + fileInfo.fileName());
                break;
            case F_SPRITE:
                sprite_files.push_back(path);
                buffer->copy(rootFolder.absolutePath() + "/sprites/" + fileInfo.fileName());
                break;
            }
        }
    }

}

QDir Project::getDir()
{
    return this->rootFolder;
}
