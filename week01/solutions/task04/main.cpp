#include "Client.h"

int main()
{
    std::cout << "Enter number of clients (1 to " << MAX_COUNT_OF_CLIENTS << "): ";
    unsigned size;
    std::cin >> size;

    if (size < 1 || size > MAX_COUNT_OF_CLIENTS)
    {
        std::cout << "Invalid number of clients!" << std::endl;
        return 1;
    }

    Client clients[MAX_COUNT_OF_CLIENTS];

    initilizeClients(clients, size);
    printClients(clients, size);

    double totalAmount = calcTotalAmount(clients, size);
    std::cout << "Total debt: " << totalAmount << std::endl;

    return 0;
}
