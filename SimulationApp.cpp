#pragma once

#include <iostream>
#include <sstream>
#include <iomanip>
#include "Event.h"
#include "Queue.h"
#include "PriorityQueue.h"
#include "EmptyDataCollectionException.h"


using namespace std;


void printResult(PriorityQueue<Event>* aPQ, Queue<Event>* aQ) {

  cout << "The Customer Queue\n" << endl;
  cout << "There are " << aQ->getElementCount() << " elements in the Customer Queue." << endl;
  aQ->printQueue();

  cout << "The Event Priority Queue\n" << endl;
  cout << "There are " << aPQ->getElementCount() << " elements in the Event Priority Queue." << endl;
  aPQ->printPriorityQueue();

  return;
}

void printStats( int peopleCount, int waitingTime ) {
  float avg = (float)waitingTime/(float)peopleCount;

  cout << "\nFinal Statistics:  " << endl;
  cout << "\tTotal number of people processed:  " << peopleCount << endl;
  cout << "\tAverage amount of time spent waiting: "
       << setprecision(3) << avg;
}


int main() {
    string aLine = "";
    int time = 0;
    int length = 0;
    bool tellerAvailable = true;
    Event currentEvent;
    Event customer;
    Event newDepartureEvent;
    int currentTime = 0;
    int departureTime = 0;
    int peopleCount = 0;
    int waitingTime = 0;

    // Create a Queue to represent the line-up of waiting customers
    Queue<Event>* customerQueue = new Queue<Event>();

    // Create a Priority Queue to hold all events (Arrival and Departure events)
    PriorityQueue<Event>* eventPQueue = new PriorityQueue<Event>();

    // currentEvent = eventPQueue->peek();  <- Crashes our code

   // Create and add arrival events to eventListPQueue
    while(getline(cin, aLine)) {   // while (there is data)
        stringstream ss(aLine);
        ss >> time >> length;      // Get next arrival time (time) and transaction time (length)
        // cout << "Read: " << time << " " << length << endl;  // For debugging purposes
        Event newArrivalEvent(Event::ARRIVAL, time, length);
        eventPQueue->enqueue(newArrivalEvent);
    }

    // printResult( eventPQueue, customerQueue );  // For debugging purposes
    cout << "Simulation Begins" << endl;

    // Event loop
    while ( !eventPQueue->isEmpty() ) {
      try {
            // Get the current event
            currentEvent = eventPQueue->peek();
      }
      catch ( EmptyDataCollectionException& anException ) {
            cout << "main:eventPQueue->peek(): " << anException.what() << endl;
      }

         // Get current time
        currentTime = currentEvent.getTime();

        // Processes an arrival event
        if ( currentEvent.isArrival() ) {
           cout << "Processing an arrival event at time:";
           cout.width(5); cout << right << currentTime << endl;
           peopleCount++;

          // Remove this event from the eventListPQueue
          if ( eventPQueue->dequeue() ) {
            // if no customer is waiting and the teller is available
            // then this customer (represented by currentEvent) is now reaching the teller
            if ( customerQueue->isEmpty() && tellerAvailable ) {
              // Create a departure event for this customer
              departureTime = currentTime + currentEvent.getLength();
              newDepartureEvent = Event(Event::DEPARTURE, departureTime);
              eventPQueue->enqueue(newDepartureEvent);
              tellerAvailable = false;
            }
            else
              // If the teller is busy, next customer line-up
              customerQueue->enqueue(currentEvent);
          }
        }
        else {
            // Processes a departure event -> customer leaving the teller and the bank
            cout << "Processing a departure event at time:";
            cout.width(4); cout << right << currentTime << endl;

            // Remove this event from the eventListPQueue
            if ( eventPQueue->dequeue() ) {
                if ( !customerQueue->isEmpty() ) {
                    // Customer at front of line-up now reaching the teller and begins transaction
                    try {
                        customer = customerQueue->peek();
                    }
                        catch ( EmptyDataCollectionException& anException ) {
                        cout << "main:eventListPQueue->peek(): " << anException.what() << endl;
                    }
                if ( customerQueue->dequeue() ) {
                    // Create a departure event for this customer
                    departureTime = currentTime + customer.getLength();
                    newDepartureEvent = Event(Event::DEPARTURE, departureTime);
                    eventPQueue->enqueue(newDepartureEvent);
                    waitingTime += ( currentTime - customer.getTime() );
                }
            }
            else
                // If no customer waiting in line-up, teller now available
                tellerAvailable = true;
            }
        }

    // printResult( eventPQueue, customerQueue );  // For debugging purposes

    }

    cout << "Simulation Ends" << endl;
    printStats( peopleCount, waitingTime );

    // Memory Cleanup
    delete customerQueue;
    customerQueue = NULL;

    delete eventPQueue;
    eventPQueue = NULL;

    // cout << "\n------------------------------" << endl;
	return 0;
}
