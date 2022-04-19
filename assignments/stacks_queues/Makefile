main: main.o stacks.o queue.o Node.o List.o
	g++ -o main main.o stacks.o queue.o Node.o List.o

stacks.o: stacks.cpp stacks.h
	g++ -c stacks.cpp -std=c++11

queue.o: queue.cpp queue.h
	g++ -c queue.cpp

Node.o: Node.cpp Node.h
	g++ -c Node.cpp

List.o: List.cpp List.h
	g++ -c List.cpp

main.o: main.cpp stacks.h queue.h Node.h
	g++ -c main.cpp -std=c++11

clean:
	rm -f main.o stacks.o queue.o Node.o List.o