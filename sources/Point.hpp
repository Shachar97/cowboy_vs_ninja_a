#ifndef POINT_HPP
#define POINT_HPP

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
using namespace std;
namespace ariel{
    class Point
    {
    // protected:
    private:
        double _x,_y;
    public:
        Point(double x=0, double y=0);
        ~Point();
    
        // Point getPoint() const;
        double getX() const;
        double getY() const;

        void set(double x,double y);
        void setX(double x);
        void setY(double y);

        double distance(const Point& other) const;

        Point& operator= (const Point& other);
        // Point operator+ (const Point& right_point);
        // Point operator- (const Point& right_point);
        bool operator== (const Point& other) const;
        bool operator!= (const Point& other) const;
        virtual string print();

        Point static moveTowards(const Point& src, const Point& dst, const double& road);
    };
}
#endif