#!/bin/bash

for (( i=0; i<=$1;i++ ))
do
	echo "Generating file $i"
	paramFile=params$i.dat
	sed 's/imageX/image'$i'/' baseParams.dat >$paramFile
	#j=$(($i - 615))
	
	#Initial rendering of the orb into a cube while moving towards zoom-in point
	#if [ $i -le 614 ] ;
	#then
	#	awk -v i="$i" '{ gsub(/2.4 3.58 1.3/, "2.4 " 3.58 - i * 0.005813008 " 1.3")};{print}' $paramFile > $paramFile.new
	#	mv $paramFile.new $paramFile
	#	awk -v i="$i" '{ gsub(/6 6 12/, "6 6 " 12 - i * 0.009756097)};{print}' $paramFile > $paramFile.new
	#	mv $paramFile.new $paramFile
	
	#Moves the camera 
	#else
	#	awk -v i="$i" '{ gsub(/6 6 12/, 2.295149969*0.9998^i" " 2.295149969*0.9998^i" "2.295149969*0.9998^i)};{print}' $paramFile > $paramFile.new
	#	mv $paramFile.new $paramFile
	#	awk '{ gsub(/2.4 3.58 1.3/, "2.4 " 0.0005 " 1.3")};{print}' $paramFile > $paramFile.new
	#	mv $paramFile.new $paramFile
	
	##On second 36.5, moves camera view down for 6 seconds while moving towards the center at 0.9998% per frame
	##if [ $i -gt 1094 ] ;
	##	then 	
	##	awk -v i="$i" '{ gsub(/0 0 0/, "0 " 0-0.025*i " 0")};{print}' $paramFile > $paramFile.new
	##	mv $paramFile.new $paramFile
	##	awk -v i="$i" '{ gsub(/6 6 12/, 2.295149969*0.9998^i" " 2.295149969*0.9998^i" "2.295149969*0.9998^i)};{print}' $paramFile > $paramFile.new
	##	mv $paramFile.new $paramFile
	##	awk '{ gsub(/2.4 3.58 1.3/, "2.4 " 0.0005 " 1.3")};{print}' $paramFile > $paramFile.new
	##	mv $paramFile.new $paramFile
	##fi

	##On second 32.5, moves camera in -y direction for 6 seconds
	##awk -v i="$i" '{ gsub(/0 0 0/, "0 -5.25 0")};{print}' $paramFile > $paramFile.new
	##mv $paramFile.new $paramFile
	##awk -v i="$i" '{ gsub(/6 6 12/, "2.200740703 " 2.200740703*0.992^i " 2.200740703")};{print}' $paramFile > $paramFile.new
	##mv $paramFile.new $paramFile
	##awk '{ gsub(/2.4 3.58 1.3/, "2.4 " 0.0005 " 1.3")};{print}' $paramFile > $paramFile.new
	##mv $paramFile.new $paramFile

	
	awk -v i="$i" '{ gsub(/0 0 0/, "0 -5.25 " 0-0.025*i)};{print}' $paramFile > $paramFile.new
	mv $paramFile.new $paramFile
	awk -v i="$i" '{ gsub(/6 6 12/, "2.200740703 0.407399065 2.200740703")};{print}' $paramFile > $paramFile.new
	mv $paramFile.new $paramFile
	awk '{ gsub(/2.4 3.58 1.3/, "2.4 " 0.0005 " 1.3")};{print}' $paramFile > $paramFile.new
	mv $paramFile.new $paramFile







	#fi
done

#awk -v i="$j" '{ gsub(/6 6 12/, 6*0.998^i" " 6*0.998^i" "6*0.998^i)};{print}' $paramFile > $paramFile.new

#41s mark 
#awk -v i="$i" '{ gsub(/6 6 12/, 1.751596796*0.9998^i" " 1.751596796*0.9998^i" "1.751596796*0.9998^i)};{print}' $paramFile > $paramFile.new