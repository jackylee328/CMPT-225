/*
 * Queue.h
 *
 * Class Definition: Queue ADT using linked linked implementation
 *
 * Created on: July 4th, 2017
 * Author: Jacky Lee & Joey Zhu
 */

#pragma once
#include <cstdio>
#include "Node.h"
#include "Event.h"
#include "EmptyDataCollectionException.h"

template <class ElementType>
class Queue {

private:
    static const int MAX_CAPACITY = 100;
    int elementCount;
    int capacity;
    Node<ElementType> *head;
    Node<ElementType> *tail;

public:
// Let's put our constructor(s) and destructor (if any) ***here***.
    Queue();

    ~Queue();

/******* Public Interface - START - *******/

   // Description: Returns the number of elements in the Queue.
   // (This method eases testing.)
   // Time Efficiency: O(1)
   int getElementCount() const;

   // Description: Returns "true" is this Queue is empty, otherwise "false".
   // Time Efficiency: O(1)
   bool isEmpty() const;

   // Description: Adds newElement to the "back" of this Queue
   //              (not necessarily the "back" of its data structure) and
   //              returns "true" if successful, otherwise "false".
   // Time Efficiency: O(1)
   bool enqueue(const ElementType& newElement);

   // Description: Removes the element at the "front" of this Queue
   //              (not necessarily the "front" of its data structure) and
   //              returns "true" if successful, otherwise "false".
   // Precondition: This Queue is not empty.
   // Time Efficiency: O(1)
   bool dequeue();

   // Description: Returns (a copy of) the element located at the "front" of this Queue.
   // Precondition: This Queue is not empty.
   // Postcondition: This Queue is unchanged.
   // Exceptions: Throws EmptyDataCollectionException if this Queue is empty.
   // Time Efficiency: O(1)
   ElementType peek() const throw(EmptyDataCollectionException);

/******* Public Interface - END - *******/

// Let's feel free to add other private helper methods to our Queue class.

}; // end Queue


template <class ElementType>
Queue<ElementType>::Queue(){
    head = NULL;
    tail = NULL;
    elementCount = 0;
    capacity = MAX_CAPACITY;
}

template <class ElementType>
Queue<ElementType>::~Queue(){
    Node<ElementType> *current = head;
    while (current != NULL){
        head = head->next;
        delete current;
        current = head;
    }
    head = NULL;
}

template <class ElementType>
int Queue<ElementType>::getElementCount() const{
    return elementCount;
}

template <class ElementType>
bool Queue<ElementType>::isEmpty() const{
    return (elementCount == 0);
}

template <class ElementType>
bool Queue<ElementType>::enqueue(const ElementType& newElement){
    if (elementCount == capacity){
        return false;
    }
    Node<ElementType> *newNode= new Node<ElementType>;
    newNode->data = newElement;
    newNode->next = NULL;
    if (isEmpty()){
        head = newNode;
        tail = newNode;
    }
    else{
        tail->next = newNode;
        tail = tail->next;
    }
    elementCount++;
    return true;
}

template <class ElementType>
bool Queue<ElementType>::dequeue(){
    if (isEmpty()){
        return false;
    }
    Node<ElementType> *current = head;
    if (elementCount == 1){
        head = NULL;
        tail = NULL;
    }
    else{
        head = head->next;
    }
    delete current;
    elementCount--;
    return true;
}

template <class ElementType>
ElementType Queue<ElementType>::peek() const throw(EmptyDataCollectionException){
    if (isEmpty()){
        throw EmptyDataCollectionException("Queue is currently empty.");
    }
    return head->data;
}
