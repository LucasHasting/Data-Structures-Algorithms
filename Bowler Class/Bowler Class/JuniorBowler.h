/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignemnt: 6
 * Date: 2/10/2023
 * Program Description: Implement and test a Bowler class and its child JuniorBowler
 * File: JuniorBowler.h
*/

//include header guards
#ifndef JUNIOR_BOWLER_H
#define JUNIOR_BOWLER_H

//inlcude Bowler header
#include "Bowler.h"

//Declare memeber variables/methods
class JuniorBowler : public Bowler {
      int age;
      int numAbsences;
      char gender;
  public:
      JuniorBowler();
      JuniorBowler(string, string, int, int, int, int, int, char);
      void setJuniorBowler(string, string, int, int, int, int, int, char);
      int getAge();
      int getNumAbsences();
      char getGender();
      void print();
};

#endif
