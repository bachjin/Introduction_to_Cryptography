# Making Logistic random sequences
The project is composed of these parts:

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Making Logistic random sequences](#making-logistic-random-sequences)
  - [create_input.py](#create_inputpy)
  - [make_output.sh](#make_outputsh)
  - [logistic.c](#logisticc)
  - [logistic32*.c](#logistic32c)
  - [draw_picture.py](#draw_picturepy)
  - [draw_bit_picture.py](#draw_bit_picturepy)
  - [analyze_out.sh](#analyze_outsh)
  - [average_period.py](#average_periodpy)
  - [compute_period.sh](#compute_periodsh)
  - [compute_pass.sh](#compute_passsh)
  - [average_pass.py](#average_passpy)
  - [how to use](#how-to-use)

<!-- /code_chunk_output -->

## create_input.py
Create input data such as `3.6000-1.in` in the ./data directory. 
Save a file `mu_list.txt` with format "%f\n" for further analysis. 
## make_output.sh
Use every `*.in` file as input for `logistic32.c`, create the corresponding output `*.out`. And the times between a char's appearance with last time are saved in `*.times`.
And save a file `outlist.txt` in that directory for drawing program to read. 

## logistic.c
According to the input mu and x, output the next PRINT_TIMES numbers in [0, 255].
## logistic32*.c
Input format: (precise, mu, x)
```
32 3.6 0.4
```
For every substitution result, output only in [0, 256) in binary char to the stdout.
Output the distance of the same char output to the stderr. 
## draw_picture.py
Draw pictures of the `.out` files in ./data directory. 
## draw_bit_picture.py
The `.out` file contains only random bytes. 
## analyze_out.sh
Use every `.out` file as input bytes to dieharder analization. Each report is in the `.a` file. 
## average_period.py
Use lines just contain an integer as input. Output is a float of the average distance of elements. 
## compute_period.sh
Use every `.times` file as input to `average_period.py ` to compute its average period. 
Store the float into `.p`. 
## compute_pass.sh
Use every `.a` file as input to `average_pass.py` to count its pass times. The output is in `report.txt`.
## average_pass.py
Count their **PASSED**, **FAILED**, **WEAK**.


## how to use
    bash clear.sh
    python3 create_input.py
    bash make_output.sh
    python3 draw_bit_picture.py
    bash analyze_out.sh
    bash compute_period.sh
    bash compute_pass.sh

    * these below are just samples *
    cat *.out | dieharder -o -f example.input -t 10
    dieharder -g 202 -f example.input -a

    dieharder -g 201 -f example.bin -a
