test: Car.o		ArrayList.o
	g++ -Wall -o test Car.o ArrayList.o 
Car.o: Car.cpp
	g++ -Wall -c Car.cpp
ArrayList.o: ArrayList.cpp
	g++ -Wall -c ArrayList.cpp
clean:	
	rm -f Car.o ArrayList.o test
