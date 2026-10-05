#ifndef GAMECHARACTER_H
#define GAMECHARACTER_H

#include <string>

struct CharacterStats
{
    int strength;
    int agility;
};

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