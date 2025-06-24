/*
 * Name: Lucas Hasting
 * Course: CS 355
 * Assignment: 12
 * Date: 4/11/2023
 * Program Description: Create/Manipulate a Heap
*/

#include <iostream>
#include <iomanip>
using namespace std;

//creates the heap
void heapify(int arr[], int size, int root)
{
    int largest = root;
    int left = 2 * root + 1;
    int right = 2 * root + 2;

    if (left < size && arr[left] > arr[largest])
	   largest = left;

    if (right < size && arr[right] > arr[largest])
	   largest = left;

    if (largest != root)
    {
	   swap(arr[root], arr[largest]);
	   heapify(arr, size, largest);
    }

    return;
}

//builds the heap
void buildHeap(int arr[], int size, int root)
{
    for (int i = size/2-1; i>0; i--)
    {
	   heapify(arr,size,i);
    }

    return;
}

//display's the array
void printHeap(int arr[], int size)
{
    int itemsPerRow = 1, row = 1;
    for (int i = 0; i < size;)
    {
	   for (int k = 0; k < 3 * (5-row); k++)
		   cout << " ";
	   
	   for (int j = 0; j < itemsPerRow; j++, i++)
	   {
		   if (i < size)
		   	cout << left << setw(4) << arr[i];
	   }
   
           cout << endl;
           itemsPerRow *= 2;
           row++;
    }


    return;
}

//sorts the heap in asscending order
void heapSort(int arr[], int size)
{
    if (size < 1)
        return;
    
    buildHeap(arr, size, 0);
    
    for (int i = size - 1; i >= 0; i--)
    {
    	swap(arr[0], arr[i]);
	heapify(arr, i, 0);
    }
    
    return;
}

//removes the root from the heap
void heapDequeue(int arr[], int &size, int &element)
{
    if (size < 1){
        element = -1;
	return;
    }

    element = arr[0];
    size--;
    arr[0] = arr[size];
    
    heapify(arr, size, 0);
    return;
}

//adds an item into the heap
void heapEnqueue(int arr[], int &size, int item)
{
    arr[size] = item;
    int spot = size;
    size++;
    
    int parent = 0;
    while (spot > 0)
    {
	   parent = (spot - 1) / 2;
	   if (arr[spot] < arr[parent])
	       swap(arr[spot], arr[parent]);
	   spot = parent;
    }


    heapify(arr, size, 0);
    return;
}

//display's the array
void displayArray(int arr[], int size)
{
    for (int i = 0; i < size; i++)
	   cout << arr[i] << "\t";
    cout << endl;

    return;
}

//main driver program
int main()
{
    int arr[] = {1, 5, 8, 9, 2, 4, 6, 7};
    int size = 8;
    int element = 0;
    buildHeap(arr, size, 0);
    heapEnqueue(arr, size, 3);
    heapDequeue(arr, size, element);

    cout << "The element removed is " << element << endl << endl;
    printHeap(arr, size);
    cout << endl;
    displayArray(arr, size);
    cout << endl;
    heapSort(arr, size); 
    cout << endl;
    displayArray(arr, size);
    
    return 0;
}
