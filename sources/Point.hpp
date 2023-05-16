/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Point.hpp- declaration of Point class
 * @class Point
 * class represent Point- location on the "cowboy_vs_ninja" game
 * 
 * @author Shachar Ketz
*/

#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>

using namespace std;

namespace ariel{

    class Point {
    
    private:

        double _x,_y;

    public:

        /**
         * constructor
         * @param x axis
         * @param y axis
        */
        Point(double x=0, double y=0);

        /**
         * destructor
        */
        ~Point();
    
        // Point getPoint() const;
        /**
         * @return x axis
        */
        double getX() const;

        /**
         * @return y axis
        */
        double getY() const;

        /**
         * set Point x and y
         * @param x
         * @param y
        */
        void set(double x,double y);

        /**
         * set Point x
         * @param x
        */
        void setX(double x);

        /**
         * set Point x and y
         * @param x
        */
        void setY(double y);

        /**
         * return the distance between the Point to given Point
         * @param other point
         * @return the distance.
        */    
        double distance(const Point& other) const;

        /**
         * set the point from other point
        */
        Point& operator= (const Point& other);
        
        /**
         * @return indicate if both pointers on the same location
        */
        bool operator== (const Point& other) const;

        /**
         * @return boolean indication if both pointers are not in the same location
        */
        bool operator!= (const Point& other) const;

        /**
         * @return string "([x],[y])"
        */
        virtual string print();

        /**
         * Gets a source point, destination point and distance.
         * The function returns the closest point to the destination point, is at most the given distance from the source point.
         * @param src point
         * @param dst point
         * @param road meters toward dst
        */
        Point static moveTowards(const Point& src, const Point& dst, const double& road);
    };
}
#endif