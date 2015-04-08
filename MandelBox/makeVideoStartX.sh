#!/bin/bash

#This scripts makes a video from a certain frame

echo "Making video from $1 onwards"
avconv -framerate 30 -start_number $1 -i image%d.bmp startingAt$1.avi
