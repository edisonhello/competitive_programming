#!/bin/bash

for i in $(seq -f "%02g" 1 9)
do
    echo "sample $i: "
    ./a.out < sample1/$i
done
