#include "GameCharacter.h"
#include <iostream>

int GameCharacter::objectCount = 0;

GameCharacter::GameCharacter()
    : name("Unknown"),
      health(100),
      level(1),
      isAlive(true),
      stats{10, 10}
{
    objectCount++;
}

GameCharacter::GameCharacter(
    const std::string& name,
    int health,
    int level,
    int strength,
    int agility
)
    : name(name),
      health(health),
      level(level),
      isAlive(true),
      stats{strength, agility}
{
    if (this->name.empty())
        this->name = "Unknown";

    if (this->health < 0)
        this->health = 0;

    if (this->health > 100)
        this->health = 100;

    if (this->level < 1)
        this->level = 1;

    if (this->stats.strength < 0)
        this->stats.strength = 0;

    if (this->stats.agility < 0)
        this->stats.agility = 0;

    if (this->health == 0)
        this->isAlive = false;

    objectCount++;
}

GameCharacter::GameCharacter(const GameCharacter& other)
    : name(other.name),
      health(other.health),
      level(other.level),
      isAlive(other.isAlive),
      stats(other.stats)
{
    objectCount++;
}

GameCharacter::~GameCharacter()
{
    objectCount--;
}

void GameCharacter::takeDamage(int damage)
{
    if (damage <= 0 || !isAlive)
        return;

    health -= damage;

    if (health <= 0)
    {
        health = 0;
        isAlive = false;
    }
}

void GameCharacter::heal(int amount)
{
    if (amount <= 0 || !isAlive)
        return;

    health += amount;

    if (health > 100)
        health = 100;
}

void GameCharacter::levelUp()
{
    if (!isAlive)
        return;

    level++;
    health = 100;
}

const std::string& GameCharacter::getName() const
{
    return name;
}

int GameCharacter::getHealth() const
{
    return health;
}

int GameCharacter::getLevel() const
{
    return level;
}

bool GameCharacter::getIsAlive() const
{
    return isAlive;
}

int GameCharacter::getStrength() const
{
    return stats.strength;
}

int GameCharacter::getAgility() const
{
    return stats.agility;
}

void GameCharacter::printInfo() const
{
    std::cout << "Имя: " << name << std::endl;
    std::cout << "Здоровье: " << health << std::endl;
    std::cout << "Уровень: " << level << std::endl;
    std::cout << "Состояние: "
              << (isAlive ? "жив" : "мертв") << std::endl;
    std::cout << "Сила: " << stats.strength << std::endl;
    std::cout << "Ловкость: " << stats.agility << std::endl;
}

int GameCharacter::getObjectCount()
{
    return objectCount;
}