/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Cowboy.hpp- declarations of cowboy class
 * @class Cowboy
 * @extends Character
 * cowboy class represent "cowboy" character type unit, in the "cowboy_vs_ninja" game.
 * 
 * @author Shachar Ketz
*/

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

    /**
     * @class Cowboy
     * @extends Character
     * cowboy class represent "cowboy" character type unit, in the "cowboy_vs_ninja" game.
    */
    class Cowboy: public Character{

    private:
        int _bullets;
    public:

        /**
         * default constructor for cowboy unit.
         * 
         * every cowboy unit start with 110 hits and 6 bullets
         * 
         * the default cowboy name is Bill carson locate in (2.5,2.5).
        */
        Cowboy();

        /**
         * constructor for cowboy unit.
         * @param name of the cowboy
         * @param location point
         * every cowboy unit start with 110 hits and 6 bullets
        */
        Cowboy(string name, Point location);

        /**
         * destructor
        */
        ~Cowboy();
        
        /**
         * shoot action damage the given enemy with 10 hits(lives)
         * @param enemy character pointer
         * @exception sooting on dead characters / yourself / without bullets left
        */
        void shoot(Character *enemy);

        /**
         * @return boolean indication if bullets left
        */
        bool hasboolets();

        /**
         * @return how many bullets left
        */
        int getBullets() const;

        /**
         * resource the cowboy to 6 bullets
        */
        void reload();

        /**
         * @return string: "C: [name], [hits(lives)] [location]"
         * if character is dead the name will be in scope & no hits will be written
        */
        string print() override;
    };
}

#endif