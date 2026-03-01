#include "Shop.h"
#include "Player.h"
#include "Helmet.h"
#include "BodyArmor.h"
#include "ItemFactory.h"
#include "Weapon.h"

void Shop::enter(Player *player) {
    std::cout << "Welcome to " << name << "!\n";
    interact(player);
}

void Shop::sellItemToPlayer(Player *player, Item *item) {
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

void Shop::interact(Player *player) {
    while (true) {
        std::cout << "------------\n";
        std::cout << "You are in the " << name << "\n";
        std::cout << "1. Buy\n";
        std::cout << "2. Sell\n";
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
            case 0: {
                return;
            }
            case 1: {
                buyMenu(player);
                continue;
            }
            case 2: {
                sellMenu(player);
                continue;
            }
            case 3: {
                player->openInventory();
                continue;
            }
            default: {
                std::cout << "Invalid Choice\n" << std::endl;
            }
        }
    }
}

void Shop::buyMenu(Player *player) {
    while (true) {
        std::cout << "------------\n";
        std::cout << "You are in the " << name << " (Buy items)\n";
        std::cout << "Money: " << player->getMoney() << "\n";
        std::cout << "Free space in bag: " << player->getFreeSpace() << "/10\n";
        std::cout << "1. Leather helmet(Protection: 5%) - 50 coins\n";
        std::cout << "2. Leather jacket(Protection: 12%) - 70 coins\n";
        std::cout << "3. Iron sword(Damage: 25HP) - 70 coins\n";
        std::cout << "4. Chainmail helmet(Protection: 10%) - 120 coins\n";
        std::cout << "5. Chainmail chestplate(Protection: 20%) - 200 coins\n";
        std::cout << "6. Steel sword(Damage: 40HP) - 200 coins\n";
        std::cout << "7. Steel helmet(Protection: 13%) - 200 coins\n";
        std::cout << "8. Steel chestplate(Protection: 27%) - 320 coins\n";
        std::cout << "9. Check inventory\n";
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
            case 0: {
                return;
            }
            case 1: {
                Item *item = ItemFactory::createItem(3);
                sellItemToPlayer(player, item);
                continue;
            }
            case 2: {
                Item *item = ItemFactory::createItem(4);
                sellItemToPlayer(player, item);
                continue;
            }
            case 3: {
                Item *item = ItemFactory::createItem(5);
                sellItemToPlayer(player, item);
                continue;
            }
            case 4: {
                Item *item = ItemFactory::createItem(6);
                sellItemToPlayer(player, item);
                continue;
            }
            case 5: {
                Item *item = ItemFactory::createItem(7);
                sellItemToPlayer(player, item);
                continue;
            }
            case 6: {
                Item *item = ItemFactory::createItem(8);
                sellItemToPlayer(player, item);
                continue;
            }
            case 7: {
                Item *item = ItemFactory::createItem(9);
                sellItemToPlayer(player, item);
                continue;
            }
            case 8: {
                Item *item = ItemFactory::createItem(10);
                sellItemToPlayer(player, item);
                continue;
            }
            case 9: {
                player->openInventory();
                continue;
            }
            default: {
                std::cout << "Invalid Choice\n" << std::endl;
            }
        }
    }
}

void Shop::sellMenu(Player *player) {
    while (true) {
        std::vector<Item*> inventory = player->getInventory();
        std::cout << "------------\n";
        std::cout << "You are in the " << name << " (Sell items)\n";
        std::cout << "Money: " << player->getMoney() << "\n";
        std::cout << "Free space in bag: " << player->getFreeSpace() << "/10\n";
        for (int i = 0; i < inventory.size(); i++) {
            if (inventory[i]->isLegendary()) {
                std::cout << i+1 << ". " << inventory[i]->getName() << " (" << inventory[i]->info() << ", legendary) - " << inventory[i]->getPrice() << " coins" << '\n';
            }
            else{
                std::cout << i+1 << ". " << inventory[i]->getName() << " (" << inventory[i]->info() << ") - " << inventory[i]->getPrice() << " coins" << '\n';
            }
        }
        if (inventory.empty()) {
            std::cout << "You do not have items in your inventory(Check equipped)\n";
        }
        std::cout << inventory.size()+1 << ". Check inventory\n";
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
        else if (choice == inventory.size()+1) {
            player->openInventory();
        }
        else if (choice <= inventory.size() && choice > 0) {
            player->sellItem(inventory[choice-1]);
        }
        else {
            std::cout << "Invalid choice\n" << std::endl;
        }
    }
}