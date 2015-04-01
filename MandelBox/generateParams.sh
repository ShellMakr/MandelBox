#!/bin/sh

i=$1
for i in $(seq $1 $2)
do
	paramFile=params$i.dat
	sed 's/imageX/image'$i'/' baseParams.dat >$paramFile
	awk -v i="$i" '{ gsub(/14.0 8.0 10.0/, $1 + 0.0001 * i " 8.0 10.0")};{print}' $paramFile > $paramFile.new
	mv $paramFile.new $paramFile
done
