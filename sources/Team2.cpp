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
    Team2::Team2():Team(){
        // _size=0;
        // for(int i=0;i<10;i++){
        //     _myTeam[i]=nullptr;
        // }
    }
    Team2::Team2(Character *leader):Team(leader){
        // _size=0;
        // this->add(leader);
    }
    // Team2::~Team2(){
    //     // for(int i=0;i<getSize();i++){
    //     //     delete getIndex(i);
    //     // }
    // }
    
    int Team2::attack(Team* enemyTeam){
        for(int i=0;i<getSize();i++){
                
                cout<<endl<<"Todo! build attack"<<endl;   
                getIndex(i)->hit(50);
        }
        return 1;
    }

    void Team2::print(){
        for(int i=0;i<getSize();i++){
            cout<<getIndex(i)->print();
            cout<<endl;
        }
    }
}