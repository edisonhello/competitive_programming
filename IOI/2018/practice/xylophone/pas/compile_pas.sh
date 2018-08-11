#!/bin/bash

TASK=xylophone

fpc -XS -O2 -o${TASK} grader.pas
