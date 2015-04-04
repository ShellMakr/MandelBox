#!/bin/bash

for (( i=0; i<=$1; i++ ))
do
echo $i
./mandelbox params$i.dat
done
