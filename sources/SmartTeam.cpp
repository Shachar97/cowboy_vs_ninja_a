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
    SmartTeam::SmartTeam():Team(){
        // _size=0;
        // for(int i=0;i<10;i++){
        //     _myTeam[i]=nullptr;
        // }
    }
    SmartTeam::SmartTeam(Character *leader):Team(leader){
        // _size=0;
        // this->add(leader);
    }
    // SmartTeam::~SmartTeam(){
    //     for(int i=0;i<_size;i++){
    //         delete _myTeam[i];
    //     }
    // }
    
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