CC=gcc
CFLAGS=-O2 

all: heap insertion bubble stooge quick merge

heap:
	$(CC) heapsort.c -o heap $(CFLAGS)

insertion:
	$(CC) insertionsort.c -o insertion $(CFLAGS)

bubble:
	$(CC) bubblesort.c -o bubble $(CFLAGS)

stooge:
	$(CC) stoogesort.c -o stooge $(CFLAGS)

merge:
	$(CC) mergesort.c -o merge $(CFLAGS)

quick:
	$(CC) quicksort.c -o quick $(CFLAGS)

clean:
	-rm -rf core heap insertion bubble a.out stooge merge quick *.dat
