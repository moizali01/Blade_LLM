#!/bin/bash

PROGRAM_NAME=sort-8.16
DIR=$(pwd)
ORIGINAL_FILE=$DIR/sort-cova.c
REDUCED_FILE=$DIR/sort-org.c
ORIGINAL_BINARY=$DIR/original_binary
REDUCED_BINARY=$DIR/reduced_binary
CC=clang
TIMEOUT_LIMIT="-k 10 10"
LOG=$DIR/log

TOTAL_TESTS=0

TOTAL_FUNCTIONALITY=0
TOTAL_SECURITY=0
TOTAL_ROBUSTNESS=0

TOTAL_FUNCTIONALITY_PASSED=0
TOTAL_SECURITY_PASSED=0
TOTAL_ROBUSTNESS_PASSED=0

function compile() {
    cd $DIR
    $CC $REDUCED_FILE -lpthread -w -o $REDUCED_BINARY >>${LOG} 2>&1 || exit 1
    $CC $ORIGINAL_FILE -lpthread -w -o $ORIGINAL_BINARY >>${LOG} 2>&1 || exit 1
    return 0
}


function run_functionality() {
    ((TOTAL_TESTS++))
    
    description=$1
    command=$2
    expected_command=$3
    sec_flag=$4
    touch $DIR/temp_output.txt $DIR/expected_output.txt
    local a=0
    local b=0
    
    if [ -n "$sec_flag" ] && [ "$sec_flag" -eq 1 ]; then
        ((TOTAL_SECURITY++))
    else
        ((TOTAL_FUNCTIONALITY++))
    fi
    
    echo -e "CASE: $TOTAL_TESTS, $description" >>${LOG} 2>&1
    eval "$command" >>${LOG} 2>&1
    if [ $? -ne 0 ]; then
        a=1
    else
        a=0
    fi
    
    eval "$expected_command" >>${LOG} 2>&1
    if [ $? -ne 0 ]; then
        b=1
    else
        b=0
    fi
    
    if [ $a -ne $b ]; then
        echo "Test failed: $description" >>${LOG} 2>&1
        return
    fi
    
    
    sed -i '/reduced_binary/d' $DIR/temp_output.txt
    sed -i '/original_binary/d' $DIR/expected_output.txt
    
    if diff $DIR/temp_output.txt $DIR/expected_output.txt >/dev/null; then
        if [ -n "$sec_flag" ] && [ "$sec_flag" -eq 1 ]; then
            ((TOTAL_SECURITY_PASSED++))
        else
            ((TOTAL_FUNCTIONALITY_PASSED++))
        fi
    else
        echo "Test failed: $description" >>${LOG} 2>&1
        echo "Expected output:"
        cat $DIR/expected_output.txt
        echo "Actual output:"
        cat $DIR/temp_output.txt
    fi
    rm $DIR/temp_output.txt $DIR/expected_output.txt >/dev/null 2>&1
}

function run_robustness() {
    ((TOTAL_TESTS++))
    ((TOTAL_ROBUSTNESS++))
    
    description=$1
    command=$2
    
    echo -e "CASE: $TOTAL_TESTS, $description" >>${LOG} 2>&1
    # eval "$command" >>${LOG} 2>&1
    output_debloat=$(timeout "$TIMEOUT_LIMIT" bash -c "$command" 2>&1 | sed "s|$REDUCED_BINARY: ||") || output_debloat="TIMEOUT"
    if [[ "$output_debloat" == "TIMEOUT" ]]; then
        echo "Test failed: $description" >>${LOG} 2>&1
        return
    fi
    ((TOTAL_ROBUSTNESS_PASSED++))
    
    
}
function functionality_cases() {
    echo "starting generality run" >>${LOG} 2>&1
    echo "=========================="
    echo "Functionality Related Tests"
    
    local english_dir="english"
    local numeric_dir="numeric_cases"
    local code_dir="code_files"
    local log_dir="log_files"
    local csv_files="csv_files"
    for file in $english_dir/*; do
        echo "Running test $file"
        run_functionality "Sorting English words: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $file > $DIR/expected_output.txt; }" 0
    done
    
    for file in $numeric_dir/*; do
        echo "Running test $file"
        run_functionality "Sorting Numeric values: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $file > $DIR/expected_output.txt; }" 0
    done
    
    for file in $code_dir/*; do
        echo "Running test $file"
        run_functionality "Sorting code files: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $file > $DIR/expected_output.txt; }" 0
    done
    
    for file in $log_dir/*; do
        echo "Running test $file"
        run_functionality "Sorting test file: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $file > $DIR/expected_output.txt; }" 0
    done
    
    for file in $csv_files/*; do
        echo "Running test $file"
        run_functionality "Sorting csv files: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $file > $DIR/expected_output.txt; }" 0
    done
    
    return 0
}
function security_cases() {
    #Non Existent file
    echo "=========================="
    echo "Security Related Tests"
    echo "=========================="
    
    local security_dir="security_cases"
    
    for file in $security_dir/*; do
        echo "Running test $file"
        run_functionality "Security test file: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $file > $DIR/expected_output.txt; }" 1
    done
    
    echo "Running test Non Existent file"
    run_functionality "Non Existent file" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/Non_existent_file.txt > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/Non_existent_file.txt > $DIR/expected_output.txt; }" 1
    
    test_name="Fuzzing with random data"
    run_functionality "$test_name" \
    "{ timeout $TIMEOUT_LIMIT python -c 'import random; print("".join(random.choice("abcde12345!@#$%^") for _ in range(1000)))''\" | $REDUCED_BINARY > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT python -c 'import random; print("".join(random.choice("abcde12345!@#$%^") for _ in range(1000)))''\" | $ORIGINAL_BINARY > $DIR/expected_output.txt; }" 1
    
    
    
}
function robustness_cases() {
    echo "=========================="
    echo "Robustness Related Tests"
    echo "=========================="
    local robustness_dir="robustness_cases"
    for file in $robustness_dir/*; do
        echo "Running test $file"
        run_robustness "Robustness test file: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }"
    done

    touch new_file.txt
    echo "Running test: Invalid Flag"
    run_robustness "Invalid Flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -a new_file.txt > $DIR/temp_output.txt; }"

    echo "Running test: No arguments"
    run_robustness "No arguments " \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -a > $DIR/temp_output.txt; }" 

    echo "Running test: -R flag"
    run_robustness "Invalid Flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -R new_file.txt > $DIR/temp_output.txt; }"
    
    echo "Running test: -z flag"
    run_robustness "Invalid Flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -z new_file.txt > $DIR/temp_output.txt; }"



    
}

function clean_env() {
    cd $DIR
    rm -rf  $LOG $REDUCED_BINARY $ORIGINAL_BINARY  $DIR/temp_output.txt $DIR/expected_output.txt > /dev/null 2>&1
    return 0
}

function main() {
    clean_env
    compile || exit 1
    
    functionality_cases
    security_cases
    robustness_cases
    
    clean_env
    
    echo "Total tests: $TOTAL_TESTS"
    echo "=========================="
    echo "Total functionality tests Passed: $TOTAL_FUNCTIONALITY_PASSED/$TOTAL_FUNCTIONALITY"
    echo "Total security tests Passed: $TOTAL_SECURITY_PASSED/$TOTAL_SECURITY"
    echo "Total robustness tests Passed: $TOTAL_ROBUSTNESS_PASSED/$TOTAL_ROBUSTNESS"
    echo "=========================="
    return 0
}

main