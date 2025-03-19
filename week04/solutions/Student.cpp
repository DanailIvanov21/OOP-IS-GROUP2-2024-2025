#include <iostream>
#include <fstream>
const int MAX = 50;

struct Student
{
    char name[MAX];
    int facNum;
    char email[MAX];
    size_t passed;
    size_t failed;
    double avgGrade;
};

void writeStudentsToFile(const Student* students, int count, std::ofstream& out)
{
    out.write((const char*)students, count * sizeof(Student));
}

size_t getFileSize(std::ifstream& file)
{
    size_t curr = file.tellg();
    file.seekg(0, std::ios::end);
    size_t size = file.tellg();
    file.seekg(curr, std::ios::beg);
    
    return size;
}

void readStudentsFromFile(Student*& ptr, size_t& studentsCount, std::ifstream& in)
{
    size_t sizeFile = getFileSize(in);
    studentsCount = sizeFile / sizeof(Student);
    ptr = new Student[studentsCount];
    in.read((char*)ptr, sizeFile);
}

void sortStudentsByGrade(Student* students, size_t count)
{
    for (size_t i = 0; i < count - 1; i++)
    {
        for (size_t j = i + 1; j < count; j++)
        {
            if (students[j].avgGrade < students[i].avgGrade)
            {
                std::swap(students[j], students[i]);
            }
        }
    }
}

int* extractFacultyNumbers(const Student* students, size_t count)
{
    int* arrayOfNumbers = new int[count];
    for (size_t i = 0; i < count; i++)
    {
        arrayOfNumbers[i] = students[i].facNum;
    }
    
    return arrayOfNumbers;
}

int* processFacultyData(Student*& student, std::ifstream& in)
{
    size_t studentsCount;
    readStudentsFromFile(student, studentsCount, in);
    sortStudentsByGrade(student, studentsCount);
    
    return extractFacultyNumbers(student, studentsCount);
}

void inputStudentsData(Student* students, int count)
{
    for (int i = 0; i < count; i++)
    {
        std::cout << "Student name " << i + 1 << "= ";
        std::cin >> students[i].name;
        std::cout << "Faculty number: ";
        std::cin >> students[i].facNum;
        std::cout << "Email " << i + 1 << "= ";
        std::cin >> students[i].email;
        std::cout << "Passed exams: ";
        std::cin >> students[i].passed;
        std::cout << "Failed exams: ";
        std::cin >> students[i].failed;
        std::cout << "Average grade: ";
        std::cin >> students[i].avgGrade;
    }
}

int main()
{
    int count;
    std::cout << "Enter number of students: ";
    std::cin >> count;

    Student* students = new Student[count];
    inputStudentData(students, count);

    std::ofstream out("students.bin", std::ios::binary);
    if (!out.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
        return -1;
    }
    
    writeStudentsToFile(students, count, out);
    out.close();

    std::ifstream in("students.bin", std::ios::binary);
    if (!in.is_open())
    {
        std::cout << "Error opening file!" << std::endl;
        return -1;
    }

    int* arrayOfFacultyNumbers = processFacultyData(students, in);

    for (size_t i = 0; i < count; i++)
    {
        std::cout << arrayOfFacultyNumbers[i] << std::endl;
    }

    in.close();
    
    delete[] arrayOfFacultyNumbers;
    delete[] students;
}
