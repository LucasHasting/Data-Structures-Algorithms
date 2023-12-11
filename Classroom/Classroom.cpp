#include "Classroom.h"

Classroom::Classroom()
{
    building = "";
    room = 0;
    seats = 0;
    whiteboards = 0;
}

Classroom::Classroom(string bldg, int rm, int st, int whtbrd)
{
    
    building = bldg;
    room = rm;
    seats = st;
    whiteboards = whtbrd;
}

void Classroom::setClassroom(string bldg, int rm, int st, int whtbrd)
{
    
    building = bldg;
    room = rm;
    seats = st;
    whiteboards = whtbrd;
}

string Classroom::getBuilding() const
{
    return building;
}

int Classroom::getRoom() const
{
    return room;
}

int Classroom::getSeats() const
{
    return seats;
}

int Classroom::getWhiteboards() const
{
    return whiteboards;
}
