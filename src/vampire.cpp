#include "vampire.h"
#include <iostream>

Vampire::Vampire(const std::string& name, int age) :
    name(name), age(age), isAlive(true), hungerLevel(100) {}

std::string Vampire::getName() const { return name; }

void Vampire::setName(const std::string& name) { this->name = name; }

int Vampire::getAge() const { return age; }

void Vampire::setAge(int age) { this->age = age; }

bool Vampire::getIsAlive() const { return isAlive; }

int Vampire::getHungerLevel() const { return hungerLevel; }

void Vampire::drinkBlood() {
    hungerLevel -= 25;
    if (hungerLevel < 0) hungerLevel = 0;
    std::cout << name << " пьёт кровь..." << std::endl;
}

void Vampire::die() { isAlive = false; }
