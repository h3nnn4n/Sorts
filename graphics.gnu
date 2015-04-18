set terminal png
set output 'master.png'

set xlabel "Size"
set autoscale

set ylabel "Time"
set title "Sorts comparitions"

set grid
set style data points

plot    'merge.dat' using 2:1 title 'Merge' with lines, \
        'heap.dat'  using 2:1 title 'Heap' with lines, \
        'quick.dat' using 2:1 title 'Quick' with lines
