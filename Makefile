CC=gcc
CFLAGS=-O2 

all: heap insertion bubble stooge quick merge

heap:
	$(CC) heapsort.c -o heapsort $(CFLAGS)

insertion:
	$(CC) insertionsort.c -o insertionsort $(CFLAGS)

bubble:
	$(CC) bubblesort.c -o bubblesort $(CFLAGS)

stooge:
	$(CC) stoogesort.c -o stoogesort $(CFLAGS)

merge:
	$(CC) mergesort.c -o mergesort $(CFLAGS)

quick:
	$(CC) quicksort.c -o quicksort $(CFLAGS)

clean:
	rm -rf core heapsort insertionsort bubblesort a.out stoogesort mergesort quicksort
