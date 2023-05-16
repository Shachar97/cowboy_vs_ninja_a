#ifndef TRAINED_NINJA_HPP
#define TRAINED_NINJA_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"

namespace ariel{
    class TrainedNinja: public Ninja{

    public:
        TrainedNinja(string name,Point location);
        ~TrainedNinja();
        void move(Character* enemy) override;
    
    };
}

#endif