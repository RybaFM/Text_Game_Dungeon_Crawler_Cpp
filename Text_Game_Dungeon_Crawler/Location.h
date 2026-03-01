//
// Created by User on 23.02.2026.
//

#ifndef TEST_LOCATION_H
#define TEST_LOCATION_H

#include <iostream>
class Player;

class Location {
protected:
    std::string name;
    Location(std::string name):name(name){};
public:
    virtual void interact(Player *player) = 0;
};

#endif //TEST_LOCATION_H