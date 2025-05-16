#pragma once
#include <cstring>
#pragma warning (disable:4996)

class Vehicle {
    char* color;
    char* brand;
    int year;
    int seats;
    int maxSpeed;

    void copyFrom(const Vehicle& other);
    void free();

public:
    Vehicle();
    Vehicle(const char* color, const char* brand, int year, int seats, int maxSpeed);
    Vehicle(const Vehicle& other);
    Vehicle& operator=(const Vehicle& other);
    ~Vehicle();

    const char* getColor() const;
    void setColor(const char* color);

    const char* getBrand() const;
    void setBrand(const char* brand);

    int getYear() const;
    void setYear(int year);

    int getSeats() const;
    void setSeats(int seats);

    int getMaxSpeed() const;
    void setMaxSpeed(int maxSpeed);
};
