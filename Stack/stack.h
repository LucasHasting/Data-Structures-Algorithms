#include <iostream>
using namespace std;
template <class T>
class Stack;
template <class T>
class Node{
      T data;
      Node<T>* next;
      Node();
      Node(T);
      Node(T,Node<T>*);
      friend class Stack<T>;      
};
template <class T>
Node<T>::Node():next(NULL){}
template <class T>
Node<T>::Node(T item):data(item), next(NULL){}
template <class T>
Node<T>::Node(T item,Node<T>* n):data(item), next(n){}
//--------------------------------------------------------------
template <class T>
class Stack{
      Node<T>* top;
public:
      Stack();
      bool Push(T item);
      bool Pop(T& item);
      void Print()const;      
};
template <class T>
Stack<T>::Stack():top(NULL){}
template <class T>
bool Stack<T>::Push(T item){
     top = new Node<T>(item, top);     
     return top;
}
template <class T>
bool Stack<T>::Pop(T& item){
     bool pop = false;
     if (top){
        item = top->data;
        Node<T>* temp = top;
        top = top->next;
        delete temp;
        pop = true;
     }
     return pop;
}
template <class T>
void Stack<T>::Print()const{
     cout << endl << "****" << endl;
     Node<T> * temp = top;
     while (temp){
           cout << temp->data << endl;
           temp = temp->next;      
     }     
     cout  << "****" << endl;
}
