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
    class Team
    {
    // protected:
    private:
        Character* _myTeam[10];
        int _size;
    public:
        Team();
        Team(Character* leader);
        ~Team();
        int getSize() const;
        void incSize();
        Character* getIndex(int index);
        void setIndex(int index,Character* soldier);
        int add(Character* soldier);
        virtual int attack(Team* enemyTeam);
        int stillAlive();
        virtual void print();
    
    };
    class Team2: public Team{
        public:
        Team2();
        // ~Team2();
        Team2(Character* leader);
        int attack(Team* enemyTeam) override;
        void print() override;
    };
    class SmartTeam: public Team{
        public:
        SmartTeam();
        // ~SmartTeam();
        SmartTeam(Character* leader);
        int attack(Team* enemyTeam) override;
        void print() override;
    };
}

#endif