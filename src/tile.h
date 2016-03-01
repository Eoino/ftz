#ifndef TILE_H
#define TILE_H

#include <string>

using namespace std;

class Tile
{
private:
    char type;
    bool enterable;
public:
    Tile(char type);
    char getType();
    bool isEnterable();
};

#endif // TILE_H
