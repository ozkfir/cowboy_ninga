//
// Created by oz on 07/04/23.
//
#include "Cowboy.hpp"
Cowboy::Cowboy(string name_,Point point):Character(name_,point,110),stack(6){
}

void Cowboy::shoot(Character * character){
    if (this->hasboolets()){
    character->hit(10);
    this->stack--;
    }
}

bool Cowboy::hasboolets(){
    return  stack>0;
}

void Cowboy::reload(){
    if(this->hasboolets()){throw runtime_error("");}
    stack=6;
}

string Cowboy::print() {return getName();}
Cowboy::~Cowboy() {}