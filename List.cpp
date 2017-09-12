/* File Name: List.cpp
*
* Class Description: List data collection ADT.
*
* Class Invariant: Data collection with the following characteristics:
*                   - Each element is unique (no duplicates).
*                   - (What other characteristic does our List have?)
*
* Authors: Yichuan Kelly Zheng, Jacky Lee
*
* Creation Date: June 5th, 2017
*/

#include <iostream>
#include <string>
#include "List.h"
#include "Patient.h"

using namespace std;

// Description: Check is the list is full
bool List::isFull(int row) const {
	return (elementCount[row] == currentCapacity[row]);
}//isFull()

void List::expand(int row) {
	// double the capacity
	int newCapacity = currentCapacity[row] * 2;
	// make a new list
	Patient* newRow = new Patient[newCapacity];
	// copy all patients to the new list
	for (int i = 0; i < currentCapacity[row]; i++) {
		newRow[i] = elements[row][i];
	}
	// delete the current row
	delete[] elements[row];
	// replace it with a new one
	elements[row] = newRow;
	// update the row capacity
	currentCapacity[row] = newCapacity;
}//expand()

int List::getRow(const Patient& element) {
	// get first letter of string
	char firstChar = element.getCareCard().at(0);
	// turn it into an integer
	int row = firstChar - '0';
	return row;
}//getRow()

//Default contructor with initialization list.
List::List(){
    // initialize list
    elements = new Patient*[10];
    // using a loop
    // set element count to 0 by default
    // capacity to default
    for (int row = 0; row < 10; row++){
        elements[row] = new Patient[DEFAULT_CAPACITY];
        elementCount[row] = 0;
        currentCapacity[row] = DEFAULT_CAPACITY;
    }
}//list()

// Parameterized Constructor
List::List(const List* aList){
    // initialize list
    elements = new Patient*[10];
    // using a loop
    for (int row = 0; row < 10; row++){
        elements[row] = new Patient[DEFAULT_CAPACITY];
        elementCount[row] = 0;
        currentCapacity[row] = DEFAULT_CAPACITY;
        // copy all patients from aList
        for (int column = 0; column < aList->elementCount[row]; column++){
            // expand if needed
            if (isFull(row)){
                expand(row);
            }
            elements[row][column] = aList->elements[row][column];
            // increase element count
            elementCount[row]++;
        }
    }
}//list(aList)

// Destructor
List::~List(){
    delete [] elements;
    elements = NULL;
}//~List()

// Description: Returns the total element count currently stored in List.
//Method to return the #of elements in the list.
int List::getElementCount() const {
	int sum = 0;
	// add all numbers in the array
	for (int i = 0; i < 10; i++) {
		sum += elementCount[i];
	}
	return sum;
}//getElementCount()

// Description: Insert an element.
// Precondition: newElement must not already be in data collection.
// Postcondition: newElement inserted and elementCount has been incremented.
//Inserts a patient into the list
bool List::insert(const Patient& newElement) {
	// first make sure patient does not already exist
	if (search(newElement) != NULL) {
		return false;
	}
	// find the row to insert
	int row = getRow(newElement);
	// check if row is full
	if (isFull(row)) {
		expand(row);
	}
	// search for column to insert
	int column = 0;
	while (column < elementCount[row] && !(elements[row][column] > newElement)) {
		column++;
	}
	//shift elements to the right to make room
	for (int i = elementCount[row]; i > column; i--) {
		elements[row][i] = elements[row][i-1];
	}
	// assign patient;
	elements[row][column] = newElement;
	// increase patient count
	elementCount[row]++;
	return true;
}//insrt(newElement)

// Description: Remove an element.
// Postcondition: toBeRemoved is removed and elementCount has been decremented.
//This method in the list removes the patient from the list.
bool List::remove(const Patient& toBeRemoved) {
	// find the row of this patient
	int row = getRow(toBeRemoved);
	// now search for column of this patient
	for (int column = 0; column < elementCount[row]; column++) {
		// Patient found!
		if (elements[row][column] == toBeRemoved) {
			// shift elements to the left
			// unless toBeRemoved is in the last column
			for (int i = column; i < elementCount[row]; i++) {
					elements[row][i] = elements[row][i+1];
			}
			// now decrease the element count
			elementCount[row]--;
			return true;
		}
	}
	// return false if patient if not found
	return false;
}//remove(toBeRemoved)

// Description: Remove all elements.
void List::removeAll() {
	// simply set elementCount to 0 in every index
	for (int i = 0; i < 10; i++) {
		elementCount[i] = 0;
	}
}//removeAll()

// Description: Search for target element.
//              Returns a pointer to the element if found,
//              otherwise, returns NULL.
Patient* List::search(const Patient& target) {
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < elementCount[row]; column++) {
			if (elements[row][column] == target) {
				return &elements[row][column];
			}
		}
	}
	return NULL;
}//search(target)

// Description: Prints all elements stored in List.
void List::printList() {
	for (int row = 0; row < 10; row++) {
		for (int column = 0; column < elementCount[row]; column++) {
			elements[row][column].printPatient();
			cout << endl;
		}
	}
}//printList()
//end of the file
