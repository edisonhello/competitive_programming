#!/bin/bash

NAME=dreaming

/usr/bin/gcc -std=gnu99 -DEVAL -static -O2 -o $NAME grader.c $NAME.c -lm
