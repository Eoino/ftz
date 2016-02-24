#ifndef ITEM_H
#define ITEM_H

#include <string>

using namespace std;

class Item
{
private:
    string name;
    int value;
    int weight;
public:
    Item(string name, int value, int weight);
};

// TODO implement
class IEquipable
{
private:
    bool equipped;
    int durability;
public:
    virtual int get_value() = 0; // durability * value
};

class Weapon: public Item, public IEquipable
{
private:
    int damage;
public:
    Weapon(string name, int value, int weight, int damage);
    // Get damage method
};

class Armour: public Item, public IEquipable
{
private:
    int protection;
public:
    Armour(string name, int value, int weight, int protection);

};

// TODO Utility class with different variables or bandage class?

#endif // ITEM_H
