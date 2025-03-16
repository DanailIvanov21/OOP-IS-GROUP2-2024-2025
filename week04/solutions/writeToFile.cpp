#include <iostream>
#include <fstream>

void writeToFile(const char* fileName)
{
    unsigned count;
    std::cin >> count;

    int* numbers = new int[count];

    for (int i = 0; i < count; i++)
    {
        std::cin>> numbers[i];
    }

    std::ofstream ofs(fileName, std::ios::binary);

    if(!ofs)
    {
        std::cerr << "Error opening the file" << std::endl;
        
        return;
    }

    ofs.write((const char*)(&count), sizeof(count));
    ofs.write((const char*)(numbers), sizeof(int)*count);

    ofs.close();
    ofs.flush();

    delete[] numbers;
}