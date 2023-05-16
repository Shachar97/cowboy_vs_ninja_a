/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/TrainedNinja.hpp- declaration of TrainedNinja class
 * @class TrainedNinja
 * @extends Ninja
 * class represent Ninja of "TrainedNinja" type unit, in the "cowboy_vs_ninja" game
 * 
 * @author Shachar Ketz
*/

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

    /**
     * @class TrainedNinja
     * @extends Ninja
     * class represent Ninja of "TrainedNinja" type unit, in the "cowboy_vs_ninja" game.
     * OldNinja speed-12, hits(lives)-120
    */
    class TrainedNinja: public Ninja{

    public:
        
        /**
         * constructor
         * @param name string the Ninja name
         * @param locationpoint in  the game 
         * 
         * @details
         *  speed-12
         *  hits(lives)-120
        */
        TrainedNinja(string name,Point location);

        /**
         * destructor
        */
        ~TrainedNinja();

        /**
         * the Ninja move toward the given enemy character in her speed (12 M).
         *  if the enemy closer then the speed, the ninja will stop on the enemy location
         * @param enemy character pointer
         * 
        */
        void move(Character* enemy) override;
    
    };
}

#endif