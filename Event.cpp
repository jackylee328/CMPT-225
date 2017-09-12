/*
 * Event.cpp
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
#include <string>
#include "Event.h"

using namespace std;

Event::Event(){
    Type = 'A';
    Time = 0;
    Length = 0;
}

Event::Event(char aType, int aTime){
    Type = aType;
    Time = aTime;
    Length = 0;
}

Event::Event(char aType, int aTime, int aLength){
    Type = aType;
    Time = aTime;
    Length = aLength;
}

Event::~Event(){
    // not needed
}

char Event::getType() const{
    return Type;
}

int Event::getTime() const{
    return Time;
}

int Event::getLength() const{
    return Length;
}

void Event::setType(char aType){
    Type = aType;
}

void Event::setTime(int aTime){
    Time = aTime;
}

void Event::setLength(int aLength){
    Length = aLength;
}

bool Event::operator > (const Event &rhs){
    return (Time > rhs.Time);
}

bool Event::operator == (const Event &rhs){
    return (Time == rhs.Time && Type == rhs.Type);
}

ostream & operator<<(ostream & os, const Event & rhs){
    os << "Type = " << rhs.getType();
    os << " Time = " << rhs.getTime();
    os << " Length = " << rhs.getLength() << " ";
    return os;
}
