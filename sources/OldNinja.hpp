#ifndef OLD_NINJA_HPP
#define OLD_NINJA_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel{
    class OldNinja: public Ninja{

    public:
        OldNinja(string name,Point location);
        ~OldNinja();
        void move(Character* enemy) override;
    
    };
}

#endif