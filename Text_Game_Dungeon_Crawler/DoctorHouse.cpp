#include "DoctorHouse.h"

#include "ItemFactory.h"
#include "Player.h"
#include "Potion.h"

void DoctorHouse::enter(Player *player) {
    std::cout << "Welcome to " << name << "!\n";
    interact(player);
}

void DoctorHouse::interact(Player *player) {
    while (true) {
        std::cout << "------------\n";
        std::cout << "You are in the " << name << "\n";
        std::cout << "1. Heal HP\n";
        std::cout << "2. Buy potions\n";
        std::cout << "3. Check inventory\n";
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
        switch (choice) {
            case 0:
                return;
            case 1:
                player->healHp(100);
                std::cout << "Your HP are full now\n";
                continue;
            case 2:
                buyPotions(player);
                continue;
            case 3:
                player->openInventory();
                continue;
            default:
                std::cout << "Invalid Choice\n" << std::endl;
        }
    }
}

void DoctorHouse::sellPotionToPlayer(Player *player, Item *item) {
    if (player->getMoney() >= item->getPrice()) {
        if (player->putInInventory(item)) {
            player->subtractMoney(item->getPrice()*2);
            std::cout << "Successfully bought an item\n";
        }
        else {
            std::cout << "Not enough space in inventory\n";
            delete item;
        }
    }
    else {
        std::cout << "Not enough money\n";
        delete item;
    }
}

void DoctorHouse::buyPotions(Player *player) {
    while (true) {
        std::cout << "------------\n";
        std::cout << "You are in the " << name << " (Buy potions)\n";
        std::cout << "Money: " << player->getMoney() << "\n";
        std::cout << "Free space in bag: " << player->getFreeSpace() << "/10\n";
        std::cout << "1. Small health potion(Heals: 25HP) - 20 coins\n";
        std::cout << "2. Big health potion(Heals: 50HP) - 30 coins\n";
        std::cout << "3. Check inventory\n";
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
        switch (choice) {
            case 0:
                return;
            case 1: {
                Item *potion = ItemFactory::createPotion(0);
                sellPotionToPlayer(player, potion);
                continue;
            }
            case 2: {
                Item *potion = ItemFactory::createPotion(1);
                sellPotionToPlayer(player, potion);
                continue;
            }
            case 3:
                player->openInventory();
                continue;
            default:
                std::cout << "Invalid Choice\n" << std::endl;
        }
    }
}

