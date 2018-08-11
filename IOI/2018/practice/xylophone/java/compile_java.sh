#!/bin/bash

TASK=xylophone

javac ${TASK}.java grader.java
jar cf ${TASK}.jar *.class
