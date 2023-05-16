/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/YoungNinja.hpp- declaration of YoungNinja class
 * @class YoungNinja
 * @extends Ninja
 * class represent Ninja of "YoungNinja" type unit, in the "cowboy_vs_ninja" game
 * 
 * @author Shachar Ketz
*/

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

    /**
     * @class OldNinja
     * @extends Ninja
     * class represent Ninja of "YoungNinja" type unit, in the "cowboy_vs_ninja" game.
     * OldNinja speed-14, hits(lives)-100
    */
    class YoungNinja: public Ninja{

    public:

        /**
         * constructor
         * @param name string the Ninja name
         * @param locationpoint in  the game 
         * 
         * @details
         *  speed-14
         *  hits(lives)-100
        */
        YoungNinja(string name,Point location);

        /**
         * destructor
        */
        ~YoungNinja();

        /**
         * the Ninja move toward the given enemy character in her speed (14 M).
         *  if the enemy closer then the speed, the ninja will stop on the enemy location
         * @param enemy character pointer
         * 
        */
        void move(Character* enemy) override;
    
    };
}

#endif