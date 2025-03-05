#include "Client.h"

void readClient(Client& c)
{
    std::cout << "Enter client details:" << std::endl;
    readPerson(c.name);
    std::cout << "Client's balance: ";
    std::cin >> c.amount;
}

void printClient(const Client& c)
{
    std::cout << "Client details:" << std::endl;
    printPerson(c.name);
    std::cout << "Balance: " << c.amount << std::endl;
}

void initilizeClients(Client* clients, unsigned size)
{
    for (int i = 0; i < size; i++)
    {
        readClient(clients[i]);
    }
}

void printClients(Client* clients, unsigned size)
{
    std::cout << "Bank Clients:" << std::endl;

    for (int i = 0; i < size; i++)
    {
        printClient(clients[i]);
    }
}

double calcTotalAmount(Client* clients, unsigned size)
{
    double totalAmount = 0;

    for (int i = 0; i < size; i++)
    {
        if (clients[i].amount < 0)
        {
            totalAmount += clients[i].amount;
        }
    }

    return totalAmount;
}
