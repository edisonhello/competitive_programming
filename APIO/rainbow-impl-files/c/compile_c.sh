#!/bin/sh

gcc rainbow.c grader.c -o rainbow -O2 -static -lm -std=c11
