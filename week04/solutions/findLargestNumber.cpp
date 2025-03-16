#include <iostream>
#include <fstream>
#include <limits.h>

int findLargestNumber(const char* fileName)
{
    std::ifstream ifs(fileName, std::ios::binary);

    if (!ifs)
    {
        std::cerr << "Error opening the file" << std::endl;

        return INT_MIN;
    }

    int largestNumber;
    if (!ifs.read((char*)&largestNumber, sizeof(largestNumber)))
    {
        std::cerr << "File is empty or read error occurred" << std::endl;

        return INT_MIN;
    }

    int currentNumber;

    while (ifs.read((char*)&currentNumber, sizeof(currentNumber)))
    {
        if (currentNumber > largestNumber)
        {
            largestNumber = currentNumber;
        }
    }

    return largestNumber;
}