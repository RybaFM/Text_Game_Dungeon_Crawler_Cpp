//
// Created by User on 23.02.2026.
//

#ifndef TEST_INVENTORY_H
#define TEST_INVENTORY_H

#include <vector>
#include <algorithm>
class Item;


class Inventory {
    std::vector<Item*> inventory;
    int inventorySize = 10;
public:
    Inventory(){};
    Inventory(int size):inventorySize(size){};
    ~Inventory();
    inline int getFreeSpace()const{return inventorySize-inventory.size();}
    inline std::vector <Item*> getInventory() const{return inventory;}
    bool addItem(Item *item);
    bool removeItem(Item *item);
    void removeAllItems();
    void clearInventory();
};

#endif //TEST_INVENTORY_H