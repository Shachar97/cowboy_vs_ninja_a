#ifndef COWBOY_HPP
#define COWBOY_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include "Point.hpp"
#include "Character.hpp"

using namespace std;

namespace ariel{
    class Cowboy: public Character{
    private:
    
        int _bullets;

    public:
        Cowboy();
        Cowboy(string name, Point location);
        ~Cowboy();
        
        void shoot(Character *enemy);
        bool hasboolets();
        int getBullets() const;
        void reload();
        string print() override;
    };
}

#endif