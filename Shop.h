#pragma once
#include "Garage.h"
#include "SportCar.h"
#include "Truck.h"
#include "Motorcycle.h"
#include <iostream>
#include <string>
class Shop {
private:
    std::string filename;
public:
    Shop();
    Shop(std::string filename);
    Shop(const Shop& obj);
    Shop& operator=(const Shop& obj);
    ~Shop();
    void showCatalog(Garage& garage);
    void buyVehicle(int index, Garage &garage);
};