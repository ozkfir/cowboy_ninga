/**
 * Demo file for the exercise on binary tree
 *
 * @author Evgeny Hershkovitch Neiterman
 * @since 2023-03
 */

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <cassert>
using namespace std;

#include "sources/Team.hpp"
#include "sources/Cowboy.hpp"

using namespace ariel;


int main() {
    Point a(32.3,44),b(1.3,3.5);
    assert(a.distance(b) == b.distance(a));
    Cowboy *tom = new Cowboy("Tom", a);
    OldNinja *sushi = new OldNinja("sushi", b);
    tom->shoot(sushi);
    cout << tom->print() <<endl;

    sushi->move(tom);
    sushi->slash(tom);
    cout << "1111111111111111111111111" <<endl;

    Team team_A(tom); 
    team_A.add(new YoungNinja("Yogi", Point(64,57)));

    // Team b(tom); should throw tom is already in team a
    cout << "222222222222222222" <<endl;

     Team team_B(sushi);
     team_B.add(new TrainedNinja("Hikari", Point(12,81)));

    cout << "333333333333333333" <<endl;

     while(team_A.stillAlive() > 0 && team_B.stillAlive() > 0){
         cout << "5555555" <<endl;

         team_A.attack(&team_B);
         cout << "66666666" <<endl;

         team_B.attack(&team_A);
         cout << "9999" <<endl;

         team_A.print();
        team_B.print();
         cout << "444444" <<endl;

     }

     if (team_A.stillAlive() > 0) cout << "winner is team_A" << endl;
     else cout << "winner is team_B" << endl;

     return 0; // no memory issues. Team should free the memory of its members. both a and b teams are on the stack. 

}
