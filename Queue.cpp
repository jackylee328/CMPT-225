/*
 * Queue.cpp
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
#include "Queue.h"  // Header file

using namespace std; // Needed for cout, cin to be recognized


// Constructor
template <class T>
Queue<T>::Queue() : front(0), back(MAX_CAPACITY - 1), elementCount(0)
{
   // cout << "Queue Default constructor" << endl; // For learning purposes!
} // end default constructor


// Copy constructor and destructor supplied by compiler

// Description: Returns the number of elements in the Queue.
template <class T>
int Queue<T>::getElementCount() const {
   return elementCount;
}

// Description: Returns "true" is this queue is empty, otherwise "false".
// Time Efficiency: O(1)   template <class T>
template <class T>
bool Queue<T>::isEmpty() const
{
   return elementCount == 0;
} // end isEmpty

// Description: Adds newElement to the "back" of this queue and
//              returns "true" if successful, otherwise "false".
// Time Efficiency: O(1)
template <class T>
bool Queue<T>::enqueue(const T& newElement)
{
   bool queuedOK = false;
   if (elementCount < MAX_CAPACITY)
   {
      // Queue has room for another item
      back = (back + 1) % MAX_CAPACITY;
      elements[back] = newElement;
      elementCount++;
      queuedOK = true;
   } // end if

   return queuedOK;
} // end enqueue


// Description: Removes the element at the "front" of this queue and
//              returns "true" if successful, otherwise "false".
// Precondition: This queue is not empty.
// Time Efficiency: O(1)
template <class T>
bool Queue<T>::dequeue()
{
   bool dequeuedOK = false;
   if (!isEmpty())
   {
      front = (front + 1) % MAX_CAPACITY;
      elementCount--;
      dequeuedOK = true;
   } // end if

   return dequeuedOK;
} // end dequeue


// Description: Returns (a copy of) the element located at the "front" of this queue.
// Precondition: This queue is not empty.
// Postcondition: This queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this queue is empty.
// Time Efficiency: O(1)
template <class T>
T Queue<T>::peek() const throw(EmptyDataCollectionException)
{
   // Enforce precondition
   if (isEmpty())
      throw EmptyDataCollectionException("peek() called with empty queue.");

   // Queue is not empty; return front
   return elements[front];
} // end peekFront

// For Testing Purposes - See Labs 3 and 4.
// Description: Prints the content of "this".
template <class T>
void Queue<T>::printQueue() const {
   cout << "Printing the queue from front = " << front << " to back = " << back << endl;
   for ( int i = front; i <= back; i++)
      cout << elements[i];
   cout << endl;
}

// ostream & operator<<(ostream & os, const Queue& rhs) {
//    int index = rhs.front;
//    int count = 0;

//    while ( count < rhs.elementCount ) {
//       cout << rhs.elements[index];
//       index = (index + 1) % rhs.MAX_CAPACITY;
//       count++;
//    }

//    return os;
// } // end of operator <<

// End of implementation file.
