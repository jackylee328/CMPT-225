#include <iostream>
#include <cstring>
#include "List.h"

using namespace std;

int main() {
    // An empty 'int' List has already been instantiated in another test case which tested the default constructor.

    // Confirm this by printing the List (and testing the method printList() in doing so).
    // We can also confirm the List is empty by calling getElementCount().
    cout << "The List is empty." << endl;
    cout << "elementCount = " << intList.getElementCount() << endl;
    cout << "elements of intList: ";
    intList.printList();

    cout << "Testing add() method: Adding the element 3 to the empty List." << endl;
    intList.add(3);

    // Confirm add(3) was successful by printing the List and the returned value of getElementCount( ) which should be 1.
    cout << "elementCount = " << intList.getElementCount() << endl;
    cout << "elements of intList: ";    intList.printList();
    return 0;

}
