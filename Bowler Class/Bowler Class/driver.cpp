/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignemnt: 6
 * Date: 2/10/2023
 * Program Description: Implement and test a Bowler class and its child JuniorBowler
 * File: driver.cpp
*/

//include junior bowler header, which include bowler header
#include "JuniorBowler.h"

int main()
{
    //calls empty constructor for Bowler class
    Bowler john;
    john.print();

    //tests setBowler for Bowler Class
    john.setBowler("John", "Jenny", 99, 75, 80);
    john.print();

    //calls the second constructor to set information for Bowler Class
    Bowler kenny("Kenny", "Jenny", 100, 100, 100);
    kenny.print();
    
    //calls empty constructor for JuniorBowler class
    JuniorBowler johnny;
    johnny.print();

    //tests setBowler for JuniorBowler Class
    johnny.setJuniorBowler("Johnny", "Jenny", 99, 75, 80, 25, 2, 'M');
    johnny.print();

    //calls the second constructor to set information for JuniorBowler Class
    JuniorBowler kenedy("Kenedy", "Jenny", 100, 100, 100, 30, 1, 'F');
    kenedy.print();
}
