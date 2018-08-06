#!/bin/bash

NAME=artclass

/usr/bin/fpc -dEVAL -XS -O2 -o$NAME grader.pas
