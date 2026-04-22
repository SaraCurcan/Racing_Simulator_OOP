#include "Garage.h"
#include<iostream>
#include<string>
#include<vector>
Garage::Garage():coins(0.0),list{} {}
Garage::Garage(double coins, const std::vector<Vehicle*>& list):coins(coins) {
    for(Vehicle* v : list) {
        this->list.push_back(v->clone());
    }
}
Garage::Garage(const Garage& obj):coins(coins) {
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