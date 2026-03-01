//
// Created by User on 22.02.2026.
//

#ifndef TEST_MONSTER_H
#define TEST_MONSTER_H

#include <vector>
#include <algorithm>
#include <iostream>

#include "Inventory.h"
class Player;
class Helmet;
class BodyArmor;
class Weapon;
class Item;


class Monster {
    std::string name;
    int hp = 100;
    int damage = 15;
    int speed = 15;
    double protection = 0;
    Helmet *helmet = nullptr;
    BodyArmor *bodyArmor = nullptr;
    Weapon *weapon = nullptr;
    Inventory inventory;
    bool isAlive = true;
public:
    Monster() = default;
    Monster(std::string name, int hp, int damage, int speed, Helmet *helmet, BodyArmor *bodyArmor, Weapon *weapon);
    ~Monster();
    bool takeDamage(int damage);
    void makeHit(Player *player);
    void die();
    std::vector<Item*> inspectBody(){return inventory.getInventory();}
    std::vector<Item*> lootEverything();
    bool lootItem(Item *item);
    inline std::string getName() const {return name;}
    inline bool isDead()const{return !isAlive;}
    inline int getHP()const {return hp;}
    inline double getSpeed()const{return speed;}
};

#endif //TEST_MONSTER_H