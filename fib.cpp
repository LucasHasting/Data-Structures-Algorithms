#include <iostream>
#include <ctime>
using namespace std;

long long fib (int);


int main ()
{
 double result;
 int start, end, difference, n;
 do
  {
    cout << "Enter n for Fibonacci sequence (-1 to quit): ";
    cin >> n;
    if (n != -1)
    {
    start = time(0);
    result = fib (n);
    end = time(0);
    difference = end - start;
    cout << "The " << n << "th Fibonacci number is " << result << endl;
    cout << "It took " << difference << " seconds to compute. " << endl;
   }
   } while (n != -1); 
    return 0;
}

long long fib (int num)
{
  if (num==0)
    return 0;
  else 
    if (num==1)
      return 1;
    else
      return fib(num-1) + fib(num-2);
}
