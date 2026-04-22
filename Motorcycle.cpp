#include "Motorcycle.h"
#include <iostream>
#include<string>
int Motorcycle::laneSplitUses=0;

Motorcycle::Motorcycle():Vehicle() {}
Motorcycle::Motorcycle(std::string type, std::string brand, double maxSpeed, double price, double speed)
:Vehicle(type,brand ,maxSpeed,price,speed,1,0.3){}
Motorcycle::Motorcycle(const Motorcycle &obj):Vehicle(obj) {}
Motorcycle& Motorcycle::operator=(const Motorcycle& obj) {
    if (this!=&obj) {
        Vehicle::operator=(obj);
    }
    return *this;
}
Motorcycle::~Motorcycle(){}
