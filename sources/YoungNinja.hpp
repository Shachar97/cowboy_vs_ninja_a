#ifndef YOUNG_NINJA_HPP
#define YOUNG_NINJA_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel{
    class YoungNinja: public Ninja{
    private:
        /* data */
    public:
        YoungNinja(string name,Point location);
        ~YoungNinja();
        void move(Character* enemy) override;
    
    };
}

#endif