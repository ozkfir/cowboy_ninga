#include <iostream>
#include "Character.hpp"
using namespace std;


using std::cout; using std::endl;

Character::Character(string name_,Point point,int hit): p(point),hit_point(hit),name(name_){}

bool  Character::isAlive(){
    if(hit_point>0)
        return true;
    return false;
}


double Character::distance(Character * player){
    return player->getLocation().distance(this->getLocation());
}

void Character::hit(int num){
//    if(hit_point==0){throw ;}
    if (hit_point<=num){hit_point=0;}
    else
        hit_point-=num;
}

string Character::getName(){
    return name;
}

Point Character::getLocation(){
    return p;
}
void Character::setLocation(Point point){
    this->p=point;
}
Character::~Character() {}

