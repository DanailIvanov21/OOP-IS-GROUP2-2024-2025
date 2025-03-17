#include <iostream>
#include <fstream>

using std::ifstream, std::ofstream;

struct Customer
{
    char* customerName = nullptr;
    unsigned customerId = 0;
    unsigned age = 0;
};

void writeCustomerToFile(const Customer& customer, ofstream& ofs)
{
    unsigned customerNameLen = strlen(customer.customerName); 
    ofs.write((const char*)&customerNameLen, sizeof(customerNameLen));
    ofs.write((const char*)customer.customerName, customerNameLen * sizeof(char));
    ofs.write((const char*)&customer.customerId, sizeof(customer.customerId));   
    ofs.write((const char*)&customer.age, sizeof(customer.age));
}

Customer readCustomer(ifstream& ifs)
{
    Customer customer;

    unsigned customerNameLen;
    ifs.read((char*)&customerNameLen, sizeof(customerNameLen));

    customer.customerName = new char[customerNameLen + 1];
    ifs.read(customer.customerName, customerNameLen * sizeof(char));
    customer.customerName[customerNameLen] = '\0'; // Null-terminate the string

    ifs.read((char*)&customer.customerId, sizeof(customer.customerId));
    ifs.read((char*)&customer.age, sizeof(customer.age));

    ifs.clear();

    return customer;
}

struct Order
{
    double price = 0;
    double vat;
    Customer customer;
};

void writeOrderToFile(std::ofstream& ofs, const Order& order)
{
    ofs.write((const char*)&order.price, sizeof(order.price));
    ofs.write((const char*)&order.vat, sizeof(order.vat));
    writeCustomerToFile(order.customer, ofs);
}

void writeOrdersToFile(std::ofstream& ofs, Order* orders, size_t numOrders)
{
    if (!ofs.is_open() || !ofs)
    {
        std::cerr << "Error opening file: " << std::endl;
        return;
    }

    ofs.write((const char*)&numOrders, sizeof(numOrders));

    for (int i = 0; i < numOrders; i++)
    {
        writeOrderToFile(ofs, orders[i]);
    }
}

Order readOrderFromFile(std::ifstream& ifs)
{
    Order result;

    ifs.read((char*)&result.price, sizeof(result.price));
    ifs.read((char*)&result.vat, sizeof(result.vat));

    result.customer = readCustomer(ifs);

    return result;
}

Order* readOrdersFromFile(std::ifstream& ifs)
{
    size_t numOrders;
    ifs.read((char*)&numOrders, sizeof(numOrders));

    Order* orders = new Order[numOrders];

    for (size_t i = 0; i < numOrders; ++i)
    {
        orders[i] = readOrderFromFile(ifs);
    }

    return orders;
}