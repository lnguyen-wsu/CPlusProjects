test: main.o	Node.o
	g++ -Wall -o test main.o Node.o
main.o : main.cpp
	g++ -Wall -c main.cpp
Node.o:	Node.cpp
	g++ -Wall -c Node.cpp
clean:
	rm -f main.o Node.o test

