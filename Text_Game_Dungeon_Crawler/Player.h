//
// Created by User on 22.02.2026.
//

#ifndef TEST_PLAYER_H
#define TEST_PLAYER_H


#include <vector>
#include <algorithm>
#include <memory>
#include <cmath>

class Item;
class Monster;
class Helmet;
class BodyArmor;
class Weapon;
class Equipment;
class Location;
class Potion;
#include "Inventory.h"
class Chest;


class Player {
    int level = 1;
    int hp = 50;
    int money = 0;
    int damage = 5;
    double protection = 0;
    Inventory inventory;
    Helmet *helmet = nullptr;
    BodyArmor *bodyArmor = nullptr;
    Weapon *weapon = nullptr;

public:
    ~Player();
    bool makeHit(Monster *monster);
    void takeDamage(int damage);
    inline void healHp(int hp) {this->hp += hp; if (this->hp>100) this->hp=100;}
    inline int getFreeSpace()const{return inventory.getFreeSpace();}
    inline int getMoney() const {return money;}
    inline int getHp() const {return hp;}
    inline double getProtection() const {return protection;}
    inline int getDamage() const {return damage;}
    inline bool subtractMoney(int price) {money -= price;return true;}
    inline bool addMoney(int price) {money += price;return true;}
    inline void updateLevel(){level++;}
    bool takeOutFromInventory(Item *item);
    inline std::vector <Item*> getInventory()const {return inventory.getInventory();}
    std::vector <Equipment*> getEquipment() const;
    void openInventory();

    bool sellItem(Item *item);
    bool takeItemFromMonster(Item *item, Monster *monster);
    bool takeItemFromChest(Item *item, Chest *chest);
    bool putInInventory(Item *item);
    bool wearHelmet(Helmet *helmet);
    bool wearBodyArmor(BodyArmor *bodyArmor);
    bool wearWeapon(Weapon *weapon);
    bool usePotion(Potion *potion, int heal);
    bool takeOffHelmet();
    bool takeOffBodyArmor();
    bool takeOffWeapon();

    void die();

};

#endif //TEST_PLAYER_H