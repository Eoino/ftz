#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "item.h"

#define ALIEN_NAME "Boo"
#define ALIEN_HEALTH 100
#define ALIEN_MONEY 15
#define ALIEN_STRENGTH 10

using namespace std;

class Character
{
private:
    /* Information */
    string name;
    int maxHealth;

    /* Position on map grid */
    int xpos;
    int ypos;

    /* Inventory */
    int money;

    virtual void attack(Character *target) = 0;
protected:
    int health;
public:
    Character(string name, int maxHealth, int money, int xpos, int ypos);
    void move(int xpos, int ypos);
    virtual void defend(int damage) = 0;
    void heal(int heal);
    string getName();
};

class Human: public Character
{
private:
    Weapon *weapon;
    Armour *armour;
    void attack(Character *target);
public:
    Human(string name, int maxHealth, int money, int xpos, int ypos);
    void defend(int damage);
    void loot(Item *item);
    void action(char keyDirection);
};

class Alien: public Character
{
private:
    int strength;
    void attack(Character *target);
public:
    Alien(int xpos, int ypos);
    void defend(int damage);
    void scout();
};

#endif // CHARACTER_H
