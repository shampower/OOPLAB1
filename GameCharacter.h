/**
 * @file GameCharacter.h
 * @brief Объявление класса игрового персонажа.
 *
 * Класс GameCharacter хранит состояние персонажа,
 * его характеристики и предоставляет методы для
 * изменения и получения этого состояния.
 */

#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>

/**
 * @brief Характеристики игрового персонажа.
 */

struct CharacterStats
{
    int strength;
    int agility;
};

/**
 * @class GameCharacter
 * @brief Представляет персонажа компьютерной игры.
 *
 * Инварианты класса:
 * - здоровье находится в диапазоне от 0 до 100;
 * - уровень не меньше 1;
 * - имя не является пустой строкой;
 * - сила и ловкость не могут быть отрицательными.
 */

class GameCharacter
{
private:
    std::string name;
    int health;
    int level;
    bool isAlive;
    CharacterStats stats;

    static int objectCount;

public:
    GameCharacter();

    GameCharacter(
        const std::string& name,
        int health,
        int level,
        int strength,
        int agility
    );

    GameCharacter(const GameCharacter& other);

    ~GameCharacter();

    void takeDamage(int damage);
    void heal(int amount);
    void levelUp();

    const std::string& getName() const;
    int getHealth() const;
    int getLevel() const;
    bool getIsAlive() const;
    int getStrength() const;
    int getAgility() const;

    void printInfo() const;

    static int getObjectCount();
};

#endif