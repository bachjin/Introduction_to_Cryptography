#!/bin/bash

cd ./data/

rm *.[ab] 2> /dev/null

for filename in $(ls *.out)
do 
    dieharder -g 201 -f ${filename} -d 4\
     >> ${filename%.*}".a"\
     2>> /dev/null
    dieharder -g 201 -f ${filename} -d 8\
     >> ${filename%.*}".a"\
     2>> /dev/null
    dieharder -g 201 -f ${filename} -d 9\
     >> ${filename%.*}".a"\
     2>> /dev/null
done