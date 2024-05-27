#!/bin/bash




if [ "$#" -ne 4 ]; then
    echo "Usage: ./compile.sh <source_file> -o <output_file>"
    exit 1
fi


source_file=$1
output_file=$4


clang++ -Wall -Wextra -Wpedantic -Werror -std=c++23 "$source_file" -o "$output_file"
