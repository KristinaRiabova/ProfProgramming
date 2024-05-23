#!/bin/bash

# Test Case 1: New User
echo "Test Case 1: New User"
java task3 Kris

# Test Case 2: Returning User
echo "Test Case 2: Returning User"
java task3 Kris

# Test Case 3: Multiple Runs with Different Names
echo "Test Case 3: Multiple Runs with Different Names"
java task3 Kris
java task3 Stephan
java task3 Dima

# Test Case 4: Reset Statistics
echo "Test Case 4: Reset Statistics"
java task3 Kris
java task3 Kris delete
java task3 Kris
java task3 Kris

# Test Case 5: Clear History with Secret Word
echo "Test Case 5: Clear History with Secret Word"
java task3 bread
java task3 Kris
