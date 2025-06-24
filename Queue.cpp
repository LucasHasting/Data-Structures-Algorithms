/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignment: 9
 * Date: 3/3/2023
 * Program Description: Template and test a Queue class
*/

#include <iostream>
using namespace std;

//declare constant
const int MAX_QUEUE = 5;

//template and declare class Queue
template <class T>
class Queue
{
private:
  //declare private member variables
  int front;
  int rear;
  int count;
  T item[MAX_QUEUE];

public:
  //declare public methods

  /*
   * Method Name: Queue
   * Method Description: constructor for the Queue class
   * Incoming: none
   * Outgoing: none
   * Return: none
  */ 
  Queue()
  {
      front = 0;
      rear = -1;
      count = 0;
  }

  /*
   * Method Name: full
   * Method Description: checks if the queue is full
   * Incoming: none
   * Outgoing: count == MAX_QUEUE
   * Return: count == MAX_QUEUE
  */ 
    bool full() const
    {
      return (count == MAX_QUEUE);
    }

  /*
   * Method Name: empty 
   * Method Description: checks if the queue is empty
   * Incoming: none
   * Outgoing: count == 0
   * Return: count == 0
  */ 
    bool empty() const
    {
      return (count == 0);
    }

  /*
   * Method Name: enqueue
   * Method Description: adds an item to the queue
   * Incoming: name
   * Outgoing: none
   * Return: none
  */ 
    void enqueue(T name)
    {
      if (!full())
      {
        rear = (rear + 1) % MAX_QUEUE;
        item[rear] = name;
        count++;
      }
      else
        cout << "Person Rejected - cannot add to a full queue" << endl;
    }

  /*
   * Method Name: dequeue 
   * Method Description: removes an item from the queue
   * Incoming: value
   * Outgoing: value, ok
   * Return: ok
  */ 
    bool dequeue(T &value)
    {
      bool ok=false;
      if (!empty())
        {
          value = item[front];
          front = (front + 1) % MAX_QUEUE;
          count--;
          ok=true;
        }
      else
        cout << "Cannot remove from an empty queue" << endl;
      return ok;
    }

  /*
   * Method Name: print
   * Method Description: print items in the queue
   * Incoming: none
   * Outgoing: none
   * Return: none
  */ 
    void print() const
    {
      cout << "FRONT: ";
      int spot = front;
      for (int i=0; i<count; i++)
      {
           cout << spot << ":" << item[spot] << " ";
           spot = (spot + 1) % MAX_QUEUE;
      }
      cout << "END" << endl;
    }

};

/*
 * Function Name: print
 * Function Description: output information on a templated queue
 * Incoming: queue, enqueue_items, dequeue_items, data
 * Outgoing: none
 * Return: none
*/ 
template <class T>
void print(Queue<T> queue, int enqueue_items, int dequeue_items, T data[])
{
  cout << "------------------------------------------------------------------------------" << endl;
  cout << "A queue example using a queue with max size of " << MAX_QUEUE << endl << endl;
  
  for (int i = 0; i < enqueue_items; i++){
  cout << data[i] << " is entering the queue" << endl;  
  queue.enqueue(data[i]);
  }
  
  cout << endl << "Queue: " << endl; 
  queue.print(); 
  cout << endl;
  
  for (int i = 0; i < dequeue_items; i++){
  T empty_data;
   
  if (queue.dequeue(empty_data))
    cout << empty_data << " has just left the queue" << endl;
  }
  
  cout << endl << "Queue: " << endl; 
  queue.print(); 
  
  cout << endl;
  cout << "------------------------------------------------------------------------------" << endl;
}

//main driver
int main()
{
  //declare templated queues 
  Queue<char> queue;
  Queue<double> queue2;
  Queue<int> queue3;
  
  //declare data to go in the queues
  char queue_items[] = {'a', 'b', 'c', 'd', 'e', 'f'};  
  double queue2_items[] = {1.1, 2.2, 3.3, 4.4, 5.5};  
  int queue3_items[] = {1};  

  //print/test each queue
  print<char>(queue, 6, 6, queue_items);
  print<double>(queue2, 5, 3, queue2_items);
  print<int>(queue3, 1, 3, queue3_items);

  //end
  return 0;
}
