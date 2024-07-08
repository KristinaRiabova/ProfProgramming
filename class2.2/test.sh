#!/bin/bash

function compare_files {
    expected_file=$1
    actual_file=$2
    if cmp -s "$expected_file" "$actual_file"; then
        echo "Test Passed: Content matches"
    else
        echo "Test Failed: Content does not match"
    fi
}

# Compile C++ program
g++ -o favorite_color favorite_color.cpp

# Remove existing output file and input files
rm -f output.txt output1.txt output2.txt input1.txt

# Run the program with valid favorite color
./favorite_color input.txt 0 0 0 output.txt

if [ -e output.txt ]; then
    echo "Test Passed: Output file created successfully"
    compare_files expected_output.txt output.txt
else
    echo "Test Failed: Output file not created"
fi

# Run the program with invalid favorite color
./favorite_color input.txt 300 400 500 output1.txt

if [ $? -ne 0 ]; then
    echo "Test Passed: Program exited with non-zero status"
else
    echo "Test Failed: Program did not exit with non-zero status"
fi

# Run the program with invalid input file
./favorite_color input2.txt 255 255 255 output.txt

if [ $? -ne 0 ]; then
    echo "Test Passed: Program exited with non-zero status"
else
    echo "Test Failed: Program did not exit with non-zero status"
fi

# Empty Input File:
# Create an empty input file
touch input1.txt

# Run the program with an empty input file
./favorite_color input1.txt 255 255 255 output.txt

if [ $? -ne 0 ]; then
    echo "Test Passed: Program exited with non-zero status"
else
    echo "Test Failed: Program did not exit with non-zero status"
fi

# Run the program with invalid pixel values
./favorite_color input2.txt 255 255 255 output.txt

if [ $? -ne 0 ]; then
    echo "Test Passed: Program exited with non-zero status"
else
    echo "Test Failed: Program did not exit with non-zero status"
fi

# Unfavorite color is the same as the favorite color
./favorite_color input.txt 0 0 0 output2.txt 0 0 0

if [ $? -ne 0 ]; then
    echo "Test Passed: Program exited with non-zero status"
else
    echo "Test Failed: Program did not exit with non-zero status"
fi

# Run the program with valid favorite color and different unfavorite color
./favorite_color input.txt 0 0 0 output2.txt 2 2 2

if [ $? -ne 0 ]; then
    echo "Test Passed: Program exited with non-zero status"
else
    echo "Test Failed: Program did not exit with non-zero status"
fi
