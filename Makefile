all: sApp

sApp: SimulationApp.cpp Queue.h PriorityQueue.h Node.h Event.o EmptyDataCollectionException.o
	g++ -Wall -std=c++11 -o sApp SimulationApp.cpp Event.o EmptyDataCollectionException.o

Event.o: Event.cpp Event.h
	g++ -c Event.cpp

EmptyDataCollectionException.o: EmptyDataCollectionException.cpp EmptyDataCollectionException.h
	g++ -c EmptyDataCollectionException.cpp

clean:
	rm -f sApp *.o
