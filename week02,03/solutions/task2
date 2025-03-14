#include <iostream>
#include <fstream>
const int BUFF_SIZE = 1024;
void replace(const char* filename, const char* find, const char* replace)
{
    std::ifstream file(filename);
    if (!file.is_open())
    {
        std::cout << "Error ifsream";
        return;
    }
 
    std::ofstream editedFile("Edited file.txt");
    if (!editedFile.is_open())
    {
        std::cout << "Error ofstream";
        return;
    }
 
    while (!file.eof())
    {
        char buff[BUFF_SIZE];
        file >> buff;
 
        if (strcmp(buff, find) == 0)
        {
            editedFile << replace << " ";
        }
        else
        {
            editedFile << buff << " ";
        }
 
    }
    file.close();
    editedFile.close();
 
}
 
int main()
{
    replace("princesa.txt", "princesa", "strandzhanka");
}
