//
// Created by User on 23.02.2026.
//

#ifndef TEST_SHOP_H
#define TEST_SHOP_H

#include <vector>

#include "Item.h"
#include "Location.h"

class Shop:public Location {
public:
    Shop():Location("Shop"){};
    ~Shop() = default;
    void enter(Player *player);
    void interact(Player *player) override;
    void buyMenu(Player *player);
    void sellItemToPlayer(Player *player, Item *item);
    void sellMenu(Player *player);
};

#endif //TEST_SHOP_H