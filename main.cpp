#include "Vehicle.h"
#include "Garage.h"
#include "Shop.h"
#include "Race.h"
#include "Exceptions.h"
#include<iostream>
#include<string>
#include<cstdlib>
#include<ctime>
#include<fstream>
void GoToGarage(Garage& garage) {
    while (true) {
        std::cout<<"Money: "<<garage.getCoins()<<std::endl;
        std::cout<<std::endl;
        std::cout<<"0. Exit\n";
        std::cout<<"1. Show vehicles\n";
        std::cout<<"2. Upgrade: price 2000\n";
        std::string choice;
        std::cin>>choice;
        try {
            if (choice=="1")
                garage.ShowOwnedVehicles();
            else if (choice=="2") {
                garage.ShowOwnedVehicles();
                std::cout<<"Choose a vehicle to upgrade\n";
                int index;
                std::cin>>index;
                if (index<=0||index>garage.getSize())
                    throw InvalidNumber("Invalid Index\n");
                garage.Upgrade(index-1);
            }
            else if (choice=="0") break;
            else std::cout<<"Invalid option\n";
        }
        catch (const std::exception& e) {
            std::cout<<"Error: "<<e.what();
        }
    }
}

int main() {
    srand(time(0));
    Garage garage;
    Shop shop;
    Race race(&garage);
    std::string choice;
    std::ifstream file("save.txt");
    if (file.is_open()) {
        garage.load(file);
        file.close();
    }
    else {
        garage.setcoins(10000);
        garage.loadDefaultVehicles("Garage.txt");
    }
    while (choice!="0") {
        std::cout<<"0. EXIT\n";
        std::cout<<"1. GO TO GARAGE\n";
        std::cout<<"2. SHOP\n";
        std::cout<<"3. START RACE\n";
        std::cout<<"4. SAVE GAME\n";
        std::cin>>choice;

        try{
            if (choice=="0") {
                std::cout<<"BYE\n";
            }
            else if (choice=="1") GoToGarage(garage);
            else if (choice=="2") shop.showCatalog(garage);
            else if (choice=="3") {
                race.chooseCar(garage);
                race.racing();
            }
            else if (choice=="4") {
                std::ofstream file("save.txt");
                garage.save(file);
                file.close();
                std::cout<<"Progress saved\n";
            }
            else std::cout<<"Invalid option\n";
        }
        catch (const MyInvalidArgument& e)
        {std::cout<<e.what();;}
        catch (const InvalidNumber& e) {
            std::cout<<e.what();;
        }
        catch (const InvalidNameException& e) {
            std::cout<<e.what();
        }
        catch (const std::exception& e) {
            std::cout<<"Error "<<e.what();
        }
    }
    return 0;
}