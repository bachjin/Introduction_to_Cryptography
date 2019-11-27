# Making Logistic random sequences
The project is composed of these parts:

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Making Logistic random sequences](#making-logistic-random-sequences)
  - [create_input.py](#create_inputpy)
  - [make_output.sh](#make_outputsh)
  - [logistic.c](#logisticc)
  - [logistic32.c](#logistic32c)
  - [draw_picture.py](#draw_picturepy)
  - [draw_bit_picture.py](#draw_bit_picturepy)
  - [how to use](#how-to-use)

<!-- /code_chunk_output -->

## create_input.py
Create input data such as `3.6000-1.in` in the ./data directory. 
## make_output.sh
Use every `*.in` file as input for `logistic.c`, create the corresponding output `*.out`. 
And save a file `outlist.txt` in that directory for drawing program to read. 

## logistic.c
According to the input mu and x, output the next PRINT_TIMES numbers in [0, 255].
## logistic32.c
The accuracy become 32 bits. And the output is now bytes instead of ascii numbers. 
## draw_picture.py
Draw pictures of the `.out` files in ./data directory. 
## draw_bit_picture.py
The `.out` file contains only random bytes. 


## how to use
> python3 create_input.py
> bash make_output.sh
> python3 draw_picture.py

> cat *.out | dieharder -o -f example.input -t 10
> dieharder -g 202 -f example.input -a
### sample input {ignore = true}
----
3.75 0.5
### sample output {ignore = true}
----
239
56
164
220
115
237
64
180
199
164

