/*
 *	Iheatu Wogu 	: 0850010
 * 	Warren 			: 1131525
 *  Graeme 			: 1153121
 *  Maciej 			: 0947341
 */


/*
 *	generateParams.cc
 *	object filename 	: paramGenerator
 *
 *	This file creates the parameter files
 *  that mandelbox uses the generate image files
 *  
 * 
 */




#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "camera.h"
#include "renderer.h"
#include "mandelbox.h"


void getParameters(char *filename, CameraParams *camera_params, RenderParams *renderer_params, MandelBoxParams *mandelBox_params );



// Uses the baseParams.dat collect information that is used
// to generate the rest of the parameter files.

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

	int end_files = atoi(argv[1]);



/**
 * This loop alters the parameters of the MadnelBox cube to enalbe us to navigate through
 */
	for (int i = 0; i < end_files; i++) {

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
			cam_p.camPos[1] -= 0.0069;

		} else if (i>= 1875 && i < 2205 ) {

			//cam_p.camTarget[2] -= 0.025;
			cam_p.camPos[2] -= 0.006;
		}
		else if (i>=2205&&i<2895){
			cam_p.camTarget[1]+=0.00525;
			cam_p.camPos[0]-=0.006;
		}
		else if (i>=2895 && i<3225){
			cam_p.camPos[2]+=0.006;
		}
		else if (i>=3225 && i<3630){
			cam_p.camTarget[1]-=0.00832716;
			cam_p.camPos[1]+=0.0069;
		}
		else if (i>=3630&&i<3780){
			cam_p.camTarget[1]+=0.03777777;
			cam_p.camTarget[2]+=0.025;
			cam_p.camPos[1]+=0.0069;
		}
		else if (i>=3780 && i <4530){
			cam_p.camTarget[1]-=0.03777777;
			cam_p.camPos[2]-=0.006;
		}
		else if (i>=4530 && i < 5580 ){
			
			cam_p.camTarget[0]-=0.03777777;
			cam_p.camPos[1]-=0.002;

		} else if (i >= 5580 &&  i < 6060 ) {

			cam_p.camTarget[2]+=0.097;
			cam_p.camPos[0]-=0.002;

			cam_p.camPos[2]+=0.007;

		} else if ( i >= 6060 && i < 7560 ) {

			cam_p.camTarget[2] -= 0.091;
			cam_p.camPos[1] -= 0.001777777;
			man_p.rMin += -0.0015;
		}

		//create parameter files
		createParams(param_name, &cam_p,  &ren_p, &man_p); 

	}

}
