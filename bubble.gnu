set terminal png
set output 'bubble.png'

set xlabel "Size"
set autoscale

set ylabel "Time"
set title "Bubble sort "

set grid
set style data points

plot    'bubble1.dat' using 2:1 title 'Quasi sorted' with lines, \
        'bubble2.dat' using 2:1 title 'Few unique'   with lines, \
        'bubble3.dat' using 2:1 title 'Reversed'     with lines, \
        'bubble4.dat' using 2:1 title 'Random'       with lines
