#pragma once
#include "Vehicle.h"
#include<iostream>
#include<string>
#include<vector>
class Garage{
private:
    double coins;
    std::vector<Vehicle*> vehicule;
public:
    Garage();
    Garage(double coins, const std::vector<Vehicle*>& list);
    Garage(const Garage& obj);
    Garage& operator=(const Garage& obj);
    ~Garage();
    void Upgrade();
    void addToGarage(Vehicle* v);
    void ShowOwnedVehicles() const;
};