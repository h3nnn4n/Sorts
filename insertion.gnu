set terminal png
set output 'insertion.png'

set xlabel "Size"
set autoscale

set ylabel "Time"
set title "Insertion sort "

set grid
set style data points

plot    'insertion1.dat' using 2:1 title 'Quasi sorted' with lines, \
        'insertion2.dat' using 2:1 title 'Few unique'   with lines, \
        'insertion3.dat' using 2:1 title 'Reversed'     with lines, \
        'insertion4.dat' using 2:1 title 'Random'       with lines
