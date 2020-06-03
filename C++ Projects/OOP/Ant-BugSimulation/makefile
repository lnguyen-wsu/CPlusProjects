test: sim.o grid.o bug.o ant.o animal.o
	g++ -g -Wall -o test sim.o grid.o bug.o ant.o animal.o
sim.o : sim.cpp
	g++	-Wall -c sim.cpp
grid.o: grid.cpp
	g++ -Wall -c grid.cpp
bug.o: bug.cpp
	g++ -Wall -c bug.cpp
ant.o: ant.cpp
	g++ -Wall -c ant.cpp
animal.o: animal.cpp
	g++ -Wall -c animal.cpp
clean: 
	rm -f sim.o grid.o bug.o ant.o animal.o test
