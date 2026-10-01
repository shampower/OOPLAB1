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
};

#endif