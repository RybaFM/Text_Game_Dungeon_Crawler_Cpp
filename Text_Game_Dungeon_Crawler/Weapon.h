//
// Created by User on 22.02.2026.
//

#ifndef TEST_WEAPON_H
#define TEST_WEAPON_H

#include "Equipment.h"
class Player;

class Weapon: public Equipment {
    int damage;
public:
    Weapon(std::string n, int p, bool l, int d):Equipment(n, p, l), damage(d) {}
    bool use(Player *player) override;
    bool unuse(Player *player) override;
    inline int getDamage() const { return damage;}
    inline std::string info() override {
        std::string res = "Damage: "  + std::to_string(damage) + "HP";
        return res;
    };
};

#endif //TEST_WEAPON_H