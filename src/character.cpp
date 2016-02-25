#include "Character.h"

Character::Character(string name, int maxHealth, int money)
{
    this->name = name;
    this->maxHealth = maxHealth;
    this->money = money;
    /* Set health to maximum */
    this->health = health;
}

void Character::move(char direction)
{
    // TODO
}

string Character::getName()
{
    return this->name;
}

Human::Human(string name)
    :Character(name, 100, 25)
{
    this->maxWeight = 30;
}

Human::Human(string name, int maxWeight, int maxHealth, int money)
    :Character(name, maxHealth, money)
{
    this->maxWeight = maxWeight;
}

void Human::attack(char direction)
{
    // TODO
}

void Human::loot()
{
    // TODO
}

Alien::Alien(string name, int maxHealth, int money)
    :Character(name, maxHealth, money)
{
    // TODO
}

void Alien::attack(char direction)
{
    // TODO
}

void Alien::scout()
{
    // TODO
}
