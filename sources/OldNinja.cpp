#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "OldNinja.hpp"

namespace ariel{
    OldNinja::OldNinja(string name,Point location){
        this->setName(name);
        this->setLocation(location);
        setSpeed(8);
        setHits(150);
    }
    OldNinja::~OldNinja(){}
    void OldNinja::move(Character* enemy){
        Point new_location=moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed());
        this->setLocation(new_location);
    }
}