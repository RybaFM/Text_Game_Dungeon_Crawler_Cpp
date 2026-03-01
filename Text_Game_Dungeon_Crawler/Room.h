//
// Created by User on 24.02.2026.
//

#ifndef TEST_ROOM_H
#define TEST_ROOM_H

#include "Location.h"
#include "Monster.h"
#include "Chest.h"

class Room:public Location {
    Monster *monster;
    Chest *chest;
public:
    Room(std::string name);
    ~Room() { delete monster;delete chest; };
    int enter(Player *player, int number, int size);
    void interact(Player *player) override;
    std::string getName(){return name;};
    void generateMonsterAndChest();
    void openChest(Player *player);
    void inspectMonster(Player *player);
    int fight(Player *player, Monster *monster);
};

#endif //TEST_ROOM_H