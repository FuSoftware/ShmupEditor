#include "fonctions_conversion.h"

std::string intToString(int i)
{
    std::stringstream ss;
    std::string s;
    ss << i;
    s = ss.str();

    return s;
}

std::string floatToString(float f)
{
    std::stringstream ss;
    std::string s;
    ss << f;
    s = ss.str();

    return s;
}

char* stringToCString(std::string input)
{
    char* output = strdup(input.c_str());
    return output;
}
