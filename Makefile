CC = gcc
CFLAGS = -Wall -Wextra -std=c99 -pedantic -I simulator/include

monteCarlo: simulator/src/monteCarlo.o
	$(CC) -o monteCarlo simulator/src/monteCarlo.o

simulator/src/monteCarlo.o: simulator/src/monteCarlo.c
	$(CC) $(CFLAGS) -c simulator/src/monteCarlo.c -o simulator/src/monteCarlo.o

clean: 
	rm simulator/src/monteCarlo.o monteCarlo.exe