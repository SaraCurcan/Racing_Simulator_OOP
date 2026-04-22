#include "SportCar.h"
#include "Exceptions.h"
#include<iostream>
#include<string>
int SportCar::availableNitro=0;
SportCar::SportCar():Vehicle(){}
SportCar::SportCar(std::string type, std::string brand, double maxSpeed, double price, double speed,int availableNitro)
    :Vehicle(type,brand,maxSpeed,price,speed,1,0.4){}

SportCar::SportCar(const SportCar &obj):Vehicle(obj){}
SportCar& SportCar::operator=(const SportCar& obj) {
    if (this!=&obj) {
        Vehicle::operator=(obj);
    }
    return *this;
}
SportCar::~SportCar(){}

int SportCar::getAvailableNitro() const { return availableNitro; }

void SportCar::applyUpgrade() {
    level+=1;
    acceleration+=0.1;
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

std::ostream& operator<<(std::ostream& out, const SportCar& obj) {
    out<<(const Vehicle&)obj;
    out<<"Nitro: "<<obj.availableNitro<<std::endl;
    return out;
}

std::istream& operator>>(std::istream& in, SportCar& obj) {
    in>>(Vehicle&)obj;
    return in;
}

void SportCar::addNitro(int value) {
    if (value<0)
        throw InvalidNumber("Error: Nitro must be a positive number\n");
    availableNitro+=value;
}
