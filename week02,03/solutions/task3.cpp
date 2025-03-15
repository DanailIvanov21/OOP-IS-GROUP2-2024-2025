#include<iostream>
#include<fstream>
 
const int MAX = 100;
void combine(const char* firstFile, const char* secondFile)
{
 
    std::ifstream inFirstFile(firstFile);
    std::ifstream inSecondFile(secondFile);
    std::ofstream newFile("combined.txt");
 
    if (!inFirstFile.is_open() || !inSecondFile.is_open() || !newFile.is_open())
    {
        std::cout << "Can't open file" << std::endl;
        return;
 
    }
 
    while (!inFirstFile.eof())
    {
        char buff[MAX];
        inFirstFile.getline(buff, MAX);
        newFile << buff << '\n';
    }
    while (!inSecondFile.eof())
    {
        char buff[MAX];
        inSecondFile.getline(buff, MAX);
        newFile << buff << '\n';
    }
    inFirstFile.close();
    inSecondFile.close();
    newFile.close();
}
 
void removeEmptyLines(const char* fileName)
{
    std::ifstream in(fileName);
 
    std::ofstream out("temp.txt");
 
    if (!in.is_open() || !out.is_open())
    {
        std::cout << "Can't open file" << std::endl;
        return;
 
    }
 
    while (!in.eof())
    {
        char buff[MAX];
 
        in.getline(buff, MAX);
       
        if (strcmp(buff, "") != 0)
        {
            out << buff << '\n';
 
        }
    }
    in.close();
    out.close();
}
 
void changeFile(const char* filename)
{
    std::ifstream in(filename);
 
    std::ofstream out("new.txt");
 
    if (!in.is_open() || !out.is_open())
    {
        std::cout << "Can't open file" << std::endl;
        return;
 
    }
 
    char s;
    while (s = in.get())
    {
        if (in.eof())
        {
            break;
        }
        if (s >= 'a' && s <= 'z')
        {
            s = s - 32;
            out << s;
        }
        else if (s >= 'A' && s <= 'Z')
        {
            s = s + 32;
            out << s;
        }
        else
        {
            out << s;
        }
 
 
    }
    in.close();
    out.close();
}
int main()
{
    combine("first.txt", "second.txt");
    removeEmptyLines("combined.txt");
    changeFile("temp.txt");
    return 0;
}
