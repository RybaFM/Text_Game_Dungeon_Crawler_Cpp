
#include <random>
#include "Player.h"
#include "Dungeon.h"


static int randomInt(int min, int max)
{
    static std::random_device rd;
    static std::mt19937 gen(rd());
    std::uniform_int_distribution<> dist(min, max);
    return dist(gen);
}

Dungeon::Dungeon() :Location("Dungeon") {
    int countRooms = randomInt(5, 10);
    rooms.reserve(countRooms);
    for (int i = 0; i < countRooms; i++) {
        std::string name = "Room " + std::to_string(i + 1);
        rooms.emplace_back(name);
    }
}


void Dungeon::enter(Player *player) {
    std::cout << "You entered dungeon...\n";
    interact(player);
}

void Dungeon::interact(Player *player) {
    while (true) {
        std::cout << "------------\n";
        std::cout << "You are in the " << name << "\n";
        std::cout << "1. Go to first room\n";
        std::cout << "2. Check inventory\n";
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
                bool res = enterRooms(player);
                if (res == false) {
                    return;
                }
                continue;
            }
            case 2: {
                player->openInventory();
                continue;
            }
            default: {
                std::cout << "Invalid Choice\n" << std::endl;
            }
        }
    }
}

bool Dungeon::enterRooms(Player *player) {
    int number = 0;
    while (true) {
        int res = rooms[number].enter(player, number, rooms.size());
        if (res == 1) {
            if (number == rooms.size() - 1) {
                return true;
            }
            else {
                number++;
                continue;
            }
        }
        else if (res == -1) {
            if (number == 0) {
                return true;
            }
            else {
                number--;
                continue;
            }
        }
        else {
            return false;
        }
    }
}