#ifndef SHIP_H
#define SHIP_H

#include <string>
#include <vector>
#include <fstream>
#include <iostream>
#include <cstdlib>

#include "tile.h"
#include "character.h"
#include "item.h"

using namespace std;

class Ship
{
private:
    string name;
    int xlen;
    int ylen;
    Tile ***map;
    vector<Alien*> aliens;
    vector<Item*> items;
    void importMap(string tilemap);
    int readNum(string line);
public:
    Ship(string name);
    ~Ship();
    vector<Alien*> getAliens();
    vector<Item*> getItems();
    Tile*** getMap();
    int* getSize();
    Alien* getAlien(int xpos, int ypos);
    bool checkPos(int xpos, int ypos);
    Item* getItem(int xpos, int ypos);
    void deleteAlien(int pos);
    void removeItem(int pos);
    inline int getXlen();
    inline int getYlen();
};

int Ship::getXlen()
{
    return xlen;
}

int Ship::getYlen()
{
    return ylen;
}

#endif // SHIP_H
