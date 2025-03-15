#include <iostream>
#include <fstream>
#include <cstring>

constexpr unsigned MAX_LENGHT_NAME = 32;
constexpr unsigned FACULTY_NUMBER_LENGHT = 11;

struct Student {
    char firstName[MAX_LENGHT_NAME];
    char lastName[MAX_LENGHT_NAME];
    char facultyNumber[FACULTY_NUMBER_LENGHT];
    unsigned takenCourses;
    double averageGrade;
    bool hasPassedAllCourses;
};

void writeStudentToFile(const Student& student, std::ofstream& ofs) {
    if (!ofs.is_open() || !ofs.good()) {
        return;
    }

    ofs << student.firstName << ' ' << student.lastName << ' '
           << student.facultyNumber << ' ' << student.takenCourses << ' '
           << student.averageGrade << ' ' << student.hasPassedAllCourses << '\n';
}

bool readStudentFromFile(std::ifstream& ifs, Student& student) {
    if (!(ifs >> student.firstName >> student.lastName >> student.facultyNumber
                 >> student.takenCourses >> student.averageGrade >> student.hasPassedAllCourses)) {
        return false;
    }

    return true;
}

void printStudent(const Student& student) {
    std::cout << "Name: " << student.firstName << " " << student.lastName << "\n"
              << "FN: " << student.facultyNumber << "\n"
              << "Average grade: " << student.averageGrade << "\n"
              << "Taken courses: " << student.takenCourses << "\n"
              << "Has passed all courses: " << std::boolalpha << student.hasPassedAllCourses << "\n";
}

void writeStudentsToFile(const Student* students, std::ofstream& ofs, unsigned size){
    for (int i = 0; i < size; ++i) {
        writeStudentToFile(students[i], ofs);
    }
}

int main() {
    const unsigned MAX_STUDENTS_COUNT = 3;
    Student students[MAX_STUDENTS_COUNT] = {
        {"Ivan", "Marinov", "2MI0724156", 5, 5.23, true},
        {"Kiril", "Ivanov", "0MI0726156", 2, 4.23, false},
        {"Monika", "Stefanova", "2MI0725156", 10, 4.23, true}
    };

    std::ofstream ofs("students.txt", std::ios::out | std::ios::trunc);
    
    if (!ofs.is_open()) {
        return -1;
    }

    writeStudentsToFile(students, ofs, MAX_STUDENTS_COUNT);

    ofs.close();

    std::ifstream ifs("students.txt", std::ios::in);
    
    if (!ifs.is_open()) {
        return -1;
    }

    Student loadedStudents[MAX_STUDENTS_COUNT];
    unsigned count = 0;
   
    while (count < MAX_STUDENTS_COUNT && readStudentFromFile(ifs, loadedStudents[count])) {
        count++;
    }

    ifs.close();

    for (int i = 0; i < count; ++i) {
        printStudent(loadedStudents[i]);
        std::cout << "\n";
    }

    return 0;
}