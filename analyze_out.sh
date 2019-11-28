#!/bin/bash

cd ./data/

for filename in $(ls *.out)
do 
    dieharder -g 201 -f ${filename} -a\
     > ${filename%.*}".a"\
     2> ${filename%.*}".b"
done