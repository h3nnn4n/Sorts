heap:
	gcc heapsort.c -o heapsort -O2

insertion:
	gcc insertionsort.c -o insertionsort -O2

bubble:
	gcc bubblesort.c -o bubblesort -O2

stooge:
	gcc stoogesort.c -o stoogesort -O2

merge:
	gcc mergesort.c -o mergesort -O2

clean:
	rm -rf core heapsort insertionsort bubblesort a.out stoogesort mergesort
