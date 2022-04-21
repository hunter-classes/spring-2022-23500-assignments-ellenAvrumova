main: main.o sorts.o mode.o
	g++ -o main main.o sorts.o mode.o -std=c++11

sorts.o: sorts.cpp sorts.h
	g++ -c sorts.cpp -std=c++11

mode.o: mode.cpp mode.h
	g++ -c mode.cpp -std=c++11

main.o: main.cpp sorts.h mode.h
	g++ -c main.cpp -std=c++11

clean:
	rm -f main.o sorts.o mode.o