# Makefile
FLAGS = -Wall
run:	main.cpp tic-tac-toe.o
	g++ $(FLAGS) -o run main.cpp tic-tac-toe.o
tic-tac-toe: tic-tac-toe.h tic-tac-toe.cpp
	g++ $(FLAGS) -c -o tic-tac-toe.o tic-tac-toe.cpp
clean:
	rm -rf *~ *.o run output.dat