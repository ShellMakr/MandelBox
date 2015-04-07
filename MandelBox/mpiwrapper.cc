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
#include "mpi.h"

#define BUF_SIZE 1024

static char buf[BUF_SIZE];
char * filename = "params.dat";
char * newparams = (char*) calloc(40, sizeof(char));
int fractal_dec = 0.01137;




int main(int argc, char* argv[]) {

	int my_rank; 			/* rank of process */
	int p; 					/* number of processes */
	int tag = 0; 			/* tag for messages */
	MPI_Status status; 		/* status for receive */
	char * command = (char*) calloc(40, sizeof(char));
	int start;
	int end;



	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	// pass in range of images that mpi is too compute
	start = atoi(argv[1]);
	end = atoi(argv[2]);
	int block = (end - start)/ p;


	// this computes the mandelbrot images for a range
	// defined for each process
	for (int i = start + (block*my_rank); i < start + ((my_rank+1)*block); i++)
	{

		sprintf(newparams,"params/params%d.dat",i);
		sprintf(command, "./mandelbox %s", newparams);
		//call the command to make the mandelbrot image
		system(command);
	}

	// this gives remainder images to the first process to computes
	if (my_rank == 0) {

		int initial = start + (block * p);
		for (int i = initial; i < end; i++)
		{
			sprintf(newparams,"params/params%d.dat",i);
			sprintf(command, "./mandelbox %s", newparams);
			//call the command to make the mandelbrot image
			system(command);
		}
	}



	MPI_Finalize();
	return 0;

}