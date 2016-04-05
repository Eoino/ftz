#include "ship.h"

Ship::Ship(string name)
{
    /* Set ship name */
    this->name = name;

    /* Read ship file */
    string tilemap = "";
    ifstream in((name + ".ftz").c_str());
    while(in)
    {
        string line;
        getline(in, line);
        if(line.size() > 0)
        {
            if(line.at(0) == '?')
            {
                if(line.find("rows") != string::npos)
                    xlen = readNum(line);
                else if(line.find("columns") != string::npos)
                    ylen = readNum(line);
            }
            else if(line.at(0) == '!')
            {
                tilemap += line.substr(1, ylen);
            }
        }
    }
    /* Initialise map with tilemap string */
    importMap(tilemap);
}

Ship::~Ship()
{
    for(int i = 0; i < xlen; i++)
    {
        for(int j = 0; j < ylen; j++)
            delete map[i][j];
        delete [] map[i];
    }
    delete [] map;

    while(!aliens.empty())
    {
        delete aliens.back();
        aliens.pop_back();
    }

    while(!items.empty())
    {
        delete items.back();
        items.pop_back();
    }
}

void Ship::importMap(string tilemap)
{
    /* Reserve memory */
    map = new Tile**[xlen];
    for(int i = 0; i < xlen; i++)
        map[i] = new Tile*[ylen];

    /* Initialise map */
    int count = 0;
    for(int i = 0; i < xlen; i++)
        for(int j = 0; j < ylen; j++)
        {
            char tile = tilemap.at(count++);
            if(tile == 'A')
            {
                /* Spawn enemy in this room*/
                Alien *alien = new Alien(i, j);
                aliens.push_back(alien);
                tile = 'R';
            }
            else if(tile == 'S')
            {
                /* Spawn sword in this room */
                Weapon *weapon = new Weapon("Sword", 25, i, j, 15);
                items.push_back(weapon);
                tile = 'R';
            }
            else if(tile == 'K')
            {
                /* Spawn stick in this room */
                Weapon *weapon = new Weapon("Stick", 5, i, j, 5);
                items.push_back(weapon);
                tile = 'R';
            }
            else if(tile == 'P')
            {
                /* Spawn pike in this room */
                Weapon *weapon = new Weapon("Pike", 10, i, j, 10);
                items.push_back(weapon);
                tile = 'R';
            }
            else if(tile == 'T')
            {
                /* Spawn shirt in this room */
                Armour *armour = new Armour("Shirt", 1, i, j, 5);
                items.push_back(armour);
                tile = 'R';
            }
            else if(tile == 'M')
            {
                /* Spawn mail in this room */
                Armour *armour = new Armour("Mail", 20, i, j, 5);
                items.push_back(armour);
                tile = 'R';
            }
            else if(tile == 'B')
            {
                /* Spawn mail in this room */
                Item *item = new Item("Bandage", 10, i, j);
                items.push_back(item);
                tile = 'R';
            }

            map[i][j] = new Tile(tile);
        }
}

int Ship::readNum(string line)
{
    int pos = line.find(":") + 1;
    return atoi((line.substr(pos, line.size())).c_str());
}

vector<Alien *> Ship::getAliens()
{
    return aliens;
}

Tile ***Ship::getMap()
{
    return map;
}

int* Ship::getSize()
{
    int *size = new int[2];
    size[0] = xlen;
    size[1] = ylen;
    return size;
}

Alien* Ship::getAlien(int xpos, int ypos)
{
    for(int i = 0; i < aliens.size(); i++)
    {
        int* pos = aliens[i]->getPos();
        if(pos[0] == xpos && pos[1] == ypos)
            return aliens[i];
    }
}

/* Check if alien exists with supplied coordinates */
bool Ship::checkPos(int xpos, int ypos)
{
    bool exists = false;
    for(int i = 0; i < aliens.size() && !exists; i++)
    {
        int* pos = aliens[i]->getPos();
        if(pos[0] == xpos && pos[1] == ypos)
            exists = true;
    }
    return exists;
}

Item *Ship::getItem(int xpos, int ypos)
{
    Item *item = nullptr;
    bool found = false;
    for(int i = 0; i < items.size() && !found; i++)
    {
        if(items[i]->checkPos(xpos, ypos))
        {
            item = items[i];
            found = true;
        }
    }
    return item;
}

/* Delete alien at specified position in vector */
void Ship::deleteAlien(int pos)
{
    delete aliens[pos];
    aliens.erase(aliens.begin() + pos);
}
