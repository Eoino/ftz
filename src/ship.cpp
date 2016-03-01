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
            map[i][j] = new Tile(tilemap.at(count++));
}

int Ship::readNum(string line)
{
    int pos = line.find(":") + 1;
    return atoi((line.substr(pos, line.size())).c_str());
}
