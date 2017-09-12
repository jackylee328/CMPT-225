/*
 * test.cpp - Lab 6
 *
 * Class Description: Test Driver for Patient class
 *
 * Modified on: May 2017
 * Author: AL
 */

#include <iostream>
#include <sstream>
#include "Queue.h"
#include "Patient.h"

using namespace std;


int main () {

  // Create an empty queue bankQueue
  Queue* aQueue = new Queue();
  string aLine = "";
  string carecard = "";
  string name = "";
  string address = "";
  string phone = "";
  string email = "";
  Patient* newPatient = NULL;

  cout << "\nTest Driver - Start" << endl << endl;

  Patient peekedPatient;
  try{
    cout << "Peeking before enqueuing:" << endl;
    peekedPatient = aQueue->peek();
    cout << "Now, let's have a look at the peeked Patient:" << endl;
    cout << peekedPatient << endl;
  }
  catch ( EmptyDataCollectionException&anException ) {
    cout << "peeking() unsuccessful because " << anException.what() << endl;
    // Place recovery code here!
  }

  // Create and add arrival events to aEventQueue
  while(getline(cin >> ws, aLine)) {   // while (there is data)
      stringstream ss(aLine);
      ss >> carecard >> name >> address >> phone >> email;
      cout << "Read: " << carecard << ", " << name << ", " << address << ", " << phone << ", " <<  email << endl;
      newPatient = new Patient(carecard);
      newPatient->setName(name);
      newPatient->setAddress(address);
      newPatient->setPhone(phone);
      newPatient->setEmail(email);
      if ( !aQueue->enqueue(*newPatient) )  return 1;
      cout << *newPatient << endl;
  }

  aQueue->printQueue();

  cout << "Test Driver - End" << endl << endl;
  return 0;
}
