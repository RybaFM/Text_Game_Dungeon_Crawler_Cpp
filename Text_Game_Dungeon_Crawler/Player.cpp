//
// Created by User on 22.02.2026.
//

#include "Player.h"
#include "Helmet.h"
#include "BodyArmor.h"
#include "Monster.h"
#include "Weapon.h"
#include "Location.h"
#include "Potion.h"
#include "Chest.h"

Player::~Player()  {
    delete helmet;
    delete bodyArmor;
    delete weapon;
}



bool Player::makeHit(Monster *monster) {
    if (monster) {
        bool res = monster->takeDamage(damage);
        return res;
    }
    return false;
}
void Player::takeDamage(int damage) {
    double reducedDamage = damage * (1.0 - this->protection);
    int finalDamage = std::max(0, static_cast<int>(std::round(reducedDamage)));
    this->hp -= finalDamage;
}

bool Player::sellItem(Item *item) {
    if (takeOutFromInventory(item)) {
        addMoney(item->getPrice());
        std::cout << "Item successfully sold\n";
        delete item;
        return true;
    }
    return false;
}

bool Player::takeItemFromMonster(Item *item, Monster *monster) {
    if (getFreeSpace() > 0 && monster->lootItem(item)) {
        putInInventory(item);
        return true;
    }
    return false;
}

bool Player::takeItemFromChest(Item *item, Chest *chest) {
    if (getFreeSpace() > 0 && chest->lootItem(item)) {
        putInInventory(item);
        return true;
    }
    return false;
}

bool Player::putInInventory(Item *item) {
    return inventory.addItem(item);
}
bool Player::takeOutFromInventory(Item *item) {
    return inventory.removeItem(item);
}

void Player::openInventory() {
    while (true) {
        std::vector<Item*> inventory = getInventory();
        std::vector<Equipment*> equipment = getEquipment();
        std::cout << "------------\n";
        std::cout << "Your current health: " << getHp() << "HP\n";
        std::cout << "Your current protection: " << (int)std::round(getProtection() * 100) << "%\n";
        std::cout << "Your current damage: " << getDamage() << "HP\n";
        std::cout << "Your money: " << getMoney() << "\n";
        std::cout << "Your inventory:" << "\n";
        std::cout << "Free space: " << getFreeSpace() << "/10\n";
        for (int i = 0; i < equipment.size(); i++) {
            if (equipment[i]->isLegendary()) {
                std::cout << i+1 << ". " << equipment[i]->getName() << " (" << equipment[i]->info() << ", legendary) equipped" <<  '\n';
            }
            else {
                std::cout << i+1 << ". " << equipment[i]->getName() << " (" << equipment[i]->info() << ") equipped" <<  '\n';
            }
        }
        for (int i = equipment.size(); i < inventory.size()+equipment.size(); i++) {
            if (inventory[i-equipment.size()]->isLegendary()) {
                std::cout << i+1 << ". " << inventory[i-equipment.size()]->getName() << " (" << inventory[i-equipment.size()]->info() << ", legendary)" << '\n';
            }
            else {
                std::cout << i+1 << ". " << inventory[i-equipment.size()]->getName() << " (" << inventory[i-equipment.size()]->info() << ")" << '\n';
            }
        }
        if (equipment.empty() && inventory.empty()) {
            std::cout << "You do not have items in your inventory\n";
        }
        std::cout << "0. Exit\n";
        std::cout << "Enter your choice: ";
        int choice;
        while (!(std::cin >> choice)) {
            std::cin.clear();
            std::cin.ignore(1000, '\n');
            std::cout << "Symbols and letters are not allowed. Enter a number: ";
        }
        std::cin.ignore(1000, '\n');
        std::cout << "------------\n";
        if (choice == 0) {
            return;
        }
        if (choice <= equipment.size() && choice > 0) {
            bool res = equipment[choice-1]->unuse(this);
            if (!res) {
                std::cout << "Not enough space in inventory\n";
            }
        }
        else if (choice <= equipment.size()+inventory.size() && choice > 0) {
            bool res = inventory[choice-1-equipment.size()]->use(this);
            if (!res) {
                std::cout << "You are wearing something already\n";
            }
        }
        else {
            std::cout << "Invalid choice\n" << std::endl;
        }
    }
}

std::vector <Equipment*> Player::getEquipment()const {
    std::vector <Equipment*> equipment;
    if (helmet != nullptr) {
        equipment.push_back(helmet);
    }
    if (bodyArmor != nullptr) {
        equipment.push_back(bodyArmor);
    }
    if (weapon != nullptr) {
        equipment.push_back(weapon);
    }
    return equipment;
}
bool Player::wearHelmet(Helmet *helmet) {
    if (this->helmet == nullptr && takeOutFromInventory(helmet)) {
        this->helmet = helmet;
        protection += helmet->getProtection();
    }
    return false;
}
bool Player::wearBodyArmor(BodyArmor *bodyArmor) {
    if (this->bodyArmor == nullptr && takeOutFromInventory(bodyArmor)) {
        this->bodyArmor = bodyArmor;
        protection += bodyArmor->getProtection();
        return true;
    }
    return false;
}
bool Player::wearWeapon(Weapon *weapon) {
    if (this->weapon == nullptr && takeOutFromInventory(weapon)) {
        this->weapon = weapon;
        damage = weapon->getDamage();
        return true;
    }
    return false;
}
bool Player::usePotion(Potion *potion, int heal) {
    if (takeOutFromInventory(potion)) {
        healHp(heal);
        delete potion;
        return true;
    }
    return false;
}
bool Player::takeOffHelmet() {
    if (putInInventory(helmet)) {
        protection -= helmet->getProtection();
        helmet = nullptr;
        return true;
    }
    return false;
}
bool Player::takeOffBodyArmor() {
    if (putInInventory(bodyArmor)) {
        protection -= bodyArmor->getProtection();
        bodyArmor = nullptr;
        return true;
    }
    return false;
}
bool Player::takeOffWeapon() {
    if (putInInventory(weapon)) {
        damage = 5;
        weapon = nullptr;
        return true;
    }
    return false;
}

void Player::die() {
    delete helmet;
    delete bodyArmor;
    delete weapon;
    helmet = nullptr;
    bodyArmor = nullptr;
    weapon = nullptr;
}