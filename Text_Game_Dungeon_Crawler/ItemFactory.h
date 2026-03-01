//
// Created by User on 24.02.2026.
//

#ifndef TEST_ITEMFACTORY_H
#define TEST_ITEMFACTORY_H
#include "Item.h"
class BodyArmor;
class Helmet;
class Weapon;

class ItemFactory {
    public:
    static Item* createItem(int id);
    static Item* createPotion(int id);
    static BodyArmor* createArmorForMonster(int id);
    static Helmet* createHelmetForMonster(int id);
    static Weapon* createWeaponForMonster(int id);
};

#endif //TEST_ITEMFACTORY_H