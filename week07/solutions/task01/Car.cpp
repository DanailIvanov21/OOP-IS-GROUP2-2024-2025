#define _CRT_SECURE_NO_WARNINGS

#include "Car.h"

Car::Car(const char* brand, const Person& owner, unsigned short yearOfRegsitration) :
    owner(owner),
    yearOfRegistration(clamp(yearOfRegsitration, 1800, 2024))
{
    setBrand(brand);
}

const char* Car::getBrand() const
{
    return brand;
}

const Person& Car::getOwner() const
{
    return owner;
}

unsigned short Car::getYearOfRegistration() const
{
    return yearOfRegistration;
}

void Car::serialize(std::ofstream& stream) const
{
    if (!stream.is_open() || !stream.good())
        return;

    stream << brand;
    stream << ',';
    stream << yearOfRegistration;
    stream << ',';
    owner.serialize(stream);
    stream << "\n";
}

void Car::deserialize(std::ifstream& stream)
{
    if (!stream.is_open() || !stream.good())
        return;

    char* brand = getNextStringEntry(stream);
    setBrand(brand);
    delete[] brand;
    stream.get();
    
    unsigned short registartionYear;
    stream >> registartionYear;
    yearOfRegistration = clamp(registartionYear, 1800, 2024);
    stream.get();
    
    owner.deserialize(stream);
}

void Car::setBrand(const char* brand)
{
    if (brand == nullptr)
    {
        setBrand("Unknown");
        return;
    }

    strncpy(this->brand, brand, 128);
}

char* Car::getNextStringEntry(std::ifstream& stream)
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

unsigned short Car::clamp(unsigned short value, unsigned short min, unsigned short max)
{
    if (value < min)
        return min;

    if (value > max)
        return max;

    return value;
}
