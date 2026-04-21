#include "SportCar.h"
#include "Exceptions.h"
#include<iostream>
#include<string>
SportCar::SportCar():Vehicle(), availableNitro(0){}
SportCar::SportCar(std::string type, std::string brand, double maxSpeed, double price, double speed,int availableNitro)
    :Vehicle(type,brand,maxSpeed,price,speed,1,0.4),availableNitro(availableNitro){}

SportCar::SportCar(const SportCar &obj):Vehicle(obj), availableNitro(obj.availableNitro){}
SportCar& SportCar::operator=(const SportCar& obj) {
    if (this!=&obj) {
        Vehicle::operator=(obj);
        availableNitro=obj.getAvailableNitro();
    }
    return *this;
}
SportCar::~SportCar(){}

int SportCar::getAvailableNitro() const { return availableNitro; }

void SportCar::setAvailableNitro(int availableNitro) { this->availableNitro=availableNitro; }

void SportCar::applyUpgrade() {
    level+=1;
    acceleration+=0.1;
}

void SportCar::accelerate(double speed) { setSpeed(getSpeed() + speed*acceleration); limitSpeed(); }

void SportCar::slowDown(double speed) { setSpeed(getSpeed() - speed*acceleration); limitSpeed(); }

void SportCar::applyNitro() {
    if (availableNitro>0) {
        std::cout<<"Nitro applied "<<std::endl;
        setSpeed(getSpeed() + 100*acceleration);
        setAvailableNitro(getAvailableNitro()-1);
    }
    else std::cout<<"No more available nitro "<<std::endl;
}
void SportCar::ability() {
    applyNitro();
}