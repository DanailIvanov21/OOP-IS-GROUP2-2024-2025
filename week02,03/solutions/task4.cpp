#define _CRT_SECURE_NO_WARNINGS

#include <iostream>
#include <cstring>
#include <fstream>

struct TypesCount
{
	unsigned int boolCount = 0;
	unsigned int integerCount = 0;
	unsigned int floatingCount = 0;
	unsigned int charcterCount = 0;
};

bool isWordType(const char* type, std::ifstream& stream)
{
	if (type == nullptr)
		return false;

	if (stream.peek() != *type)
		return false;

	std::ios::streampos begPos = stream.tellg();
	while (stream.good() && !stream.eof())
	{
		if (*type == '\0')
			break;

		if (*type != stream.get())
		{
			stream.seekg(begPos, std::ios::beg);
			return false;
		}

		type++;
	}

	if (*type != '\0' || stream.peek() != ' ')
	{
		stream.seekg(begPos, std::ios::beg);
		return false;
	}

	return true;
}

TypesCount calculateTypesCount()
{
	std::ifstream sourceCode("week2t4.cpp", std::ios::in);

	TypesCount count;

	if (!sourceCode.is_open())
		return count;

	while (sourceCode.good() && !sourceCode.eof())
	{
		if (isWordType("bool", sourceCode)) count.boolCount++;
		else if (isWordType("int", sourceCode)) count.integerCount++;
		else if (isWordType("double", sourceCode)) count.floatingCount++;
		else if (isWordType("char", sourceCode)) count.charcterCount++;
		else sourceCode.get();
	}

	sourceCode.close();
	
	return count;
}

int main()
{
	TypesCount count = calculateTypesCount();

	std::cout << "Bool count " << count.boolCount << "\n";
	std::cout << "Int count " << count.integerCount << "\n";
	std::cout << "Double count " << count.floatingCount << "\n";
	std::cout << "Char count " << count.charcterCount << std::endl;

	double test;
	double test2;
	bool damnItIsTrue;
	char myChar;
}
