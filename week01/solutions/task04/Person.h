#pragma once
#include <iostream>
constexpr unsigned SIZE = 16;

struct Person
{
    char firstname[SIZE];
    char lastname[SIZE];
};

void readPerson(Person& p);
void printPerson(const Person& p);
