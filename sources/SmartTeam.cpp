/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/SmartTeam.cpp- implement of SmartTeam class
 * @class SmartTeam
 * @extends Team class
 * class represent Team type unit, in the "cowboy_vs_ninja" game
 * Team unit is array that can contain at most of 10 characters pointers units
 * 
 * @author Shachar Ketz
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"
#include "Team.hpp"
using namespace std;
namespace ariel{

    SmartTeam::SmartTeam():Team(){ }

    SmartTeam::SmartTeam(Character *leader):Team(leader){ }
    
    int SmartTeam::attack(Team* enemyTeam){
        for(int i=0;i<getSize();i++){
                
                cout<<endl<<"Todo build attack"<<endl;
                getIndex(i)->hit(50);
        }
        return 1;
    }

    void SmartTeam::print(){
        for(int i=0;i<getSize();i++){
            cout<<getIndex(i)->print();
            cout<<endl;
        }
    }
}