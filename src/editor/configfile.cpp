#include "configfile.h"

ConfigFile::ConfigFile()
{

}

ConfigFile::ConfigFile(std::string path)
{
    this->path = path;
    root = loadJSONFile(path.c_str());

    if(root.empty())
    {
        //Invalid file
        generateFile();
    }
    else
    {
        //File is valid
        loadConfig();
    }
}

void ConfigFile::save()
{
    Json::Value s_root;

    s_root["versions"]["cfg"] = conf_file_ver;

    std::cout << p_names.size() << " projects to save" << std::endl;

    for(int i=0;i<p_names.size();i++)
    {
        s_root["recent_projects"][i][0] = p_names.at(i);
    }

    for(int i=0;i<p_paths.size();i++)
    {
        s_root["recent_projects"][i][1] = p_paths.at(i);
    }


    saveJSONFile(s_root,path.c_str());
}

void ConfigFile::loadConfig()
{
    loadVersion();

    //Loads data depending on the file's version
    if (conf_file_ver >= 1)
    {
        loadProjects();
    }
    else
    {
        //File may be invalid
        generateFile();
    }

    //Updates the file
    if (conf_file_ver < CONFIG_FILE_VER)
    {
        updateFile();
    }
}

void ConfigFile::loadVersion()
{

    version[0][0] = VERSION_MAJ;
    version[0][1] = VERSION_MIN;
    version[0][2] = VERSION_BUG;
    version[0][3] = VERSION_REV;

    if(root["versions"]["cfg"].isInt())
    {
        conf_file_ver = root["versions"]["cfg"].asInt();
    }
    else
    {
        conf_file_ver = 0;
    }
}

void ConfigFile::loadProjects()
{
    //Loads the projects (10 max)
    int limit;
    if(root["recent_projects"].size()>PROJECT_LIMIT){limit = PROJECT_LIMIT;}else{limit = root["recent_projects"].size();}

    for(int i=0;i<limit;i++)
    {
        p_names.push_back(root["recent_projects"][i][0].asString());
        p_paths.push_back(root["recent_projects"][i][1].asString());
    }
}

void ConfigFile::addProject(std::string name, std::string path)
{
    p_names.insert(p_names.begin(),name);
    p_paths.insert(p_paths.begin(),path);

    std::cout << "Adding project " << name << " - " << path << std::endl;
}

void ConfigFile::generateFile()
{
    //Generates a clean cfg file if it failed to load
    this->conf_file_ver = CONFIG_FILE_VER;

    save();
}

void ConfigFile::updateFile()
{
    //Updates from the current version to the last
}

std::string ConfigFile::getProjectName(int i)
{
    return this->p_names.at(i);
}

std::string ConfigFile::getProjectPath(int i)
{
    return this->p_paths.at(i);
}

int ConfigFile::getProjectCount()
{
    return p_names.size();
}

