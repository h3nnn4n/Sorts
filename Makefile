CC=gcc
CFLAGS=-O2 
OTHERS=sort_utils.c 

all: heap insertion bubble stooge quick merge

heap:
	$(CC) heapsort.c -o heap $(CFLAGS) $(OTHERS)

insertion:
	$(CC) insertionsort.c -o insertion $(CFLAGS) $(OTHERS)

bubble:
	$(CC) bubblesort.c -o bubble $(CFLAGS) $(OTHERS)

stooge:
	$(CC) stoogesort.c -o stooge $(CFLAGS) $(OTHERS)

merge:
	$(CC) mergesort.c -o merge $(CFLAGS) $(OTHERS)

quick:
	$(CC) quicksort.c -o quick $(CFLAGS) $(OTHERS)

clean:
	-rm -rf core heap insertion bubble a.out stooge merge quick *.dat
