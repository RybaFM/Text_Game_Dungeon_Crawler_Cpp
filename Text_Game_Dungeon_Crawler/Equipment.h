//
// Created by User on 23.02.2026.
//

#ifndef TEST_EQUIPMENT_H
#define TEST_EQUIPMENT_H

#include <iostream>
#include "Item.h"
class Player;

class Equipment: public Item {

protected:
    Equipment(std::string name, int price, bool legendary):Item(name, price, legendary){}
public:
    virtual ~Equipment() {}
    virtual bool unuse(Player *player) = 0;
};

#endif //TEST_EQUIPMENT_H