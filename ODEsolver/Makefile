AbstractODESolver.o: AbstractODESolver.cpp AbstractODESolver.hpp
	g++ -c -O AbstractODESolver.cpp

ForwardEuler.o: ForwardEuler.cpp ForwardEuler.hpp
	g++ -c -O ForwardEuler.cpp

RK4.o: RK4.cpp RK4.hpp
	g++ -c -O RK4.cpp

main.o: main.cpp AbstractODESolver.hpp ForwardEuler.hpp RK4.hpp
	g++ -c -O main.cpp

main: main.o AbstractODESolver.o ForwardEuler.o RK4.o
	g++ -O -o main main.o AbstractODESolver.o ForwardEuler.o RK4.o