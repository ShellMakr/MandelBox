/*
 *	Iheatu Wogu 	: 0850010
 * 	Warren 			: 1131525
 *  Graeme 			:
 *  Maciej 			:	 
 */


/*
 *	mpiwrapper.cc
 *	object filename 	: mpirunner
 *
 *	mpiwarapper takes the object file mandelbox
 *	and passs different parameter files. A group of
 *	passes to mandelbox are handled by every processor
 *	passed in by mpi.
 *
 *  The wrapper allows ranges in order to facilitate
 *  tests. These test are 
 * 
 */


#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>

#define BUF_SIZE 1024

static char buf[BUF_SIZE];
char * filename = "params.dat";
char * newparams = (char*) calloc(40, sizeof(char));
int fractal_dec = 0.01137;
int main(int argc, char* argv[]) {

	char * command = (char*) calloc(40, sizeof(char));
	int start;
	int end;


	// pass in range of images that mpi is too compute
	start = atoi(argv[1]);
	end = atoi(argv[2]);


	for (int i = start; i < end; i++)
	{
		sprintf(newparams,"params/params%d.dat",i);
		sprintf(command, "./mandelbox %s", newparams);
		//printf("%s\n", command);
		//call the command to make the mandelbrot image
		system(command);
	}

	return 0;

}


./mpiserialunner 18 22
./mpiserialunner 27 31
./mpiserialunner 36 40
./mpiserialunner 45 49
./mpiserialunner 72 76
./mpiserialunner 81 85
./mpiserialunner 90 94
./mpiserialunner 99 103
./mpiserialunner 108 112
./mpiserialunner 117 121
./mpiserialunner 126 130
./mpiserialunner 135 139
./mpiserialunner 144 148
./mpiserialunner 153 157
./mpiserialunner 162 166
./mpiserialunner 171 175
./mpiserialunner 180 184
./mpiserialunner 189 193
./mpiserialunner 198 202
./mpiserialunner 207 211
./mpiserialunner 216 220
./mpiserialunner 225 230
./mpiserialunner 234 238
./mpiserialunner 252 256
./mpiserialunner 261 265
./mpiserialunner 270 274
./mpiserialunner 279 283
./mpiserialunner 288 292
