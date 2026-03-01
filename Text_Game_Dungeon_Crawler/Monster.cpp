#include "Monster.h"
#include "Player.h"
#include "Helmet.h"
#include "BodyArmor.h"
#include "Weapon.h"
#include "Item.h"


Monster::Monster(std::string name, int hp, int damage, int speed, Helmet *helmet, BodyArmor *bodyArmor, Weapon *weapon):inventory(50) {
    this->name = name;
    this->hp = hp;
    this->damage = damage;
    if (weapon != nullptr) {
        this->damage += weapon->getDamage();
    }
    this->speed = speed;
    this->helmet = helmet;
    this->bodyArmor = bodyArmor;
    this->weapon = weapon;
    this->protection = 0;
    if (helmet != nullptr) {
        this->protection += helmet->getProtection();
    }
    if (bodyArmor != nullptr) {
        this->protection += bodyArmor->getProtection();
    }
}
Monster::~Monster() {
    delete helmet;
    delete bodyArmor;
    delete weapon;
}

void Monster::makeHit(Player *player) {
    if (player) {
        player->takeDamage(damage);
    }
}
bool Monster::takeDamage(int damage) {
    double reducedDamage = damage * (1.0 - this->protection);
    int finalDamage = std::max(0, static_cast<int>(std::round(reducedDamage)));
    this->hp -= finalDamage;
    if (this->hp <= 0) {
        die();
    }
    return true;
}
void Monster::die() {
    if (helmet != nullptr) {
        inventory.addItem(helmet);
        this->helmet = nullptr;
    }
    if (bodyArmor != nullptr) {
        inventory.addItem(bodyArmor);
        this->bodyArmor = nullptr;
    }
    if (weapon != nullptr) {
        inventory.addItem(weapon);
        this->weapon = nullptr;
    }
    this->protection = 0;
    this->damage = 15;
    this->isAlive = false;
}
std::vector<Item*> Monster::lootEverything() {
    std::vector<Item*> items;
    if (this->hp <= 0) {
        items = inventory.getInventory();
        inventory.removeAllItems();
    }
    return items;
}
bool Monster::lootItem(Item *item) {
    if (this->hp <= 0) {
        return inventory.removeItem(item);
    }
    return false;
}