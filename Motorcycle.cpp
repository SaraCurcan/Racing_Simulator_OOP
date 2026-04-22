#include "Motorcycle.h"
#include <iostream>
#include<string>
int Motorcycle::laneSplitUses=0;

Motorcycle::Motorcycle():Vehicle() {}
Motorcycle::Motorcycle(std::string brand, std::string type, double maxSpeed, double price, double speed,double agility)
:Vehicle(brand,type ,maxSpeed,price,speed,1,0.3),agility((agility)){}
Motorcycle::Motorcycle(const Motorcycle &obj):Vehicle(obj),agility((obj.agility)) {}
Motorcycle& Motorcycle::operator=(const Motorcycle& obj) {
    if (this!=&obj) {
        Vehicle::operator=(obj);
        this->agility=agility;
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
    acceleration+=(0.05*level);
    agility+=0.1;
    std::cout<<brand<<" "<<type<<" upgraded to level "<<level<<std::endl;
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
    in>>(Vehicle&)obj;
    std::cout<<"Agility value: ";
    std::string input;
    in>>input;
    try {
        double value=std::stod(input);
        if (value<0) {
            throw InvalidNumber("Enter a positive number\n");
        }
        obj.setAgility(value);
    }
    catch (const std::exception& e) {
        throw InvalidNumber("Please enter a valid number\n");
    }
    return in;
}
void Motorcycle::print(std::ostream &out) const {
    out<<"Brand: "<<brand<<std::endl;
    out<<"Type: "<<type<<std::endl;
    out<<"Max Speed: "<<getMaxSpeed()<<std::endl;
    out<<"Nitro: "<<laneSplitUses<<std::endl;
    out<<"Agility: "<<agility<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const Motorcycle& obj) {
    obj.print(out);
    return out;
}