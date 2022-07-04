Book.o : Book.cpp Book.hpp
	g++ -c -O Book.cpp

UseBook.o : UseBook.cpp Book.hpp
	g++ -c -O UseBook.cpp

UseBook : Book.o UseBook.o
	g++ -O -o UseBook Book.o UseBook.o

