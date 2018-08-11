#!/bin/bash

TASK=xylophone

java -Xmx1024M -Xss1024M -cp ${TASK}.jar grader
