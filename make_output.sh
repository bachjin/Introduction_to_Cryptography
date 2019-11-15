#!/bin/bash

cd ./data/
for filename in $(ls *.in)
do
	../logistic < ${filename} > ${filename: 0: 2}".out"
done

