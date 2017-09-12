/*
 * Event.h
 *
 * Class Definition: Stores a type (arrival/departure),
 * arrival/departure time, and the durature of an event
 *
 * Created on: July 4th, 2017
 * Author: Jacky Lee & Joey Zhu
 */

#pragma once
#include <iostream>
#include <ostream>

using namespace std;

class Event{
private:
    char Type;
    int Time;
    int Length;

public:
    // constructors and destructor
    Event();
    Event(char aType, int aTime);
    Event(char aType, int aTime, int aLength);
    ~Event();
    // getters
    char getType() const;
    int getTime() const;
    int getLength() const;
    // setters
    void setType(char aType);
    void setTime(int aTime);
    void setLength(int aLength);
    // operator overloads
    bool operator > (const Event &rhs);
    bool operator == (const Event &rhs);
    friend ostream & operator<<(ostream & os, const Event& rhs);
};
