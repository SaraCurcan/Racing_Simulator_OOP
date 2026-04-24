#include"Shop.h"
#include "Race.h"
#include "Garage.h"
#include "SportCar.h"
#include "Motorcycle.h"
#include "Truck.h"
#include <iostream>
#include <fstream>
#include <string>
#include<cmath>

Race::Race(Garage* g):playerVehicle(nullptr), opponent(nullptr),weather(Weather::sunny),DistanceUntilFinish(200),garage(g){}
Race::Race(Weather w,Garage* g):playerVehicle(nullptr),opponent(nullptr),weather(w),DistanceUntilFinish(200),garage(g){}
Race::Race(const Race& obj):playerVehicle(nullptr),opponent(nullptr),weather(obj.weather),DistanceUntilFinish(obj.DistanceUntilFinish),garage(obj.garage) {
    if (obj.playerVehicle!=nullptr)
        playerVehicle=obj.playerVehicle->clone();
    if (obj.opponent!=nullptr)
        opponent=obj.opponent->clone();
}
Race& Race::operator=(const Race& obj) {
    if (this!=&obj) {
        delete playerVehicle;
        delete opponent;
        playerVehicle=nullptr;
        opponent=nullptr;
        weather=obj.weather;
        DistanceUntilFinish=obj.DistanceUntilFinish;
        garage=obj.garage;
        if (obj.playerVehicle)
            playerVehicle=obj.playerVehicle->clone();
        if (obj.opponent)
            opponent=obj.opponent->clone();
    }
    return *this;
}
Race::~Race() {
    delete playerVehicle;
    delete opponent;
}

void Race::createOpponent() {
    if (opponent) {
        delete opponent;
    }
    opponent=nullptr;
    int random=rand()%3;
    if (random==0)
        opponent=new SportCar("AUDI","R8",200,2000);
    else if (random==1)
        opponent=new Motorcycle("Suzuki","Hayabusa",230,2700,0.4);
    else if (random==2)
        opponent=new Truck("Toyota","Land_Cruiser",170,1800,0.4);
}
double Race::weatherBehavior(Vehicle* v) {
    double change=1;
    bool isSportCar=dynamic_cast<SportCar*>(v);
    bool isMotor=dynamic_cast<Motorcycle*>(v);
    bool istruck=dynamic_cast<Truck*>(v);
    switch (weather) {
        case Weather::sunny:
            change=1.0;
            break;
        case Weather::rainy:
            if (isSportCar) change=0.80;
            else if (isMotor) change=0.65;
            else if (istruck) change=1;
            break;
        case Weather::snowy:
            if (isSportCar) change=0.7;
            else if (isMotor) change=0.65;
            else if (istruck) change=0.9;
            break;
        case Weather::ice:
            if (isSportCar) change=0.55;
            else if (isMotor) change=0.30;
            else if (istruck) change=0.75;
            break;
    }
    return change;
}

void Race::generateWeather() {
    int random=rand()%4;
    switch (random) {
        case 0: weather=Weather::sunny; break;
        case 1: weather=Weather::rainy;break;
        case 2: weather=Weather::snowy;break;
        case 3: weather=Weather::ice;break;
    }
    std::cout<<"Weather condition: ";
    switch (weather) {
        case Weather::sunny: std::cout<<"Sunny ☀️\n";break;
        case Weather::snowy: std::cout<<"Snowy ❄️\n";break;
        case Weather::rainy: std::cout<<"Rainy 🌧️\n";break;
        case Weather::ice: std::cout<<"Ice 🧊\n";break;
    }
    std::cout<<"Weather condition can affect your speed\n\n";
}

void Race::chooseCar(Garage &garage) {
    garage.ShowOwnedVehicles();
    std::cout<<"Choose a vehicle index:\n";
    std::string choice;
    std::cin>>choice;
    for (char c : choice) {
        if (!isdigit(c)) {
            throw MyInvalidArgument("Please introduce a number\n");
        }
    }
    int index;
    try {
        index=std::stoi(choice);
    }
    catch (...) {
        throw MyInvalidArgument("Index out of range!\n");
    }
    index--;
    if (index<0 || index>=garage.getSize())
        throw InvalidNumber("Index out of range!\n");
    if (playerVehicle)
    delete playerVehicle;
    playerVehicle=garage.getVehicle(index)->clone();
}
void Race::racing() {
    if (!playerVehicle) {
        std::cout<<"NO vehicle selected\n";
        return;
    }
    if (!opponent)
    createOpponent();
    double playerDistance=0;
    double opponentDistance=0;
    generateWeather();
    while (true) {
        if (playerDistance>=DistanceUntilFinish || opponentDistance>=DistanceUntilFinish) break;
        printRace(playerDistance,opponentDistance);
        std::cout<<"1. Accelerate\n";
        std::cout<<"2. SlowDown\n";
        std::cout<<"3. Use ability\n";
        std::cout<<"4. Press break\n";
        std::string choice;
        std::cin>>choice;
        if (choice!="1" && choice!="2" && choice!="3" && choice!="4")
            {std::cout<<"Invalid choice";
            continue;}
        if (choice=="1") {
            playerVehicle->accelerateAction();
        }
        else if (choice=="2") {
            playerVehicle->slowDownAction();
        }
        else if (choice=="3") {
            playerVehicle->useAbility();
        }
        else if (choice=="4") {
            playerVehicle->pressBreakAction();
        }
        int number=rand()%10;
        double difference=opponentDistance-playerDistance;
        if (difference>20) {
            if (number<7)
                opponent->slowDownAction();
            else
                opponent->accelerateAction();
        }
        else if (opponent->getSpeed()<playerVehicle->getSpeed()) {
            opponent->accelerateAction();
        }
        else {
            if (number<6)
                opponent->accelerateAction();
            else
                opponent->slowDownAction();
        }
            double playerSpeed=playerVehicle->getSpeed()+playerVehicle->getAcceleration();
            double opponentSpeed=opponent->getSpeed()+opponent->getAcceleration();
            playerSpeed=playerSpeed*weatherBehavior(playerVehicle);
            opponentSpeed=opponentSpeed*weatherBehavior(opponent);
            playerDistance+=playerSpeed;
            opponentDistance+=opponentSpeed;

    }
    printRace(playerDistance,opponentDistance);
    if (playerDistance>=DistanceUntilFinish) {
        std::cout<<"YOU WON!\n";
        garage->setcoins(garage->getCoins()+1000);
        std::cout<<"+1000 coins\n";
    }
    else std::cout <<"YOU LOST!\n";
}

std::string Race::getEmoji(Vehicle *v) {
    if (dynamic_cast<SportCar*>(v)) return "🏎️";
    if (dynamic_cast<Motorcycle*>(v)) return "🏍️";
    if (dynamic_cast<Truck*>(v)) return "🚚";
    return "🚗";
}

void Race::printRace(double playerDistance, double opponentDistance) {
    const int size=50;
    int p=(playerDistance/DistanceUntilFinish)*size;
    int o=(opponentDistance/DistanceUntilFinish)*size;
    if (p>=size) p=size-1;
    if (o>=size) o=size-1;
    std::string playerEmoji=getEmoji(playerVehicle);
    std::string opponentEmoji=getEmoji(opponent);
    std::cout<<std::endl;
    for (int i=0;i<size;i++) {
        if (i==p)
            std::cout<<playerEmoji;
        else std::cout<<".";
    }
    std::cout<<"You\n";
    for (int i=0;i<size;i++) {
        if (i==o)
            std::cout<<opponentEmoji;
        else std::cout<<".";
    }
    std::cout<<"Enemy\n";
}
