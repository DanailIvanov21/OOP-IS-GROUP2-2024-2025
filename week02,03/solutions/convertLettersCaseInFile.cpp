#include <iostream>
#include <fstream>
#include "copyFile.h"

constexpr int MAX_LINE_SIZE = 1024;
const int CONVERT_LETTER = 'a' - 'A';

bool isCapsLetter(char ch) {
    return ch >= 'A' && ch <= 'Z';
}

bool isSmallLetter(char ch) {
    return ch >= 'a' && ch <= 'z';
}

void convertLetters(char* buffer, bool toCaps)
{
    int index = 0;

    while (buffer[index] != '\0')
    {
        if (toCaps)
        {
            if (isSmallLetter(buffer[index]))
            {
                buffer[index] -= CONVERT_LETTER;
            }
        }
        else
        {
            if (isCapsLetter(buffer[index]))
            {
                buffer[index] += CONVERT_LETTER;
            }
        }

        index++;
    }
}

void convertLettersCaseInFile(const char* fileName, bool toCaps) 
{
    std::ifstream ifs(fileName);

    if (!ifs.is_open()) 
    {
        std::cerr << "Error opening input file: " << fileName << std::endl;
        return;
    }

    std::ofstream ofs("temp.txt");

    if (!ofs.is_open()) 
    {
        std::cerr << "Error opening temporary file." << std::endl;
        ifs.close();
        return;
    }

    char buffer[MAX_LINE_SIZE];

    while (ifs.getline(buffer, MAX_LINE_SIZE)) 
    {
        convertLetters(buffer, toCaps);
        ofs << buffer << std::endl;
    }

    ifs.close();
    ofs.close();

    copyFile("temp.txt", fileName);
}