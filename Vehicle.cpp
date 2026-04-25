#include "Vehicle.h"
#include "Exceptions.h"
#include<iostream>
#include<string>
Vehicle::Vehicle():type(""),brand(""),speed(0.0),price(0.0),maxSpeed(0.0),level(1), acceleration(0.0){}
Vehicle::Vehicle(std::string brand, std::string type, double maxSpeed, double price, double speed, int level,double acceleration) {
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
    obj.print(out);
    return out;
}
std::istream& operator>>(std::istream& in , Vehicle& obj) {
    getline(in,obj.brand);
    if (obj.brand.empty()) throw InvalidNameException();
    getline(in,obj.type);
    if (obj.type.empty()) throw InvalidNameException();
    std::string input;
    in>>input;
    try {
        obj.maxSpeed=std::stod(input);
        if (obj.maxSpeed<0) throw InvalidNumber();
    }
    catch (const std::exception& e) {
        throw MyInvalidArgument("A number is expected\n");
    }
    in>>obj.price;
    if (obj.price<0) throw InvalidNumber();
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
    if(speed<0) {
        throw InvalidNumber("You should accelerate with a positive value\n");
    }
    setSpeed(getSpeed()+ speed*acceleration);
    limitSpeed();
}
void Vehicle::slowDown(double speed) {
    if(speed<0) {
        throw InvalidNumber();
    }
    double newSpeed=getSpeed()-speed*acceleration;
    double finalSpeed=std::max(newSpeed,0.0);
    setSpeed(finalSpeed);
    if (finalSpeed==0.0){ pressBreak(); }
    limitSpeed();
}
void Vehicle::upgradetMaxSpeed(double value) {
    if (value<=0) {
        throw InvalidNumber("Error: Upgrade value must be positive\n");
    }
    maxSpeed+=value;
}

bool Vehicle::isMaxLevel() const {
        if (level >= 10) {
            std::cout << brand << " " << type << " reached max level\n";
            return true;
        }
        return false;
}

double Vehicle::getPrice() const {return price;}
void Vehicle::setPrice(double value) {
    if (value<0) throw InvalidNumber("Enter a positive price\n");
    price=value;
}
void Vehicle::print(std::ostream& out) const {}

void Vehicle::accelerateAction() { accelerate(acceleration); }
void Vehicle::slowDownAction() { slowDown(acceleration); }
void Vehicle::useAbility() { ability(); }
void Vehicle::pressBreakAction() { pressBreak();}

void Vehicle::setMaxSpeed(double value) {
    if (value<0)
        throw InvalidNumber();
    maxSpeed=value;
}

void Vehicle::save(std::ostream &out) const {
    out<<brand<<"\n";
    out<<type<<"\n";
    out<<maxSpeed<<"\n";
    out<<speed<<"\n";
    out<<price<<"\n";
    out<<level<<"\n";
    out<<acceleration<<"\n";
}
void Vehicle::load(std::istream& in) {
    std::getline(in>>std::ws,brand);
    std::getline(in,type);
    in>>maxSpeed;
    in>>speed;
    in>>price;
    in>>level;
    in>>acceleration;
    in.ignore();


}
