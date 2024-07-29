#!/bin/bash

# Paths to the files
PROGRAM_NAME="uniq-8.16"
LARGE_FILE="data.c"
SMALL_FILE="lines"
DIR=/$(pwd)
ORIGINAL_FILE="uniq-8.16.c.origin.c"
DEBLOATED_FILE="uniq-8.16-GPT.c"
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log.txt


compile_files(){
    # echo "Compiling the original file"
    $CC -w $ORIGINAL_FILE -o $ORIGINAL_BINARY 
    if [ $? -ne 0 ]; then
        echo "Error: Compilation of $ORIGINAL_FILE failed"
        exit 1
    fi

    # echo "Compiling the debloated file"
    $CC -w $DEBLOATED_FILE -o $REDUCED_BINARY 
    if [ $? -ne 0 ]; then
        echo "Error: Compilation of $DEBLOATED_FILE failed"
        exit 1
    fi
}
# Function to execute uniq and check the result
execute_uniq() {
    local file=$1
    local options=$2
    local output_file=$3

    # echo "Executing: uniq $options $file"
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $options $file; } > $output_file 2> $LOG
    if [ $? -ne 0 ]; then
        echo "Error: uniq $options $file failed"
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $options $file; } > "temporary_reduced.txt" 2> $LOG
    if [ $? -ne 0 ]; then
        echo "Error: uniq $options $file failed"
        return 1
    fi
    diff $output_file "temporary_reduced.txt"
    if [ $? -ne 0 ]; then
        echo "Error: Output of uniq $options $file is different"
        rm "temporary_reduced.txt"
        return 1
    fi
    rm "temporary_reduced.txt"
    return 0
}

run(){
    # Creating a small test file with duplicate lines
    # echo -e "Creating small test file with duplicate lines"
    echo -e "Line1\nLine1\nline1\nLine2\nline2\nLine3\nline3\nline3\nLine4\nline4\nline1" > $SMALL_FILE

    # Test case 1: Using uniq with -c flag on the large file
    # echo "Test Case 1: uniq -c on $LARGE_FILE"
    execute_uniq $LARGE_FILE "-c" "output_large_c.txt"
    execute_uniq $LARGE_FILE "-c" "output_large_c.txt"
    # execute_uniq $LARGE_FILE "-i" "output_large_c.txt"

    # Test case 3: Using uniq with -c flag on the small test file
    # echo "Test Case 2: uniq -c on $SMALL_FILE"
    execute_uniq $SMALL_FILE "-c" "output_small_c.txt"
    execute_uniq $SMALL_FILE "-c" "output_small_c.txt"
    # execute_uniq $SMALL_FILE "-i" "output_small_c.txt"

}
clean_env(){
    rm -f $REDUCED_BINARY $SMALL_FILE $ORIGINAL_BINARY $LOG output_large_c.txt output_large_i.txt output_small_c.txt output_small_i.txt
}

function main(){
    clean_env
    compile_files
    run || exit 1
    clean_env
    exit 0
}

main