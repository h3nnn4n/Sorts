#!/bin/bash

SORTS='merge heap quick'
TESTS=`seq  1000 2500 50000`
RUNS=`seq 0 0`

make clean
make

for alg in $SORTS
do
    for size in $TESTS
    do
        for n in $RUNS
        do
            ./$alg $size $1 >> ${alg}.dat
        done
    done
done
