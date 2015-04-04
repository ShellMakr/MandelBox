#!/bin/bash

for (( i=0; i<=$1; i++ ))
do
	paramFile=params$i.dat
	sed 's/imageX/image'$i'/' baseParams.dat >$paramFile
	awk -v i="$i" '{ gsub(/14.0 8.0 10.0/, $1 - 0.01 * i " 8.0 10.0")};{print}' $paramFile > $paramFile.new
	mv $paramFile.new $paramFile
done
