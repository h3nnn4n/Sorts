set terminal png
set output 'quick.png'

set xlabel "Size"
set autoscale

set ylabel "Time"
set title "Quick sort "

set grid
set style data points

plot    'quick1.dat' using 2:1 title 'Quasi sorted' with lines, \
        'quick2.dat' using 2:1 title 'Few unique'   with lines, \
        'quick3.dat' using 2:1 title 'Reversed'     with lines, \
        'quick4.dat' using 2:1 title 'Random'       with lines
