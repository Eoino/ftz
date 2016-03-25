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

int* Character::getPos()
{
    int *pos = new int[2];
    pos[0] = xpos;
    pos[1] = ypos;
    return pos;
}

int Character::getHealth()
{
    return health;
}

Human::Human(string name, int maxHealth, int money, int xpos, int ypos)
    :Character(name, maxHealth, money, xpos, ypos)
{
    weapon = nullptr;
    armour = nullptr;
}

void Human::attack(Character *target)
{
    int damage = weapon->getDamage();
    target->defend(damage);
}

void Human::defend(int damage)
{
    if(armour == nullptr)
        health -= damage;
    else
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

void Alien::scout(Tile ***map, Human *human)
{
    /* Check position in relation to player */
    int *pos = human->getPos();
    int distx = xpos - pos[0];
    int disty = ypos - pos[1];

    /* Cleanup */
    delete [] pos;

    /* Aggro if player is within range */
    if(distx < 4 && distx > -4 && disty < 4 && disty > -4)
    {
        /* Attack if in range */
        if(distx < 2 && distx > -2 && disty < 2 && disty > -2)
            attack(human);
        else
        {
            bool moved = false;
            if(distx < -1)
            {
                if(map[xpos+1][ypos]->isEnterable())
                {
                    xpos++;
                    moved = true;
                }
            }
            if(moved == false && distx > 1)
            {
                if(map[xpos-1][ypos]->isEnterable())
                {
                    xpos--;
                    moved = true;
                }
            }
            if(moved == false && disty < -1)
            {
                if(map[xpos][ypos+1]->isEnterable())
                {
                    ypos++;
                    moved = true;
                }
            }
            if(moved == false && disty > 1)
            {
                if(map[xpos][ypos-1]->isEnterable())
                {
                    ypos--;
                    moved = true;
                }
            }
        }
    }
}
