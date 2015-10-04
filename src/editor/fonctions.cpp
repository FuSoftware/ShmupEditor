#include "fonctions.h"
#include "constantes.h"

#include <QFile>
#include <QDir>

void copyFile(std::string source, std::string dest)
{
    std::ifstream  src(source.c_str(), std::ios::binary);
    std::ofstream  dst(dest.c_str(),   std::ios::binary);

    dst << src.rdbuf();
    src.close();
    dst.close();
}

bool isPair(int number)
{
    if(number & 1)
    {
        return false;
    }
    else
    {
        return true;
    }
}

void checkFolder(std::string path)
{
    QDir dirCache1(path.c_str());
    if (!dirCache1.exists()) {
        dirCache1.mkpath(".");
    }
}

/*Conversion*/
std::string intToString(int i)
{
    std::stringstream ss;
    std::string s;
    ss << i;
    s = ss.str();

    return s;
}

char* stringToCString(std::string input)
{
    char* output = strdup(input.c_str());
    return output;
}

// Get current date/time, format is YYYY-MM-DD.HH:mm:ss
const std::string currentDateTime()
{
    time_t     now = time(0);
    struct tm  tstruct;
    char       buf[80];
    tstruct = *localtime(&now);
    // Visit http://en.cppreference.com/w/cpp/chrono/c/strftime
    // for more information about date/time format
    strftime(buf, sizeof(buf), "%Y-%m-%d | %X", &tstruct);

    return buf;
}

void outputInfo(std::string type, std::string data, int level)
{
    std::cout << "[" << type << "]"
              << "[" << currentDateTime() << "]"
              << "|";

    for(int i=0;i<level;i++)
    {
        std::cout <<"-";
    }

    std::cout << "> " << data << std::endl;
}
