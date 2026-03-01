#include "Helmet.h"
#include "Player.h"

bool Helmet::use(Player *player) {
    return player->wearHelmet(this);
}
bool Helmet::unuse(Player *player) {
    return player->takeOffHelmet();
}