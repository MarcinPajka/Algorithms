CC = gcc

all: sort.o misc.o main_sort.o
	$(CC) sort.o misc.o main_sort.o -o sort.out

sort.o: sort.c sort.h
	$(CC) sort.c -c -o sort.o   

misc.o: misc.c misc.h
	$(CC) misc.c -c -o misc.o 

main_sort.o: main_sort.c sort.h misc.h
	$(CC) main_sort.c -c -o main_sort.o

clean:
	rm -f *.o sort.out
