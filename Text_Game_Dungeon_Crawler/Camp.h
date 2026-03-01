#ifndef TEST_CAMP_H
#define TEST_CAMP_H

#include "DoctorHouse.h"
#include "Location.h"
#include "Shop.h"
class Player;
class Dungeon;

class Camp : public Location {
    //DoctorHouse doctorHouse;
    //Shop shop;
public:
    Camp():Location("Hero Camp") {};//, doctorHouse()
    void interact(Player *player) override;
    void enter(Player *player);
    void aboutLegendaryItems(Player *player);
};

#endif //TEST_CAMP_H