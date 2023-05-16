/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/OldNinja.hpp- declaration of OldNinja class
 * @class OldNinja
 * @extends Ninja
 * class represent Ninja of "Oldninja" type unit, in the "cowboy_vs_ninja" game
 * 
 * @author Shachar Ketz
*/

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

    /**
     * @class OldNinja
     * @extends Ninja
     * class represent Ninja of "Oldninja" type unit, in the "cowboy_vs_ninja" game.
     * OldNinja speed-8, hits(lives)-150
    */
    class OldNinja: public Ninja{

    public:

        /**
         * constructor
         * @param name string the Ninja name
         * @param locationpoint in  the game 
         * 
         * @details
         *  speed-8
         *  hits(lives)-150
        */
        OldNinja(string name,Point location);

        /**
         * destructor
        */
        ~OldNinja();

        /**
         * the Ninja move toward the given enemy character in her speed (8 M).
         *  if the enemy closer then the speed, the ninja will stop on the enemy location
         * @param enemy character pointer
         * 
        */
        void move(Character* enemy) override;
    
    };
}

#endif