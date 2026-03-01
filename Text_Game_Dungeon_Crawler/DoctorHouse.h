#ifndef TEST_DOCTORHOUSE_H
#define TEST_DOCTORHOUSE_H

#include "Item.h"
#include "Location.h"

class DoctorHouse:public Location {
public:
    DoctorHouse():Location("Doctor's House"){};
    ~DoctorHouse() = default;
    void enter(Player *player);
    void interact(Player *player) override;
    void buyPotions(Player *player);
    void sellPotionToPlayer(Player *player, Item *item);
};

#endif //TEST_DOCTORHOUSE_H