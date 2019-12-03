#!/bin/bash

cd ./data/
for filename in $(ls outlist.txt 2> /dev/null)
do
rm ${filename}
done

for filename in $(ls *.in)
do
	../logistic32_interfere < ${filename} 1> ${filename%.*}".out" 2> ${filename%.*}".times"
	echo ${filename%.*}".out" >> outlist.txt
done

