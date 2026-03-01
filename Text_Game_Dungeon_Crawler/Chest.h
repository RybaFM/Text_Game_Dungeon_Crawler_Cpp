//
// Created by User on 28.02.2026.
//

#ifndef TEST_CHEST_H
#define TEST_CHEST_H
#include "Inventory.h"
#include <iostream>
#include <vector>

class Chest {
    std::string name;
    Inventory inventory;
public:
    Chest(std::string name);
    std::string getName(){return name;};
    std::vector<Item*> getLoot()const {return inventory.getInventory();};
    bool lootItem(Item *item);
};

#endif //TEST_CHEST_H