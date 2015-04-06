#!/bin/bash

for (( i=0; i<=$1; i++ ))
do
	echo "Generating file $i"
	paramFile=params$i.dat
	sed 's/imageX/image'$i'/' baseParams.dat >$paramFile
	j=$(($i - 615))
	if [ $i -le 614 ] ;
	then
		awk -v i="$i" '{ gsub(/2.4 7 1.3/, "2.4 " 7 - i * 0.0113813 " 1.3")};{print}' $paramFile > $paramFile.new
		mv $paramFile.new $paramFile
		awk -v i="$i" '{ gsub(/6 6 12/, "6 6 " 12 - i * 0.009756097)};{print}' $paramFile > $paramFile.new
		mv $paramFile.new $paramFile
	else
		awk -v i="$j" '{ gsub(/6 6 12/, 6*0.998^i" " 6*0.998^i" "6*0.998^i)};{print}' $paramFile > $paramFile.new
		mv $paramFile.new $paramFile
		awk '{ gsub(/2.4 7 1.3/, "2.4 " 0.0005 " 1.3")};{print}' $paramFile > $paramFile.new
		mv $paramFile.new $paramFile
	fi
done
