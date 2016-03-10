#include "Character.h"

Character::Character(string name, int maxHealth, int money, int xpos, int ypos)
{
    this->name = name;
    this->maxHealth = maxHealth;
    this->money = money;
    this->xpos = xpos;
    this->ypos = ypos;
    /* Set health to maximum */
    this->health = maxHealth;
}

void Character::move(char direction)
{
    // TODO
}

string Character::getName()
{
    return this->name;
}

Human::Human(string name, int maxHealth, int money, int xpos, int ypos)
    :Character(name, maxHealth, money, xpos, ypos)
{

}

void Human::loot()
{
    // TODO
}

Alien::Alien(int xpos, int ypos)
    :Character(ALIEN_NAME, ALIEN_HEALTH, ALIEN_MONEY, xpos, ypos)
{
    // TODO
}

void Alien::scout()
{
    // TODO
}
