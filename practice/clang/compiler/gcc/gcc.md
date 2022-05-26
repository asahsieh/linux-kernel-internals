# C Language - GNU Compiler Collection (GCC)

[TOC]

> [online docs of GCC](https://gcc.gnu.org/onlinedocs/gcc/)

## [3 GCC Command Options](https://gcc.gnu.org/onlinedocs/gcc/Invoking-GCC.html#Invoking-GCC)
### 3.13 Options Controlling the Preprocessor
> [online link](https://gcc.gnu.org/onlinedocs/gcc/Preprocessor-Options.html#Preprocessor-Options)
#### `gcc -E -o out_file.i in_file.c`
Do preprocessing
#### `-D name`
Predefine *name* as a macro, with definition 1. 

## My notes
### Creating object files
> ref. [3.1 creating object files ](https://www.gnu.org/software/libtool/manual/html_node/Creating-object-files.html) in [Libtool](https://www.gnu.org/software/libtool/manual/html_node/index.html)

To create an object file from a source file, the compiler is invoked with the -c flag (and any other desired flags):

`burger$ gcc -g -O -c main.c`
