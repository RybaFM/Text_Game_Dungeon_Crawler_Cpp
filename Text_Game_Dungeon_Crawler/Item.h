//
// Created by User on 22.02.2026.
//

#ifndef TEST_ITEM_H
#define TEST_ITEM_H
#include <string>
class Player;
class Monster;

class Item {
    std::string name;
    int price;
    bool legendary;
public:
    Item(std::string n, int p, bool legendary):name(n), price(p), legendary(legendary){}
    virtual ~Item() {}
    virtual bool use(Player *player) = 0;
    inline std::string getName() const {return name;}
    inline int getPrice() const {return price;}
    inline bool isLegendary() const {return legendary;}
    virtual std::string info() = 0;
};

#endif //TEST_ITEM_H