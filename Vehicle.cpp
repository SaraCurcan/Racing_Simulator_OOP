#include "Vehicle.h"
#include "Exceptions.h"
#include<iostream>
#include<string>
Vehicle::Vehicle():type(""),brand(""),speed(0.0),price(0.0),maxSpeed(0.0){}
Vehicle::Vehicle(std::string type, std::string brand, double maxSpeed, double price, double speed) {
    if (type.empty() || brand.empty()) {
        throw InvalidNameException();
    }
    if (maxSpeed<=0 || speed<0 || price<0) {
        throw InvalidNumber();
    }
    this->type=type;
    this->brand=brand;
    this->maxSpeed=maxSpeed;
    this->speed=speed;
    this->price=price;
}
Vehicle::Vehicle(const Vehicle& obj):type(obj.type), brand(obj.brand),maxSpeed(obj.maxSpeed),speed(obj.speed),price(obj.price){}
Vehicle& Vehicle::operator=(const Vehicle& obj) {
    if (this!=&obj) {
        this->type=obj.type;
        this->brand=obj.brand;
        this->maxSpeed=obj.maxSpeed;
        this->speed=obj.speed;
        this->price=obj.price;
    }
    return *this;
}
Vehicle::~Vehicle() {}

void Vehicle::pressBreak() {
    speed=0;
}

void Vehicle::upgrade() {
    maxSpeed+=15;
}

std::string Vehicle::getType() const {return type;}
std::string Vehicle::getBrand() const {return brand;}
double Vehicle::getMaxSpeed() const {return maxSpeed;}

std::ostream& operator<<(std::ostream& out, const Vehicle& obj) {
    out<<"Brand: "<<obj.getBrand()<<std::endl;
    out<<"Type: "<<obj.getType()<<std::endl;
    out<<"Max Speed: "<<obj.getMaxSpeed()<<std::endl;
    return out;
}
std::istream& operator>>(std::istream& in , Vehicle& obj) {
    std::cout<<"Brand: ";
    getline(in,obj.brand);
    if (obj.brand.empty()) throw InvalidNameException();
    std::cout<<"Type: ";
    getline(in,obj.type);
    if (obj.type.empty()) throw InvalidNameException();
    std::cout<<"Max Speed: ";
    in>>obj.maxSpeed;
    if (obj.maxSpeed<=0) throw InvalidNumber();
    in.ignore();
    return in;
}
