#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <iostream>
#include <fstream>
#include "camera.h"
#include "renderer.h"
#include "mandelbox.h"

int FPSForProject = 30;

void getParameters(char *filename, CameraParams *camera_params, RenderParams *renderer_params,
		   MandelBoxParams *mandelBox_paramsP);

MandelBoxParams mandelBox_params;

float* changeSmooth(int timeInSeconds, float beginValue, float endValue){//Smoothly changes a variable
	int numIter = FPSForProject*timeInSeconds;
	float stepSize = (endRange - beginRange)/numIter;

	int i;
	float varValues[numIter];
	for (i=0; i<numIter; i++){
		varValues[i] = stepSize*i + beginRange;
	}
	return varValues;
}

void createParams(const char filename) {

}

int main(int argc, char* argv[]) {

	CameraParams    camera_params;
  	RenderParams    renderer_params;
  	char * image_name = (char*) calloc(40, sizeof(char));

	printf("%s\n","generating files.." );

	// gets information from the base param file
	getParameters("baseParams.dat", &camera_params, &renderer_params, &mandelBox_params);

	int num_of_files = atoi(argv[1]);

	for (int i = 0; i < num_of_files; i++) {
		sprintf(image_name,"image%d.bmp",i);
		strcpy(renderer_params.file_name, image_name);
		printf("%s\n",renderer_params);
	}



}
