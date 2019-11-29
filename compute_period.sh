#!/bin/bash

cd ./data/

for filename in $(ls *.b)
do 
    cat ${filename} | awk '{ print $7 }' | \
    python3 ../average_period.py > ${filename%.*}".p"
done