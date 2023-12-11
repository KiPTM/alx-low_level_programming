#!/bin/bash

# Compile specific source files into a shared object library
gcc -shared -o liball.so -fPIC libdynamic.c functions.c
echo "Dynamic library 'liball.so' created from specific .c files"
