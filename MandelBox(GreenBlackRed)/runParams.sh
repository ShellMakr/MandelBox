#!/bin/bash

for (( i=0; i<=$1; i++ ))
do
echo "Generating image$i.bmp"
time ./mandelbox params$i.dat
echo
echo
done
