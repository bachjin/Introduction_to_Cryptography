#!/bin/bash

cd ./data/

for mu in $(cat mu_list.txt)
do
    for precise in '08' '16' '24' '32'
    do 
        cat ${precise}*${mu}*.b | awk '{ print $7 }' | \
        python3 ../average_period.py > ${precise}'-'${mu}".p"
    done
done