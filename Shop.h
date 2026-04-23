#pragma once
#include <iostream>
#include <string>
class Shop {
private:
    std::string filename;
public:
    Shop();
    Shop(std::string filename);
    Shop(const Shop& obj);
    Shop& operator=(const Shop& obj);
    ~Shop();
    void showCatalog() const;
    void buyVehicle();
    friend std::ostream& operator<<(std::ostream& out,const Shop& obj);
    friend std::istream& operator>>(std::istream& in, Shop& obj);
};