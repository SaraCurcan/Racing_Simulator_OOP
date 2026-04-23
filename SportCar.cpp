#include "SportCar.h"
#include "Exceptions.h"
#include<iostream>
#include<string>
int SportCar::availableNitro=0;
SportCar::SportCar():Vehicle(){}
SportCar::SportCar(std::string brand, std::string type, double maxSpeed, double price)
    :Vehicle(brand,type,maxSpeed,price,0.0,1,0.4){}

SportCar::SportCar(const SportCar &obj):Vehicle(obj){}
SportCar& SportCar::operator=(const SportCar& obj) {
    if (this!=&obj) {
        Vehicle::operator=(obj);
    }
    return *this;
}
int SportCar::getAvailableNitro() const { return availableNitro; }

void SportCar::applyUpgrade() {
    if (isMaxLevel())return;
    upgradetMaxSpeed(30.0);
    level+=1;
    acceleration+=(0.06*level);
    std::cout<<brand<<" "<<type<<" upgraded to level "<<level<<std::endl;
}
void SportCar::applyNitro() {
    if (availableNitro>0) {
        std::cout<<"Nitro applied "<<std::endl;
        setSpeed(getSpeed() + 100*acceleration);
        availableNitro--;
    }
    else std::cout<<"No more available nitro "<<std::endl;
}
void SportCar::ability() {
    applyNitro();
}

void SportCar::print(std::ostream &out) const {
    Vehicle::print(out);
    out<<"Nitro: "<<availableNitro<<std::endl;
}

std::ostream& operator<<(std::ostream& out, const SportCar& obj) {
    obj.print(out);
    return out;
}

std::istream& operator>>(std::istream& in, SportCar& obj) {
    in>>static_cast<Vehicle&>(obj);
    return in;
}

void SportCar::addNitro(int value) {
    if (value<0)
        throw InvalidNumber("Error: Nitro must be a positive number\n");
    availableNitro+=value;
}
