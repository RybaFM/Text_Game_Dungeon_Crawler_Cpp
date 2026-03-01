//
// Created by User on 23.02.2026.
//

#include "Potion.h"
#include "Player.h"

bool Potion::use(Player *player) {
    return player->usePotion(this, heal);
}