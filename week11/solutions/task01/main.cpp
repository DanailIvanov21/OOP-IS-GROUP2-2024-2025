#include <iostream>
#include "Vehicle.h"
#include "Bicycle.h"
#include "Car.h"

int main() {
    Vehicle v("Red", "Toyota", 2020, 5, 180);
    std::cout << "Vehicle: Brand = " << v.getBrand() << ", Color = " << v.getColor() << ", Year = " << v.getYear()
        << ", Seats = " << v.getSeats() << ", Max Speed = " << v.getMaxSpeed() << " km/h" << std::endl;

    Bicycle b("Blue", "Trek", 2021, 1, 30, 21, true, true, true);
    std::cout << "Bicycle: Brand = " << b.getBrand() << ", Color = " << b.getColor() << ", Year = " << b.getYear()
        << ", Seats = " << b.getSeats() << ", Max Speed = " << b.getMaxSpeed() << " km/h" << ", Speed Count = "
        << b.getSpeedCount() << ", Has Lights = " << (b.getHasLights() ? "Yes" : "No") << ", Has Reflectors = "
        << (b.getHasReflectors() ? "Yes" : "No") << ", Has Bell = " << (b.getHasBell() ? "Yes" : "No") << std::endl;

    Car c("Black", "Audi", 2019, 5, 250, "A4", 4, 220);
    std::cout << "Car: Brand = " << c.getBrand() << ", Color = " << c.getColor() << ", Year = " << c.getYear()
        << ", Seats = " << c.getSeats() << ", Max Speed = " << c.getMaxSpeed() << " km/h" << ", Model = "
        << c.getModel() << ", Doors = " << c.getDoors() << ", Horsepower = " << c.getHorsepower() << " HP" << std::endl;

    return 0;
}
