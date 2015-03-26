LDFLAGS = -lm -openmp
CFLAGS= -O3 -Wall -openmp
CXXFLAGS= -O3 -Wall -openmp
CXX=mpicxx
CC=mpic++
RM=rm

PROGRAM_NAME= mandelbox

all: $(PROGRAM_NAME)

$(PROGRAM_NAME): main.o print.o timing.o savebmp.o getparams.o 3d.o getcolor.o distance_est.o mandelboxde.o raymarching.o renderer.o init3D.o
	$(CC) -o $@ $^ $(CFLAGS) $(LDFLAGS)

run-serial: $(PROGRAM_NAME)
	./$(PROGRAM_NAME)$(EXEXT) params.dat

clean:
	$(RM) *.o $(PROGRAM_NAME)$(EXEEXT) image.bmp
