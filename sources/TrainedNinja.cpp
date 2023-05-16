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