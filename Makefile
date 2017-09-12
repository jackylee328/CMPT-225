all: lab6

lab6: Lab6App.o Queue.o Patient.o EmptyDataCollectionException.o
	g++ -std=c++11 -o lab6 Lab6App.o Queue.o Patient.o EmptyDataCollectionException.o

# Note, this makefile is very strong in terms of dependencies.
# It assumes most classes can depend on others, just to be safe.
# This results in much redundant compilation, and one could remove some of these dependencies.

Lab6App.o: Lab6App.cpp Queue.h Patient.h EmptyDataCollectionException.h
	g++ -std=c++11 -c Lab6App.cpp
	
Queue.o: Queue.cpp Queue.h Patient.h EmptyDataCollectionException.h
	g++ -std=c++11 -c Queue.cpp

Patient.o: Patient.cpp Patient.h
	g++ -std=c++11 -c Patient.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -std=c++11 -c EmptyDataCollectionException.cpp

clean:
	rm -f lab6 *.o