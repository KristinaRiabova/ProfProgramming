#!/bin/bash

# Test Case 1: New User
echo "Test Case 1: New User"
./task3 Kris

# Test Case 2: Returning User
echo "Test Case 2: Returning User"
./task3 Kris

# Test Case 3: Multiple Runs with Different Names
echo "Test Case 3: Multiple Runs with Different Names"
./task3 Kris
./task3 Stephan
./task3 Dima

# Test Case 4: Reset Statistics
echo "Test Case 4: Reset Statistics"
./task3 Kris
./task3 Kris delete
./task3 Kris
./task3 Kris

# Test Case 5: Clear History 
echo "Test Case 5: Clear History"
./task3 bread
./task3 Kris