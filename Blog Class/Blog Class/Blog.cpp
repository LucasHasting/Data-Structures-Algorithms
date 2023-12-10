/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignment: 3
 * Date: 1/29/2023
 * Program Description: Create a blog class, add blogs to it and display them, and create a website with them
 * File: Blog.cpp
*/

//include the blog class header
#include "Blog.h"

/*
 * Method Name: Blog
 * Method Description: Constructor for the Blog class
 * Incoming: None
 * Outgoing: None
 * Return: None
*/
Blog::Blog()
{
    authorFirst = "";
    authorLast = "";
    content = "";
    month = 0;
    day = 0;
    year = 0;
}

/*
 * Method Name: setBlog
 * Method Description: Setter for the Blog class, sets all member variables
 * Incoming: authorF, authorL, Content, Month, Day, Year
 * Outgoing: None
 * Return: None
*/
void Blog::setBlog(string authorF, string authorL, string Content, int Month, int Day, int Year)
{
    authorFirst = authorF;
    authorLast = authorL;
    content = Content;
    month = Month;
    day = Day;
    year = Year;

    //end
    return;
}

/*
 * Method Name: getAuthorFirst
 * Method Description: Getter for the Blog class, gets authorFirst
 * Incoming: None
 * Outgoing: authorFirst
 * Return: authorFirst
*/
string Blog::getAuthorFirst() const
{
    return authorFirst;
}

/*
 * Method Name: getAuthorLast
 * Method Description: Getter for the Blog class, gets authorLast
 * Incoming: None
 * Outgoing: authorLast
 * Return: authorLast
*/
string Blog::getAuthorLast() const
{
    return authorLast;
}

/*
 * Method Name: getContent
 * Method Description: Getter for the Blog class, gets content
 * Incoming: None
 * Outgoing: content
 * Return: content
*/
string Blog::getContent() const
{
    return content;
}

/*
 * Method Name: getMonth
 * Method Description: Getter for the Blog class, gets month
 * Incoming: None
 * Outgoing: month
 * Return: month
*/
int Blog::getMonth() const
{
    return month;
}

/*
 * Method Name: getDay
 * Method Description: Getter for the Blog class, gets day
 * Incoming: None
 * Outgoing: day
 * Return: day
*/
int Blog::getDay() const
{
    return day;
}

/*
 * Method Name: getYear
 * Method Description: Getter for the Blog class, gets year
 * Incoming: None
 * Outgoing: year
 * Return: year
*/
int Blog::getYear() const
{
    return year;
}

/*
 * Method Name: totalDays
 * Method Description: Gets the total days from the date of the blog
 * Incoming: None
 * Outgoing: days
 * Return: days
*/
int Blog::totalDays() const
{
    //int array with all the days of each month
    const int MONTH_DAYS[] = {31,28,31,30,31,30,31,31,30,31,30,31};

    //gets all the days from previous years and the current month
    int days = (getYear() - 1) * 365 + getDay();

    //adds the days from each month until the current month
    for (int i = 0; i < getMonth() - 1; i++)
        days += MONTH_DAYS[i];

    //adds in the leap years
    days += getYear() / 4 - getYear() / 100 + getYear() / 400;

    //end
    return days;
}

/*
 * Method Name: operator <
 * Method Description: Overloads the < operator to compare blogs
 * Incoming: right
 * Outgoing: true or false
 * Return: true or false
*/
bool Blog::operator<(Blog right) const
{
    if (totalDays() < right.totalDays())
	    return true;
    else
	    return false;
}
