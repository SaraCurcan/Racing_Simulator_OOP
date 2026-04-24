#pragma once
#include "Vehicle.h"
#include<string>
#include<iostream>
enum class Weather {sunny,rainy, snowy,ice};
class Garage;
class Race {
private:
    Vehicle* playerVehicle;
    Vehicle* opponent;
    Weather weather;
    double DistanceUntilFinish;
    Garage* garage;
    void createOpponent();
    double weatherBehavior(Vehicle* v);
public:
    Race(Garage* g);
    Race(Weather w,Garage* g);
    Race(const Race& obj);
    Race& operator=(const Race& obj);
    ~Race();
    void racing();
    void chooseCar(Garage& garage);
    void printRace(double playerDistance, double opponentDistance);
    std::string getEmoji(Vehicle* v);
    void generateWeather();
};