#ifndef CHARACTER_HPP
#define CHARACTER_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"

using namespace std;
namespace ariel{
    class Character: public Point
    {
    private:
        int _hits;
        string _name;
        Point _location;
    public:
        Character(string name="NPC", Point location=Point(0,0));
        virtual ~Character();

        int getHits() const;
        void setHits(int lives);
        void setName(string name);
        bool isAlive();

        double distance(const Character& other) const;

        void hit(int damage);

        string getName() const;
        
        Point getLocation() const;
        void setLocation(Point location);
        virtual string print()=0;
    
    };
}
#endif