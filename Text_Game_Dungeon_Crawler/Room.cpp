#include "Room.h"
#include "Player.h"
#include <random>
#include "ItemFactory.h"
#include <chrono>
#include <conio.h>

Room::Room(std::string name):Location(name) {
    generateMonsterAndChest();
}

int Room::enter(Player *player, int number, int size) {
    while (true) {
        std::cout << "------------\n";
        std::cout << "You are in the " << name << "\n";
        if (number == size - 1) {
            std::cout << "1. Leave dungeon\n";
        }
        else {
            std::cout << "1. Go to next room\n";
        }
        if (!monster->isDead()) {
            std::cout << "2. Fight monster: (" << monster->getName() << ")\n";
        }
        else {
            std::cout << "2. Loot monster: (" << monster->getName() << ")\n";
        }
        std::cout << "3. Open chest: (" << chest->getName() << ")\n";
        std::cout << "4. Check inventory\n";
        if (number == 0) {
            std::cout << "0. Exit\n";
        }
        else {
            std::cout << "0. Go to previous room\n";
        }
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
                return -1;
            }
            case 1: {
                return 1;
            }
            case 2: {
                if (!monster->isDead()) {
                    int res = fight(player, monster);
                    if (res == 0) {
                        return 0;
                    }
                }
                else {
                    inspectMonster(player);
                }
                continue;
            }
            case 3: {
                if (monster->isDead()) {
                    openChest(player);
                }
                else {
                    std::cout << "You cannot check chest, while monster is still alive\n";
                }
                continue;
            }
            case 4: {
                player->openInventory();
                continue;
            }
            default: {
                std::cout << "Invalid Choice\n" << std::endl;
            }
        }
    }
}

void Room::openChest(Player *player) {
    while (true) {
        std::vector<Item*> loot = chest->getLoot();
        std::cout << "------------\n";
        std::cout << "Chest:\n";
        for (int i = 0; i < loot.size(); i++) {
            if (loot[i]->isLegendary()) {
                std::cout << i+1 << ". " << loot[i]->getName() << " (" << loot[i]->info() << ", legendary)" <<  '\n';
            }
            else {
                std::cout << i+1 << ". " << loot[i]->getName() << " (" << loot[i]->info() << ")" <<  '\n';
            }
        }
        if (loot.empty()) {
            std::cout << "There are no items\n";
        }
        std::cout << loot.size()+1 << ". Check inventory\n";
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
        if (choice > 0 && choice <= loot.size()) {
            player->takeItemFromChest(loot[choice-1], chest);
        }
        else if (choice == loot.size()+1) {
            player->openInventory();
        }
        else {
            std::cout << "Invalid choice\n" << std::endl;
        }
    }
}

void Room::inspectMonster(Player *player) {
    while (true) {
        std::vector<Item*> loot = monster->inspectBody();
        std::cout << "------------\n";
        std::cout << "Monster's inventory:\n";
        for (int i = 0; i < loot.size(); i++) {
            if (loot[i]->isLegendary()) {
                std::cout << i+1 << ". " << loot[i]->getName() << " (" << loot[i]->info() << ", legendary)" <<  '\n';
            }
            else {
                std::cout << i+1 << ". " << loot[i]->getName() << " (" << loot[i]->info() << ")" <<  '\n';
            }
        }
        if (loot.empty()) {
            std::cout << "There are no items\n";
        }
        std::cout << loot.size()+1 << ". Check inventory\n";
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
        if (choice > 0 && choice <= loot.size()) {
            player->takeItemFromMonster(loot[choice-1], monster);
        }
        else if (choice == loot.size()+1) {
            player->openInventory();
        }
        else {
            std::cout << "Invalid choice\n" << std::endl;
        }
    }
}

void Room::interact(Player *player) {

}

static int randomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

void Room::generateMonsterAndChest() {
    int temp = randomInt(1, 100);
    if (temp >= 1 && temp <= 30) {
        monster = new Monster("Undead", 80, 5, 10, nullptr, ItemFactory::createArmorForMonster(0), ItemFactory::createWeaponForMonster(0));
        chest = new Chest("Common chest");
    }
    else if (temp >= 31 && temp <= 60) {
        monster = new Monster("Vampire", 100, 5, 20, nullptr, ItemFactory::createArmorForMonster(2), ItemFactory::createWeaponForMonster(2));
        chest = new Chest("Common chest");
    }
    else if (temp >= 61 && temp <= 80) {
        monster = new Monster("Orc", 200, 25, 20, nullptr, ItemFactory::createArmorForMonster(4), ItemFactory::createWeaponForMonster(4));
        chest = new Chest("Common chest");
    }
    else if (temp >= 81 && temp <= 83) {
        monster = new Monster("Undead legionnaire", 120, 10, 50, ItemFactory::createHelmetForMonster(1), ItemFactory::createArmorForMonster(1), ItemFactory::createWeaponForMonster(1));
        chest = new Chest("Common chest");
    }
    else if (temp >= 84 && temp <= 86) {
        monster = new Monster("Powerful vampire", 140, 10, 50, ItemFactory::createHelmetForMonster(3), ItemFactory::createArmorForMonster(3), ItemFactory::createWeaponForMonster(3));
        chest = new Chest("Common chest");
    }
    else if (temp >= 86 && temp <= 93) {
        monster = new Monster("Necromancer", 150, 10, 70, ItemFactory::createHelmetForMonster(5), ItemFactory::createArmorForMonster(5), ItemFactory::createWeaponForMonster(5));
        chest = new Chest("Rare chest");
    }
    else if (temp >= 94 && temp <= 97) {
        monster = new Monster("Demon", 250, 25, 80, ItemFactory::createHelmetForMonster(6), ItemFactory::createArmorForMonster(6), ItemFactory::createWeaponForMonster(6));
        chest = new Chest("Legendary chest");
    }
    else {
        monster = new Monster("Demon king", 350, 50, 90, ItemFactory::createHelmetForMonster(7), ItemFactory::createArmorForMonster(7), ItemFactory::createWeaponForMonster(7));
        chest = new Chest("Legendary chest");
    }
}

int Room::fight(Player *player, Monster *monster) {
    while (!monster->isDead()) {
        std::cout << "------------\n";
        std::cout << "You are in the " << name << "\n";
        std::cout << "Your HP: " << player->getHp() << "\n";
        std::cout << "Monster's HP: " << monster->getHP() << "\n";
        std::cout << "1. Punch monster\n";
        std::cout << "2. Check inventory\n";
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
            case 1: {
                player->makeHit(monster);
                std::cout << "You punched monster!\n";
                if (monster->isDead()) {
                    std::cout << "Monster is dead!\n";
                    break;
                }
                int control = randomInt(3, 5);
                char controlChar = '0' + control;
                std::cout << "QUICK! Press " << control << " to dodge!\n";
                auto start = std::chrono::steady_clock::now();
                bool dodged = false;
                bool pressed = false;
                double limitSeconds = 1 - monster->getSpeed()/100;

                while (std::chrono::duration_cast<std::chrono::seconds>(
                       std::chrono::steady_clock::now() - start).count() < limitSeconds) {

                    if (_kbhit()) {
                        char input = _getch();
                        pressed = true;
                        if (input == controlChar) {
                            dodged = true;
                        }
                        break;
                    }
                }

                if (dodged) {
                    std::cout << "SUCCESS! You dodged the attack!\n";
                } else {
                    if (!pressed) std::cout << "TOO SLOW! ";
                    else std::cout << "WRONG KEY! ";

                    monster->makeHit(player);
                    std::cout << "Monster hit you!\n";
                }
                if (player->getHp()<=0) {
                    std::cout << "DEATH!\n";
                    player->die();
                    return 0;
                }
                continue;
            }
            case 2: {
                player->openInventory();
                continue;
            }
            default: {
                std::cout << "Invalid choice!\n";
            }
        }
    }
    return true;
}

