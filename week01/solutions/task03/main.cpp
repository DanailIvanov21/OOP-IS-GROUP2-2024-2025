#include "Laptop.h"
const size_t AMOUNT_OF_LAPTOPS = 5;

int main()
{
    Laptop laptops[AMOUNT_OF_LAPTOPS];

    for (size_t i = 0; i < AMOUNT_OF_LAPTOPS; i++)
    {
        initialize(laptops[i]);
    }

    showMostExpensiveLaptop(laptops, AMOUNT_OF_LAPTOPS);

    std::cout << averagePrice(laptops, AMOUNT_OF_LAPTOPS) << std::endl;

    printLaptopsWindows(laptops, AMOUNT_OF_LAPTOPS);

    return 0;
}
