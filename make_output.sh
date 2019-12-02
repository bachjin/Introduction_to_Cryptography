#!/bin/bash

cd ./data/
for filename in $(ls outlist.txt 2> /dev/null)
do
rm ${filename}
done

for filename in $(ls *.in)
do
	../logistic32_interfere < ${filename} > ${filename%.*}".out"
	echo ${filename%.*}".out" >> outlist.txt
done

