#include "stack.h"

int main()
{
    Stack<int> s1;
    Stack<double> s2;
    //Stack<JuniorBowler> s3;
    Stack<string> s4;
    
    s2.Print();
    s4.Push("dog");
    s4.Push("cat");
    s4.Print();
    s4.Push("horse");

    string thing;
    s4.Pop(thing);
    s4.Pop(thing);
    s4.Print();
    s4.Pop(thing);
    s4.Pop(thing);
    s4.Print();
}
