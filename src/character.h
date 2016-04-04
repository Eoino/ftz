#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "item.h"
#include "tile.h"

#define ALIEN_NAME "Boo"
#define ALIEN_HEALTH 100
#define ALIEN_MONEY 15
#define ALIEN_STRENGTH 10

using namespace std;

class Character
{
private:
    string name;
    int maxHealth;
    int money;
    virtual void attack(Character *target) = 0;
protected:
    int health;
    int xpos;
    int ypos;
public:
    Character(string name, int maxHealth, int money, int xpos, int ypos);
    void move(int xpos, int ypos);
    virtual void defend(int damage) = 0;
    void heal(int heal);
    string getName();
    int* getPos();
    int getHealth();
    void setPos(int xpos, int ypos);
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
    void scout(Tile ***map, Human *human);
};

#endif // CHARACTER_H
