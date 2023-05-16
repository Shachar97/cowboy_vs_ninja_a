/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Team.cpp- implementation of Team class
 * @class Team
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
    Team::Team():_size(0){ }

    Team::Team(Character *leader):_size(0){

        this->add(leader);
    }

    Team::~Team(){
        for(int i=0;i < this->getSize(); i++){
            delete _myTeam[i];
        }
    }

    int Team::getSize() const {return this->_size;}

    Character* Team::getIndex(int index){
        if(getSize()<=index){
            return nullptr;
        }
        return _myTeam[index];
    }

    void Team::incSize(){_size++;}

    int Team::add(Character* soldier){

        if(this->getSize()<10){
            for(int i=0;i<this->getSize();i++){
                if(_myTeam[i]==soldier){
                    throw std::runtime_error("soldier already in the team\n");
                }
            }
            _myTeam[_size++]=soldier;
            return 1;
        }
        throw std::runtime_error("Team is full\n");
        return -1;
    }

    int Team::attack(Team* enemyTeam){
        for(int i=0;i<this->getSize();i++){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(_myTeam[i]);
            if(cowboy){
                
                cout<<endl<<"TODO! C build attack"<<endl;
                cowboy->hit(50);
            }
        }
        for(int i=0;i<this->getSize();i++){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(_myTeam[i]);
            if(!cowboy){
                
                cout<<endl<<"TODO! N build attack"<<endl;
                _myTeam[i]->hit(50);
            }
        }
        return 1;
    }

    int Team::stillAlive(){
        int count=0;
        for(int i=0;i<this->getSize();i++){
            if(_myTeam[i]->isAlive()){
                count++;
            }
        }
        return count;
    }

    void Team::print(){
        for(int i=0;i<this->getSize();i++){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(_myTeam[i]);
            if(cowboy){
                cout<<cowboy->print();
                cout<<endl;
            }
            
        }
        for(int i=0;i<this->getSize();i++){
            Cowboy* cowboy = dynamic_cast<Cowboy*>(_myTeam[i]);
            if(!cowboy){
                cout<<_myTeam[i]->print();
                cout<<endl;
            }
        }
    }
}