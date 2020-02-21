CC = gcc -O -Wpedantic -Wall -Wextra 

all:  sort.o misc.o main_sort.o 
	$(CC) sort.o misc.o main_sort.o -o sort.out
	rm -f *.o
pq.o: PQ/pq.c PQ/pq.h SORT/sort.h
	$(CC) PQ/pq.c -c -o pc.o

sort.o: SORT/sort.c SORT/sort.h SORT/misc.h pq.o
	$(CC) SORT/sort.c -c  -o sort.o   

misc.o: SORT/misc.c SORT/misc.h
	$(CC) SORT/misc.c -c -o misc.o 

main_sort.o: SORT/main_sort.c SORT/sort.h SORT/misc.h
	$(CC) SORT/main_sort.c -c -o main_sort.o

clean:
	rm -f *.o *.data sort.out
