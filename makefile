CFLAGS = -g -Wall -Weffc++ -std=c++11 -Iinclude -o

all: clean bin/cRace

bin/cRace: bin/main.o bin/Agent.o bin/Graph.o bin/Parser.o bin/Party.o bin/Simulation.o
	g++ -o bin/cRace bin/main.o bin/Agent.o bin/Graph.o bin/Parser.o bin/Party.o bin/Simulation.o

bin/main.o: src/main.cpp
	g++ $(CFLAGS) bin/main.o src/main.cpp

bin/Agent.o: src/Agent.cpp
	g++ $(CFLAGS) bin/Agent.o src/Agent.cpp src/SelectionPolicy.cpp

bin/Graph.o: src/Graph.cpp
	g++ $(CFLAGS) bin/Graph.o src/Graph.cpp src/Party.cpp

bin/Parser.o: src/Parser.cpp
	g++ $(CFLAGS) bin/Parser.o src/Parser.cpp

bin/Party.o: src/Party.cpp
	g++ $(CFLAGS) bin/Party.o src/Party.cpp src/Simulation.cpp src/JoinPolicy.cpp

bin/Simulation.o: src/Simulation.cpp
	g++ $(CFLAGS) bin/Simulation.o src/Simulation.cpp

bin/Coalition.o: src/Coalition.cpp
	g++ $(CFLAGS) bin/Coalition.o

bin/JoinPolicy.o: src/JoinPolicy.cpp
	g++ $(CFLAGS) bin/JoinPolicy.o

bin/SelectionPolicy.o: src/JoinPolicy.cpp
	g++ $(CFLAGS) bin/SelectionPolicy.o src/Agent.cpp
	
clean:
	rm -f bin/*
