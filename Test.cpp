#include "doctest.h"
#include <iostream>
#include <fstream>
#include <sstream>
#include <stdexcept>
#include <string>
#include <cmath>
#include "sources/Point.hpp"
#include "sources/Character.hpp"
#include "sources/Ninja.hpp"
#include "sources/YoungNinja.hpp"
#include "sources/OldNinja.hpp"
#include "sources/TrainedNinja.hpp"
#include "sources/Cowboy.hpp"
#include "sources/Team.hpp"

using namespace ariel;
using namespace std;

TEST_SUITE("Point class tests") {
    Point p1(1,1);
    Point p2;//default constructor (0,0)
    Point p3(0,0);
    Point p4(5,0);
    Point p5(-5,0);
    Point p6(0,5);
    Point p7(0,-5);


    TEST_CASE("operator=, ==, !="){
        CHECK_EQ(p1.getX(),1);
        CHECK_EQ(p1.getY(),1);
        CHECK_EQ(p2.getX(),0);
        CHECK_EQ(p2.getY(),0);
        CHECK_EQ(p2,p3);
        CHECK_NE(p1,p2);
        p1=p7;
        CHECK_EQ(p1,p7);
    }

    TEST_CASE("getters & setters"){
        p1.set(0,0);
        CHECK_EQ(p1,p2);
        p1.setX(5);
        CHECK_EQ(p1.getX(),5);
        CHECK_EQ(p1.getY(),0);
        p1.setY(2);
        CHECK_EQ(p1.getX(),5);
        CHECK_EQ(p1.getY(),2);
    }

    TEST_CASE("distance"){

        CHECK_EQ(p2.distance(p3),0);

        /*on the same axis*/
        CHECK_EQ(p2.distance(p4),5);
        CHECK_EQ(p2.distance(p5),5);
        CHECK_EQ(p4.distance(p2),5);
        CHECK_EQ(p5.distance(p2),5);
        CHECK_EQ(p4.distance(p5),10);
        CHECK_EQ(p5.distance(p4),10);


        CHECK_EQ(p2.distance(p6),5);
        CHECK_EQ(p2.distance(p7),5);
        CHECK_EQ(p6.distance(p2),5);
        CHECK_EQ(p7.distance(p2),5);
        CHECK_EQ(p6.distance(p7),10);
        CHECK_EQ(p7.distance(p6),10);

        double solution = sqrt(50.0);
        CHECK_EQ(p4.distance(p7),solution);
    }

    TEST_CASE("moveToward function"){
        p1=Point::moveTowards(p2, p6, 3);
        CHECK_EQ(p1,Point(0,3));
        p1=Point::moveTowards(p2, p4, 3);
        CHECK_EQ(p1,Point(3,0));

        p1=Point::moveTowards(p2, p5, 3);
        CHECK_EQ(p1,Point(-3,0));
        p1=Point::moveTowards(p2, p7, 3);
        CHECK_EQ(p1,Point(0,-3));
    }
    
}
TEST_SUITE("Cowboy & Ninja's class tests") {

    Cowboy TheGood("Blondie",Point(0,0));
    Cowboy TheBad("Angel Eyes",Point(5,0));
    Cowboy TheUgly("Tuco",Point(0,-5));
    
    

    TEST_CASE("Cowboy ammo & live"){
        
        /*check constructor*/
        CHECK_EQ(TheGood.getHits(),110);
        CHECK_EQ(TheBad.getHits(),110);
        CHECK_EQ(TheUgly.getHits(),110);
        
        CHECK_EQ(TheGood.getLocation(),Point(0,0));
        CHECK_EQ(TheBad.getLocation(),Point(5,0));
        CHECK_EQ(TheUgly.getLocation(),Point(0,-5));
        
        /*check shoot(), isAlive() & hasboolets() funcs*/
        for(int i=1;i<=5;i++){
            TheGood.shoot(&TheBad);
            CHECK_EQ(TheGood.hasboolets(),true);
            CHECK_EQ(TheBad.isAlive(),true);
            CHECK_EQ(TheBad.getHits(),110-(i*10));
        }

        TheGood.shoot(&TheBad);
        CHECK_EQ(TheGood.hasboolets(),false);
        CHECK_EQ(TheBad.isAlive(),true);
        CHECK_EQ(TheBad.getHits(),110-60);
        CHECK_THROWS_AS(TheGood.shoot(&TheBad),std::runtime_error);
        CHECK_EQ(TheGood.hasboolets(),false);
        CHECK_EQ(TheBad.isAlive(),true);
        CHECK_EQ(TheBad.getHits(),110-60);

        /*check reload() func*/
        TheGood.reload();
        CHECK_EQ(TheGood.hasboolets(),true);
        for(int i=1;i<=4;i++){
            TheGood.shoot(&TheBad);
            CHECK_EQ(TheGood.hasboolets(),true);
            CHECK_EQ(TheBad.isAlive(),true);
            CHECK_EQ(TheBad.getHits(),50-(i*10));
        }
        
        /*check exceptions*/
        TheGood.shoot(&TheBad);
        CHECK_EQ(TheBad.isAlive(),false);
        CHECK_EQ(TheBad.getHits(),0);
        CHECK_THROWS_AS(TheGood.shoot(&TheBad),std::runtime_error); /*shooting dead men*/
    }

    OldNinja Leonardo("Leonardo",Point(0.1,0.1));
    TrainedNinja Raphael("Raphael",Point(0.3,0.3));
    YoungNinja  Michelangelo("Michelangelo",Point(0.6,0.6));

    TEST_CASE("Ninja attack & live"){
        
        CHECK_EQ(Leonardo.getHits(),150);
        CHECK_EQ(Raphael.getHits(),120);
        CHECK_EQ(Michelangelo.getHits(),100);
        
        CHECK_EQ(Leonardo.getLocation(),Point(0.1,0.1));
        CHECK_EQ(Raphael.getLocation(),Point(0.3,0.3));
        CHECK_EQ(Michelangelo.getLocation(),Point(0.6,0.6));

        for(int i=1;i<3;i++){
            Leonardo.slash(&Raphael);
            CHECK_EQ(Raphael.isAlive(),true);
            CHECK_EQ(Raphael.getHits(),120-(i*40));
        }
        Leonardo.slash(&Raphael);
        CHECK_EQ(Raphael.isAlive(),false);
        CHECK_EQ(Raphael.getHits(),0);
        CHECK_NOTHROW(Michelangelo.slash(&Leonardo));//distance check
        CHECK_THROWS_AS(Leonardo.slash(&Raphael),std::runtime_error);/*slasing dead*/
    }

    TEST_CASE("self hurting & zombies"){
        CHECK_THROWS_AS(Leonardo.slash(&Leonardo),std::runtime_error);
        CHECK_THROWS_AS(TheUgly.shoot(&TheUgly),std::runtime_error);

        CHECK_THROWS_AS(Raphael.slash(&Leonardo),std::runtime_error);
        CHECK_THROWS_AS(TheBad.shoot(&TheUgly),std::runtime_error);
    }

    
    TEST_CASE("Ninja movement"){
        /*reset ninjas & cowboys*/
        TheBad.setHits(110);
        TheGood.setHits(110);
        TheUgly.setHits(110);

        Leonardo.setHits(150);
        Raphael.setHits(120);
        Michelangelo.setHits(100);

        CHECK_EQ(TheBad.getHits(),(110));
        CHECK_EQ(TheGood.getHits(),(110));
        CHECK_EQ(TheUgly.getHits(),(110));

        TheBad.setLocation(Point(20,0));
        TheGood.setLocation(Point(0,20));
        TheUgly.setLocation(Point(-20,0));

        Leonardo.setLocation(Point(0,0));
        Raphael.setLocation(Point(0,0));
        Michelangelo.setLocation(Point(0,0));

        CHECK_EQ(TheBad.getLocation(),Point(20,0));
        CHECK_EQ(TheGood.getLocation(),Point(0,20));
        CHECK_EQ(TheUgly.getLocation(),Point(-20,0));

        CHECK_EQ(Leonardo.getLocation(),Point(0,0));
        CHECK_EQ(Raphael.getLocation(),Point(0,0));
        CHECK_EQ(Michelangelo.getLocation(),Point(0,0));

        Leonardo.move(&TheBad);//+8
        Raphael.move(&TheGood);//+12
        Michelangelo.move(&TheUgly);//+14

        CHECK_EQ(Leonardo.getLocation(),Point(8,0));
        CHECK_EQ(Raphael.getLocation(),Point(0,12));
        CHECK_EQ(Michelangelo.getLocation(),Point(-14,0));

        CHECK_THROWS_AS(Leonardo.slash(&TheBad),std::runtime_error);
        CHECK_THROWS_AS(Raphael.slash(&TheGood),std::runtime_error);
        CHECK_THROWS_AS(Michelangelo.slash(&TheUgly),std::runtime_error);

        CHECK_EQ(TheBad.getHits(),(110));
        CHECK_EQ(TheGood.getHits(),(110));
        CHECK_EQ(TheUgly.getHits(),(110));

        Leonardo.move(&TheBad);//+8
        Raphael.move(&TheGood);//+12
        Michelangelo.move(&TheUgly);//+14

        CHECK_EQ(Leonardo.getLocation(),Point(16,0));
        CHECK_EQ(Raphael.getLocation(),Point(0,20));
        CHECK_EQ(Michelangelo.getLocation(),Point(-20,0));

        CHECK_THROWS_AS(Leonardo.slash(&TheBad),std::runtime_error);
        CHECK_NOTHROW(Raphael.slash(&TheGood));
        CHECK_NOTHROW(Michelangelo.slash(&TheUgly));

        CHECK_EQ(TheBad.getHits(),(110));
        CHECK_EQ(TheGood.getHits(),(110-40));
        CHECK_EQ(TheUgly.getHits(),(110-40));

        Leonardo.move(&TheBad);//+8
        Raphael.move(&TheGood);//+12
        Michelangelo.move(&TheUgly);//+14

        CHECK_EQ(Leonardo.getLocation(),Point(20,0));
        CHECK_EQ(Raphael.getLocation(),Point(0,20));
        CHECK_EQ(Michelangelo.getLocation(),Point(-20,0));

        CHECK_NOTHROW(Leonardo.slash(&TheBad));
        CHECK_NOTHROW(Raphael.slash(&TheGood));
        CHECK_NOTHROW(Michelangelo.slash(&TheUgly));

        CHECK_EQ(TheBad.getHits(),(110-40));
        CHECK_EQ(TheGood.getHits(),(110-80));
        CHECK_EQ(TheUgly.getHits(),(110-80));
    }
}

TEST_SUITE("Teams Classes") {
    /*Team 1*/
    Cowboy* Sheriff = new Cowboy("Deputy",Point(0,5));
    Cowboy* Billy = new Cowboy("Billy The kid",Point(10,5));
    Cowboy* TheGood = new Cowboy("Blondie",Point(20,5));
    Cowboy* TheBad = new Cowboy("Angel Eyes",Point(30,5));
    Cowboy* TheUgly = new Cowboy("Tuco",Point(40,5));

    OldNinja* Splinter = new OldNinja("Splinter",Point(5,0));
    OldNinja* Donatello = new OldNinja("Donatello",Point(15,0));
    TrainedNinja* Raphael = new TrainedNinja("Raphael",Point(25,0));
    YoungNinja*  Michelangelo = new YoungNinja("Michelangelo",Point(35,0));
    YoungNinja* Leonardo = new YoungNinja("Leonardo",Point(45,0));

    /*Team 2*/
    Cowboy* John = new Cowboy("John Wesley Hardin",Point(5,15));
    Cowboy* Frank = new Cowboy("Frank James",Point(15,15));
    Cowboy* Peters = new Cowboy("Peters Ringo",Point(25,15));
    Cowboy* Miller = new Cowboy("Jim Miller",Point(35,15));
    Cowboy* Sam = new Cowboy("Sam Bass",Point(45,15));

    OldNinja* Kakashi = new OldNinja("Kakashi Hatake",Point(0,20));
    OldNinja* Scorpion = new OldNinja("Scorpion",Point(10,20));
    TrainedNinja* Ryu = new TrainedNinja("Ryu Hayabusa",Point(20,20));
    YoungNinja*  Tsunade = new YoungNinja("Tsunade",Point(30,20));
    YoungNinja* Naruto = new YoungNinja("Naruto Uzumaki",Point(40,20));
    
    Team Sherif_Team(Sheriff);
    Team2 John_Team(John);

    TEST_CASE("adding member to the group"){

        CHECK_EQ(Sherif_Team.getSize(),1);
        CHECK_EQ(John_Team.getSize(),1);

        Sherif_Team.add(Splinter);
        CHECK_EQ(Sherif_Team.getSize(),2);
        Sherif_Team.add(Billy);
        CHECK_EQ(Sherif_Team.getSize(),3);
        Sherif_Team.add(Donatello);
        CHECK_EQ(Sherif_Team.getSize(),4);
        Sherif_Team.add(TheGood);
        CHECK_EQ(Sherif_Team.getSize(),5);
        Sherif_Team.add(Raphael);
        CHECK_EQ(Sherif_Team.getSize(),6);
        Sherif_Team.add(TheBad);
        CHECK_EQ(Sherif_Team.getSize(),7);
        Sherif_Team.add(Michelangelo);
        CHECK_EQ(Sherif_Team.getSize(),8);
        Sherif_Team.add(TheUgly);
        CHECK_EQ(Sherif_Team.getSize(),9);
        Sherif_Team.add(Leonardo);
        CHECK_EQ(Sherif_Team.getSize(),10);

        auto Joker = new Cowboy("Joker",Point(0,0));
        CHECK_THROWS_AS(Sherif_Team.add(Joker),std::runtime_error);
        CHECK_EQ(Sherif_Team.getSize(),10);
        delete Joker;

        John_Team.add(Frank);
        John_Team.add(Peters);
        John_Team.add(Miller);
        John_Team.add(Sam);
        CHECK_THROWS_AS(John_Team.add(Sam),std::runtime_error);
        CHECK_EQ(John_Team.getSize(),5);
        John_Team.add(Kakashi);
        John_Team.add(Scorpion);
        John_Team.add(Ryu);
        John_Team.add(Tsunade);
        John_Team.add(Naruto);

    }

    TEST_CASE("Attack"){

        cout<<"Team:"<<endl;
        Sherif_Team.print();
        cout<<endl<<"Team2"<<endl;
        John_Team.print();
        cout<<endl;
        

        Sherif_Team.attack(&John_Team);

        CHECK_NE(Splinter->getLocation(),Point(5,0));
        CHECK_NE(Donatello->getLocation(),Point(15,0));
        CHECK_NE(Raphael->getLocation(),Point(25,0));
        CHECK_NE(Michelangelo->getLocation(),Point(35,0));
        CHECK_NE(Leonardo->getLocation(),Point(45,0));

        CHECK_EQ(Splinter->getLocation(),Point(5,0).moveTowards(Point(5,0),Point(5,15),8));
        CHECK_EQ(Donatello->getLocation(),Point(15,0).moveTowards(Point(15,0),Point(5,15),8));
        CHECK_EQ(Raphael->getLocation(),Point(25,0).moveTowards(Point(25,0),Point(5,15),12));
        CHECK_EQ(Michelangelo->getLocation(),Point(35,0).moveTowards(Point(35,0),Point(5,15),14));
        CHECK_EQ(Leonardo->getLocation(),Point(45,0).moveTowards(Point(45,0),Point(5,15),14));

        CHECK_EQ(Sheriff->getBullets(),5);
        CHECK_EQ(Billy->getBullets(),5);
        CHECK_EQ(TheGood->getBullets(),5);
        CHECK_EQ(TheBad->getBullets(),5);
        CHECK_EQ(TheUgly->getBullets(),5);

        CHECK_EQ(John->getHits(),110-50);

        John->setHits(0);

        /*stillAlive update*/
        CHECK_EQ(John_Team.stillAlive(),9);
        
        Splinter->setLocation(Point(5,0));
        Leonardo->setLocation(Point(0,19.1));
    
        Sherif_Team.attack(&John_Team);

        /*the group chasing after the new leader*/
        CHECK_EQ(Splinter->getLocation(),Point(5,0).moveTowards(Point(5,0),Point(0,20),8));

        /*the ninja hwo close enough start the attack*/
        CHECK_EQ(Leonardo->getLocation(),Point(0,19.1));
        CHECK_EQ(Splinter->getHits(),150-90);
    }
    
}