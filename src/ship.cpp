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
    // TODO
    // Delete tile map
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
            if(tile == 'S')
            {
                /* Spawn weapon in this room */
                Weapon *weapon = new Weapon("Sword", 25, i, j, 15);
                items.push_back(weapon);
                tile = 'R';
            }
            else if(tile == 'T')
            {
                /* Spawn armour in this room */
                Armour *armour = new Armour("Shirt", 5, i, j, 1);
                items.push_back(armour);
                tile = 'R';
            }
            else if(tile == 'M')
            {
                /* Spawn medkit in this room */
                // TODO
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
