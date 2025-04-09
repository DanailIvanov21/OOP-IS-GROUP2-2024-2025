#pragma once

#include <fstream>

enum Gender {
	UNKNOWN = -1,
	MALE,
	FEMALE
};

class Person
{
public:
	Person(const char* firstName, const char* lastName, Gender gender, unsigned short yearOfBirth);
	Person(const Person& other);
	~Person();

	Person& operator=(const Person& other);

	const char* getFirstName() const;
	const char* getLastName() const;
	Gender getGender() const;
	unsigned short getYearOfBirth() const;

	void serialize(std::ofstream& stream) const;
	void deserialize(std::ifstream& stream);

	void setFirstName(const char* firstName);
	void setLastName(const char* lastName);
	void setGender(Gender gender);
	void setYearOfBirth(unsigned short yearOfBirth);

private:
	char* firstName;
	char* lastName;
	Gender gender;
	unsigned short yearOfBirth;

	void freeMemory();
	void copyDynamic(const Person& other);
	char* copyStringOrEmpty(const char* str);
	char* getNextStringEntry(std::ifstream& stream);
};
