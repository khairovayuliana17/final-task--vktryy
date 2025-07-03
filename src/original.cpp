#include "original.h"
#include <iostream>

OriginalVampire::OriginalVampire(const std::string& name, int age) :
    Vampire(name, age), sireLine(0) {}

int OriginalVampire::getSireLine() const { return sireLine; }

void OriginalVampire::compel() {
    std::cout << name << " использует силу принуждения!" << std::endl;
}

void OriginalVampire::createVampire() {
    if (isAlive) {
        sireLine++;
        std::cout << name << " создал нового вампира! Теперь в его линии " << sireLine
                  << " вампиров" << std::endl;
    } else {
        sireLine = 0;
        std::cout << "Мёртвые вампиры не могут создавать новых. Вся кровная линия мертва"
                  << std::endl;
    }
}
