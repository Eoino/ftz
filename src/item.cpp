#include "item.h"

Item::Item(string name, int value)
{
    this->name = name;
    this->value = value;
}

Item::Item(string name, int value, int xpos, int ypos)
{
    this->name = name;
    this->value = value;
    this->xpos = xpos;
    this->ypos = ypos;
}

Item::~Item()
{

}

int Item::getValue()
{
    return this->value;
}

void Item::setPos(int xpos, int ypos)
{
    this->xpos = xpos;
    this->ypos = ypos;
}

/* Checks if item is at specified position */
bool Item::checkPos(int xpos, int ypos)
{
    if(this->xpos == xpos && this->ypos == ypos)
        return true;
    return false;
}

string Item::getName()
{
    return name;
}

Weapon::Weapon(string name, int value, int damage)
    :Item(name, value)
{
    this->damage = damage;
}

Weapon::Weapon(string name, int value, int xpos, int ypos, int damage)
    :Item(name, value, xpos, ypos)
{
    this->damage = damage;
}

Weapon::~Weapon()
{

}

int Weapon::getDamage()
{
    return this->damage;
}

Armour::Armour(string name, int value, int protection)
    :Item(name, value)
{
    this->protection = protection;
}

Armour::Armour(string name, int value, int xpos, int ypos, int protection)
    :Item(name, value, xpos, ypos)
{
    this->protection = protection;
}

Armour::~Armour()
{

}

int Armour::getProtection()
{
    return this->protection;
}
