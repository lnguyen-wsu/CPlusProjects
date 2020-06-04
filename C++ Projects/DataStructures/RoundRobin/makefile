test: round_robin.o process.o
	g++ -Wall -o test round_robin.o process.o
round_robin.o: round_robin.cpp
	g++ -Wall -c round_robin.cpp
process.o: process.cpp
	g++ -Wall -c process.cpp
clean:
	rm -f round_robin.o process.o test	
