#include "Truck.h"
#include "Exceptions.h"
#include "iostream"
#include "string"
int Truck::stabilityUses=0;
Truck::Truck():Vehicle() {}
Truck::Truck(std::string brand, std::string type, double maxSpeed, double price, double speed,double stability)
:Vehicle(brand,type,maxSpeed,price,speed,1,0.2), stability(stability){};
Truck::Truck(const Truck& obj):Vehicle(obj),stability((obj.stability)){}
Truck& Truck::operator=(const Truck& obj) {
    if (this!=&obj) {
        Vehicle::operator=(obj);
        this->stability=obj.stability;
    }
    return *this;
}
Truck::~Truck(){}

double Truck::getStability() const { return stability;}
void Truck::setStability(double value) {
    if (value<0) throw InvalidNumber("Enter a positive number\n");
    stability=value;
}

int Truck::getStabilityUses() const {return stabilityUses;}

void Truck::setStabilityUses(int value) {
    if (value<0) throw InvalidNumber("Enter a positive number\n");
    stabilityUses=value;
}
