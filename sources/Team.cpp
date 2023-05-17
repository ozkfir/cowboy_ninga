//
// Created by oz on 07/04/23.
//
typedef enum  {COWBOY = 0, NINJA=1,EROR=-1} Result;
#include "Team.hpp"
#include <limits.h>


int Team::get_size()const{
    return size;
}
void Team::set_size(int num){
    this->size=num;
}

void Team::set_leader() {
    double min_distance=INT_MAX;
    int index=-1;
    for (int i = 0; i < this->size; ++i)
    {
        if(this->character[i]->isAlive() && this->leader->distance(this->character[i])<min_distance)
        {
            index=i;
        }
    }
    if(index==-1){throw ;}
    this->leader= this->character[index];
}

string Team::getCharactertype(Character *obj) {
    return typeid(obj).name();
//    if(typeid(obj).name()=="cowboy")
//        return Cowboy;

}
Team::Team(Character * leader_):size(1){
    this->character[0]=leader_;
    this->leader=leader_;
}
void Team::add(Character * player){
    if(size==10){throw ;}
        character[size] = player;
        size++;
}
Character * Team::get_close_live_enemy(Team * team){
    Character * team_Close=NULL;
    double min_distance_team=INT_MAX;
    for (int k = 0; k <team->get_size() ; ++k) {

        if(team->character[k]->isAlive() && this->leader->distance(team->character[k])<min_distance_team)
        {
            min_distance_team=this->leader->distance(team->character[k]);
            team_Close=team->character[k];
        }
    }
    if(team_Close==NULL){}
    return team_Close;
}


bool Team::leader_alive(){
    return this->leader->isAlive();
}
int Team::stillAlive(){
    int num =0;
//    for (int k = 0; k <this->size ; ++k) {
//        if(character[k]->isAlive())
//            num++;
//    }
    return num;
}



Team::~Team(){}
Team2::Team2(Character * leader_):Team(leader_){}
Team2::~Team2(){}
SmartTeam::SmartTeam(Character * leader_):Team(leader_){}
SmartTeam::~SmartTeam(){}





void Team::attack(Team *enemy){
    //what if all the enemys dead
//    if (!this->leader_alive()){
//        this->set_leader();
//    }
//
//    for (int i = 0; i < enemy->get_size(); ++i) {
//        enemy->get_character(i)->hit(1000);
//
//    }
//
//    Character * enemy_Close= get_close_live_enemy(enemy);//wat if null

//    for (int i = 0; i < this->get_size(); ++i) {
//        if (!enemy_Close->isAlive()) {
//            Character * enemy_Close = get_close_live_enemy(enemy);
//            if (enemy_Close == NULL)
//                break;
//        }
//        if (getCharactertype(this->character[i])=="Cowboy")//coboy
//        {Cowboy temp=dynamic_cast<Cowboy*>this->character[i];
//            if (temp.hasboolets())
//                temp.shoot(enemy_Close);
//
//        }
//        for (int i = 0; i <this->get_size() ; ++i) {
//            if (!enemy_Close->isAlive()) {
//                Character * enemy_Close = get_close_live_enemy(enemy);
//                if (enemy_Close == NULL)
//                    break;
//            }
//            if (getCharactertype(this->character[i])=="Ninja")//Ninja TODO young==old==train
//            {
//                Ninja temp=(Ninja)this->character[i];
//                if (temp->distance()<=1)
//                    temp.slash(enemy_Close);
//                else
//                    temp.move();
//            }
//        }
//    }
}








    void Team2::attack(Team *enemy){
//        if (!this->leader_alive()) {
//            this->set_leader();
//        }

//        Character *enemy_Close= get_close_live_enemy(enemy);
//        for (int i = 0; i < this->get_size(); ++i) {
//            if (!enemy_Close->isAlive()) {
//                Character * enemy_Close = get_close_live_enemy(enemy);
//                if (enemy_Close == NULL)
//                    break;
//            }
//            if (getCharactertype(this->get_character(i))=="Cowboy")//coboy
//            {Cowboy temp=(Cowboy)this->get_character(i);
//                if (temp.hasboolets())
//                    temp.shoot(enemy_Close);
//
//            }
//             else {
//                     if (getCharactertype(this->get_character(i))=="Ninja"){//Ninja TODO young==old==train
//
//                         Ninja temp=(Ninja)this->get_character(i);;
//                             if (temp->distance()<=1)
//                                temp.slash(enemy_Close);
//                            else
//                                temp.move();
//            }
//        }
//    }
}




void SmartTeam::attack(Team * enemy) {
//    if (!this->leader_alive()) {
//        this->set_leader();
//    }
//
//    Character *enemy_Close = get_close_live_enemy(enemy);
//    for (int i = 0; i <10; ++i) {
//        if (!enemy_Close->isAlive()) {
//            Character *enemy_Close = get_close_live_enemy(enemy);
//            if (enemy_Close == NULL)
//                break;
//        }
//
//    }
}







void Team::print(){
    cout<<"Team"<<endl;
    for (int i = 0; i < this->get_size(); ++i) {
        cout<<(this->get_character(i))->print()<<endl;
    }
}
void SmartTeam::print(){
    cout << "SmartTeam" << endl;
    for (int i = 0; i < this->get_size(); ++i) {
        cout<<(this->get_character(i))->print()<<endl;
    }
}
void Team2::print() {
    cout << "Team2" << endl;
    for (int i = 0; i < this->get_size(); ++i) {
        cout<<(this->get_character(i))->print()<<endl;
    }
}

Character *Team::get_character(int i) {return this->character[i];}