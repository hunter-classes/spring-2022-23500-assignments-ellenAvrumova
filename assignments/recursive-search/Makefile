main: main.o knights.o
	g++ -o main main.o knights.o

knights.o: knights.cpp knights.h
	g++ -c knights.cpp

main.o: main.cpp knights.h
	g++ -c main.cpp

clean:
	rm -f main.o knights.o tests.o