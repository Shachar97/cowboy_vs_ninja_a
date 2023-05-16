#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include <string.h>
using namespace std;

namespace ariel{
    Character::Character(string name,Point location):_name(name),_location(location),_hits(100){
        // this->set(location.getX(),location.getY());
        // this->_hits=10;
    }
    Character::~Character(){}
    bool Character::isAlive(){ return _hits>0;}
    string Character::getName() const {return _name;}
    int Character::getHits() const {return _hits;}
    void Character::setHits(int lives){
        _hits=lives;
    }
    double Character::distance(const Character& other) const{
        return this->getLocation().distance(other.getLocation());
    }
    void Character::setName(string name){this->_name=name;}
    void Character::hit(int damage){
        if(this->getHits()-damage < 0){
            this->setHits(0);
        }else{
            this->setHits(this->getHits()-damage);
        }
    }
    Point Character::getLocation() const {
        return this->_location;
    }
    void Character::setLocation(Point location){
        this->_location=location;
    }

}