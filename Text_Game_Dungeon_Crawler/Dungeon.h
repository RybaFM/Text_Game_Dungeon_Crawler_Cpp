//
// Created by User on 24.02.2026.
//

#ifndef TEST_DUNGEON_H
#define TEST_DUNGEON_H
#include <vector>

#include "Location.h"
#include "Room.h"

class Dungeon : public Location {
    std::vector<Room> rooms;
public:
    Dungeon();
    ~Dungeon() = default;
    void enter(Player *player);
    void interact(Player *player) override;
    bool enterRooms(Player *player);
};

#endif //TEST_DUNGEON_H