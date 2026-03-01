//
// Created by User on 22.02.2026.
//

#ifndef TEST_BODYARMOR_H
#define TEST_BODYARMOR_H

#include "Armor.h"
class Player;

class BodyArmor: public Armor {

public:
    BodyArmor(std::string name, int price, bool legendary, double protection):Armor(name, price, legendary, protection){}
    bool use(Player *player) override;
    bool unuse(Player *player) override;
};

#endif //TEST_BODYARMOR_H