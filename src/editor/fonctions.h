#ifndef FONCTIONS_H
#define FONCTIONS_H

#include <iostream>
#include <cstring>
#include <ctime>
#include <string.h>
#include <fstream>
#include <sstream>

void copyFile(std::string source, std::string dest);

bool isPair(int number);
void checkFolder(std::string path);

std::string intToString(int i);
char* stringToCString(std::string input);

const std::string currentDateTime();
void outputInfo(std::string type, std::string data, int level);

#endif // FONCTIONS_H
