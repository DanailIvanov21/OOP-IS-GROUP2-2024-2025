#pragma once

#include "Person.h"

#include <fstream>

class Car
{
public:
	Car(const char* brand, const Person& owner, unsigned short yearOfRegsitration);

	const char* getBrand() const;
	const Person& getOwner() const;
	unsigned short getYearOfRegistration() const;

	void serialize(std::ofstream& stream) const;
	void deserialize(std::ifstream& stream);

private:
	char brand[128];
	Person owner;
	unsigned short yearOfRegistration;

	void setBrand(const char* brand);
	char* getNextStringEntry(std::ifstream& stream);
	unsigned short clamp(unsigned short value, unsigned short min, unsigned short max);
};
