#!/bin/bash

PROGRAM_NAME=date-8.21
DIR=$(pwd)
C_FILE=$DIR/date-util.c.blade.c
# C_FILE=$DIR/date-blade.c
ORIGINAL_FILE=$DIR/date-org.c
ORIGINAL_BINARY=$DIR/date-original
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
CC=clang
TIMEOUT_LIMIT="-k 2 2"
LOG=$DIR/log
TOTAL_TESTS=0
PASSED_TESTS=0

# Function to clean up test files
function cleanup_test_files() {
    rm -f $DIR/temp_output.txt $DIR/expected_output.txt $DIR/combined_output.txt
}

# Function to run a single test case
function run_test_case() {
    local command=("$@")
    local description="${command[-1]}"
    unset 'command[-1]'
    
    ((TOTAL_TESTS++))

    # Run both commands simultaneously and capture their outputs
    { 
        paste <(timeout $TIMEOUT_LIMIT $REDUCED_BINARY "${command[@]}" 2>/dev/null) \
              <(timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "${command[@]}" 2>/dev/null)
    } > $DIR/combined_output.txt

    # Check if either command timed out or failed
    if [[ ${PIPESTATUS[0]} -ne 0 || ${PIPESTATUS[1]} -ne 0 ]]; then
        echo "Test failed: $description"
        echo "One or both commands failed or timed out."
        return 1
    fi

    # Separate the outputs
    cut -f1 $DIR/combined_output.txt > $DIR/temp_output.txt
    cut -f2 $DIR/combined_output.txt > $DIR/expected_output.txt

    # Compare the outputs
    diff $DIR/temp_output.txt $DIR/expected_output.txt
    
    if [[ $? -eq 0 ]]; then
        echo "Test passed: $description"
        # echo "Output: $(cat $DIR/temp_output.txt)"
        ((PASSED_TESTS++))
    else
        echo "Test failed: $description"
        # echo "Reduced output: $(cat $DIR/temp_output.txt)"
        # echo "Original output: $(cat $DIR/expected_output.txt)"
    fi

    cleanup_test_files
}

# Function to run date formatting tests
function run_format_tests() {
    echo
    echo "Running date formatting tests..."
    
    # Test case 1: Formatting the current date in YYYY-MM-DD format
    run_test_case "+%Y-%m-%d" "Format date in YYYY-MM-DD"

    # Test case 2: Formatting the current time in HH:MM:SS format
    run_test_case "+%H:%M:%S" "Format time in HH:MM:SS"

    # Test case 3: Displaying the Unix timestamp
    run_test_case "+%s" "Display Unix timestamp"

    # Test case 4: Formatting with full date and time
    run_test_case "+%Y-%m-%d+%H:%M:%S" "Format full date and time"

    # Test case 5: Custom format with weekday and week number
    run_test_case "+%A, Week %U" "Format with weekday and week number"

    # Test case 6: ISO 8601 format
    run_test_case "+%F +%T" "ISO 8601 date and time format"

    # Test case 7: Locale-specific format
    run_test_case "+%c" "Locale-specific date and time format"
}

function run_date_calculation_tests() {
    echo
    echo "Running date calculation tests..."
    
    # Relative date tests
    run_test_case -d "yesterday" "+%Y-%m-%d" "Calculate yesterday's date"
    run_test_case -d "tomorrow" "+%Y-%m-%d" "Calculate tomorrow's date"
    run_test_case -d "next Monday" "+%Y-%m-%d" "Calculate next Monday's date"
    run_test_case -d "last Friday" "+%Y-%m-%d" "Calculate last Friday's date"
    
    # Absolute date tests
    run_test_case -d "2024-01-01 + 5 days" "+%Y-%m-%d" "Calculate 5 days from 2024-01-01"
    run_test_case -d "2024-02-28 + 1 day" "+%Y-%m-%d" "Leap year: Calculate 1 day after Feb 28, 2024"
    run_test_case -d "2023-02-28 + 1 day" "+%Y-%m-%d" "Non-leap year: Calculate 1 day after Feb 28, 2023"
    
    # Edge case tests
    run_test_case -d "2024-01-31 + 1 month" "+%Y-%m-%d" "End-of-month transition: Jan 31 to Feb"
    run_test_case -d "2024-04-30 + 1 day" "+%Y-%m-%d" "End-of-month transition: Apr 30 to May 1"

    
    # Special case tests
    run_test_case -d "2023-12-31 + 1 day" "+%Y-%m-%d" "New Year's Eve to New Year's Day"
    run_test_case -d "100 years ago" "+%Y" "Calculate the year 100 years ago"


    # Incremental/Decremental tests
    run_test_case -d "2024-01-01 + 10 days" "+%Y-%m-%d" "Add 10 days to 2024-01-01"
    run_test_case -d "2024-01-01 - 2 weeks" "+%Y-%m-%d" "Subtract 2 weeks from 2024-01-01"
    run_test_case -d "2024-01-01 + 1 year" "+%Y-%m-%d" "Add 1 year to 2024-01-01"
    run_test_case -d "2024-01-01 + 1 month - 3 days" "+%Y-%m-%d" "Compound calculation: Add 1 month and subtract 3 days"
    
    # Negative offset tests
    run_test_case -d "-1 day" "+%Y-%m-%d" "Negative offset: Calculate the previous day"
    run_test_case -d "-1 month" "+%Y-%m-%d" "Negative offset: Calculate the previous month"
}

function run_generality_tests() {
    echo
    echo "Running generality tests..."
    
    # General test for compound functionality
    run_test_case -d "yesterday" "+%F +%T" "Combination of date calculation and formatting"
    run_test_case -d "2024-12-31 + 1 day" "+%A, %d %B %Y" "Calculate New Year's Day with full date formatting"
}
function run_edge_case_tests() {
    echo
    echo "Running edge case tests..."

    # Leap year tests
    run_test_case -d "2000-02-29" "+%Y-%m-%d" "Verify leap year 2000"
    run_test_case -d "2100-02-28 + 1 day" "+%Y-%m-%d" "Verify non-leap year 2100"
    run_test_case -d "2400-02-29" "+%Y-%m-%d" "Verify leap year 2400"

    # Date rollover tests
    run_test_case -d "2023-01-31 + 1 month" "+%Y-%m-%d" "Month rollover in a 31-day month"
    run_test_case -d "2023-03-31 - 1 month" "+%Y-%m-%d" "Month rollback from 31 to 28"

    # Large date ranges
    run_test_case -d "9999-12-31" "+%Y-%m-%d" "Far future date"
    run_test_case -d "0000-01-01" "+%Y-%m-%d" "Earliest representable date"
    run_test_case -d "@-62167219200" "+%Y-%m-%d" "Unix epoch for 0000-01-01"

   
}

function run_extended_generality_tests() {
    echo
    echo "Running extended generality tests..."

    # Various date input formats
    run_test_case -d "@1631234567" "+%Y-%m-%d %H:%M:%S" "Unix timestamp input"
    run_test_case -d "15 Sep 2023 14:30:00" "+%Y-%m-%d %H:%M:%S" "Human-readable date input"

    # Different output formats
    run_test_case -d "now" "+%s.%M"  "Unix timestamp with microseconds"

    # Relative date expressions
    run_test_case -d "now + 3 months 2 weeks 4 days" "+%Y-%m-%d" "Complex relative date calculation"
    run_test_case -d "today - 100 years" "+%Y-%m-%d" "Long-term past date calculation"

    # Combining multiple operations
    run_test_case -d "2023-01-01 + 1 year - 1 day" "+%Y-%m-%d" "Multiple date operations"
    run_test_case -d "last Monday + 2 weeks" "+%Y-%m-%d" "Relative and fixed date combination"

    # Date comparisons
    run_test_case -d "2023-01-01" -d "2024-01-01" "+%Y-%m-%d" "Compare two dates"

}


# Function to compile and test the binaries
function compile_and_test() {
    cd $DIR
    echo "Compiling binaries..."
    
    # Compile the original and reduced binaries
    $CC -w $ORIGINAL_FILE -o $ORIGINAL_BINARY >&$LOG || exit 1
    $CC -w $C_FILE -o $REDUCED_BINARY >&$LOG || exit 1

    # Run the tests
    run_format_tests
    run_date_calculation_tests
    run_generality_tests
    run_edge_case_tests
    run_extended_generality_tests

    echo
    echo "Total tests run: $TOTAL_TESTS"
    echo "Total tests passed: $PASSED_TESTS"
    if [[ $TOTAL_TESTS -eq $PASSED_TESTS ]]; then
        echo "All tests passed successfully."
    else
        echo "Some tests failed."
    fi
}

# Function to clean the environment
function clean_env() {
    rm -f $LOG $REDUCED_BINARY $ORIGINAL_BINARY
    cleanup_test_files
}

function main() {
    clean_env
    compile_and_test || exit 1
    
    clean_env
}

main
