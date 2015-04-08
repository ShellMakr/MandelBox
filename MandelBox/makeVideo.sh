#!/bin/bash

#This is the a scripts that builds the video

echo "Creating new frame"
avconv -framerate 30 -i image%d.bmp output.avi
