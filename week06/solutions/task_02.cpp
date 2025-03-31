#include <iostream>
#include <fstream>
#include <cstring>
const int MAX = 124;
class Alcohol {
private:
    char* name;
    double price;

public:
    Alcohol() : name(nullptr), price(0.0) {}
   
    Alcohol(const char* n, double p) : name(nullptr), price(0.0) {
        setName(n);
        setPrice(p);
    }
    
    ~Alcohol() {
        delete[] name;
    }

    void setName(const char* n) {
        if (name) {
            delete[] name;
        }
        name = new char[strlen(n) + 1];
        strcpy(name, n);
    }

    void setPrice(double p) {
        price = p;
    }
 
    const char* getName() const {
        return name;
    }
    
    double getPrice() const {
        return price;
    }

    void print() const {
        std::cout << "Alcohol: " << (name ? name : "Unknown") << ", Price: " << price << "\n";
    }
    void saveToTextFile(const char* filename) const {
        std::ofstream file(filename);
        if (!file) {
            std::cerr << "Error: Could not open " << filename << " for writing.\n";
            return;
        }
        file << name << "\n" << price << "\n";
        file.close();
    }
    void loadFromTextFile(const char* filename) {
        std::ifstream file(filename);
        if (!file) {
            std::cerr << "Error: Could not open " << filename << " for reading.\n";
            return;
        }
        char buffer[MAX];
        file.getline(buffer, MAX);
        setName(buffer);
        file >> price;
        file.close();
    }
    void saveToBinaryFile(const char* filename) const {
        std::ofstream file(filename, std::ios::binary);
        if (!file) {
            std::cerr << "Error: Could not open " << filename << " for writing.\n";
            return;
        }
        size_t len = strlen(name);
        file.write((const char*)&len, sizeof(len));
        file.write(name, len);
        file.write((const char*)&price, sizeof(price));
        file.close();
    }
    void loadFromBinaryFile(const char* filename) {
        std::ifstream file(filename, std::ios::binary);
        if (!file) {
            std::cerr << "Error: Could not open " << filename << " for reading.\n";
            return;
        }
        size_t len;
        file.read((char*)&len, sizeof(len));
        char* buffer = new char[len + 1];
        file.read(buffer, len);
        buffer[len] = '\0';
        setName(buffer);
        delete[] buffer;
        file.read((char*)&price, sizeof(price));
        file.close();
    }
};

int main() {
    Alcohol a("Whiskey", 25.50);
    a.print();
    
    a.saveToTextFile("alcohol.txt");
    a.saveToBinaryFile("alcohol.bin");
    
    Alcohol b;
    b.loadFromTextFile("alcohol.txt");
    b.print();
    
    Alcohol c;
    c.loadFromBinaryFile("alcohol.bin");
    c.print();
    
    return 0;
}
