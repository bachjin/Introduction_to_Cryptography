#!/bin/bash

cd ./data/
rm outlist.txt
for filename in $(ls *.in)
do
	../logistic < ${filename} > ${filename%.*}".out"
	echo ${filename%.*}".out" >> outlist.txt
done

