Matrix.o: Matrix.cpp Matrix.hpp
	g++ -c -O Matrix.cpp

main.o: main.cpp Matrix.hpp
	g++ -c -O main.cpp

main: main.o Matrix.o
	g++ -O -o main main.o Matrix.o