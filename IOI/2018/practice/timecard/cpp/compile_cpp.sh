#!/bin/bash

TASK=timecard

g++ -std=c++14 -Wall -O2 -static -o ${TASK} grader.cpp ${TASK}.cpp
