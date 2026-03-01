//
// Created by User on 23.02.2026.
//

#include "Inventory.h"

#include "Equipment.h"

Inventory::~Inventory()  {
    for (Item *item : inventory) {
        delete item;
    }
    inventory.clear();
}

bool Inventory::addItem(Item *item) {
    if (getFreeSpace() > 0) {
        inventory.push_back(item);
        return true;
    }
    return false;
}
bool Inventory::removeItem(Item *item) {
    auto it = std::find(inventory.begin(), inventory.end(), item);
    if (it != inventory.end()) {
        inventory.erase(it);
        return true;
    }
    return false;
}
void Inventory::removeAllItems() {
    inventory.clear();
}

void Inventory::clearInventory() {
    for (Item *item : inventory) {
        delete item;
    }
    inventory.clear();
}
