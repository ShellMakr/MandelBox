#!/bin/bash

if [ -a mandelbox ]; then
	make
fi 

cd params
./makeParams.sh
cd ..
mpiCC mpiwrapper.cc -o mpirunner
mpiCC -np 8 ./mandelbox $1 $2
