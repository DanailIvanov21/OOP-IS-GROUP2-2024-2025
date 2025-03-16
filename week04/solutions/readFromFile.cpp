#include <iostream>
#include <fstream>

int* readFromFile(const char* fileName)
{
    std::ifstream ifs(fileName, std::ios::binary);

    if (!ifs.is_open())
    {
        std::cerr << "Error opening file: " << fileName << std::endl;

        return nullptr;
    }

    unsigned count;
    ifs.read((char*)(&count), sizeof(count));

    int* numbers = new int[count];
    ifs.read((char*)numbers, sizeof(int) * count);

    return numbers;
}