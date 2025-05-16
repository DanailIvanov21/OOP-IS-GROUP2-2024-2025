#include "Car.h"

Car::Car() : Vehicle(), model(nullptr), doors(0), horsepower(0) {}

Car::Car(const char* color, const char* brand, int year, int seats, int maxSpeed, const char* model, int doors, int horsepower)
    : Vehicle(color, brand, year, seats, maxSpeed), doors(doors), horsepower(horsepower) {
    setModel(model);
}

Car::Car(const Car& other) : Vehicle(other) {
    copyFrom(other);
}

Car& Car::operator=(const Car& other) {
    if (this != &other) {
        Vehicle::operator=(other);
        free();
        copyFrom(other);
    }
    return *this;
}

Car::~Car() {
    free();
}

void Car::copyFrom(const Car& other) {
    setModel(other.model);
    doors = other.doors;
    horsepower = other.horsepower;
}

void Car::free() {
    delete[] model;
}

const char* Car::getModel() const { 
    return model; 
}
void Car::setModel(const char* value) {
    delete[] model;
    model = new char[strlen(value) + 1];
    strcpy(model, value);
}

int Car::getDoors() const { 
    return doors; 
}
void Car::setDoors(int value) { 
    doors = value; 
}

int Car::getHorsepower() const { 
    return horsepower; 
}
void Car::setHorsepower(int value) { 
    horsepower = value; 
}
