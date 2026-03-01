#include "Camp.h"
#include "Player.h"
#include "Dungeon.h"

void Camp::enter(Player *player) {
    std::cout << "Your are waking up in dirt...\n";
    std::cout << "Stranger: hey, buddy, what happened again?\n";
    std::string temp;
    std::cout << "Type anything\n";
    std::cin >> temp;
    std::cin.ignore(1000, '\n');
    std::cout << "You look up and see you old friend Stan\n";
    std::cout << "Stan: how many times I said that you shouldn't gamble!\n";
    std::cout << "Stan: first thing you must do now is to go to the doctor and then sell your silly pocker cards!\n";
    std::cout << "Stan: and don't say me that you lost all your money...\n";
    std::cout << "Stan: oh... you actually did... perfect.\n";
    std::string temp2;
    std::cout << "Type anything\n";
    std::cin >> temp2;
    std::cin.ignore(1000, '\n');
    std::cout << "Stan: you should stop gambling, trust me!\n";
    std::cout << "Stan: you actually will be useful on searching for legendary artefacts! You can make some money there as well.\n";
    interact(player);
}


void Camp::interact(Player *player) {
    while (true) {
        player->healHp(60);
        std::cout << "------------\n";
        std::cout << "You are in the " << name << "\n";
        std::cout << "1. Go to the dungeon\n";
        std::cout << "2. Go to the shop\n";
        std::cout << "3. Go to the local doctor\n";
        std::cout << "4. About legendary items\n";
        std::cout << "5. Check inventory\n";
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
                Dungeon dungeon;
                dungeon.enter(player);
                continue;
            }
            case 2: {
                Shop shop;
                shop.enter(player);
                continue;
            }
            case 3: {
                DoctorHouse doctorHouse;
                doctorHouse.enter(player);
                continue;
            }
            case 4:
                aboutLegendaryItems(player);
                continue;
            case 5:
                player->openInventory();
                continue;
            default:
                std::cout << "Invalid Choice\n" << std::endl;
        }
    }
}

void Camp::aboutLegendaryItems(Player *player) {
    std::cout << "------------\n";
    std::cout << "Stranger: Hey, stranger! Have you heard about some ancient blade, that was just found?\n";
    std::cout << "You: ";
    std::string something;
    std::cin >> something;
    std::cin.ignore(1000, '\n');
    std::cout << "Stranger: Actually, doesn't matter.\n";
    std::cout << "Stranger: People are ready to go in those dungeons just to gamble with life.\n";
    std::cout << "Stranger: I heard that some items that could be found there are very rare.\n";
    std::cout << "Stranger: But c'mon is it worth your life?\n";
    std::cout << "Type anything to finish dialogue\n";
    std::cin >> something;
    std::cin.ignore(1000, '\n');
    std::cout << "------------\n";
}