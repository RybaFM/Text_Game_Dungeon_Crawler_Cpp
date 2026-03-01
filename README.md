# ⚔️ Text Dungeon Crawler

A classic terminal-based RPG built in C++20. Explore dungeons, fight monsters, and collect legendary gear.

## 🚀 How to Run
This project uses **CMake**. To build and run the game:
1. Open the `Text_Game_Dungeon_Crawler` folder in **CLion** (or your favorite IDE).
2. Let CMake load the project.
3. Build and Run the `test` target.

## 🛠️ Project Structure
The game is built using an Object-Oriented approach with over 20 specialized classes:
* **Core Logic**: `Game`, `Player`, `Inventory` (handles storing items for chests, monsters and player)
* **World**: `Camp`, `Dungeons`, `Shop`, `Doctor's House`
* **Entities**: `Monster`
* **Items**: `Weapon`, `Helmet`, `Body Armor`, `Potion`, `Stuff` (Decorative items)
* **Systems**: `ItemFactory` (for generating objects), `Dungeon` (for generating rooms), `Room` (for generating monsters and chests), `Chest` (for generating loot)

## 🕹️ Features
* **Dynamic Combat**: Battle various monsters in a turn-based system.
* **Equipment System**: Separate slots for Weapons, Helmets, and Body Armor.
* **Exploration**: Procedural-style movement through dungeon rooms and camp locations.
* **Economy**: Visit the Shop to buy items or the Doctor's House to heal and buy potions.

## 💻 Requirements
* **Language**: C++20
* **Build System**: CMake 3.20+
* **Compiler**: MinGW, GCC, or Clang