#include <iostream>
#include <fstream>
#include <iomanip>
#include "Classroom.cpp"
using namespace std;

const int MAX_CLASSROOMS = 2;
void addClassroom (Classroom classroom[], int &numClassrooms);
void displayClassrooms (Classroom classroom[], int numClassrooms);
void saveClassrooms (Classroom classroom[], int numClassrooms);
void loadClassroom (Classroom classroom[], int &numClassrooms);
void logMaker (Classroom classroom[], int numClassrooms);

int main()
{
	Classroom classroom[MAX_CLASSROOMS]; // Declaring classroom array
	int numClassrooms=0;

	loadClassroom(classroom, numClassrooms);
	
	//addClassroom(classroom, numClassrooms);
	displayClassrooms(classroom, numClassrooms);
	logMaker(classroom, numClassrooms);
	return 0;
}

void logMaker (Classroom classroom[], int numClassrooms)
{
	ofstream outfile;
	string filename;
	for (int i = 0; i < numClassrooms; i++)
	{
		filename = "./logs/" + classroom[i].getBuilding() + to_string(classroom[i].getRoom()) + ".txt";
		outfile.open(filename.c_str());
		
		outfile << classroom[i].getBuilding() << endl
		     << classroom[i].getRoom() << " "
		     << classroom[i].getSeats() << " "
		     << classroom[i].getWhiteboards()
		     << endl;
		
		outfile.close();
	}

}

void saveClassrooms (Classroom classroom[], int numClassrooms)
{
	ofstream outfile("rooms.txt");
	for (int i = 0; i < numClassrooms; i++)
		outfile << classroom[i].getBuilding() << endl
		     << classroom[i].getRoom() << " "
		     << classroom[i].getSeats() << " "
		     << classroom[i].getWhiteboards()
		     << endl;
	outfile.close();
}

void displayClassrooms (Classroom classroom[], int numClassrooms)
{
	cout << "Building       Room   Seats   Whtboards" << endl;  
	for (int i = 0; i < numClassrooms; i++)
		cout << setw(12) << classroom[i].getBuilding() 
		     << setw(6) << classroom[i].getRoom()
		     << setw(6) << classroom[i].getSeats()
		     << setw(6) << classroom[i].getWhiteboards()
		     << endl;
}

void loadClassroom (Classroom classroom[], int &numClassrooms)
{
	ifstream infile("rooms.txt");
	string theBuilding = ""; 
	int theRoom=0, theSeats=0, theBoards=0;

	getline(infile, theBuilding);
	
	//priming the input
	while(!infile.eof())
	{
	  infile >> theRoom;
	  infile >> theSeats;
	  infile >> theBoards;
	
	  classroom[numClassrooms++].setClassroom(theBuilding,theRoom,theSeats,theBoards);
	  infile >> ws;
	  getline(infile, theBuilding);
	}

	infile.close();
}

void addClassroom (Classroom classroom[], int &numClassrooms)
{
	string theBuilding = ""; 
	int theRoom=0, theSeats=0, theBoards=0;
	cout << "Building? ";
	getline(cin, theBuilding);
	cout << "Room? ";
	cin >> theRoom;
	cout << "Seats? ";
	cin >> theSeats;
	cout << "Whiteboards? ";
	cin >> theBoards >> ws;
	classroom[numClassrooms++].setClassroom(theBuilding,theRoom,theSeats,theBoards);
}
