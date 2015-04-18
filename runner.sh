#!/bin/bash

SORTS='1 2 3 4'
TESTS=`seq  1000 2500 50000`
RUNS=`seq 0 0`

for typee in $SORTS
do
    for size in $TESTS
    do
        for n in $RUNS
        do
            ./$1 $size $typee >> ${1}${typee}.dat
        done
    done
done
