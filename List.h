/* File Name: List.h
*
* Class Description: List data collection ADT.
*
* Class Invariant: Data collection with the following characteristics:
*                   - Each element is unique (no duplicates).
*                   - List is sorted in ascending order
*
* Authors: Yichuan Kelly Zheng, Jacky Lee
*
* Creation Date: June 5th, 2017
*/

#pragma once
#include <string>
#include "Patient.h"

using namespace std;

class List {

private:
	static const int DEFAULT_CAPACITY = 3;

	int elementCount[10];
	int currentCapacity[10];

	Patient** elements;

	// Description: Check is the row is full
	bool isFull(int row) const;

	void expand(int row);

	int getRow(const Patient& element);

public:
	// Default constructor
	List();

	// Parameterized Constructor
	List(const List* aList);

	// Destructor
	~List();

	// Description: Returns the total element count currently stored in List.
	int  getElementCount() const;

	// Description: Insert an element.
	// Precondition: newElement must not already be in data collection.
	// Postcondition: newElement inserted and elementCount has been incremented.
	bool insert(const Patient& newElement);

	// Description: Remove an element.
	// Postcondition: toBeRemoved is removed and elementCount has been decremented.
	bool remove(const Patient& toBeRemoved);

	// Description: Remove all elements.
	void removeAll();

	// Description: Search for target element.
	//              Returns a pointer to the element if found,
	//              otherwise, returns NULL.
	Patient* search(const Patient& target);

	// Description: Prints all elements stored in List.
	void printList();

}; // end List
