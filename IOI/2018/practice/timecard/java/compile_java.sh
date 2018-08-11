#!/bin/bash

TASK=timecard

javac ${TASK}.java grader.java
jar cf ${TASK}.jar *.class