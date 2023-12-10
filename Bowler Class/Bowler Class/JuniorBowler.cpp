/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignemnt: 6
 * Date: 2/10/2023
 * Program Description: Implement and test a Bowler class and its child JuniorBowler
 * File: JuniorBowler.cpp
*/

//include header file
#include "JuniorBowler.h"

/*
 * Method Name: JuniorBowler
 * Method Decription: Contructor for the JuniorBowler Class with no parameters
 * Incoming: None
 * Outgoing: None
 * Return: None
*/  
JuniorBowler::JuniorBowler() : Bowler()
{
    age = 0;
    numAbsences = 0;
    gender = '0';
}

/*
 * Method Name: Bowler
 * Method Decription: Contructor for the JuniorBowler Class with parameters
 * Incoming: fn, ln, g1, g2, g3, a, na, g
 * Outgoing: None
 * Return: None
*/  
JuniorBowler::JuniorBowler(string fn, string ln, int g1, int g2, int g3, int a, int na, char g) 
: Bowler (fn, ln, g1, g2, g3)
{
    age = a;
    numAbsences = na;
    gender = g;
}

/*
 * Method Name: setBowler
 * Method Decription: Sets the data for the JuniorBowler object
 * Incoming: fn, ln, g1, g2, g3, a, na, g
 * Outgoing: None
 * Return: None
*/  
void JuniorBowler::setJuniorBowler(string fn, string ln, int g1, int g2, int g3, int a, int na, char g)
{
    Bowler::setBowler(fn, ln, g1, g2, g3);
    age = a;
    numAbsences = na;
    gender = g;
}

/*
 * Method Name: getAge
 * Method Decription: getter for the age variable
 * Incoming: None
 * Outgoing: age
 * Return: age
*/  
int JuniorBowler::getAge()
{
    return age;
}

/*
 * Method Name: getnumAbsences
 * Method Decription: getter for the numAbsences variable
 * Incoming: None
 * Outgoing: numAbsences
 * Return: numAbsences
*/  
int JuniorBowler::getNumAbsences()
{
    return numAbsences;
}

/*
 * Method Name: getGender
 * Method Decription: getter for the gender variable
 * Incoming: None
 * Outgoing: gender
 * Return: gender
*/  
char JuniorBowler::getGender()
{
    return gender;
}

/*
 * Method Name: print
 * Method Decription: displays the data in the JuniorBowler object
 * Incoming: None
 * Outgoing: None
 * Return: None
*/  
void JuniorBowler::print()
{
    Bowler::print();
    cout << "Age: " << age << endl
	 << "Number of Absences: " << numAbsences << endl
	 << "Gender: " << gender << endl;
}
