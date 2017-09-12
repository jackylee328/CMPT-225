/*
 * SimulationApp.cpp
 *
 * Created on: July 4th, 2017
 * Author: Jacky Lee & Joey Zhu
 */

#pragma once
#include <iostream>
#include <stdio.h>
#include "Queue.h"
#include "PriorityQueue.h"
#include "Event.h"

using namespace std;

static int processed;
static int currentTime;
static bool tellerAvailable;
Queue<Event> bankLine;
PriorityQueue<Event> eventPriorityQueue;
static double totalWaitTime = 0.0;

void processArrival(Event arrivalEvent){
    cout << "Processing an arrival event at time:  " << currentTime << endl;
    //cout << eventPriorityQueue.peek() << "removed from PriorityQueue" << endl;
    eventPriorityQueue.dequeue();
    if (bankLine.isEmpty() && tellerAvailable){
    	int transactionTime = arrivalEvent.getLength();
        int departureTime = currentTime + transactionTime;
        Event newDepartureEvent = Event('D', departureTime);
        //cout << newDepartureEvent << "added to PriorityQueue1" << endl;
        eventPriorityQueue.enqueue(newDepartureEvent);
        tellerAvailable = false;
    }
    else{
        //cout << arrivalEvent << "added to bankLine" << endl;
        bankLine.enqueue(arrivalEvent);
    }
}

void processDeparture(Event departureEvent){
    cout << "Processing a departure event at time: " << currentTime << endl;
    //cout << eventPriorityQueue.peek() << "removed from PriorityQueue" << endl << endl;
	eventPriorityQueue.dequeue();
	if (!bankLine.isEmpty()){
		Event customer = bankLine.peek();
		bankLine.dequeue();
        double waitTime = currentTime - customer.getTime();
        totalWaitTime += waitTime;
        int transactionTime = customer.getLength();
		int departureTime = currentTime + transactionTime;
		Event newDepartureEvent = Event('D', departureTime);
        //cout << newDepartureEvent << "added to PriorityQueue2" << endl << endl;
		eventPriorityQueue.enqueue(newDepartureEvent);
	}
	else{
		tellerAvailable = true;
	}
}

void simulate(){
    tellerAvailable = true;
    int aTime, aLength;
    int result = scanf("%d", &aTime);
    scanf("%d", &aLength);
    while (result != EOF){
        Event newArrivalEvent = Event('A', aTime, aLength);
        //cout << newArrivalEvent << "added to PriorityQueue" << endl << endl;
        eventPriorityQueue.enqueue(newArrivalEvent);
        result = scanf("%d", &aTime);
        scanf("%d", &aLength);
    }
    int i = 0;
    while (!eventPriorityQueue.isEmpty()){
        //eventPriorityQueue.printQueue();
        Event newEvent;
        try{
            newEvent = eventPriorityQueue.peek();
        }
        catch ( EmptyDataCollectionException&anException ) {
            cout << "peeking() unsuccessful because " << anException.what() << endl;
        }
        currentTime = newEvent.getTime();
        if (newEvent.getType() == 'A'){
            processArrival(newEvent);
            processed++;
        }
        else{
            processDeparture(newEvent);
        }
        i++;
    }
}


int main(int argc, char* argv[]){
    currentTime = 0;
    cout << "Simulation Begins" << endl;
    simulate();
    cout << "Simulation Ends" << endl << endl;
    cout << "Final Statistics:" << endl;
    cout << "	Total number of people processed: " << processed << endl;
    float averageWaitTime = totalWaitTime / processed;
    cout << "	Average amount of time spent waiting: " << averageWaitTime << endl;
    return 0;
}
