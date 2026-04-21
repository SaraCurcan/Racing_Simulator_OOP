#include "Vehicle.h"
#include "Exceptions.h"
#include<iostream>
#include<string>
Vehicle::Vehicle():name(""),brand(""),speed(0.0),price(0.0),maxSpeed(0.0){}
Vehicle::Vehicle(std::string name, std::string brand, double maxSpeed, double price, double speed) {
    if (name.empty() || brand.empty()) {
        throw InvalidNameException();
    }
    if (maxSpeed<=0 || speed<0 || price<0) {
        throw InvalidNumber();
    }
    this->name=name;
    this->brand=brand;
    this->maxSpeed=maxSpeed;
    this->speed=speed;
    this->price=price;
}
Vehicle::Vehicle(const Vehicle& obj):name(obj.name), brand(obj.brand),maxSpeed(obj.maxSpeed),speed(obj.speed),price(obj.price){}
Vehicle& Vehicle::operator=(const Vehicle& obj) {
    if (this!=&obj) {
        this->name=obj.name;
        this->brand=obj.brand;
        this->maxSpeed=obj.maxSpeed;
        this->speed=obj.speed;
        this->price=obj.price;
    }
    return *this;
}
Vehicle::~Vehicle() {}