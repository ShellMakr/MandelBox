#!/bin/bash

for (( i=0; i<=$1; i++ ))
do
./mandelbox params$i.dat
done
