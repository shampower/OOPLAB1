#include "GameCharacter.h"

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
    level++;
    health = 100;
    isAlive = true;
}