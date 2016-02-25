#ifndef STRUCTURE_H
#define STRUCTURE_H

#include <string>

using namespace std;

class Structure
{
private:
    string name;
    bool enterable;
public:
    Structure(string name, bool enterable);
    bool isEnterable();
};

class Room: public Structure
{
private:
    char type;
public:
    Room(char type);
};

class Wall: public Structure
{
private:
public:
    Wall();
};


#endif // STRUCTURE_H
