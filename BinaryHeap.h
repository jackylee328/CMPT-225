/*
 * BinaryHeap.h
 *
 * Description: Minimum binary heap data collection ADT class. Array-based implementation.
 *
 * Author:
 *
 * Date: July 2017
 *
 */
#pragma once

#include <iostream>
#include "Event.h"
#include "EmptyDataCollectionException.h"   // Feel free to recycle an exception class from Assignment 3.

using namespace std;


template <class T>
class BinaryHeap {

private:
    // To do: Add the data members here!
	static const int DEFAULT_CAPACITY = 30;
	int elementCount;
	int CAPACITY;
	T elements[DEFAULT_CAPACITY];

	// Utility method - Recursively put the array back into a minimum binary heap.
	void reHeapUp(int indexOfBottom);

	// Utility method - Recursively put the array back into a minimum binary heap.
	void reHeapDown(int indexOfRoot);


public:
	// Default Constructor
	BinaryHeap();

	// More constructors?

    // Description: Returns the number of elements in the Binary Heap.
	// Time Efficiency: O(1)
    int getElementCount() const;

	// Description: Inserts newElement into the Binary Heap.
	//              It returns "true" if successful, otherwise "false".
	// Postcondition: Remains a Binary Heap after the insertion.
	bool insert(const Event& newElement);

	// Description: Removes the root of the Binary Heap.
	//              It returns "true" if successful, otherwise "false".
	// Precondition: This Binary Heap is not empty.
	// Postcondition: Remains a Binary Heap after the deletion.
	bool remove();

	// Description: Retrieves (but does not remove) the root.
	// Precondition: This Binary Heap is not empty.
	// Postcondition: This Binary Heap is unchanged.
	// Exceptions: Throws EmptyDataCollectionException if this Priority Queue is empty.
	// Time Efficiency: O(1)
	Event retrieve() const throw(EmptyDataCollectionException);

	// For Testing Purposes - See Labs 3 and 4.
	// Description: Prints the content of "this".
	void printList();

}; // end BinaryHeap

#include "BinaryHeap.cpp"
