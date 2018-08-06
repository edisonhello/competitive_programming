#!/bin/bash

NAME=artclass

# /usr/bin/g++ -ljpeg -DEVAL -static -O2 grader.c graderlib.c $NAME.cpp
g++ -ljpeg artclass.cpp grader.c graderlib.c
