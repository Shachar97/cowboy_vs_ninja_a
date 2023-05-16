
#include <iostream>
#include <fstream>
#include <sstream>
#include <string>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
using namespace std;
namespace ariel{
    Ninja::Ninja(string name,Point location){
        setName(name);
        setLocation(location);
    }
    Ninja::~Ninja(){}
    void Ninja::slash(Character *enemy){
        if(this->isAlive() && distance(*enemy)<=1){
            enemy->hit(40);
        }
    }
    string Ninja::print(){
        string answer="N: ";
        if(this->isAlive()){
            answer += getName() + ": hits=" + to_string(getHits())+", location: "+getLocation().print();
        }else{
            answer +="(" +getName()+"), location: "+getLocation().print();
        }
        
        return answer;
    }
    int Ninja::getSpeed() const{return _speed;}
    void Ninja::setSpeed(int speed){ this->_speed=speed;}
}