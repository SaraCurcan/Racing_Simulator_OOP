#include"Shop.h"
#include "Garage.h"
#include "SportCar.h"
#include "Motorcycle.h"
#include "Truck.h"
#include <iostream>
#include <fstream>
#include <string>
Shop::Shop():filename("Shop.txt"){}
Shop::Shop(std::string filename):filename(filename){}
Shop::Shop(const Shop& obj):filename(obj.filename){}
Shop& Shop::operator=(const Shop& obj) {
    if(this!=&obj)
        filename=obj.filename;
    return *this;
}
Shop::~Shop(){}

void Shop::showCatalog(Garage& garage){
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr<<"Couldn't open the file "<<filename<<std::endl;;
        return;
    }
    std::string vehicleType,brand,type;
    double maxSpeed, price;
    int index=0;
    std::cout<<std::endl;
    std::cout<<"                       VEHICLES SHOP                       \n";
    std::cout<<std::endl;
    while (file>>vehicleType>>brand>>type>>maxSpeed>>price) {

        std::cout<<++index<<" Vehicle Type: "<<vehicleType<<" "
        <<brand<<" "<<type<<" Max Speed: "<<maxSpeed<<" Price: "<<price<<std::endl;
        std::cout<<"---------------------------------------------------------------------\n";
    }
    file.close();
    std::cout<<"Enter the number of the vehicle you want to buy!\n";
    std::string value;
    std::cin>>value;
    try {
        int choice = std::stoi(value);
        if (choice>=1 && choice<=index) {
           buyVehicle(choice,garage);
        }
        else std::cout<<"Enter a valid number between 1 and "<<index<<std::endl;
    }
    catch (...) {std::cout<<"Please enter a valid number!\n";}
}

void Shop::buyVehicle(int index, Garage &garage) {
    std::ifstream file(filename);
    if (!file.is_open()) {
        std::cerr<<"Couldn't open the file "<<filename<<std::endl;;
        return;
    }
    std::string vehicleType,brand,type;
    double maxSpeed, price;
    int currentIndex=1;
    while (file>>vehicleType>>brand>>type>>maxSpeed>>price) {
        if (index==currentIndex) {
            if (garage.checkVehicle(brand,type)) {
                std::cout<<"You already own this vehicle!\n";
                return;
            }
            if (garage.getCoins()<price) {
                std::cout<<"Sorry! Not enough money!\n";
                return;
            }
            garage.setcoins(garage.getCoins()-price);
            Vehicle* v=nullptr;
            if (vehicleType=="SportCar")
                v=new SportCar(brand,type,maxSpeed,price);
            else if (vehicleType=="Motorcycle")
                v=new Motorcycle(brand,type,maxSpeed,price,0.1);
            else if (vehicleType=="Truck")
                v=new Truck(brand,type,maxSpeed,price,0.1);

            if (v!=nullptr) {
                garage.addVehicle(v);
                delete v;
                std::cout<<"Congrats! You purchased "<<brand<<" "<<type<<std::endl;
            }
            return;
        }
        currentIndex++;
    }
}
