/*
 * PriorityQueue.cpp
 *
 * Description: Link-based implementation of data collection Priority Queue ADT.
 *
 * Class Invariant: The elements stored in this Priority Queue are always sorted.
 *
 * Author: Inspired by Frank M. Carrano and Tim Henry (textbook).
 *
 * Date: June 2016
 *
 */


#include <string>  // needed?
#include <iostream>  // needed?
#include "PriorityQueue.h"  // Header file

using namespace std; // Needed for cout, cin to be recognized


// Default Constructor
template <class T>
PriorityQueue<T>::PriorityQueue() {
   BH = new BinaryHeap<T>();
} // end of default constructor

// Destructor
template <class T>
PriorityQueue<T>::~PriorityQueue() {
    //trivial
}  // end destructor

// Description: Returns the number of elements in the Priority Queue.
template <class T>
int PriorityQueue<T>::getElementCount() const {
   return BH->getElementCount();
}

// Description: Returns "true" is this Priority Queue is empty, otherwise "false".
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::isEmpty() const {
   return (BH->getElementCount() == 0);
}  // end isEmpty


// Description: Inserts newElement in sort order.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is sorted.
// Postcondition: Once newElement is inserted, this Priority Queue remains sorted.
// Time Efficiency: O(n)
template <class T>
bool PriorityQueue<T>::enqueue(const T& newElement) {
    bool ableToEnqueue = BH->insert(newElement);
   return ableToEnqueue;
} // end enqueue


// Description: Removes the element with the "highest" priority.
//              It returns "true" if successful, otherwise "false".
// Precondition: This Priority Queue is not empty.
// Time Efficiency: O(1)
template <class T>
bool PriorityQueue<T>::dequeue() {
   bool ableToDequeue = BH->remove();
   return ableToDequeue;
}  // end remove


// Description: Returns (a copy of) the element with the "highest" priority.
// Precondition: This Priority Queue is not empty.
// Postcondition: This Priority Queue is unchanged.
// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
// Time Efficiency: O(1)
template <class T>
T PriorityQueue<T>::peek() const throw(EmptyDataCollectionException) {
    if (BH->getElementCount() == 0){
        throw(EmptyDataCollectionException("peek() called with an empty PriorityQueue."));
    }
    else{
        return BH->retrieve();
    }
}  // end peek


// For Testing Purposes - See Labs 3 and 4.
// Description: Prints the content of "this".
template <class T>
void PriorityQueue<T>::printPriorityQueue( ) const {
   BH->printList();
}  // end printPriorityQueue

// ostream& operator<<(ostream & os, const PriorityQueue& rhs) {
//   	Node* current = rhs.head;

// 	// Traverse the list
// 	while (current != NULL){
// 		cout << current -> data; // Print data
// 		current = current -> next; // Go to next Node
// 	}

// 	return os;
// } // end of operator <<

//  End of implementation file.
