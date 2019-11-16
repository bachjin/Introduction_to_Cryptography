# Making Logistic random sequences
The project is composed of these parts:

<!-- @import "[TOC]" {cmd="toc" depthFrom=1 depthTo=6 orderedList=false} -->

<!-- code_chunk_output -->

- [Making Logistic random sequences](#making-logistic-random-sequences)
  - [create_input.py](#create_inputpy)
  - [make_output.sh](#make_outputsh)
  - [logistic.c](#logisticc)

<!-- /code_chunk_output -->

## create_input.py
Create input data such as `1.in` in the ./data directory. 
## make_output.sh
Use every `*.in` file as input for `logistic.c`, create the corresponding output. 
## logistic.c
According to the input mu and x, output the next PRINT_TIMES numbers in [0, 255].

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

