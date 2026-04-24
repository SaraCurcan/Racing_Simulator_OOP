#include "Garage.h"
#include "Vehicle.h"
#include "SportCar.h"
#include "Exceptions.h"
#include "Truck.h"
#include "Motorcycle.h"
#include<iostream>
#include<string>
#include<vector>
#include<fstream>
Garage::Garage():coins(0.0),list{} {}
Garage::Garage(double coins, const std::vector<Vehicle*>& list):coins(coins) {
    for(Vehicle* v : list) {
        this->list.push_back(v->clone());
    }
}
Garage::Garage(const Garage& obj):coins(obj.coins) {
    for(Vehicle* v : obj.list) {
        list.push_back(v->clone());
    }
}
Garage& Garage::operator=(const Garage& obj) {
if (this!=&obj) {
    for (Vehicle* v : list)
        delete v;
    list.clear();
    this->coins=obj.coins;
    for (Vehicle* v: obj.list) {
        list.push_back(v->clone());
    }
}
    return *this;
}
Garage::~Garage(){
    for (Vehicle* v : list)
        delete v;
    list.clear();
}
void Garage::Upgrade(int index) {
    if (coins>=2000) {
        Vehicle* v=list[index];
        v->applyUpgrade();
    }
    else std::cout<<"Not enough money\n";
}

void Garage::ShowOwnedVehicles() const {
    int i=1;
    for (Vehicle* v : list) {
        std::cout<<i<<". "<<*v<<std::endl;
        i++;
    }
}

void Garage::addVehicle(Vehicle *v) {
    if (v!=nullptr)
        list.push_back(v->clone());
}
double Garage::getCoins() const { return coins; }

void Garage::setcoins(double value) {
    if (value<0)
        throw InvalidNumber("Enter a positive amount of moeny\n");
    coins=value;
}

std::ostream& operator<<(std::ostream& out, const Garage& obj) {
    out<<"You have "<<obj.list.size()<<" vehicles in your garage\n";
    out<<"Money: "<<obj.coins<<std::endl;
    for (Vehicle* v : obj.list)
        out<<*v<<std::endl;
    return out;
}
std::istream& operator>>(std::istream& in, Garage& obj) {
    int vehicleNo;
    in>>vehicleNo;
    in.ignore();
    for (int i=0;i<vehicleNo;++i) {
        std::string vehicleType;
        getline(in,vehicleType);
        Vehicle *v=nullptr;
        if (vehicleType=="SportCar")
            v=new SportCar();
        else if (vehicleType=="Motorcycle")
            v=new Motorcycle();
        else if (vehicleType=="Truck")
            v=new Truck();
        if (v!=nullptr) {
            in>>*v;
            obj.addVehicle(v);
            delete v;
        }
    }
    return in;
}

bool Garage::checkVehicle(const std::string &brand, const std::string &type) {
    for (const Vehicle* v: list) {
        if (v->getBrand()==brand && v->getType()==type)
            return true;
    }
    return false;
}
Vehicle* Garage::getVehicle(int index) const {
    if (index<0||index>=list.size())
        throw MyInvalidArgument("Invalid vehicle index\n");
    return list[index];
}

int Garage::getSize() const {
    return list.size();
}

void Garage::loadDefaultVehicles(const std::string& filename) {
    if (!this->list.empty()) {
        return;
    }
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr<<"Couldn't open the file\n";
        return;
    }
    std::string vehicleType,brand,type;
    double maxSpeed,price;
    while (file>>vehicleType>>brand>>type>>maxSpeed>>price) {
        Vehicle* v=nullptr;
        if (vehicleType=="Sportcar")
            v=new SportCar(brand,type,maxSpeed,price);
        else if (vehicleType=="Motorcycle")
            v=new Motorcycle(brand,type,maxSpeed,price,0.5);
        else if (vehicleType=="Truck")
            v=new Truck(brand,type,maxSpeed,price,0.5);
        if (v!=nullptr) {
            addVehicle(v);
            delete v;
        }

    }
    file.close();
}
