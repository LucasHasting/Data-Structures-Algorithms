#include <iostream>
using namespace std;

class Classroom
{
    private:
       string building;
       int room;
       int seats;
       int whiteboards;
    public:
       Classroom();
       Classroom(string,int,int,int);
       void setClassroom(string,int,int,int);
       string getBuilding() const;
       int getRoom() const;
       int getSeats() const;
       int getWhiteboards() const;
};
