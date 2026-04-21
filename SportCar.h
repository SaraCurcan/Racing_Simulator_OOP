#pragma once
#include "Vehicle.h"
#include "Exceptions.h"
#include<iostream>
#include<string>

class SportCar : public Vehicle {
private:
    int availableNitro;
    void applyNitro();
public:
    SportCar();
    SportCar(std::string type, std::string brand, double maxSpeed, double price, double speed, int availableNitro);
    SportCar(const SportCar& obj);
    SportCar& operator=(const SportCar& obj);
    void accelerate(double speed) override;
    void upgrade() override;
    void slowDown(double speed) override;
    void ability() override;
    void drift();
    int getAvailableNitro() const;
    friend std::ostream& operator<<(std::ostream& out,const SportCar& obj);
    friend std::istream& operator>>(std::istream& in, SportCar& obj);

};