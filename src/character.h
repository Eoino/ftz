#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "item.h"

#define ALIEN_NAME "Boo"
#define ALIEN_HEALTH 100
#define ALIEN_MONEY 15

using namespace std;

class Character
{
private:
    /* Information */
    string name;
    int maxHealth;
    int health;

    /* Position on map grid */
    int xpos;
    int ypos;

    /* Inventory */
    int money;

    void move(char direction);
    void attack(char direction);
public:
    Character(string name, int maxHealth, int money, int xpos, int ypos);
    void heal(int heal);
    string getName();
};

class Human: public Character
{
private:
    Weapon *weapon;
    Armour *armour;
public:
    Human(string name, int maxHealth, int money, int xpos, int ypos);
    void loot();
    void action(char keyDirection); // Enum for directions?
};

class Alien: public Character
{
public:
    Alien(int xpos, int ypos);
    void scout();
};

#endif // CHARACTER_H
