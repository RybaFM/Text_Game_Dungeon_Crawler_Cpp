//
// Created by User on 23.02.2026.
//

#ifndef TEST_STUFF_H
#define TEST_STUFF_H
#include "Item.h"

class Stuff:public Item {
    public:
    Stuff(std::string name, int price, bool legendary):Item(name, price, legendary){};
    bool use(Player *player)override{return true;}
    std::string info()override{return "Stuff";}
};

#endif //TEST_STUFF_H