#include "Laptop.h"

void matchOperationSystem(Laptop& l, const char os[OS_SIZE])
{
    if (strcmp(os, "WINDOWS") == 0)
    {
        l.operationSystem = OperationSystem::WINDOWS;
        return;
    }

    if(strcmp(os, "MACOS") == 0)
    {
        l.operationSystem = OperationSystem::MACOS;
        return;
    }

    if (strcmp(os, "LINUX") == 0)
    {
        l.operationSystem = OperationSystem::LINUX;
        return;
    }

    l.operationSystem = OperationSystem::NONE;
}

void initialize(Laptop& l)
{
    char os[OS_SIZE];
    std::cout << "Enter laptop specifications:" << std::endl;
    std::cin >> l.price >> l.model >> l.sizeOfScreen >> l.capacityOfHDD >> l.videocard >> l.hasSSD >> os;

    matchOperationSystem(l, os);
}

void printOperationSystem(OperationSystem os)
{
    switch (os)
    {
    case OperationSystem::WINDOWS: std::cout << "WINDOWS" << std::endl; return; break;
    case OperationSystem::LINUX: std::cout << "LINUX" << std::endl; return; break;
    case OperationSystem::MACOS: std::cout << "MACOS" << std::endl; return; break;
    default: std::cout << "None" << std::endl; return; break;
    }
}

void print(const Laptop& l)
{
    std::cout << "Laptop specifications: " << std::endl;
    std::cout << l.price << std::endl;
    std::cout << l.model << std::endl;
    std::cout << l.sizeOfScreen << std::endl;
    std::cout << l.capacityOfHDD << std::endl;
    std::cout << l.videocard << std::endl;
    std::cout << l.hasSSD << std::endl;
    printOperationSystem(l.operationSystem);
}

unsigned findIndexOfMostExpensiveLaptop(const Laptop* laptops, const size_t size)
{
    size_t highestPrice = laptops[0].price;
    size_t index = 0;

    for (size_t i = 1; i < size; i++)
    {
        if (laptops[i].price > highestPrice)
        {
            highestPrice = laptops[i].price;
            index = i;
        }
    }

    return index;
}


void showMostExpensiveLaptop(const Laptop* laptops, const size_t size)
{
    unsigned index = findIndexOfMostExpensiveLaptop(laptops, size);

    print(laptops[index]);
}

double averagePrice(const Laptop* laptops, const size_t size)
{
    double sum = 0;

    for (size_t i = 0; i < size; i++)
    {
        sum += laptops[i].price;
    }
    
    return sum / size;
}

void printLaptopsWindows(const Laptop* laptops, const size_t size)
{
    for (size_t i = 0; i < size; i++)
    {
        if (laptops[i].operationSystem == OperationSystem::WINDOWS)
        {
            print(laptops[i]);
        }
    }
}
