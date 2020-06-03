test:stringset.o test.o
	g++ -Wall -o test stringset.o test.o
stringset.o: stringset.cpp
	g++ -Wall -c stringset.cpp
test.o: test.cpp
	g++ -Wall -c test.cpp
clean:
	rm -f stringset.o test.cpp bin
