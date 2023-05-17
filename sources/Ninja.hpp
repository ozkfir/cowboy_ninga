#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "point.hpp"
#include "Character.hpp"

using namespace std;


#ifndef NINGA
#define NINGA

class Ninja:public Character{
    int speed;
protected:
public:
    Ninja(string name,Point point,int h_p,int speed_);

    void  move(Character *enemy);

    void slash(Character *enemy);
    virtual string print()=0;
~Ninja();
};
#endif


#ifndef YOUNGNINGA
#define YOUNGNINGA
class YoungNinja:public Ninja{
public:
    YoungNinja(string name,Point point);
    string print();
    ~YoungNinja();

};
#endif



#ifndef TRAINEDNINGA
#define TRAINEDNINGA
class TrainedNinja:public Ninja{
public:
    TrainedNinja(string name,Point point);
    string print();
    ~TrainedNinja();
};
#endif



#ifndef OLDNINGA
#define OLDNINGA
class OldNinja:public Ninja{
public:
    OldNinja(string name,Point point);
    string print();
    ~OldNinja();
};
#endif
