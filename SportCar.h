#pragma once
#include "Vehicle.h"
#include "Exceptions.h"
#include<iostream>
#include<string>

class SportCar : public Vehicle {
private:
    static int availableNitro;
    void applyNitro();
public:
    SportCar();
    SportCar(std::string brand, std::string type, double maxSpeed, double price);
    SportCar(const SportCar& obj);
    SportCar& operator=(const SportCar& obj);
    virtual ~SportCar()=default;
    void applyUpgrade() override;
    void ability() override;
    void drift();
    int getAvailableNitro() const;
    friend std::ostream& operator<<(std::ostream& out,const SportCar& obj);
    friend std::istream& operator>>(std::istream& in, SportCar& obj);
    void addNitro(int value);
    void print(std::ostream& out)const override;
    Vehicle* clone() const override {
        return new SportCar(*this);
    };
    virtual void load(std::istream& in) override;
    virtual void save(std::ostream& out) const override;
};