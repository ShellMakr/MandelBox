#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "mpi.h"

void makeParams() {
	FILE *fp;
	int ender;
	static char buf[BUF_SIZE];



}


int main(int argc, char* argv[]) {

	int my_rank; 			/* rank of process */
	int p; 					/* number of processes */
	int tag = 0; 			/* tag for messages */
	MPI_Status status; 		/* status for receive */	


	MPI_Init(&argc, &argv);
	MPI_Comm_rank(MPI_COMM_WORLD, &my_rank);
	MPI_Comm_size(MPI_COMM_WORLD, &p);

	int range = 30 / p;

	for (int i = 0; i < range; ++i)
	{
		/* code */
	}



	system("./mandelbox params.dat");



	MPI_Finalize();
	return 0;

}