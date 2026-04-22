#pragma once
#include "Vehicle.h"
#include "Exceptions.h"
#include<iostream>
#include<string>

class Motorcycle:public Vehicle {
private:
    static int laneSplitUses;
    double agility;
    void overTake();
public:
    Motorcycle();
    Motorcycle(std::string brand, std::string type, double MaxSpeed, double price, double speed,double agility);
    Motorcycle(const Motorcycle& obj);
    Motorcycle& operator=(const Motorcycle& obj);
    virtual ~Motorcycle()=default;
    void ability() override;
    void applyUpgrade() override;
    int getLaneSplitUses() const;
    void addLaneSplitUses(int value);
    friend std::istream& operator>>(std::istream& in, Motorcycle& obj);
    friend std::ostream& operator<<(std::ostream& out, const Motorcycle& obj);
    void setAgility(double value);
    void print(std::ostream& out)const override;
    Vehicle* clone() const override {
        return new Motorcycle(*this);
    };
};