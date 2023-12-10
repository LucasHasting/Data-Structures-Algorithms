/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignemnt: 6
 * Date: 2/10/2023
 * Program Description: Implement and test a Bowler class and its child JuniorBowler
 * File: Bowler.cpp
*/

//include header file
#include "Bowler.h"

/*
 * Method Name: Bowler
 * Method Decription: Contructor for the Bowler Class with no parameters
 * Incoming: None
 * Outgoing: None
 * Return: None
*/  
Bowler::Bowler()
{
    firstName = "EMPTY";
    lastName = "EMPTY";
    game1 = 0;
    game2 = 0;
    game3 = 0;
}

/*
 * Method Name: Bowler
 * Method Decription: Contructor for the Bowler Class with parameters
 * Incoming: fn, ln, g1, g2, g3
 * Outgoing: None
 * Return: None
*/  
Bowler::Bowler(string fn, string ln, int g1, int g2, int g3)
{
    firstName = fn;
    lastName = ln;
    game1 = g1;
    game2 = g2;
    game3 = g3;
}

/*
 * Method Name: setBowler
 * Method Decription: Sets the data for the Bowler object
 * Incoming: fn, ln, g1, g2, g3
 * Outgoing: None
 * Return: None
*/  
void Bowler::setBowler(string fn, string ln, int g1, int g2, int g3)
{
    firstName = fn;
    lastName = ln;
    game1 = g1;
    game2 = g2;
    game3 = g3;
}

/*
 * Method Name: getFirstName
 * Method Decription: getter for the firstName variable
 * Incoming: None
 * Outgoing: firstName
 * Return: firstName
*/  
string Bowler::getFirstName()
{
    return firstName;
}

/*
 * Method Name: getLastName
 * Method Decription: getter for the lastName variable
 * Incoming: None
 * Outgoing: lastName
 * Return: lastName
*/  
string Bowler::getLastName()
{
    return lastName;
}

/*
 * Method Name: getGame1
 * Method Decription: getter for the game1 variable
 * Incoming: None
 * Outgoing: game1
 * Return: game1
*/  
int Bowler::getGame1()
{
    return game1;
}

/*
 * Method Name: getGame2
 * Method Decription: getter for the game2 variable
 * Incoming: None
 * Outgoing: game2
 * Return: game2
*/  
int Bowler::getGame2()
{
    return game2;
}

/*
 * Method Name: getGame3
 * Method Decription: getter for the game3 variable
 * Incoming: None
 * Outgoing: game3
 * Return: game3
*/  
int Bowler::getGame3()
{
    return game3;
}

/*
 * Method Name: print
 * Method Decription: displays the data in the Bowler object
 * Incoming: None
 * Outgoing: None
 * Return: None
*/  
void Bowler::print()
{
    cout << endl << getFirstName() << " " << getLastName()
	 << endl << "Game 1: " << getGame1()
	 << endl << "Game 2: " << getGame2()
	 << endl << "Game 3: " << getGame3()
	 << endl << "Total: " << getTotal()
	 << endl << "Average: " << getAverage() << endl;
}

/*
 * Method Name: getTotal 
 * Method Decription: Calculates the total points a Bowler has made
 * Incoming: None
 * Outgoing: None
 * Return: game1 + game2 + game3
*/  
int Bowler::getTotal()
{
    return getGame1() + getGame2() + getGame3();
}

/*
 * Method Name: getAverage 
 * Method Decription: Calculates the average points a Bowler has made
 * Incoming: None
 * Outgoing: None
 * Return: total / 3
*/  
double Bowler::getAverage()
{
    return getTotal() / 3.0;
}
