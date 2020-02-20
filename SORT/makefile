CC = gcc

all: sort.o misc.o main_sort.o 
	$(CC) sort.o misc.o main_sort.o -o sort.out

pq.o: ../PQ/pq.c ../PQ/pq.h sort.h
	$(CC) ../PQ/pq.c -c -o pc.o

sort.o: sort.c sort.h misc.h pq.o
	$(CC) sort.c -c  -o sort.o   

misc.o: misc.c misc.h
	$(CC) misc.c -c -o misc.o 

main_sort.o: main_sort.c sort.h misc.h
	$(CC) main_sort.c -c -o main_sort.o

clean:
	rm -f *.o *.data sort.out
