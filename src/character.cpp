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

void Character::move(int xpos, int ypos)
{
    this->xpos = xpos;
    this->ypos = ypos;
}

void Character::heal(int heal)
{
    health += heal;
    if(health > maxHealth)
        health = maxHealth;
}

string Character::getName()
{
    return this->name;
}

Human::Human(string name, int maxHealth, int money, int xpos, int ypos)
    :Character(name, maxHealth, money, xpos, ypos)
{

}

void Human::attack(Character *target)
{
    int damage = weapon->getDamage();
    target->defend(damage);
}

void Human::defend(int damage)
{
    health -= damage - armour->getProtection();
}

void Human::loot(Item *item)
{
    item->setPos(-1, -1);
    // TODO
}

void Human::action(char keyDirection)
{
    // TODO
}

Alien::Alien(int xpos, int ypos)
    :Character(ALIEN_NAME, ALIEN_HEALTH, ALIEN_MONEY, xpos, ypos)
{
    this->strength = ALIEN_STRENGTH;
}

void Alien::attack(Character *target)
{
    int damage = strength;
    target->defend(damage);
}

void Alien::defend(int damage)
{
    health -= damage;
}

void Alien::scout()
{
    // TODO
}
