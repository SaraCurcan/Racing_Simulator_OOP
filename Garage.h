#pragma once
#include "Vehicle.h"
#include<iostream>
#include<string>
#include<vector>
class Garage{
private:
    double coins;
    std::vector<Vehicle*> list;
public:
    Garage();
    Garage(double coins, const std::vector<Vehicle*>& list);
    Garage(const Garage& obj);
    Garage& operator=(const Garage& obj);
    ~Garage();
    void Upgrade(int index);
    void addVehicle(Vehicle* v);
    void ShowOwnedVehicles() const;
    double getCoins() const;
    void setcoins(double value);
    Vehicle* getVehicle(int index) const;
    int getSize() const;
    bool checkVehicle(const std::string& brand, const std::string &type);
    friend std::ostream& operator<<(std::ostream& out, const Garage& obj);
    friend std::istream& operator>>(std::istream& in, Garage& obj);
    void loadDefaultVehicles(const std::string& filename);
    void saveFile(const std::string& filename);
    void loadFile(const std::string& filename);
    void load(std::istream& in);
    void save(std::ostream& out) const;
};