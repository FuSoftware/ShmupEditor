#ifndef FONCTIONS_CONVERSION_H
#define FONCTIONS_CONVERSION_H

#include <iostream>
#include "../constantes.h"

#include <sstream>
#include <cstdlib>
#include <cstring>

std::string intToString(int i);
std::string floatToString(float f);
char* stringToCString(std::string input);

#endif
