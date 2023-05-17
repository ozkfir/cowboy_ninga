#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "point.hpp"
using namespace std;
namespace ariel{}
#ifndef CHARACTER
#define CHARACTER

class Character{
    Point p;
    int hit_point;
    string name;
string kind;

public:
    Character(string name_,Point point,int hit);

    bool isAlive();

   double distance(Character * player);

   void hit(int num);

    string getName();

    Point getLocation();
    virtual string print()=0;
    void setLocation(Point point);

~Character();


};
#endif
