#ifndef TEST_ARMOR_H
#define TEST_ARMOR_H

#include <iostream>
#include "Equipment.h"
#include <cmath>
class Player;

class Armor: public Equipment {

protected:
    double protection;
    Armor(std::string name, int price, bool legendary, double protection):Equipment(name, price, legendary), protection(protection){}
public:
    virtual ~Armor(){}
    double getProtection() const {return protection;}
    inline std::string info() override {
        std::string res = "Protection: "  + std::to_string((int)std::round(protection * 100)) + "%";
        return res;
    };
};

#endif //TEST_ARMOR_H