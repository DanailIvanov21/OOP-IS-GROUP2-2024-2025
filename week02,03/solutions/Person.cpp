#include <iostream>
#include <fstream>

constexpr unsigned MAX_NAME_LENGHT = 64;

struct Person {
    char name[MAX_NAME_LENGHT];
    bool gender;
    unsigned age;
};

void writePersonsToFile(const Person* persons, size_t size, const char* fileName) {
    std::ofstream ofs(fileName);

    if (!ofs.is_open()) 
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return;
    }

    ofs << size << std::endl; 

    for (size_t i = 0; i < size; ++i) 
    {
        ofs << persons[i].name << ' ' << persons[i].gender << ' ' << persons[i].age << std::endl;
    }

    ofs.close();
}

Person* readPersonsFromFile(const char* fileName) 
{
    std::ifstream ifs(fileName);

    if (!ifs.is_open()) 
    {
        std::cerr << "Error opening file: " << fileName << std::endl;
        return nullptr;
    }

    size_t size;
    ifs >> size; 
    Person* persons = new Person[size];

    for (size_t i = 0; i < size; ++i) 
    {
        ifs >> persons[i].name >> persons[i].gender >> persons[i].age;
        ifs.ignore();
    }

    ifs.close();

    return persons;
}