#!/bin/bash

# Specify the binary to test
# Change this variable based on the type of binary to test
BINARY_TO_TEST="java task3"

# Function to compare actual result (AR) with expected result (ER)
compare_results() {
    AR="$1"
    ER="$2"
    if [ "$AR" = "$ER" ]; then
        echo "PASS: Expected result matches actual result"
    else
        echo "FAIL: Expected result does not match actual result"
    fi
}

# Test Case 1: New User
echo "Test Case 1: New User"
EXPECTED_RESULT="Welcome, Kris!"
ACTUAL_RESULT="$($BINARY_TO_TEST Kris)"
compare_results "$ACTUAL_RESULT" "$EXPECTED_RESULT"

# Test Case 2: Returning User
echo "Test Case 2: Returning User"
EXPECTED_RESULT="Hello again(x1), Kris"
ACTUAL_RESULT="$($BINARY_TO_TEST Kris)"
compare_results "$ACTUAL_RESULT" "$EXPECTED_RESULT"

# Test Case 3: Multiple Runs with Different Names
echo "Test Case 3: Multiple Runs with Different Names"
EXPECTED_RESULT_1="Welcome, Vera!"
EXPECTED_RESULT_2="Welcome, Stephan!"
EXPECTED_RESULT_3="Welcome, Dima!"
ACTUAL_RESULT_1="$($BINARY_TO_TEST Vera)"
ACTUAL_RESULT_2="$($BINARY_TO_TEST Stephan)"
ACTUAL_RESULT_3="$($BINARY_TO_TEST Dima)"
compare_results "$ACTUAL_RESULT_1" "$EXPECTED_RESULT_1"
compare_results "$ACTUAL_RESULT_2" "$EXPECTED_RESULT_2"
compare_results "$ACTUAL_RESULT_3" "$EXPECTED_RESULT_3"

# Test Case 4: Reset Statistics
echo "Test Case 4: Reset Statistics"
EXPECTED_RESULT_1="Welcome, Alena!"
EXPECTED_RESULT_2="Statistics for Alena reset."
EXPECTED_RESULT_3="Welcome, Alena!"
ACTUAL_RESULT_1="$($BINARY_TO_TEST Alena)"
ACTUAL_RESULT_2="$($BINARY_TO_TEST Alena delete)"
ACTUAL_RESULT_3="$($BINARY_TO_TEST Alena)"
compare_results "$ACTUAL_RESULT_1" "$EXPECTED_RESULT_1"
compare_results "$ACTUAL_RESULT_2" "$EXPECTED_RESULT_2"
compare_results "$ACTUAL_RESULT_3" "$EXPECTED_RESULT_3"

# Test Case 5: Clear History with Secret Word
echo "Test Case 5: Clear History with Secret Word"
EXPECTED_RESULT="All history cleared."
ACTUAL_RESULT="$($BINARY_TO_TEST bread)"
compare_results "$ACTUAL_RESULT" "$EXPECTED_RESULT"

# Additional Test: Verify history is cleared
echo "Additional Test: Verify history is cleared"
ACTUAL_RESULT="$($BINARY_TO_TEST Kris)"
EXPECTED_RESULT="Welcome, Kris!"
compare_results "$ACTUAL_RESULT" "$EXPECTED_RESULT"
