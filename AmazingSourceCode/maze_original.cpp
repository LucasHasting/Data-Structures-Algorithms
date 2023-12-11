#include <iostream>
#include <fstream>
#include <unistd.h>

using namespace std;
const int MAX_DIM=40;
void readMaze (char maze[][MAX_DIM], int &rows, int &cols, int &currRow, int &currCol);
void displayMaze (char maze[][MAX_DIM], int rows, int cols);
bool move(char maze[][MAX_DIM], int rows, int cols, int currRow, int currCol);
bool unoccupied (char maze[][MAX_DIM], int rows, int cols, int currRow, int currCol);

int main()
{
  int rows=0, cols=0, currRow=0, currCol=0;
  char maze[MAX_DIM][MAX_DIM];
  readMaze (maze, rows, cols, currRow, currCol);

  if (move (maze, rows, cols, currRow, currCol))
    cout << "Solved" << endl;
  else
    cout << "No Solution" << endl;
  return 0;
}

bool unoccupied (char maze[][MAX_DIM], int rows, int cols, int currRow, int currCol)
{
  if (maze[currRow][currCol]!='.' && maze[currRow][currCol]!='@' && maze[currRow][currCol]!='X' && 
       currRow>=0 && currCol>=0 && currRow<=rows && currCol<=cols)
   {
    if (maze[currRow][currCol] == 'O')
       maze[currRow][currCol] = '@';
    return true;
   }
  else
    return false;
}


bool move(char maze[][MAX_DIM], int rows, int cols, int currRow, int currCol)
{
  static bool done=false;
  cout << "Row: " << currRow << " Col: " << currCol << endl;

  if (maze[currRow][currCol] == 'F')
  {
    done = true;
    return done;
  }

    sleep(1);     
    displayMaze(maze,rows,cols);
    if (unoccupied(maze,rows,cols,currRow-1,currCol) && !done)
      move(maze,rows,cols,currRow-1,currCol);

    if (unoccupied(maze,rows,cols,currRow+1,currCol) && !done)
      move(maze,rows,cols,currRow+1,currCol);

    if (unoccupied(maze,rows,cols,currRow,currCol+1) && !done)
      move(maze,rows,cols,currRow,currCol+1);

    if (unoccupied(maze,rows,cols,currRow,currCol-1) && !done)
      move(maze,rows,cols,currRow,currCol-1);
 

  if (!done)
    maze[currRow][currCol] = '.';

  return done;
}

void readMaze (char maze[][MAX_DIM], int &rows, int &cols, int &currRow, int &currCol)
{
  ifstream infile;
  string filename;
  do
  {
    cout << "Enter file name: ";
    getline(cin,filename);
    infile.open(filename.c_str());
  } while (infile.fail());

  infile >> rows >> cols;
  for (int r=0; r<rows; r++)
    for (int c=0; c<cols; c++)
	  {
        infile >> ws >> maze[r][c];
        if (maze[r][c] == 'S')
		  {
        	maze[r][c] = '@';
			currRow = r;
			currCol = c;
		  }
	  }
  infile.close();
}
  

void displayMaze (char maze[][MAX_DIM], int rows, int cols)
{
  cout << endl;
  for (int r=0; r<rows; r++)
   {
     for (int c=0; c<cols; c++)
       if (maze[r][c] == 'O')
	     cout << " ";
	   else
	     cout << maze[r][c];
       cout << endl;
    } 
  cout << endl;
}
