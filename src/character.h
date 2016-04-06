#ifndef CHARACTER_H
#define CHARACTER_H

#include <string>

#include "item.h"
#include "tile.h"

#define ALIEN_NAME "Boo"
#define ALIEN_HEALTH 40
#define ALIEN_MONEY 15
#define ALIEN_STRENGTH 10

using namespace std;

class Character;
class Human;
class Alien;

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
    ~Character();
    inline void move(int xpos, int ypos);
    virtual void defend(int damage) = 0;
    void heal(int heal);
    inline string getName();
    int* getPos();
    inline int getHealth();
    inline void setPos(int xpos, int ypos);
};

inline void Character::move(int xpos, int ypos)
{
    this->xpos = xpos;
    this->ypos = ypos;
}

inline string Character::getName()
{
    return name;
}

inline int Character::getHealth()
{
    return health;
}

inline void Character::setPos(int xpos, int ypos)
{
    this->xpos = xpos;
    this->ypos = ypos;
}

class Human: public Character
{
private:
    Weapon *weapon;
    Armour *armour;
    void attack(Character *target);
public:
    Human(string name, int maxHealth, int money, int xpos, int ypos);
    ~Human();
    void defend(int damage);
    void loot(Item *item);
    void action(Alien *alien);
    void setWeapon(Weapon *weapon);
    void setArmour(Armour *armour);
};

class Alien: public Character
{
private:
    int strength;
    void attack(Character *target);
public:
    Alien(int xpos, int ypos);
    virtual ~Alien();
    void defend(int damage);
    void scout(Tile ***map, Human *human);
};

#endif // CHARACTER_H
