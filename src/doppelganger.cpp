#include "doppelganger.h"
#include <iostream>

Doppelganger::Doppelganger(const std::string& name, int age, const std::string& originalName) :
    Vampire(name, age), originalName(originalName), bloodMagicReserve(100) {}

std::string Doppelganger::getOriginalName() const { return originalName; }

int Doppelganger::getBloodMagicReserve() const { return bloodMagicReserve; }

void Doppelganger::confuseEnemy() {
    std::cout << name << " путает врагов, выдавая себя за " << originalName << std::endl;
}

void Doppelganger::decreaseBloodMagicReserve() {
    bloodMagicReserve -= 10;
    if (bloodMagicReserve <= 10) {
        bloodMagicReserve = 10;
        isAlive = false;
        std::cout << name << " умер от потери магической крови!" << std::endl;
    }
}
