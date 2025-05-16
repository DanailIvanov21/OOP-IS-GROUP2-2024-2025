#pragma once
#include "Vehicle.h"

class Bicycle : public Vehicle {
    int speedCount;
    bool hasLights;
    bool hasReflectors;
    bool hasBell;

public:
    Bicycle();
    Bicycle(const char* color, const char* brand, int year, int seats, int maxSpeed, int speedCount, bool hasLights, bool hasReflectors, bool hasBell);
    

    int getSpeedCount() const;
    void setSpeedCount(int speedCount);

    bool getHasLights() const;
    void setHasLights(bool hasLights);

    bool getHasReflectors() const;
    void setHasReflectors(bool hasReflectors);

    bool getHasBell() const;
    void setHasBell(bool hasBell);
};
