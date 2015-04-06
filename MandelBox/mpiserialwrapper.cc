/*
 *	Iheatu Wogu 	: 0850010
 * 	Warren 			: 1131525
 *  Graeme 			: 
 *  Maciej 			: 0947341
 *  
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
 *  dynamic image creation
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
