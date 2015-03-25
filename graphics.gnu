set terminal png
set output 'master.png'

set xlabel "Tamanho"
set autoscale

set ylabel "Temp"
set title "Sorts compatirions"

set grid
set style data points

plot    'merge.dat' using 2:1 title 'Merge', \
        'heap.dat'  using 2:1 title 'Heap', \
        'quick.dat' using 2:1 title 'Quick'
