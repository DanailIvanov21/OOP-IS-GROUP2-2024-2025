#pragma once
#include "Person.h"
constexpr unsigned MAX_COUNT_OF_CLIENTS = 20;

struct Client
{
    Person name;
    double amount;
};

void readClient(Client& c);
void printClient(const Client& c);
void initilizeClients(Client* clients, unsigned size);
void printClients(Client* clients, unsigned size);
double calcTotalAmount(Client* clients, unsigned size);
