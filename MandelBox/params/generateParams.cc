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

void createParams(CameraParams *camP, RenderParams *renP, MandelBoxParams *boxP) {
	
	//file to write too
	FILE *fp;
	double *d;


	fp = fopen(renP->file_name, "w");

	if( !fp ) 
	{
		printf(" *** File %s does not exist\n", renP->file_name);
		exit(1);
	}

	int count = 0;

	  // CAMERA
	  //camera position
	  d = camP->camPos;
	  fprintf( fp, "%lf %lf %lf\n", d, d+1, d+2);
	 
	  //camera target
	  d = camP->camTarget;
	  fprintf( fp, "%lf %lf %lf\n", d, d+1, d+2);
	 
	  //camera up 
	  d = camP->camUp;
	  fprintf( fp, "%lf %lf %lf\n", d, d+1, d+2);
	 
	  //field of view
	  fprintf( fp, "%lf\n", &camP->fov);
	 
	  
	  //IMAGE
	  //width, height
	  fprintf( fp, "%d %d\n", &renP->width, &renP->height);
	 
	  //detail
	  fprintf( fp, "%f\n", &renP->detail);
	 
	  
	  //FRACTAL
	  fprintf( fp, "%f %f %f\n", &boxP->scale, &boxP->rMin, &boxP->rFixed);
 	 
	  
	  fprintf( fp, "%d %f \n", &boxP->num_iter, &boxP->escape_time);
	 
	  
	  //COLORING 
	  fprintf( fp, "%d\n", &renP->colourType);
	 
	  fprintf( fp, "%f \n", &renP->brightness);
	 
	  fprintf( fp, "%d \n", &renP->super_sampling);
	 
	  
	  //FILENAME:
	  fprintf(fp, "%s\n", renP->file_name);
	 
	
	fclose(fp);

}




// float* changeSmootzh(int timeInSeconds, float beginValue, float endValue){//Smoothly changes a variable
// 	int numIter = FPSForProject*timeInSeconds;
// 	float stepSize = (endRange - beginRange)/numIter;

// 	int i;
// 	float varValues[numIter];
// 	for (i=0; i<numIter; i++){
// 		varValues[i] = stepSize*i + beginRange;
// 	}
// 	return varValues;
// }

int main(int argc, char* argv[]) {

	CameraParams    camera_params;
	RenderParams    renderer_params;
	MandelBoxParams mandelBox_params;
	char * image_name = (char*) calloc(40, sizeof(char));
	
	printf("%s\n","generating files.." );

	// gets information from the base param file
	getParameters("baseParams.dat", &camera_params, &renderer_params, &mandelBox_params);

	int num_of_files = atoi(argv[1]);

	for (int i = 0; i < num_of_files; i++) {

		CameraParams    cam_p = camera_params;
		RenderParams    ren_p = renderer_params;
		MandelBoxParams man_p = mandelBox_params;

		sprintf(image_name,"image%d.bmp",i);
		strcpy(ren_p.file_name, image_name);
		printf("%s\n",ren_p.file_name);


		//create parameter files
		createParams(&cam_p,  &ren_p, &man_p); 

	}



}
