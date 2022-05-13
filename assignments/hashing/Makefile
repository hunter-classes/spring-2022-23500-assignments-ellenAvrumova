main: main.o Dictionary.o Person.o List.o Node.o
	g++ -o main main.o Dictionary.o Person.o List.o Node.o

main.o: main.cpp Dictionary.h Person.h List.h Node.h
	g++ -c main.cpp -std=c++11

tests: tests.o Dictionary.o Person.o List.o Node.o
	g++ -o tests tests.o Dictionary.o Person.o List.o Node.o

tests.o: tests.cpp Dictionary.h Person.h List.h Node.h
	g++ -c tests.cpp -std=c++11

Dictionary.o: Dictionary.cpp Dictionary.h
	g++ -c Dictionary.cpp

Person.o: Person.cpp Person.h
	g++ -c Person.cpp

List.o: List.cpp List.h
	g++ -c List.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

clean:
	rm -f main.o tests.o Dictionary.o Person.o List.o Node.o