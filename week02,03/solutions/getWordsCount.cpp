#include <iostream>
#include <fstream>

constexpr unsigned MAX_WORD_SIZE = 128;

int getWordsCount(const char* fileName)
{
    std::ifstream ifs(fileName);

    if (!ifs.is_open())
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return -1;
    }

    int counter = 0;
    char word[MAX_WORD_SIZE];

    while (ifs >> word) // >> omits '\t', ' ' and '\n'
    {
        ++counter;
    }

    ifs.close();

    return counter;
}