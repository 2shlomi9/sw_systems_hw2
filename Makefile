
CC = gcc
FLAGS= -g -Wall
all: connections
connections: main.o my_mat.o
	$(CC) $(FLAGS)  main.o my_mat.o -o connections
main.o: main.c my_mat.h
	$(CC) $(FLAGS) -c main.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -fPIC -c my_mat.c
my_mat.a: my_mat.o 
	ar -rcs my_mat.a my_mat.o 
.PHONY: clean all
clean:
	rm -f *.o *.a connections
