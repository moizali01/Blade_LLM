#!/bin/bash

PROGRAM_NAME=sort-8.16
DIR=$(pwd)
ORIGINAL_FILE=$DIR/sort-util.c.blade.c
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
    eval "$command" >>${LOG} 2>&1
    a=$?
    if [ $a -ne 124 ]; then
        ((TOTAL_ROBUSTNESS_PASSED++))
    else
        echo "Test failed: $description" >>${LOG} 2>&1
        return
    fi
    
    
}
function functionality_cases() {
    echo "starting generality run" >>${LOG} 2>&1
    echo "=========================="
    echo "Functionality Related Tests"
    
    local english_dir="test_files/english"
    local numeric_dir="test_files/numeric_cases"
    local code_dir="test_files/code_files"
    local log_dir="test_files/log_files"
    local csv_files="test_files/csv_files"
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
    
    local security_dir="test_files/security_cases"
    
    for file in $security_dir/*; do
        echo "Running test $file"
        run_functionality "Security test file: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $file > $DIR/expected_output.txt; }" 1
    done
    
    test_name="Fuzzing with random data"
    run_functionality "$test_name" \
    "{ timeout $TIMEOUT_LIMIT python -c 'import random; print("".join(random.choice("abcde12345!@#$%^") for _ in range(1000)))''\" | $REDUCED_BINARY > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT python -c 'import random; print("".join(random.choice("abcde12345!@#$%^") for _ in range(1000)))''\" | $ORIGINAL_BINARY > $DIR/expected_output.txt; }" 1
    
    # Prepare test files and directories outside the test cases

    # Create directories
    mkdir -p no_read_dir
    mkdir -p sticky_dir

    # Create files and set permissions
    echo -e "apple\nbanana\ncherry" > readonly_file
    chmod 444 readonly_file

    echo -e "apple\nbanana\ncherry" > no_read_dir/file
    chmod 000 no_read_dir

    echo -e "apple\nbanana\ncherry" > setuid_file
    chmod u+s setuid_file

    echo -e "apple\nbanana\ncherry" > setgid_file
    chmod g+s setgid_file

    echo -e "apple\nbanana\ncherry" > sticky_dir/file
    chmod +t sticky_dir

    # Large buffer overflow input
    echo -e "$(printf '%0.s1' {1..1000000})\n$(printf '%0.s2' {1..1000000})" > buffer_overflow

    # Potential format string input
    echo -e "%s\n%s\n%s\n%s" > format_string

    # Maximum filename length
    FILE_NAME=$(printf 'a%.0s' {1..255})
    echo -e "apple\nbanana\ncherry" > $FILE_NAME

    # Running tests
    echo "Running test Non Existent file"
    run_functionality "Non Existent file" \
      "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/Non_existent_file.txt > $DIR/temp_output.txt; }" \
      "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/Non_existent_file.txt > $DIR/expected_output.txt; }" 1

    echo "Running test Read from read-only file"
    run_functionality "Read from read-only file" \
      "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY readonly_file > $DIR/temp_output.txt; }" \
      "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY readonly_file > $DIR/expected_output.txt; }" 1

    echo "Running test File in directory without read permission"
    run_functionality "File in directory without read permission" \
      "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY no_read_dir/file > $DIR/temp_output.txt; }" \
      "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY no_read_dir/file > $DIR/expected_output.txt; }" 1

    echo "Running test File with setuid bit"
    run_functionality "File with setuid bit" \
      "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY setuid_file > $DIR/temp_output.txt; }" \
      "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY setuid_file > $DIR/expected_output.txt; }" 1

    echo "Running test File with setgid bit"
    run_functionality "File with setgid bit" \
      "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY setgid_file > $DIR/temp_output.txt; }" \
      "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY setgid_file > $DIR/expected_output.txt; }" 1

    echo "Running test File in sticky bit directory"
    run_functionality "File in sticky bit directory" \
      "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY sticky_dir/file > $DIR/temp_output.txt; }" \
      "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY sticky_dir/file > $DIR/expected_output.txt; }" 1

    echo "Running test File with potential buffer overflow input"
    run_functionality "File with potential buffer overflow input" \
      "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY buffer_overflow > $DIR/temp_output.txt; }" \
      "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY buffer_overflow > $DIR/expected_output.txt; }" 1

    echo "Running test File with potential format string input"
    run_functionality "File with potential format string input" \
      "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY format_string > $DIR/temp_output.txt; }" \
      "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY format_string > $DIR/expected_output.txt; }" 1

    echo "Running test File with maximum allowed filename length"
    run_functionality "File with maximum allowed filename length" \
      "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $FILE_NAME > $DIR/temp_output.txt; }" \
      "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $FILE_NAME > $DIR/expected_output.txt; }" 1

    rm -rf readonly_file \
       no_read_dir/file \
       no_read_dir \
       setuid_file \
       setgid_file \
       sticky_dir/file \
       sticky_dir \
       buffer_overflow \
       format_string \
       $(printf 'a%.0s' {1..255}) 
}
function robustness_cases() {
    echo "=========================="
    echo "Robustness Related Tests"
    echo "=========================="
    local robustness_dir="test_files/robustness_cases"
    for file in $robustness_dir/*; do
        echo "Running test $file"
        run_robustness "Robustness test file: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }"
    done

    touch new_file.txt
    echo "Running test: Invalid Flag"
    run_robustness "Invalid Flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -abc new_file.txt > $DIR/temp_output.txt; }"

    echo "Running test: No arguments"
    run_robustness "No arguments " \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -a > $DIR/temp_output.txt; }" 

    echo {a..z} | tr ' ' '\n' | shuf > shuffled_alphabet.txt
 
    #test on all sort flags
    flags=(-b -d -f -g -i -M -h -n -R -r -V -c -C -k -m -o -s -S -t -T -u -z --help --version)
    for flag in ${flags[@]}; do
        echo "Running test invalid flag: $flag"
        run_robustness "Robustness test file: $flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $flag shuffled_alphabet.txt > $DIR/temp_output.txt; }"
    done

    
}

function clean_env() {
    cd $DIR
    rm -rf $REDUCED_BINARY $ORIGINAL_BINARY  $DIR/temp_output.txt $DIR/expected_output.txt > /dev/null 2>&1
    return 0
}

function main() {
    clean_env
    rm -rf $LOG
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
    echo "Total tests Passed: $((TOTAL_FUNCTIONALITY_PASSED + TOTAL_SECURITY_PASSED + TOTAL_ROBUSTNESS_PASSED))/$((TOTAL_FUNCTIONALITY + TOTAL_SECURITY + TOTAL_ROBUSTNESS))"
    
    return 0
}

main