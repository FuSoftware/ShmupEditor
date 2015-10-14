#ifndef CONFIGFILE_H
#define CONFIGFILE_H

#define CONFIG_FILE_VER 1

#define PROJECT_LIMIT 10

#include <iostream>
#include <vector>

#include "fonctions_json.h"
#include "constantes.h"

class ConfigFile
{
public:
    ConfigFile();
    ConfigFile(std::string path);

    void save();
    void loadConfig();
    void loadVersion();
    void loadProjects();
    void addProject(std::string name, std::string path);
    void generateFile();
    void updateFile();

    std::string getProjectName(int i);
    std::string getProjectPath(int i);
    int getProjectCount();

private:
    Json::Value root;
    std::string path;

    int conf_file_ver;
    int version[2][4]; //Version has 4 significant numbers

    std::vector<std::string> p_names;
    std::vector<std::string> p_paths;

    bool update_needed;
};

#endif // CONFIGFILE_H
