#!/bin/bash

# Paths to the files
PROGRAM_NAME="grep"
DIR=$(pwd)
ORIGINAL_FILE="grep-org.c"
DEBLOATED_FILE="grep-util.c"
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang
TIMEOUT_LIMIT="-k 5 5"
LOG=$DIR/log.txt

compile_files(){
    CFLAGS="-w $1 -D __msan_unpoison(s,z) -lpcre"
    # Compiling the original file
    $CC -w $ORIGINAL_FILE $CFLAGS -o $ORIGINAL_BINARY 
    if [ $? -ne 0 ]; then
        echo "Error: Compilation of $ORIGINAL_FILE failed"
        exit 1
    fi

    # Compiling the debloated file
    $CC -w $DEBLOATED_FILE $CFLAGS  -o $REDUCED_BINARY 
    if [ $? -ne 0 ]; then
        echo "Error: Compilation of $DEBLOATED_FILE failed"
        exit 1
    fi
    
    return 0
}

# Function to execute grep and check the result
execute_grep() {
    local file=$1
    local pattern=$2
    local output_file=$3

    # Executing: grep $pattern $file
    echo "Executing: grep $pattern $file"
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "$pattern" $file; } > $output_file 2> $LOG
    if [ $? -ne 0 ]; then
        echo "Error: grep $pattern $file failed"
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY "$pattern" $file; } > "temporary_reduced.txt" 2> $LOG
    if [ $? -ne 0 ]; then
        echo "Error: grep $pattern $file failed"
        return 1
    fi
    # Comparing the output of the original and the debloated binary
    diff $output_file "temporary_reduced.txt" >& /dev/null
    if [ $? -ne 0 ]; then
        echo "Error: Output of grep $pattern $file is different"
        rm "temporary_reduced.txt"
        return 1
    fi

    rm "temporary_reduced.txt"
    echo Test passed

    return 0
}

run(){
    # Creating a small test file with log entries
    echo -e "INFO: This is a log message\nERROR: This is an error message\nWARNING: This is a warning message" > small_log.txt
    
    # Creating a directory with multiple test files
    mkdir -p test_dir
    echo -e "ERROR: First error message" > test_dir/file1.txt
    echo -e "INFO: Just an info message\nERROR: Second error message" > test_dir/file2.txt
    echo -e "WARNING: Just a warning" > test_dir/file3.txt

    # Execute grep on the single test file
    execute_grep "small_log.txt" "ERROR" "output_small_error.txt" || return 1

    # Execute grep on the directory
    execute_grep "-r test_dir" "ERROR" "output_dir_error.txt" || return 1

    # execute grep on multiple files
    execute_grep "small_log.txt test_dir/file1.txt test_dir/file2.txt test_dir/file3.txt" "ERROR" "output_dir_error.txt" || return 1

    return 0
}

clean_env(){
    rm -f $REDUCED_BINARY $LOG $ORIGINAL_BINARY small_log.txt output_small_error.txt output_dir_error.txt temporary_reduced.txt
    rm -rf test_dir
    return 0
}

function main(){
    clean_env
    compile_files
    run || exit 1
    clean_env
    exit 0
}

main
