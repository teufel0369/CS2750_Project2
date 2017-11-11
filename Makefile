GCC = gcc
CFLAGS = -O -Wall -Wshadow
    
proj2 : functions.o main.o
	$(GCC) $(CFLAGS) -c functions.o main.o -o proj2

functions.o : functions.c
	$(GCC) $(CFLAGS) -c functions.c
    
main.o : main.c
	$(GCC) $(CFLAGS) -c main.c
