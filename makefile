CC = g++
CFLAGS = -Wall -g

test.exe: test.o sevenseg_solver.o
	$(CC) $(CFLAGS) -o test.exe test.o sevenseg_solver.o

test.o: test.cpp sevenseg_solver.h
	$(CC) $(CFLAGS) -c test.cpp

sevenseg_solver.o: sevenseg_solver.h