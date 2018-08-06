#!/bin/bash

for i in $(seq -f "%02g" 1 10)
do
    echo "sample $i: "
    ./a.out < sample3/$i
done
