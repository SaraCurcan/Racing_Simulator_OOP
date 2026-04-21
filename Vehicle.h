#pragma once
#include<iostream>
#include<string>
class Vehicle {
private:
    double price;
    double speed;
protected:
    std::string type;
    std::string brand;
    double maxSpeed;
    virtual void accelerate(double speed)=0;
    virtual void slowDown(double speed)=0;
    virtual void ability()=0;
    virtual void upgrade()=0;
    void limitSpeed();
    void pressBreak();
public:
    Vehicle();
    Vehicle(std::string type, std::string brand, double maxSpeed, double price, double speed);
    Vehicle(const Vehicle& obj);
    Vehicle& operator=(const Vehicle& obj);
    virtual ~Vehicle();
    friend std::istream& operator>>(std::istream& in, Vehicle& obj);
    friend std::ostream& operator<<(std::ostream& out, const Vehicle& obj);
    std::string getType() const;
    std::string getBrand() const;
    double getMaxSpeed() const;

};