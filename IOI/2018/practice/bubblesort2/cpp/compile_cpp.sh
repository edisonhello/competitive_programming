#!/bin/bash

TASK=bubblesort2

g++ -std=c++14 -O2 -static -o ${TASK} grader.cpp ${TASK}.cpp
