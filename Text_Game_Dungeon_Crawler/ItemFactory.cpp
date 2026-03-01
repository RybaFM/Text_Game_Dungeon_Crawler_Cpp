//
// Created by User on 24.02.2026.
//

#include "ItemFactory.h"

#include "Item.h"
#include "Helmet.h"
#include "BodyArmor.h"
#include "Stuff.h"
#include "Weapon.h"
#include "Potion.h"

Item* ItemFactory::createItem(int id)  {
    switch(id) {
        case 0: return new BodyArmor("Old leather jacket", 25, false, 0.1);
        case 1: return new Weapon ("Pocket knife", 15, false, 8);
        case 2: return new Stuff ("Custom pocker cards", 100, false);
        case 3: return new Helmet("Leather helmet", 25, false, 0.05);
        case 4: return new BodyArmor("Leather jacket", 35, false, 0.12);
        case 5: return new Weapon("Iron sword", 35, false, 25);
        case 6: return new Helmet("Chainmail helmet", 60, false, 0.1);
        case 7: return new BodyArmor("Chainmail chestplate", 100, false, 0.2);
        case 8: return new Weapon("Steel sword", 100, false, 40);
        case 9: return new Helmet("Steel helmet", 100, false, 0.13);
        case 10: return new BodyArmor("Steel chestplate", 160, false, 0.27);
        case 11: return new Stuff("Cigarettes", 10, false);
        default: return nullptr;
    }
}

Item* ItemFactory::createPotion(int id)  {
    switch(id) {
        case 0: return new Potion("Small health potion", 10, false, 25);
        case 1: return new Potion("Big health potion", 15, false, 50);
        default: return nullptr;
    }
}

BodyArmor* ItemFactory::createArmorForMonster(int id) {
    switch(id) {
        //undead
        case 0: return new BodyArmor("Leather rags", 10, false, 0.05);
        //undead legionnaire
        case 1: return new BodyArmor("Ancient bone armor", 220, true, 0.3);
        //vampire
        case 2: return new BodyArmor("Noble vampire coat", 120, false, 0.15);
        //powerful vampire
        case 3: return new BodyArmor("Ancient vampire armor", 250, true, 0.3);
        //orc
        case 4: return new BodyArmor("Orc warplate", 70, false, 0.2);
        //necromancer
        case 5: return new BodyArmor("Cursed chestplate", 300, true, 0.4);
        //demon
        case 6: return new BodyArmor("Hellforged armor", 300, true, 0.4);
        //demon king
        case 7: return new BodyArmor("Demon lord armor", 800, true, 0.5);

        default: return nullptr;
    }
}

Helmet* ItemFactory::createHelmetForMonster(int id) {
    switch(id) {
        case 1: return new Helmet("Ancient bone helmet", 150, true, 0.15);
        case 3: return new Helmet("Ancient vampire helmet", 175, true, 0.15);
        case 5: return new Helmet("Cursed skull helmet", 250, true, 0.2);
        case 6: return new Helmet("Hellforged helmet", 250, true, 0.2);
        case 7: return new Helmet("Crown of Hell", 800, true, 0.25);
        default: return nullptr;
    }
}

Weapon* ItemFactory::createWeaponForMonster(int id) {
    switch(id) {
        //undead
        case 0: return new Weapon("Rusty sword", 20, false, 15);
        //undead legionnaire
        case 1: return new Weapon("Ancient bone club", 200, true, 40);
        //vampire
        case 2: return new Weapon("Vampire rapier", 100, false, 30);
        //powerful vampire
        case 3: return new Weapon("Ancient vampire blade", 250, true, 40);
        //orc
        case 4: return new Weapon("Orc warhammer", 120, false, 35);
        //necromancer
        case 5: return new Weapon("Cursed blade of souls", 350, true, 50);
        //demon
        case 6: return new Weapon("Hellforged greatsword", 350, true, 50);
        //demon king
        case 7: return new Weapon("Blade of Hell", 1000, true, 60);
        default: return nullptr;
    }
}