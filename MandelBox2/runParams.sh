#!/bin/sh

for i in $(seq $1 $2)
do
mpirun -np 32 ./mandelbox params$i.dat
mv imageX.bmp image-$i.bmp
done
