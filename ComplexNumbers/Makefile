CC=g++ -c -g -Wall -ansi -pedantic 
LN=g++

OBJS=main.o Complex.o

cplex: $(OBJS)
	$(LN) -o cplex $(OBJS)
	
main.o: main.cpp Complex.hpp
	$(CC) main.cpp
	
Complex.o: Complex.cpp Complex.hpp
	$(CC) Complex.cpp

clean:
	/bin/rm -rf $(OBJS) cplex
