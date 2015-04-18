set terminal png
set output 'heap.png'

set xlabel "Size"
set autoscale

set ylabel "Time"
set title "Heap sort"

set grid
set style data points

plot    'heap1.dat' using 2:1 title 'Quasi sorted' with lines, \
        'heap2.dat' using 2:1 title 'Few unique'   with lines, \
        'heap3.dat' using 2:1 title 'Reversed'     with lines, \
        'heap4.dat' using 2:1 title 'Random'       with lines
