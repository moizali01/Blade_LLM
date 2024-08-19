#!/bin/bash

PROGRAM_NAME=date-8.21
DIR=$(pwd)
C_FILE=$DIR/date-util.c.blade.c
ORIGINAL_FILE=$DIR/date-org.c
ORIGINAL_BINARY=$DIR/date-original
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log.txt
TOTAL_TESTS=0
PASSED_TESTS=0

# Function to create random files for testing
function create_test_files() {
    # Regular file
    # echo "Creating regular test file..."
    touch $DIR/testfile.txt

    # File with special characters in the name
    # echo "Creating file with special characters..."
    touch $DIR/"special_file_@#$%.txt"

    # File with long name
    # echo "Creating file with a long name..."
    touch $DIR/"this_is_a_very_long_filename_to_test_the_edge_case_of_filename_length.txt"

    # Hidden file
    # echo "Creating hidden file..."
    touch $DIR/.hiddenfile

    # File with spaces in the name
    # echo "Creating file with spaces in the name..."
    touch $DIR/"file with spaces.txt"

    # Create files with random modification times
    touch -t 202401010101 $DIR/testfile.txt
    touch -t 202306151230 $DIR/"special_file_@#$%.txt"
    touch -t 202212241200 $DIR/"this_is_a_very_long_filename_to_test_the_edge_case_of_filename_length.txt"
    touch -t 202408191245 $DIR/.hiddenfile
    touch -t 202402251530 $DIR/"file with spaces.txt"
}

# Function to clean up test files
function cleanup_test_files() {
    rm -f $DIR/testfile.txt
    rm -f $DIR/"special_file_@#$%.txt"
    rm -f $DIR/"this_is_a_very_long_filename_to_test_the_edge_case_of_filename_length.txt"
    rm -f $DIR/.hiddenfile
    rm -f $DIR/"file with spaces.txt"
    rm -f $DIR/temp_output.txt
    rm -f $DIR/expected_output.txt
    rm -f $DIR/dates.txt
    rm -f $DIR/dates1.txt
    rm -f $DIR/dates2.txt
}

# Function to run a single test case
function run_test_case() {
    local test_name=$1
    local reduced_command=$2
    local original_command=$3

    echo "Running $test_name..."
    ((TOTAL_TESTS++))

    # Run the reduced binary command
    { timeout $TIMEOUT_LIMIT $reduced_command &> $DIR/temp_output.txt; } &> /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        echo fail
        return
    fi
    
    # Run the original binary command
    { timeout $TIMEOUT_LIMIT $original_command &> $DIR/expected_output.txt; } &> /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        echo "$test_name failed on original binary."
        return
    fi
    diff $DIR/temp_output.txt $DIR/expected_output.txt > /dev/null
    if [[ $? -ne 0 ]]; then
        echo fail
        return
    fi
    echo pass
    ((PASSED_TESTS++))
}

run_disaster() {
    local test_name=$1
    local reduced_command=$2
    local original_command=$3

    echo "Running $test_name..."
    ((TOTAL_TESTS++))

    # Run the reduced binary command
    { timeout $TIMEOUT_LIMIT $reduced_command &> $DIR/temp_output.txt; } &> /dev/null
    r=$?
    if [[ $r -ne 1 ]]; then
        echo fail
        return
    fi
    
    # Run the original binary command
    { timeout $TIMEOUT_LIMIT $original_command &> $DIR/expected_output.txt; } &> /dev/null
    diff $DIR/temp_output.txt $DIR/expected_output.txt > /dev/null
    if [[ $? -ne 0 ]]; then
        echo fail
        return
    fi
    echo pass
    ((PASSED_TESTS++))
}


function run_generality_tests() {
    run_f_flag_tests
    # Summary of test results
    echo "Summary: $PASSED_TESTS out of $TOTAL_TESTS tests passed."
}

function run_f_flag_tests() {
    # Test 1: Valid dates in file
    echo "2023-08-19" > $DIR/dates.txt
    echo "2024-01-01" >> $DIR/dates.txt
    run_test_case "-f flag with valid dates" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt
    
    # Test 2: Invalid dates in file
    echo "invalid-date" > $DIR/dates.txt
    echo "2023-02-30" >> $DIR/dates.txt
    run_disaster "-f flag with invalid dates" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 3: Empty file
    > $DIR/dates.txt
    run_test_case "-f flag with empty file" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 4: File with mixed valid and invalid dates
    echo "2023-08-19" > $DIR/dates.txt
    echo "invalid-date" >> $DIR/dates.txt
    echo "2024-01-01" >> $DIR/dates.txt
    run_disaster "-f flag with mixed valid and invalid dates" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 5: File with a date that has a time component
    echo "2023-08-19 12:34:56" > $DIR/dates.txt
    echo "2024-01-01 23:59:59" >> $DIR/dates.txt
    run_test_case "-f flag with date and time components" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 6: File with dates in different formats
    echo "08/19/2023" > $DIR/dates.txt
    echo "2024-01-01" >> $DIR/dates.txt
    run_test_case "-f flag with different date formats" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 7: File with a lot of dates
    for i in {1..100}
    do
        echo "2023-08-19" >> $DIR/dates.txt
    done
    run_test_case "-f flag with a lot of dates" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 8: File with dates in the past, present, and future
    echo "2021-08-19" > $DIR/dates.txt
    echo "2023-08-19" >> $DIR/dates.txt
    echo "2024-01-01" >> $DIR/dates.txt
    run_test_case "-f flag with dates in the past, present, and future" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 9: File with dates and other text
    echo "2023-08-19" > $DIR/dates.txt
    echo "This is a test file." >> $DIR/dates.txt
    echo "2024-01-01" >> $DIR/dates.txt
    run_disaster "-f flag with dates and other text" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 10: File with dates and special characters
    echo "2023-08-19" > $DIR/dates.txt
    echo "2024-01-01" >> $DIR/dates.txt
    run_test_case "-f flag with dates and special characters" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 11: File with dates and spaces
    echo "  2023-08-19" > $DIR/dates.txt
    echo "2024-01-01  " >> $DIR/dates.txt
    echo " " >> $DIR/dates.txt
    run_test_case "-f flag with dates and spaces" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 12: File with dates and newlines
    echo "2023-08-19" > $DIR/dates.txt
    echo "" >> $DIR/dates.txt
    echo "2024-01-01" >> $DIR/dates.txt
    run_test_case "-f flag with dates and newlines" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 13: File with dates and tabs
    echo "2023-08-19" > $DIR/dates.txt
    echo -e "\t2024-01-01" >> $DIR/dates.txt
    run_test_case "-f flag with dates and tabs" "$REDUCED_BINARY -f $DIR/dates.txt" "$ORIGINAL_BINARY -f $DIR/dates.txt"
    rm -f $DIR/dates.txt

    # Test 14: Files with valid dates but special characters in the name
    echo "2023-08-19" > $DIR/"dates@#$%.txt"
    echo "2024-01-01" >> $DIR/"dates@#$%.txt"
    run_test_case "-f flag with valid dates but special characters in the name" "$REDUCED_BINARY -f $DIR/dates@#$%.txt" "$ORIGINAL_BINARY -f $DIR/dates@#$%.txt"
    rm -f $DIR/"dates@#$%.txt"

    # Test 15: Files with valid dates but spaces in the name
    echo "2023-08-19" > $DIR/"dates with spaces.txt"
    echo "2024-01-01" >> $DIR/"dates with spaces.txt"
    run_test_case "-f flag with valid dates but spaces in the name" "$REDUCED_BINARY -f $DIR/dates with spaces.txt" "$ORIGINAL_BINARY -f $DIR/dates with spaces.txt"
    rm -f $DIR/"dates with spaces.txt"

}

function compile_and_test() {
    cd $DIR
    CFLAGS="-w $BIN_CFLAGS"
    
    # Compile original binary
    $CC $ORIGINAL_FILE $CFLAGS -o $ORIGINAL_BINARY >&$LOG || exit 1
    
    # Compile reduced binary
    $CC $C_FILE $CFLAGS -o $REDUCED_BINARY >&$LOG || exit 1
    
    # Create test files
    create_test_files
    
    # Run generality tests
    run_generality_tests

    # Clean up test files
    cleanup_test_files
}

function clean_env() {
    cd $DIR
    rm -rf $LOG $REDUCED_BINARY $ORIGINAL_BINARY $DIR/temp_output.txt $DIR/expected_output.txt dates.txt dates1.txt dates2.txt
    return 0
}

function main() {
    clean_env
    compile_and_test || exit 1
    clean_env
}

main