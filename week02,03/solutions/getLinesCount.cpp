#include <iostream>
#include <fstream>

constexpr unsigned MAX_LINE_SIZE = 1024;

int getLinesCount(std::ifstream& file)
{
    if(!file.good())
    {
        return -1;
    }

    int count = 0;

    long long currentPossition = file.tellg();
    file.seekg(std::ios::beg);

    while (!file.eof())
    {
        char buff[MAX_LINE_SIZE];
        file.getline(buff, MAX_LINE_SIZE);
        count++;
    }

    file.seekg(currentPossition); //resets the stream's get position.
    file.clear();

    return count;
}