#pragma once
#include <iostream>
constexpr unsigned OS_SIZE = 8;

enum class OperationSystem
{
    NONE = -1,
    WINDOWS,
    LINUX,
    MACOS
};

struct Laptop
{
    double price;
    char model[32];
    int sizeOfScreen;
    int capacityOfHDD;
    char videocard[32];
    bool hasSSD;
    OperationSystem operationSystem;
};

void matchOperationSystem(Laptop& l, const char os[OS_SIZE]);
void initialize(Laptop& l);
void printOperationSystem(OperationSystem os);
void print(const Laptop& l);
unsigned findIndexOfMostExpensiveLaptop(const Laptop* laptops, const size_t size);
void showMostExpensiveLaptop(const Laptop* laptops, const size_t size);
double averagePrice(const Laptop* laptops, const size_t size);
void printLaptopsWindows(const Laptop* laptops, const size_t size);
