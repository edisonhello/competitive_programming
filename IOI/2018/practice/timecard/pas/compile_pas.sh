#!/bin/bash

TASK=timecard

fpc -XS -O2 -o${TASK} grader.pas
