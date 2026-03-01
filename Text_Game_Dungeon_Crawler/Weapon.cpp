//
// Created by User on 22.02.2026.
//

#include "Weapon.h"
#include "Player.h"

bool Weapon::use(Player *player) {
    return player->wearWeapon(this);
}
bool Weapon::unuse(Player *player) {
    return player->takeOffWeapon();
}