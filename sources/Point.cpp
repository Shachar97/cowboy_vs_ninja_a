/**
 * @package "cowboy_vs_ninja_a"
 * @file sources/Point.cpp- implementation of Point class
 * @class Point
 * class represent Point- location on the "cowboy_vs_ninja" game
 * 
 * @author Shachar Ketz
*/

#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include "Point.hpp"
#include <cmath>
#include <string>
#include <limits>

using namespace std;

namespace ariel{

    Point::Point(double x,double y): _x(x),_y(y){}

    Point::~Point(){}

    double Point::getX() const {return this->_x;}

    double Point::getY() const {return this->_y;}

    void Point::set(double x, double y){ this->_x=x; this->_y=y;}

    void Point::setX(double x) {this->_x=x;}

    void Point::setY(double y) {this->_y=y;}
    
    double Point::distance(const Point& other) const{
        double d_x = this->getX() - other.getX();
        double d_y = this->getY() - other.getY();
        return std::sqrt(d_x*d_x + d_y*d_y);
    }

    Point& Point::operator= (const Point& other){
        this->set(other.getX(),other.getY());
        return *this;
    }

    bool Point::operator== (const Point& other) const {
        return (this->getX()==other.getX()) && (this->getY() == other.getY());
    }
    
    bool Point::operator!= (const Point& other) const {return !(*this==other);}

    string Point::print(){
        string answer= "(";
        answer+=to_string(this->getX());
        answer+=",";
        answer+=to_string(this->getY());
        answer+=")";
        
        return answer;
    }

    Point Point::moveTowards(const Point& src, const Point& dst, const double& road) {
        double dx = dst.getX() - src.getX();
        double dy = dst.getY() - src.getY();
        double distance = std::sqrt(dx * dx + dy * dy);

        if (road >= distance) {
            return dst;  
        } else {
            double ratio = road / distance;
            double mx = dx * ratio;
            double my = dy * ratio;
            return Point(src.getX() + mx, src.getY() + my);
        }
    }
}
