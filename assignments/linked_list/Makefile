OBJECTS = main.o List.o Node.o OListNode.o
CXXFLAGS =
LDFLAGS =
CXX = g++

main:main.o List.o Node.o OListNode.o
	$(CXX) -o main $(OBJECTS)

tests: tests.o List.o Node.o OListNode.o
	$(CXX) -o tests tests.o List.o Node.o OListNode.o

main.o: main.cpp List.h

tests.o: tests.cpp doctest.h List.h
	$(CXX) -c tests.cpp -std=c++11

List.o: List.cpp List.h	Node.h

Node.o: Node.cpp Node.h	

clean:
	rm -f $(OBJECTS) tests.o