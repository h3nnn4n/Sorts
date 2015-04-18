set terminal png
set output 'merge.png'

set xlabel "Size"
set autoscale

set ylabel "Time"
set title "Merge sort"

set grid
set style data points

plot    'merge1.dat' using 2:1 title 'Quasi sorted' with lines, \
        'merge2.dat' using 2:1 title 'Few unique'   with lines, \
        'merge3.dat' using 2:1 title 'Reversed'     with lines, \
        'merge4.dat' using 2:1 title 'Random'       with lines
