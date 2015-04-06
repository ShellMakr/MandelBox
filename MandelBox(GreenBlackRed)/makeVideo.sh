#!/bin/bash

echo "Creating new frame"	#avconv -framerate 30 -i image%d.bmp output.avi
avconv -framerate 30 -i image%d.bmp output.avi

