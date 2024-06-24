# Run the program
g++ -o favorite_color favorite_color.cpp
rm output.txt input1.txt

# Run the program with valid favorite color
./favorite_color input.txt 0 0 0 output.txt


if [ -e output.txt ]; then
    echo "Test Passed: Output file created successfully"
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


./favorite_color input1.txt 255 255 255 output.txt


if [ $? -ne 0 ]; then
    echo "Test Passed: Program exited with non-zero status"
else
    echo "Test Failed: Program did not exit with non-zero status"
fi

#Invalid Pixel Values
./favorite_color input2.txt 255 255 255 output.txt
if [ $? -ne 0 ]; then
    echo "Test Passed: Program exited with non-zero status"
else
    echo "Test Failed: Program did not exit with non-zero status"
fi
