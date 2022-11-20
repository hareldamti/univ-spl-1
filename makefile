CFLAGS = -g -Wall -Weffc++ -std=c++11 -Iinclude -o

all: clean bin/cRace

partial:
	g++ $(CFLAGS) bin/Parser.o src/Parser.cpp src/Graph.cpp

bin/cRace: bin/main.o bin/Agent.o bin/Graph.o bin/Parser.o bin/Party.o bin/Simulation.o bin/Coalition.o bin/JoinPolicy.o bin/SelectionPolicy.o
	g++ -o bin/cRace bin/main.o bin/Agent.o bin/Parser.o bin/Graph.o bin/Party.o bin/Simulation.o bin/Coalition.o bin/JoinPolicy.o bin/SelectionPolicy.o


bin/main.o: src/main.cpp
	g++ $(CFLAGS) bin/main.o src/main.cpp src/Parser.cpp src/Simulation.cpp

bin/Agent.o: src/Agent.cpp
	g++ $(CFLAGS) bin/Agent.o src/Agent.cpp

bin/Graph.o: src/Graph.cpp
	g++ $(CFLAGS) bin/Graph.o src/Graph.cpp

bin/Parser.o: src/Parser.cpp
	g++ $(CFLAGS) bin/Parser.o src/Parser.cpp src/Agent.cpp src/SelectionPolicy.cpp src/JoinPolicy.cpp

bin/Party.o: src/Party.cpp
	g++ $(CFLAGS) bin/Party.o src/Party.cpp src/Coalition.cpp

bin/Simulation.o: src/Simulation.cpp
	g++ $(CFLAGS) bin/Simulation.o src/Simulation.cpp src/Party.cpp src/Agent.cpp src/Coalition.cpp src/Graph.cpp

bin/Coalition.o: src/Coalition.cpp
	g++ $(CFLAGS) bin/Coalition.o src/Coalition.cpp

bin/JoinPolicy.o: src/JoinPolicy.cpp
	g++ $(CFLAGS) bin/JoinPolicy.o src/JoinPolicy.cpp

bin/SelectionPolicy.o: src/SelectionPolicy.cpp
	g++ $(CFLAGS) bin/SelectionPolicy.o src/SelectionPolicy.cpp
	
clean:
	rm -f bin/*
