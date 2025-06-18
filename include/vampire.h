#ifndef VAMPIRE_H
#define VAMPIRE_H

#include <string>

class Vampire {
  protected:
    std::string name;
    int age;
    bool isAlive;
    int hungerLevel;

  public:
    Vampire(const std::string& name, int age);

    // Геттеры и сеттеры
    std::string getName() const;
    void setName(const std::string& name);
    int getAge() const;
    void setAge(int age);
    bool getIsAlive() const;
    int getHungerLevel() const;

    // Методы
    void drinkBlood();
    void die();
};

#endif
