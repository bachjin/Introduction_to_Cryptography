#!/bin/bash

cd ./data/
rm outlist.txt
for filename in $(ls *.in)
do
	../logistic32 < ${filename} > ${filename%.*}".out"
	echo ${filename%.*}".out" >> outlist.txt
done

