#include "Vehicle.h"
#include "Exceptions.h"
#include<iostream>
#include<string>
Vehicle::Vehicle():type(""),brand(""),speed(0.0),price(0.0),maxSpeed(0.0),level(1), acceleration(0.0){}
Vehicle::Vehicle(std::string type, std::string brand, double maxSpeed, double price, double speed, int level,double acceleration) {
    if (type.empty() || brand.empty()) {
        throw InvalidNameException();
    }
    if (maxSpeed<=0 || speed<0 || price<0 ||  acceleration<0) {
        throw InvalidNumber();
    }
    this->type=type;
    this->brand=brand;
    this->maxSpeed=maxSpeed;
    this->speed=speed;
    this->price=price;
    if (level < 1)
        this->level=1;
    else
        this->level=level;
    this->acceleration=acceleration;
}
Vehicle::Vehicle(const Vehicle& obj):type(obj.type), brand(obj.brand),maxSpeed(obj.maxSpeed),speed(obj.speed),price(obj.price),level(obj.level), acceleration(obj.acceleration){}
Vehicle& Vehicle::operator=(const Vehicle& obj) {
    if (this!=&obj) {
        this->type=obj.type;
        this->brand=obj.brand;
        this->maxSpeed=obj.maxSpeed;
        this->speed=obj.speed;
        this->price=obj.price;
        this->level=obj.level;
        this->acceleration=obj.acceleration;
    }
    return *this;
}
Vehicle::~Vehicle() {}

void Vehicle::pressBreak() {
    setSpeed(0);
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
    if (obj.type.empty()) throw InvalidNameException();   std::cout<<"Max Speed: ";
    in>>obj.maxSpeed;
    if (obj.maxSpeed<=0) throw InvalidNumber();
    in.ignore();
    return in;
}

void Vehicle::limitSpeed() {
    if (speed>maxSpeed)
        speed=maxSpeed;
    if (speed<0)
        speed=0;
}

void Vehicle::increaseMaxSpeed(double value) {
    maxSpeed+=value;
}

double Vehicle::getSpeed() const {return speed;}

void Vehicle::setSpeed(double speed) {
    this->speed=speed;
    limitSpeed();
}
double Vehicle::getAcceleration () const { return acceleration; }

void Vehicle::setAcceleration(double acceleration) {
    this->acceleration=acceleration;
}
void Vehicle::accelerate(double speed) {
    if(speed<1) {
        throw InvalidNumber("You should accelerate with a positive value\n");
    }
    setSpeed(getSpeed()+ speed*acceleration);
    limitSpeed();
}
void Vehicle::slowDown(double speed) {
    if(speed<0) {
        throw InvalidNumber("enter a positive value\n");
    }
    double newSpeed=getSpeed()-speed*acceleration;
    double finalSpeed=std::max(newSpeed,0.0);
    setSpeed(finalSpeed);
    if (finalSpeed==0.0){ pressBreak(); }
    limitSpeed();
}