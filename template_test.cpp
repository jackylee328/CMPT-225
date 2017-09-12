#include <iostream>
#include <cstring>
#include "List.h"

using namespace std;

int main() {
    // An empty 'int' List has already been instantiated in another test case which tested the default constructor.
    List<int> intList;
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

    cout << "Add element 7 to List that currently has element 3." << endl;
    intList.add(7);
    cout << "elementCount = " << intList.getElementCount() << endl;
    cout << "elements of intList: ";
    intList.printList();

    cout << "Add element 9 to List that currently has elements 6, 5, 7, 3." << endl;
    intList.add(5);
    intList.add(6);
    intList.add(9);
    cout << "elementCount = " << intList.getElementCount() << endl;
    cout << "elements of intList: ";
    intList.printList();

    cout << "Remove element 8 from List that currently has elements 6, 5, 7, 3." << endl;
    intList.remove(9);
    intList.remove(8);
    cout << "elementCount = " << intList.getElementCount() << endl;
    cout << "elements of intList: ";
    intList.printList();

    cout << "Add element 9 to List that currently has elements 9, 6, 5, 7, 3." << endl;
    intList.add(9);
    intList.add(9);
    cout << "elementCount = " << intList.getElementCount() << endl;
    cout << "elements of intList: ";
    intList.printList();

    cout << "Remove element 3 from List that currently has elements 9, 6, 5, 7, 3." << endl;
    intList.remove(9);
    intList.remove(3);
    cout << "elementCount = " << intList.getElementCount() << endl;
    cout << "elements of intList: ";
    intList.printList();

    cout << "Remove element 9 from List that currently has elements 9, 6, 5, 7." << endl;
    intList.remove(9);
    cout << "elementCount = " << intList.getElementCount() << endl;
    cout << "elements of intList: ";
    intList.printList();
    return 0;

}
