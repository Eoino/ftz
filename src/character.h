#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>
#include "item.h"

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
    Item* inv;

    /* Function - Attack character standing in tile denoted by direction */
    virtual void attack(char direction) = 0;
public:
    Character(string name, int maxHealth, int money);
    void move(char direction);
    string getName();
};


class Human: public Character
{
private:
    int maxWeight;
    void attack(char direction);
public:
    Human(string name);
    Human(string name, int maxWeight, int maxHealth, int money);
    void loot();
};


class Alien: public Character
{
private:
    void attack(char direction);
public:
    Alien(string name, int maxHealth, int money);
    void scout();
};


#endif // CHARACTER_H
