#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string.h>
#include "Ninja.hpp"
#include "Cowboy.hpp"
//#include "YoungNinja.hpp"
//#include "OldNinja.hpp"
#include <vector>

using namespace std;

#ifndef TEAM
#define TEAM
class Team{
    int size;
    Character* character[10];
    Character * leader;
private:

public:
    bool leader_alive();
    bool kind_of_player();
    string getCharactertype(Character *obj);
    void set_size(int i);
    int get_size()const;
    Character * get_character(int i);
    void set_leader();///bool
    Character * get_leader();
    Character * get_close_live_enemy(Team * team);
    Team(Character * leader);
    void add(Character * player);
    virtual void attack(Team *team);
    virtual void print();
    int stillAlive();
~Team();
};
#endif






#ifndef TEAM2
#define TEAM2
class Team2:public Team{

private:
public:
    Team2(Character *obj);
    ~Team2();
    void attack(Team *team);
    void print();
};
#endif




#ifndef SMART_TEAM
#define SMART_TEAM
class SmartTeam:public Team{

private:
    bool leader_alive();
public:

    SmartTeam(Character *obj);
    ~SmartTeam();
    void attack(Team *team);
    void print();
};
#endif





