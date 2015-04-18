#!/bin/bash

SORTS='merge heap quick bubble insertion'

make clean
make all

for alg in $SORTS
do
    ./runner.sh ./${alg}
    gnuplot ${alg}.gnu
done
