LDFLAGS = -lm -fopenmp
CFLAGS= -O3 -Wall -fopenmp
CXXFLAGS= -O3 -Wall -fopenmp
CC=g++
RM=rm

PROGRAM_NAME= mandelbox

$(PROGRAM_NAME): main.o print.o timing.o savebmp.o getparams.o 3d.o getcolor.o distance_est.o mandelboxde.o raymarching.o renderer.o init3D.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

run-serial:
	./generateParams.sh 7199
	time ./runParams.sh 7199

run-parallel:
	cd params	
	./generateParams.sh 7199
	cd ..
	mpiCC mpiwrapper.cc -o mpirunner 
	mpirun -np 4 ./mpirunner

clean:
	$(RM) *.o $(PROGRAM_NAME)$(EXEEXT) *~ image.bmp *.gcno *.gcda gmon.out *.gcov params*.dat image*.bmp
