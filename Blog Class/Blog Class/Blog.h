/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignment: 3
 * Date: 1/29/2023
 * Program Description: Create a blog class, add blogs to it and display them, and create a website with them
 * File: Blog.h
*/

//delcare libraries
#include <iostream>
#include <iomanip>
#include <fstream>
using namespace std;

//declare Blog class
class Blog
{
      //declare private memeber variables
    private:
	 string authorFirst, authorLast, content;
	 int month, day, year;

      //declare public methods and constructor
    public:
	 Blog();
	 void setBlog(string authorF, string authorL, string Content, int Month, int Day, int Year);
	 string getAuthorFirst() const;
	 string getAuthorLast() const;
	 string getContent() const;
	 int getMonth() const;
	 int getDay() const;
	 int getYear() const;
	 int totalDays() const;
	 bool operator<(Blog right) const;

};
