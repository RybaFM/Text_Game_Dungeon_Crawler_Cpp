//
// Created by User on 23.02.2026.
//

#ifndef TEST_POTION_H
#define TEST_POTION_H

#include "Item.h"
class Player;

class Potion: public Item {
    int heal;
    public:
    Potion(std::string name, int price, bool legendary, int heal):Item(name, price, legendary), heal(heal){}
    inline std::string info() override {
        std::string res = "Heals: "  + std::to_string(heal) + "HP";
        return res;
    };
    bool use(Player *player) override;
};

#endif //TEST_POTION_H