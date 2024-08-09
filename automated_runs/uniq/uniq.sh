#!/bin/bash

# Paths to the files
PROGRAM_NAME="uniq-8.16"
LARGE_FILE="data.c"
SMALL_FILE="lines"
DIR=/$(pwd)
ORIGINAL_FILE="uniq-og.c"
DEBLOATED_FILE="uniq-util.c"
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log.txt

# Initialize score
score=0
total_tests=2

compile_files(){
    # echo "Compiling the original file"
    $CC -w $ORIGINAL_FILE -o $ORIGINAL_BINARY 
    if [ $? -ne 0 ]; then
        # echo "Error: Compilation of $ORIGINAL_FILE failed"
        exit 1
    fi

    # echo "Compiling the debloated file"
    $CC -w $DEBLOATED_FILE -o $REDUCED_BINARY 
    if [ $? -ne 0 ]; then
        # echo "Error: Compilation of $DEBLOATED_FILE failed"
        exit 1
    fi
}
# Function to execute uniq and check the result
execute_uniq() {
    local file=$1
    local output_file=$2

    # echo "Executing: uniq $file"
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $file; } > $output_file 2>> $LOG
    if [ $? -ne 0 ]; then
        # echo "Error: uniq $file failed because of original binary"
        rm "temporary_reduced.txt"
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file; } > "temporary_reduced.txt" 2>> $LOG
    if [ $? -ne 0 ]; then
        # echo "Error: uniq $file failed because of reduced binary"
        rm "temporary_reduced.txt"
        return 1
    fi
    diff $output_file "temporary_reduced.txt"
    if [ $? -ne 0 ]; then
        # echo "Error: Output of uniq $file is different"
        rm "temporary_reduced.txt"
        return 1
    fi
    rm "temporary_reduced.txt"
    # echo "Test passed"
    return 0
}

run(){
    # Creating a small test file with duplicate lines
    echo -e "Line1\nLine1\nline1\nLine2\nline2\nLine3\nline3\nline3\nLine4\nline4\nline1" > $SMALL_FILE

    # Test case 1: Using uniq with on the large file
    execute_uniq $LARGE_FILE "output_large.txt" || return 1
    if [ $? -eq 0 ]; then
        score=$((score + 1))
    fi

    # Test case 2: Using uniq with on the small test file
    execute_uniq $SMALL_FILE "output_small.txt" || return 1
    if [ $? -eq 0 ]; then
        score=$((score + 1))
    fi
}

clean_env(){
    rm -f $ORIGINAL_BINARY $REDUCED_BINARY $SMALL_FILE $LARGE_FILE $LOG output_large.txt output_small.txt
}

function main(){
    clean_env
    cp $ORIGINAL_FILE $LARGE_FILE
    compile_files
    run || exit 1
    clean_env
    exit 0
}

main


