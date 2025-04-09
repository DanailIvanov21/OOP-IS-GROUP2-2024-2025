#define _CRT_SECURE_NO_WARNINGS

#include "Person.h"

#include <cstring>

Person::Person(const char* firstName, const char* lastName, Gender gender, unsigned short yearOfBirth) :
    firstName(copyStringOrEmpty(firstName)),
    lastName(copyStringOrEmpty(lastName)),
    gender(gender), yearOfBirth(yearOfBirth)
{
}

Person::Person(const Person& other) :gender(other.gender),yearOfBirth(other.yearOfBirth)
{
    copyFrom(other);
}

Person::~Person()
{
    freeMemory();
}

Person& Person::operator=(const Person& other)
{
    if (this != &other)
    {
        freeMemory();
        copyFrom(other);
        gender = other.gender;
        yearOfBirth = other.yearOfBirth;
    }

    return *this;
}

const char* Person::getFirstName() const
{
    return firstName;
}

const char* Person::getLastName() const
{
    return lastName;
}

Gender Person::getGender() const
{
    return gender;
}

unsigned short Person::getYearOfBirth() const
{
    return yearOfBirth;
}

void Person::serialize(std::ofstream& stream) const
{
    if (!stream.is_open() || !stream.good())
        return;

    stream << firstName;
    stream << ',';
    stream << lastName;
    stream << ',';
    stream << gender;
    stream << ',';
    stream << yearOfBirth;
}

void Person::deserialize(std::ifstream& stream)
{
    if (!stream.is_open() || !stream.good())
        return;

    delete[] firstName;
    firstName = getNextStringEntry(stream);
    stream.get(); // Getting rid of ','

    delete[] lastName;
    lastName = getNextStringEntry(stream);
    stream.get(); // Getting rid of ','

    int genderIndex;
    stream >> genderIndex;

    gender = genderIndex == 0 || genderIndex == 1 ? Gender(genderIndex) : Gender::UNKNOWN;
    stream.get(); // Getting rid of ','

    stream >> yearOfBirth;
}

void Person::setFirstName(const char* firstName)
{
    if (firstName == nullptr)
        return;

    delete[] this->firstName;
    this->firstName = copyStringOrEmpty(firstName);
}

void Person::setLastName(const char* lastName)
{
    if (lastName == nullptr)
        return;

    delete[] this->lastName;
    this->lastName = copyStringOrEmpty(lastName);
}

void Person::setGender(Gender gender)
{
    this->gender = gender;
}

void Person::setYearOfBirth(unsigned short yearOfBirth)
{
    this->yearOfBirth = yearOfBirth;
}

void Person::freeMemory()
{
    delete[] firstName;
    delete[] lastName;
}

void Person::copyDynamic(const Person& other)
{
    firstName = copyStringOrEmpty(other.firstName);
    lastName = copyStringOrEmpty(other.lastName);
    
}

char* Person::copyStringOrEmpty(const char* str)
{
    if (str == nullptr)
        return copyStringOrEmpty("");

    return strcpy(new char[strlen(str) + 1], str);
}

char* Person::getNextStringEntry(std::ifstream& stream)
{
    std::streampos currentPos = stream.tellg();
    size_t stringLength = 0;

    while (stream.get() != ',')
        stringLength++;

    stream.seekg(currentPos, std::ios::beg);

    char* readString = new char[stringLength + 1];

    size_t currStringPos = 0;
    while (stream.peek() != ',' && currStringPos < stringLength)
    {
        readString[currStringPos] = stream.get();
        currStringPos++;
    }

    readString[currStringPos] = '\0';
    return readString;
}
