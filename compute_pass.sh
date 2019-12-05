#!/bin/bash

cd ./data/

rm report.txt temp.txt 2> /dev/null

for mu in $(cat mu_list.txt)
do
    for precise in '08' '16' '24' '32'
    do 
            echo ${mu} ${precise} >> report.txt
            cat ${precise}*${mu}*.a | grep '\(\(bit\)\|\(1s\)\)' | \
            python3 ../average_pass.py >> report.txt
    done
done