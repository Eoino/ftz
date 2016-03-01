#include "tile.h"


Tile::Tile(char type)
{
    this->type = type;
    if(type != 'W')
        enterable = true;
    else
        enterable = false;
}

char Tile::getType()
{
    return type;
}

bool Tile::isEnterable()
{
    return enterable;
}
