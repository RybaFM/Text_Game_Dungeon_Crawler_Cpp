//
// Created by User on 28.02.2026.
//

#include "Chest.h"
#include <random>

#include "ItemFactory.h"
#include "BodyArmor.h"
#include "Weapon.h"

static int randomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

Chest::Chest(std::string name):name(name), inventory(50) {
    if (name == "Common chest") {
        int temp = randomInt(0, 7);
        if (temp == 2){temp = 11;}
        inventory.addItem(ItemFactory::createItem(temp));
    }
    else if (name == "Rare chest") {
        int temp = randomInt(0, 4);
        int temp2 = randomInt(0, 4);
        if (temp == 3){temp = 2;}
        if (temp == 1){temp = 0;}
        if (temp2 == 3){temp2 = 2;}
        if (temp2 == 1){temp2 = 0;}
        inventory.addItem(ItemFactory::createArmorForMonster(temp));
        inventory.addItem(ItemFactory::createWeaponForMonster(temp2));
    }
    else if (name == "Legendary chest") {
        int temp = randomInt(0, 7);
        int temp2 = randomInt(0, 7);
        inventory.addItem(ItemFactory::createArmorForMonster(temp));
        inventory.addItem(ItemFactory::createWeaponForMonster(temp2));
    }
}
bool Chest::lootItem(Item *item) {
    return inventory.removeItem(item);
}
