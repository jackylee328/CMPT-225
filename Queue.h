/*
 * Queue.h
 *
 * Description: Array-based implementation of data collection Queue ADT.
 *
 * Class invariants: FIFO or LILO
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 *
 * Date: June 2016
 */

#pragma once

#include <iostream>
#include "EmptyDataCollectionException.h"


template <class T>
class Queue {

private:
   static const int MAX_CAPACITY = 100;

   T elements[MAX_CAPACITY];  // Array of Queue items
   int front;                 // Index to front of queue
   int back;                  // Index to back of queue
   int elementCount;          // Number of elements currently in the queue

public:
   // Constructor
   Queue();
   // Copy constructor and destructor supplied by compiler

   // Description: Returns the number of elements in the Queue.
   int getElementCount() const;

   // Description: Returns "true" is this queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Adds newElement to the "back" of this queue and
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
   bool enqueue(const T& newElement);

   // Description: Removes the element at the "front" of this queue and
   //              returns "true" if successful, otherwise "false".
   // Precondition: This queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns (a copy of) the element located at the "front" of this queue.
   // Precondition: This queue is not empty.
   // Postcondition: This queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this queue is empty.
   // Time Efficiency: O(1)
   T peek() const throw(EmptyDataCollectionException);

   // For Testing Purposes - See Labs 3 and 4.
   // Description: Prints the content of "this".
   void printQueue() const;
   // friend ostream & operator<<(ostream & os, const Queue& rhs);

}; // end Queue

#include "Queue.cpp"
