#include "Motorcycle.h"
#include <iostream>
#include<string>
int Motorcycle::laneSplitUses=0;

Motorcycle::Motorcycle():Vehicle() {}
Motorcycle::Motorcycle(std::string brand, std::string type, double maxSpeed, double price,double agility)
:Vehicle(brand,type ,maxSpeed,price,0.0,1,3.2),agility((agility)){}
Motorcycle::Motorcycle(const Motorcycle &obj):Vehicle(obj),agility((obj.agility)) {}
Motorcycle& Motorcycle::operator=(const Motorcycle& obj) {
    if (this!=&obj) {
        Vehicle::operator=(obj);
        this->agility=obj.agility;
    }
    return *this;
}
int Motorcycle::getLaneSplitUses() const {return laneSplitUses;}
void Motorcycle::addLaneSplitUses(int value) {
    if (value<0)
        throw InvalidNumber("You can't buy less than 0\n");
    laneSplitUses+=value;
}

void Motorcycle::applyUpgrade() {
    if (isMaxLevel())return;
    level+=1;
    acceleration+=(0.08*level);
    agility+=0.4;
    laneSplitUses+=2;
    std::cout<<brand<<" "<<type<<" upgraded to level "<<level<<std::endl;
    std::cout<<"Max Speed: "<<getMaxSpeed()<<" acceleration power: "<<acceleration<<" agility: "<<agility<<std::endl;
}

void Motorcycle::overTake() {
    if (laneSplitUses<1) {
        std::cout<<"No more lanes available\n";
        return;
    }
    double bonusSpeed=50;
    setSpeed(getSpeed()+ bonusSpeed);
    limitSpeed();
    laneSplitUses--;
    std::cout<<"You performed an overtake\n";
}

void Motorcycle::ability() {
    overTake();
}
void Motorcycle::setAgility(double value) {
    if (value<0)
        throw InvalidNumber("Enter a positive number\n");
    agility=value;
}

std::istream& operator>>(std::istream& in, Motorcycle& obj) {
    in>>static_cast<Vehicle&>(obj);
    obj.setAgility(0.1);
    return in;
}
void Motorcycle::print(std::ostream &out) const {
    Vehicle::print(out);
    out<<"Agility: "<<agility<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const Motorcycle& obj) {
    obj.print(out);
    return out;
}
void Motorcycle::save(std::ostream &out) const {
    out<<"Motorcycle\n";
    Vehicle::save(out);
    out<<agility<<"\n";
}

void Motorcycle::load(std::istream &in) {
    Vehicle::load(in);
    in>>agility;
    in.ignore();
}