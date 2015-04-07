#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "camera.h"
#include "renderer.h"
#include "mandelbox.h"

#define BUF_SIZE 1024

static char buf[BUF_SIZE];

int FPSForProject = 30;

void getParameters(char *filename, CameraParams *camera_params, RenderParams *renderer_params, MandelBoxParams *mandelBox_params );



// creates the parameter files to be read
void createParams( char * param_name, CameraParams *camP, RenderParams *renP, MandelBoxParams *boxP) {
	
	//file to write too
	FILE *fp;
	double *d;


	fp = fopen(param_name, "w");

	if( !fp ) 
	{
		printf(" *** File %s does not exist\n", renP->file_name);
		exit(1);
	}

	int count = 0;

	  // CAMERA
	  //camera position
	d = camP->camPos;
	fprintf( fp, "%lf %lf %lf\n", *d, *(d+1), *(d+2));

	  //camera target
	d = camP->camTarget;
	fprintf( fp, "%lf %lf %lf\n", *d, *(d+1), *(d+2));

	  //camera up 
	d = camP->camUp;
	fprintf( fp, "%lf %lf %lf\n", *d, *(d+1), *(d+2));

	  //field of view
	fprintf( fp, "%lf\n", camP->fov);


	  //IMAGE
	  //width, height
	fprintf( fp, "%d %d\n", renP->width, renP->height);

	  //detail
	fprintf( fp, "%f\n", renP->detail);


	  //FRACTAL
	fprintf( fp, "%f %f %f\n", boxP->scale, boxP->rMin, boxP->rFixed);


	fprintf( fp, "%d %f \n", boxP->num_iter, boxP->escape_time);


	  //COLORING 
	fprintf( fp, "%d\n", renP->colourType);

	fprintf( fp, "%f \n", renP->brightness);

	fprintf( fp, "%d \n", renP->super_sampling);


	  //FILENAME:
	fprintf(fp, "%s\n", renP->file_name);

	
	fclose(fp);

}


int main(int argc, char* argv[]) {

	CameraParams    cam_p;
	RenderParams    ren_p;
	MandelBoxParams man_p;
	char * param_name = (char*) calloc(40, sizeof(char));
	char * image_name = (char*) calloc(40, sizeof(char));
	
	printf("%s\n","generating files.." );

	// gets information from the base param file
	getParameters("baseParams.dat", &cam_p, &ren_p, &man_p);

	int start_file = atoi(argv[1]);
	int end_files = atoi(argv[2]);




	for (int i = start_file; i < end_files; i++) {

		sprintf(param_name, "params%d.dat", i);
		sprintf(image_name, "image%d.bmp", i);
		strcpy(ren_p.file_name, image_name);
		printf("%s\n",param_name);


		if ( i < 615 ) {

			cam_p.camPos[2] += -0.00975609975609975609975609;
			man_p.rMin += -0.0058203252032520325203252;

		} else if ( i > 614 && i < 1093 ) {
	
			cam_p.camPos[0] *= 0.998;
			cam_p.camPos[1] *= 0.998;
			cam_p.camPos[2] *= 0.998;

		} else if (i >= 1093 && i < 1275 ) {

			cam_p.camTarget[1] -= 0.025;
			cam_p.camPos[0] *= 0.9998;
			cam_p.camPos[1] *= 0.9998;
			cam_p.camPos[2] *= 0.9998;


		} else if ( i >= 1275 && i < 1875 ) {
			cam_p.camPos[1] -= 0.006;
		}



		//create parameter files
		createParams(param_name, &cam_p,  &ren_p, &man_p); 

	}

}
