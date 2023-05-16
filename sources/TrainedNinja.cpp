/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/TrainedNinja.cpp- implementation of TrainedNinja class
 * @class TrainedNinja
 * @extends Ninja
 * class represent Ninja of "TrainedNinja" type unit, in the "cowboy_vs_ninja" game
 * 
 * @author Shachar Ketz
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "TrainedNinja.hpp"

namespace ariel{
    TrainedNinja::TrainedNinja(string name,Point location){
        this->setName(name);
        setLocation(location);
        setSpeed(12);
        setHits(120);
    }
    
    TrainedNinja::~TrainedNinja(){}

    void TrainedNinja::move(Character* enemy){
        Point new_location=moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed());
        this->setLocation(new_location);
    }
}