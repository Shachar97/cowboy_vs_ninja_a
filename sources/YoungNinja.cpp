#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"

namespace ariel{
    YoungNinja::YoungNinja(string name,Point location){
        this->setName(name);
        setLocation(location);
        setSpeed(14);
        setHits(100);
    }
    YoungNinja::~YoungNinja(){}
    void YoungNinja::move(Character* enemy){
        Point new_location=moveTowards(this->getLocation(), enemy->getLocation(), this->getSpeed());
        this->setLocation(new_location);
    }
}