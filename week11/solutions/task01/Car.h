#pragma once
#include "Vehicle.h"

class Car : public Vehicle {
    char* model;
    int doors;
    int horsepower;

    void copyFrom(const Car& other);
    void free();

public:
    Car();
    Car(const char* color, const char* brand, int year, int seats, int maxSpeed, const char* model, int doors, int horsepower);
    Car(const Car& other);
    Car& operator=(const Car& other);
    ~Car();

    const char* getModel() const;
    void setModel(const char* model);

    int getDoors() const;
    void setDoors(int doors);

    int getHorsepower() const;
    void setHorsepower(int horsepower);
};
