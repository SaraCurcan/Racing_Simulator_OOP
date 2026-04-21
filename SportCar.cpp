#include "SportCar.h"
#include "Exceptions.h"
#include<iostream>
#include<string>
SportCar::SportCar():Vehicle(), availableNitro(0){}
SportCar::SportCar(std::string type, std::string brand, double maxSpeed, double price, double speed, int availableNitro)
    :Vehicle(type,brand,maxSpeed,price,speed,1),availableNitro(availableNitro){}

SportCar::SportCar(const SportCar &obj):Vehicle(obj), availableNitro(obj.availableNitro){}
SportCar& SportCar::operator=(const SportCar& obj) {
    if (this!=&obj) {
        Vehicle::operator=(obj);
        availableNitro=obj.getAvailableNitro();
    }
    return *this;
}
SportCar::~SportCar(){}