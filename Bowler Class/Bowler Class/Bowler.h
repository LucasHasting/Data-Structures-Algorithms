/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignemnt: 6
 * Date: 2/10/2023
 * Program Description: Implement and test a Bowler class and its child JuniorBowler
 * File: Bowler.h
*/

//include header guards
#ifndef BOWLER_H
#define BOWLER_H

//include input/output stream
#include <iostream>
using namespace std;

//declare member variables and methods
class Bowler{
    private:
      string firstName;
      string lastName;
      int game1;
      int game2;
      int game3;
    public:
      Bowler();
      Bowler(string, string, int, int, int);
      void setBowler(string, string, int, int, int);
      string getFirstName();
      string getLastName();
      int getGame1();
      int getGame2();
      int getGame3();
      void print();
      int getTotal();
      double getAverage();
};

#endif
