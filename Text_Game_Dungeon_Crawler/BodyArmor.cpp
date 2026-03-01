#include "BodyArmor.h"
#include "Player.h"

bool BodyArmor::use(Player *player) {
    return player->wearBodyArmor(this);
}
bool BodyArmor::unuse(Player *player) {
    return player->takeOffBodyArmor();
}