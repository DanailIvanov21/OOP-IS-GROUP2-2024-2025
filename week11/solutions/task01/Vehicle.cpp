#include "Vehicle.h"

Vehicle::Vehicle() : color(nullptr), brand(nullptr), year(0), seats(0), maxSpeed(0) {}

Vehicle::Vehicle(const char* color, const char* brand, int year, int seats, int maxSpeed) : Vehicle() {
    setColor(color);
    setBrand(brand);
    setYear(year);
    setSeats(seats);
    setMaxSpeed(maxSpeed);
}

Vehicle::Vehicle(const Vehicle& other) {
    copyFrom(other);
}

Vehicle& Vehicle::operator=(const Vehicle& other) {
    if (this != &other) {
        free();
        copyFrom(other);
    }
    return *this;
}

Vehicle::~Vehicle() {
    free();
}

void Vehicle::copyFrom(const Vehicle& other) {
    setColor(other.color);
    setBrand(other.brand);
    year = other.year;
    seats = other.seats;
    maxSpeed = other.maxSpeed;
}

void Vehicle::free() {
    delete[] color;
    delete[] brand;
}

const char* Vehicle::getColor() const { 
    return color; 
}
void Vehicle::setColor(const char* value) {
    delete[] color;
    color = new char[strlen(value) + 1];
    strcpy(color, value);
}

const char* Vehicle::getBrand() const { 
    return brand; 
}
void Vehicle::setBrand(const char* value) {
    delete[] brand;
    brand = new char[strlen(value) + 1];
    strcpy(brand, value);
}

int Vehicle::getYear() const { 
    return year; 
}
void Vehicle::setYear(int value) { 
    year = value; 
}

int Vehicle::getSeats() const { 
    return seats; 
}
void Vehicle::setSeats(int value) { 
    seats = value; 
}

int Vehicle::getMaxSpeed() const { 
    return maxSpeed; 
}
void Vehicle::setMaxSpeed(int value) { 
    maxSpeed = value; 
}
