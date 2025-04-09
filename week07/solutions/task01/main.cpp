#include <iostream>
#include <fstream>

#include "Car.h"
#include <cstring>

size_t countNewLines(std::ifstream& stream)
{
	size_t linesCount = 0;
	std::streampos currPos = stream.tellg();

	if (!stream.is_open() || !stream.good())
		return linesCount;

	char currChar = '\0';
	while (!stream.eof())
	{
		currChar = stream.get();
		if (currChar == '\n')
			linesCount++;
	}

	stream.clear();
	stream.seekg(currPos, std::ios::beg);

	return linesCount;
}

void writeCarsToTextFile(const char* textFile, Car** cars, size_t carsSize)
{
	if (textFile == nullptr)
		return;

	std::ofstream outStream(textFile, std::ios::out);

	if (!outStream.is_open())
		return;

	for (size_t i = 0; i < carsSize; i++)
	{
		cars[i]->serialize(outStream);
	}
}

Car** readCarsFromTextFile(const char* textFile, size_t& carsSize)
{
	if (textFile == nullptr)
		return nullptr;

	std::ifstream inStream(textFile, std::ios::in);

	if (!inStream.is_open())
		return nullptr;

	carsSize = countNewLines(inStream);
	Car** cars = new Car*[carsSize];

	for (size_t i = 0; i < carsSize && !inStream.eof(); i++)
	{
		cars[i] = new Car(nullptr, Person(nullptr, nullptr, Gender::UNKNOWN, 0), 0); // We need an empty object in order to use deserialize!
		cars[i]->deserialize(inStream);
		inStream.get();
	}

	return cars;
}

void deleteCars(Car** cars, size_t carsSize)
{
	for (size_t i = 0; i < carsSize; i++)
	{
		delete cars[i];
	}

	delete[] cars;
}

void printCar(const Car& car)
{
	std::cout << "Brand: " << car.getBrand() << "\n";
	std::cout << "Year of Registration: " << car.getYearOfRegistration() << "\n";
	std::cout << "Owner Name: ";
	std::cout << car.getOwner().getFirstName() << " " << car.getOwner().getLastName() << "\n";
	std::cout << "Owner gender index: " << car.getOwner().getGender() << "\n";
	std::cout << "Owner year of birth: " << car.getOwner().getYearOfBirth() << "\n";
}

void printCars(const Car** cars, size_t carsSize)
{
	for (size_t i = 0; i < carsSize; i++)
	{
		printCar(*cars[i]);
		std::cout << "\n\n";
	}
}

size_t getOwnersCount(const char* brand, const Car** cars, size_t carsCount)
{
	size_t count = 0;

	if (brand == nullptr)
		return count;

	for (size_t i = 0; i < carsCount; i++)
	{
		if (strcmp(brand, cars[i]->getBrand()) == 0)
			count++;
	}

	return count;
}

const char* getMostOwnedBrand(const Car** cars, size_t carsCount)
{
	const char* mostOwnedBrand = nullptr;
	size_t maxCount = 0;

	for (size_t i = 0; i < carsCount; i++)
	{
		size_t currentBrandCount = getOwnersCount(cars[i]->getBrand(), cars, carsCount);
		
		if (currentBrandCount > maxCount)
		{
			mostOwnedBrand = cars[i]->getBrand();
			maxCount = currentBrandCount;
		}
	}

	return mostOwnedBrand;
}

int main()
{
	Person p1("Ivan", "Ivanov", Gender::MALE, 2002);
	Person p2("Georgi", "Gospodinov", Gender::MALE, 1996);
	Person p3("Emilia", "Stefanova", Gender::FEMALE, 1998);

	constexpr size_t CARS_SIZE = 4;
	Car** cars = new Car*[CARS_SIZE];
	cars[0] = new Car("Audi", p1, 2003);
	cars[1] = new Car("Mercedes", p2, 2020);
	cars[2] = new Car("Nissan", p3, 2004);
	cars[3] = new Car("Audi", p1, 2018);

	writeCarsToTextFile("cars.txt", cars, CARS_SIZE);
	deleteCars(cars, CARS_SIZE);

	size_t newCarsSize = 0;
	Car** newCars = readCarsFromTextFile("cars.txt", newCarsSize);
	
	printCars((const Car**)newCars, newCarsSize);

	const char* mostOwnedCar = getMostOwnedBrand((const Car**)newCars, newCarsSize);
	std::cout << "Most owned car brand: " << mostOwnedCar;

	deleteCars(newCars, newCarsSize);
}
