test: encryption.o	node.o
	g++ -Wall -o test encryption.o node.o
encryption.o:	encryption.cpp
	g++ -Wall -c encryption.cpp
node.o:	node.cpp
	g++ -Wall -c node.cpp
clean:
	rm -f encryption.o node.o huff.sch alice.huff test 
