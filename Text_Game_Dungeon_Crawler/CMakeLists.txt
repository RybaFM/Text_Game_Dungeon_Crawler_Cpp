cmake_minimum_required(VERSION 4.0)
project(test)

set(CMAKE_CXX_STANDARD 20)

add_executable(test main.cpp
        Item.cpp
        Item.h
        Weapon.cpp
        Weapon.h
        Player.cpp
        Player.h
        Monster.cpp
        Monster.h
        Armor.cpp
        Armor.h
        Helmet.h
        Helmet.cpp
        BodyArmor.cpp
        BodyArmor.h
        Equipment.cpp
        Equipment.h
        Inventory.cpp
        Inventory.h
        Location.cpp
        Location.h
        Camp.cpp
        Camp.h
        Game.cpp
        Game.h
        DoctorHouse.cpp
        DoctorHouse.h
        Potion.cpp
        Potion.h
        Stuff.cpp
        Stuff.h
        Shop.cpp
        Shop.h
        ItemFactory.cpp
        ItemFactory.h
        Dungeon.cpp
        Dungeon.h
        Room.cpp
        Room.h
        Chest.cpp
        Chest.h)
