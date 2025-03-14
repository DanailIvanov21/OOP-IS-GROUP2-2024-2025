#include <iostream>
#include <fstream>

constexpr unsigned MAX_LINE_SIZE = 1024;

bool copyFile(const char* source_filename, const char* destination_filename) // it is bool so we can see if the operation is successful
{
    std::ifstream source_file(source_filename);

    if (!source_file.is_open()) 
    {
        std::cerr << "Error opening source file." << std::endl; // cerr is error message

        return false;
    }

    std::ofstream destination_file(destination_filename);

    if (!destination_file.is_open()) 
    {
        std::cerr << "Error opening destination file." << std::endl;
        source_file.close();

        return false;
    }

    char line[MAX_LINE_SIZE];

    while (source_file.getline(line, MAX_LINE_SIZE)) 
    {
        destination_file << line << std::endl;
    }

    source_file.close();
    destination_file.close();

    std::cout << "File copied successfully." << std::endl;

    return true;
}

int main()
{
    
}
