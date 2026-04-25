#pragma once
#include "Vehicle.h"
#include<iostream>
#include<string>
class Truck: public Vehicle {
private:
    double stability;
    static int stabilityUses;
    void handling();
public:
    Truck();
    Truck(std::string brand, std::string type, double maxSpeed, double price, double stability);
    Truck(const Truck& obj);
    Truck& operator=(const Truck& obj);
    virtual ~Truck()=default;
    double getStability() const;
    void setStability(double value);
    int getStabilityUses() const;
    void addStabilityUses(int value);
    void applyUpgrade() override;
    void ability() override;
    friend std::ostream& operator<<(std::ostream& out, const Truck& obj);
    friend std::istream& operator>>(std::istream& in, Truck& obj);
    void print(std::ostream& out)const override;
    Vehicle* clone() const override {
        return new Truck(*this);
    };
    virtual void load(std::istream& in) override;
    virtual void save(std::ostream& out) const override;
};