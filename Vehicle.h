#pragma once
#include<iostream>
#include<string>
class Vehicle {
private:
    double price;
    double speed;
protected:
    std::string name;
    std::string brand;
    double maxSpeed;
    virtual void accelerate(double speed)=0;
    virtual void slowDown(double speed)=0;
    void pressBreak(double speed);
public:
    Vehicle();
    Vehicle(std::string name, std::string brand, double maxSpeed, double price, double speed);
    Vehicle(const Vehicle& obj);
    Vehicle& operator=(const Vehicle& obj);
    virtual ~Vehicle();
    void upgrade();
    friend istream& operator>>(istream& in, Vehicle& obj);
    friend ostream& operator<<(ostream& out, const Vehicle& obj);

};