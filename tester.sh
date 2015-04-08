#!/bin/bash

SORTS='merge heap quick'
TESTS=`seq  500 1000 50000`
RUNS=`seq 0 5`

make clean
make

for alg in $SORTS
do
    for size in $TESTS
    do
        for n in $RUNS
        do
            ./$alg $size >> ${alg}.dat
        done
    done
done
