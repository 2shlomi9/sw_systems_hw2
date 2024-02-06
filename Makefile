CC = gcc
FLAGS= -g -Wall
all: my_graph
my_graph: my_graph.o my_mat.o
	$(CC) $(FLAGS)  my_graph.o my_mat.o -o connections
my_graph.o: my_graph.c my_mat.h
	$(CC) $(FLAGS) -c my_graph.c
my_mat.o: my_mat.c my_mat.h
	$(CC) $(FLAGS) -fPIC -c my_mat.c
my_mat.a: my_mat.o 
	ar -rcs my_mat.a my_mat.o 
.PHONY: clean all
clean:
	rm -f *.o *.a connections
