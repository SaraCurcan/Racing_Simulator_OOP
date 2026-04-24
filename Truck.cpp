#include "Truck.h"
#include "Exceptions.h"
#include <iostream>
#include <string>
int Truck::stabilityUses=0;
Truck::Truck():Vehicle(),stability((0.0)) {}
Truck::Truck(std::string brand, std::string type, double maxSpeed, double price, double stability)
:Vehicle(brand,type,maxSpeed,price,0.0,1,2.1), stability(stability){};
Truck::Truck(const Truck& obj):Vehicle(obj),stability((obj.stability)){}
Truck& Truck::operator=(const Truck& obj) {
    if (this!=&obj) {
        Vehicle::operator=(obj);
        this->stability=obj.stability;
    }
    return *this;
}
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

void Truck::applyUpgrade() {
    if (isMaxLevel())return;
    level+=1;
    acceleration+=(0.05*level);
    stability+=0.1;
    std::cout<<brand<<" "<<type<<" upgraded to level "<<level<<std::endl;
}
void Truck::handling() {
    if (stabilityUses<1) {
        std::cout<<"No more power available\n";
        return;
    }
    acceleration*=2;
    stabilityUses--;
    std::cout<<"Your acceleration power increased with "<<acceleration*2<<std::endl;
}

void Truck::ability() {
    handling();
}
void Truck::print(std::ostream &out) const {
    Vehicle::print(out);
    out<<"Stability: "<<stability<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const Truck& obj) {
    obj.print(out);
    return out;
}
std::istream& operator>>(std::istream& in, Truck& obj) {
    in>>static_cast<Vehicle&>(obj);
    obj.setStability(0.0);
    return in;
}
