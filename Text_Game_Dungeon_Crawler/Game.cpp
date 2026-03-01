//
// Created by User on 23.02.2026.
//

#include "Game.h"
#include "Weapon.h"
#include "BodyArmor.h"
#include "Item.h"
#include "Stuff.h"
#include "ItemFactory.h"

void Game::start() {
    Item *bodyArmor = ItemFactory::createItem(0);
    Item *knife = ItemFactory::createItem(1);
    Item *stuff = ItemFactory::createItem(2);
    player.putInInventory(bodyArmor);
    player.putInInventory(knife);
    player.putInInventory(stuff);
    bodyArmor->use(&player);

    Camp camp;
    camp.enter(&player);
}
