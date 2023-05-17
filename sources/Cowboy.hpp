#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include "Character.hpp"

using namespace std;

#ifndef COWBOY
#define COWBOY
class Cowboy:public Character{
int stack;

public:

    Cowboy(string name_,Point point);

    void shoot(Character * character);

    bool hasboolets();

    void reload();
~Cowboy();
    virtual string print()override;
};
#endif
