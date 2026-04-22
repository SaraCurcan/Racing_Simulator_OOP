#pragma once
#include<iostream>
#include<string>
class Vehicle {
private:
    double price;
    double speed;
    double maxSpeed;
protected:
    int level=1;
    std::string type;
    std::string brand;
    double acceleration;
    virtual void accelerate(double speed);
    virtual void slowDown(double speed);
    virtual void ability()=0;
    void limitSpeed();
    void pressBreak();
    void increaseMaxSpeed(double value);
    void setAcceleration(double acceleration);
public:
    Vehicle();
    Vehicle(std::string brand, std::string type, double maxSpeed, double price, double speed, int level, double acceleration);
    Vehicle(const Vehicle& obj);
    Vehicle& operator=(const Vehicle& obj);
    virtual ~Vehicle();
    friend std::istream& operator>>(std::istream& in, Vehicle& obj);
    friend std::ostream& operator<<(std::ostream& out, const Vehicle& obj);
    double getSpeed() const;
    void setSpeed(double speed);
    double getAcceleration() const;
    std::string getType() const;
    std::string getBrand() const;
    double getMaxSpeed() const;
    virtual void applyUpgrade()=0;
    void upgradetMaxSpeed(double value);
    bool isMaxLevel() const;
    double getPrice() const;
    void setPrice(double value);
    virtual void print(std::ostream& out) const =0;
    virtual Vehicle* clone() const =0;
};