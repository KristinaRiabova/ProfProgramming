#!/bin/bash


if [ "$#" -lt 4 ]; then
    echo "Usage: ./compile.sh <source_file> -o <output_file> [additional_flags]"
    exit 1
fi


source_file=$1
output_file=$4

# Shift the arguments so $@ will contain any additional flags passed
shift 4

clang++ -Wall -Wextra -Wpedantic -Werror -std=c++23 "$source_file" -o "$output_file" "$@"
