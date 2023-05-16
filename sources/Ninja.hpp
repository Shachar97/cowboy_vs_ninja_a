#ifndef NINJA_HPP
#define NINJA_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Point.hpp"
#include "Character.hpp"

using namespace std;
namespace ariel{
    class Ninja: public Character {
    
    private:
        int _speed;
    public:
        Ninja(string name="Ninjagoh", Point location=Point(0,0));
        ~Ninja();
    
        virtual void move(Character *enemy)=0;
        void slash(Character *enemy);
        string print() override;
        int getSpeed() const;
        void setSpeed(int speed);
    };
}

#endif