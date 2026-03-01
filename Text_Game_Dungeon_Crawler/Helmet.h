//
// Created by User on 22.02.2026.
//

#ifndef TEST_HELMET_H
#define TEST_HELMET_H

#include "Armor.h"
class Player;

class Helmet: public Armor {

public:
    Helmet(std::string name, int price, bool legendary, double protection):Armor(name, price, legendary, protection){}
    bool use(Player *player) override;
    bool unuse(Player *player) override;
};

#endif //TEST_HELMET_H