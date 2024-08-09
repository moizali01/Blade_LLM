#!/bin/bash

# Paths to the files
PROGRAM_NAME="uniq-og"
LARGE_FILE="data.c"
SMALL_FILE="lines"
DIR=$(pwd)
ORIGINAL_FILE="uniq-og.c"
ORIGINAL_BINARY="$DIR/$PROGRAM_NAME.obin"
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG="$DIR/log.txt"

# Initialize score
total_tests=2

compile_files(){
    echo "Compiling the original file for coverage"
    "$CC" -fprofile-instr-generate -fcoverage-mapping -w "$ORIGINAL_FILE" -o "$ORIGINAL_BINARY" 
    if [ $? -ne 0 ]; then
        echo "Error: Compilation of $ORIGINAL_FILE failed" >&2
        exit 1
    fi
}

# Function to execute uniq and generate profraw
execute_uniq() {
    local file="$1"
    local output_file="$2"
    local profraw_file="$3"

    export LLVM_PROFILE_FILE="$profraw_file"
    # echo "Executing: uniq $file"
    "$ORIGINAL_BINARY" "$file" > /dev/null
    return $?
}

# Function to generate coverage report
generate_report() {
    local prof1="$1"
    local prof2="$2"

    # Merge profraws
    llvm-profdata merge -output=merged.profdata "$prof1" "$prof2"
    
    # Generate coverage report
    llvm-cov show "$ORIGINAL_BINARY" -instr-profile=merged.profdata > coverage.txt
    return $?
}

run(){
    # Creating a small test file with duplicate lines
    echo -e "Line1\nLine1\nline1\nLine2\nline2\nLine3\nline3\nline3\nLine4\nline4\nline1" > "$SMALL_FILE"

    # Test case 1: Using uniq with on the large file
    execute_uniq "$LARGE_FILE" "output_large.txt" "large.profraw" || return 1

    # Test case 2: Using uniq with on the small test file
    execute_uniq "$SMALL_FILE" "output_small.txt" "small.profraw" || return 1

    # Generate coverage report
    generate_report "large.profraw" "small.profraw" || return 1
}

clean_env(){
    rm -f "$ORIGINAL_BINARY" "$SMALL_FILE" "$LARGE_FILE" "$LOG" output_large.txt output_small.txt *.profraw *.profdata
    echo "Cleaned the environment"
}

function main(){
    clean_env
    cp "$ORIGINAL_FILE" "$LARGE_FILE"
    clang-format -i "ORIGINAL_FILE"
    compile_files
    run || exit 1
    echo "Coverage report generated"
    clean_env
    exit 0
}

main