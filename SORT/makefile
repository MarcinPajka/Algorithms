CC = g++ -O -std=c++14 -Wpedantic -Wall -Wextra
all: main_sort.o sort.o
	$(CC) main_sort.o  -o sort.out
	rm -f *.o

sort.o: sort.cpp sort.h
	$(CC) sort.cpp -c -o sort.o   

queue.o: queue.cpp queue.h 
	$(CC) queue.cpp -c -o queue.o   


main_sort.o: sort_template.h 
	$(CC) main_sort.cpp -c -o main_sort.o

clean:
	rm -f *.o *.data sort.out
