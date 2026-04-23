#include"Shop.h"
#include "Garage.h"
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

void Shop::showCatalog() const {
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
}
