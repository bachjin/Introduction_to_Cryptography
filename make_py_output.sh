#!/bin/bash

cd ./data/
for filename in $(ls *.in)
do 
	python3 ../logistic.py < ${filename} > ${filename%.*}".out"
done
