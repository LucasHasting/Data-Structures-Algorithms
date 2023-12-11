#include <iostream>
using namespace std;

void moveDisks (int numDisks, int sourcePeg, int targetPeg, int sparePeg)
{
  static int count = 1;
  if (numDisks > 0)
    {
      moveDisks(numDisks-1, sourcePeg, sparePeg, targetPeg);
      cout << count++ << " Move disk from peg#" << sourcePeg << " to peg#" << targetPeg << endl;
      moveDisks(numDisks-1, sparePeg, targetPeg, sourcePeg);
    }
}

int main()
{
  int numDisks=0;
  cout << "How many disks to move? ";
  cin >> numDisks;
  moveDisks (numDisks, 1, 3, 2);

  return 0;
}
