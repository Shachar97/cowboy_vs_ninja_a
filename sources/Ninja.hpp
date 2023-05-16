/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Ninja.hpp- declaration of Ninja class
 * @class Ninja
 * @extends Character
 * abstract class represent character of "ninja" type unit, in the "cowboy_vs_ninja" game
 * 
 * @author Shachar Ketz
*/

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
        
    /**
     * @class Ninja
     * @extends Character
     * abstract class represent character of "ninja" type unit, in the "cowboy_vs_ninja" game
     * @details
     * any Ninja character have the ability to move toward other character and to slash near (1 M) character (40 hits damage).
     * YOungNinja- speed-14, hits(lives)-100
     * TrainedNinja speed-12, hits(lives)-120
     * OldNinja speed-8, hits(lives)-150
    */
    class Ninja: public Character {
    
    private:
        int _speed;
    public:

        /**
         * constructor
         * @param name string the Ninja name
         * @param locationpoint in  the game
         * 
        */
        Ninja(string name="Ninjagoh", Point location=Point(0,0));

        /**
         * destructor
        */
        ~Ninja();

        /**
         * pure virtual func.
         * the Ninja move toward the given enemy character in her speed (8/12/14).
         *  if the enemy closer then the speed, the ninja will stop on the enemy location
         * @param enemy character pointer
         * 
        */
        virtual void move(Character *enemy)=0;

        /**
         * given enemy get 40 hits damage if he near (less then 1 M) the Ninja
         * @param enemy character pointer
         * @exception the enemy is already dead or not near the Ninja
        */
        void slash(Character *enemy);

        /**
         * @return string: "N: [name], [hits(lives)] [location]"
         * if character is dead the name will be in scope & no hits will be written
        */
        string print() override;

        /**
         * @return speed of ninja, give access to _speed field for inheritance classes.
        */
        int getSpeed() const;

        /**
         * set speed of ninja, give access to _speed field for inheritance classes.
         * @param speed
        */
        void setSpeed(int speed);
    };
}

#endif