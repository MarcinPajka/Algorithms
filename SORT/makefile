CC = g++ -O -std=c++11 -Wpedantic -Wall -Wextra -I/usr/include/python2.7 
all:  sort.o  main_sort.o 
	$(CC) main_sort.o  -o sort.out
	rm -f *.o

sort.o: sort.cpp sort.h
	$(CC) sort.cpp -c -o sort.o   

main_sort.o: sort.h
	$(CC) main_sort.c -c -o main_sort.o

clean:
	rm -f *.o *.data sort.out
