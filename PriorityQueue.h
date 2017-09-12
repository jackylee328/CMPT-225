/*
 * PriorityQueue.h
 *
 * Class Definition: PriorityQueue using array implementation
 *
 * Created on: July 4th, 2017
 * Author: Jacky Lee & Joey Zhu
 */

#pragma once
#include <iostream>
#include <new>
#include "Event.h"
#include "EmptyDataCollectionException.h"

using namespace std;

template <class ElementType>
class PriorityQueue {

private:
    static const int MAX_CAPACITY = 100;
    ElementType array[100];
    int front;
    int back;
    int capacity;

public:
// Let's put our constructor(s) and destructor (if any) ***here***.
    PriorityQueue();

    ~PriorityQueue();

/******* Public Interface - START - *******/

   // Description: Returns the number of elements in the Priority Queue.
   // (This method eases testing.)
   // Time Efficiency: O(1)
   int getElementCount() const;

   // Description: Returns "true" is this Priority Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Inserts newElement in sort order.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is sorted.
   // Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
   // Time Efficiency: O(n)
   bool enqueue(const ElementType& newElement);

   // Description: Removes the element with the "highest" priority.
   //              It returns "true" if successful, otherwise "false".
   // Precondition: This Priority Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns (a copy of) the element with the "highest" priority.
   // Precondition: This Priority Queue is not empty.
   // Postcondition: This Priority Queue is unchanged.
   // Exceptions: Thows EmptyDataCollectionException if this Priority Queue is empty.
   // Time Efficiency: O(1)
   ElementType peek() const throw(EmptyDataCollectionException);


/******* Public Interface - END - *******/

// Let's feel free to add other private helper methods to our Priority Queue class.

}; // end PriorityQueue

template <class ElementType>
PriorityQueue<ElementType>::PriorityQueue(){
    front = -1;
    back = -1;
    capacity = MAX_CAPACITY;
}

template <class ElementType>
PriorityQueue<ElementType>::~PriorityQueue(){
    // not needed
}

template <class ElementType>
int PriorityQueue<ElementType>::getElementCount() const{
    if (front == -1){
        return 0;
    }
    if (front == back){
        return 1;
    }
    return (back-front+1);
}

template <class ElementType>
bool PriorityQueue<ElementType>::isEmpty() const{
    return (front == -1);
}

template <class ElementType>
bool PriorityQueue<ElementType>::enqueue(const ElementType& newElement){
    if ((back+1) % capacity == front){
        return false;
    }
    if (isEmpty()){
        front = 0;
        back = 0;
        array[front] = newElement;
    }
    else{
        int i = front;
        while (i <= back && (!(array[i] > newElement))){
            i++;
        }
        for (int j = back+1; j > i; j--){
            array[j] = array[j-1];
        }
        array[i] = newElement;
        back = (back+1) % capacity;
    }
    return true;
}

template <class ElementType>
bool PriorityQueue<ElementType>::dequeue(){
    if (isEmpty()){
      return false;
    }
    if (front == back){
        front = -1;
        back = -1;
    }
    else{
        front++;
    }
    return true;
}

template <class ElementType>
ElementType PriorityQueue<ElementType>::peek() const throw(EmptyDataCollectionException){
    if (isEmpty()){
        throw EmptyDataCollectionException("Queue is currently empty.");
    }
    return array[front];
}
