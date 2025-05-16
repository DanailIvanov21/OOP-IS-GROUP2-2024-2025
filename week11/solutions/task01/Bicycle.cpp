#include "Bicycle.h"

Bicycle::Bicycle() : Vehicle(), speedCount(0), hasLights(false), hasReflectors(false), hasBell(false) {}

Bicycle::Bicycle(const char* color, const char* brand, int year, int seats, int maxSpeed, int speedCount, bool hasLights, bool hasReflectors, bool hasBell)
    : Vehicle(color, brand, year, seats, maxSpeed), speedCount(speedCount), hasLights(hasLights), hasReflectors(hasReflectors), hasBell(hasBell) {}




int Bicycle::getSpeedCount() const { 
    return speedCount; 
}
void Bicycle::setSpeedCount(int value) { 
    speedCount = value; 
}

bool Bicycle::getHasLights() const { 
    return hasLights; 
}
void Bicycle::setHasLights(bool value) { 
    hasLights = value; 
}

bool Bicycle::getHasReflectors() const { 
    return hasReflectors; 
}
void Bicycle::setHasReflectors(bool value) { 
    hasReflectors = value; 
}

bool Bicycle::getHasBell() const { 
    return hasBell; 
}
void Bicycle::setHasBell(bool value) { 
    hasBell = value; 
}
