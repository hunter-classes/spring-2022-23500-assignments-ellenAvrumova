OBJECTS=main.o BSTree.o Node.o
LDFLAGS=
CXXFLAGS=

main: $(OBJECTS)
	g++ -o main $(OBJECTS) 

tests: tests.o BSTree.o Node.o
	g++ -o tests tests.o BSTree.o Node.o

BSTree.o: BSTree.cpp Node.h BSTree.h

main.o: main.cpp Node.h BSTree.h

Node.o: Node.cpp Node.h
	g++ -c Node.cpp -std=c++11

tests.o: tests.cpp doctest.h Node.h BSTree.h 
	g++ -c tests.cpp -std=c++11

clean:
	rm -f $(OBJECTS) tests.o