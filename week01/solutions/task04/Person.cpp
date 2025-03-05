#include "Person.h"
void readPerson(Person& p)
{
    std::cout << "First name: ";
    std::cin >> p.firstname;
    std::cout << "Last name: ";
    std::cin >> p.lastname;
}

void printPerson(const Person& p)
{
    std::cout << "First name: " << p.firstname << std::endl
        << "Last name: " << p.lastname << std::endl;
}
