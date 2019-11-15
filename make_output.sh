#!/bin/bash

cd ./data/
for filename in $(ls *.in)
do
	../logistic < ${filename} > ${filename%.*}".out"
done

