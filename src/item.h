#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
private:
    string name;
    int value;
    int xpos;
    int ypos;
public:
    Item(string name, int value);
    Item(string name, int value, int xpos, int ypos);
    ~Item();
    int getValue();
    void setPos(int xpos, int ypos);
    bool checkPos(int xpos, int ypos);
    string getName();
};

class Weapon: public Item
{
private:
    int damage;
public:
    Weapon(string name, int value, int damage);
    Weapon(string name, int value, int xpos, int ypos, int damage);
    ~Weapon();
    int getDamage();
};

class Armour: public Item
{
private:
    int protection;
public:
    Armour(string name, int value, int protection);
    Armour(string name, int value, int xpos, int ypos, int protection);
    ~Armour();
    int getProtection();
};

#endif // ITEM_H
