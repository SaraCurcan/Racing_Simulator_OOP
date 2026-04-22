#pragma once
#include "Vehicle.h"
#include "Exceptions.h"
#include<iostream>
#include<string>

class Motorcycle:public Vehicle {
private:
    static int laneSplitUses;
public:
    Motorcycle();
    Motorcycle(std::string type, std::string brand, double MaxSpeed, double price, double speed);
    Motorcycle(const Motorcycle& obj);
    Motorcycle& operator=(const Motorcycle& obj);
    ~Motorcycle();
    void ability() override;
    void applyUpgrade() override;
    int getLaneSplitUses() const;
    void addLaneSplitUses(int value);
    friend std::istream& operator>>(std::istream& in, Motorcycle& obj);
    friend std::ostream& operator<<(std::ostream& out, const Motorcycle& obj);

};