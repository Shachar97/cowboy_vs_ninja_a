/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Team.hpp- declarations of Team class
 * @class Team
 * 
 * class represent Team type unit, in the "cowboy_vs_ninja" game
 * Team unit is array that can contain at most of 10 characters pointers units
 * 
 * @author Shachar Ketz
*/

#ifndef TEAM_HPP
#define TEAM_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include "Character.hpp"
#include "Ninja.hpp"
#include "YoungNinja.hpp"
#include "OldNinja.hpp"
#include "TrainedNinja.hpp"
#include "Cowboy.hpp"

namespace ariel{

    class Team{
    
    private:
        Character* _myTeam[10];
        int _size;
    public:

        /**
         * constructor
        */
        Team();

        /**
         * constructor- with leader.
        */
        Team(Character* leader);

        /**
         * destructor-
         * delete all character's pointers in the team
        */
        ~Team();

        /**
         * @return count of characters pointers in the team (lives & dies)
        */
        int getSize() const;

        /**
         * increase the size +1
        */
        void incSize();

        /**
         * @return the character's pointer in the given index
         * @exception out of bound
        */
        Character* getIndex(int index);

        /**
         * add character's pointer to the team in index
         * @param index
         * @param character's pointer
        */
        void setIndex(int index,Character* soldier);

        /**
         * add character pointer in the end of the list.
        */
        int add(Character* soldier);

        /**
         * attack() receives a pointer to an enemy group. Attacking the enemy group will be done in the following way:
         * * First check if the leader of the attacking group is alive.
         * * Otherwise, a new leader must be chosen, who is the living character closest (in terms of location) to the dead leader.
         * * Then the group will choose a victim from among the enemy group.
         * * The victim is the member of the living enemy group who is closest to the leader of the attacking group.
         * * All living members of the attacking group will attack the chosen victim.
         * * Cowboys who have bullets in their guns will shoot the victim, and cowboys who don't have bullets will load their weapons.
         * * Ninjas within 1 meter of the victim will kill the victim, and ninjas further away will advance towards the victim.
         * * At each stage, if the victim If dead, a new victim will be chosen (which will be, again, the living enemy character closest to the leader of the attacking group).
         * * If there are no living members in the attacking group or the enemy group the attack will end.
         * 
         * attack orders: first Cowboys member, then Ninjas members
         * @param enemyTeam pointer
        */
        virtual int attack(Team* enemyTeam);

        /**
         * @return count of how many character in the group still alive
        */
        int stillAlive();

        /**
         * print to the screen all the characters members in the group.
         * first Cowboys, then Ninjas
        */
        virtual void print();
    
    };

    class Team2: public Team{
        public:

        /**
         * constructor.
        */
        Team2();

        /**
         * constructor- with leader.
        */
        Team2(Character* leader);

        /**
         * receives a pointer to an enemy group. Attacking the enemy group will be done in the following way:
         * * First check if the leader of the attacking group is alive.
         * * Otherwise, a new leader must be chosen, who is the living character closest (in terms of location) to the dead leader.
         * * Then the group will choose a victim from among the enemy group.
         * * The victim is the member of the living enemy group who is closest to the leader of the attacking group.
         * * All living members of the attacking group will attack the chosen victim.
         * * Cowboys who have bullets in their guns will shoot the victim, and cowboys who don't have bullets will load their weapons.
         * * Ninjas within 1 meter of the victim will kill the victim, and ninjas further away will advance towards the victim.
         * * At each stage, if the victim If dead, a new victim will be chosen (which will be, again, the living enemy character closest to the leader of the attacking group).
         * * If there are no living members in the attacking group or the enemy group the attack will end.
         * 
         *  attack orders: by order of joining the Team
         * 
         * @param enemyTeam pointer
        */
        int attack(Team* enemyTeam) override;

        /**
         * print to the screen all the characters members in the group.
         * by order of joining the Team
        */
        void print() override;
    };

    class SmartTeam: public Team{
        public:

        /**
         * constructor.
        */
        SmartTeam();
        
        /**
         * constructor- with leader.
        */
        SmartTeam(Character* leader);

        /*attackthe other groop To-DO*/
        int attack(Team* enemyTeam) override;

        /**
         * print to the screen all the characters members in the group.
         * by order of joining the Team
        */
        void print() override;
    };
}

#endif