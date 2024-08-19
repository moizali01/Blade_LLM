#!/bin/bash

PROGRAM_NAME=date-8.21
DIR=$(pwd)
original_file=$DIR/date-org.c
ORIGINAL_BINARY=$DIR/date-original
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log.txt

function run() {
    astyle -j -A4 $original_file >&$LOG

    # Test case 1: Using -f flag to read dates from a file and display them
    echo "2024-07-01" > $DIR/date_input.txt
    LLVM_PROFILE_FILE="$DIR/profile1.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -f $DIR/date_input.txt > /dev/null

    # Test case 2: Using the -f flag to read dates from a file and display them
    echo "2024-06-01" > $DIR/date_input.txt
    echo "2024-07-02" >> $DIR/date_input.txt
    LLVM_PROFILE_FILE="$DIR/profile2.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -f $DIR/date_input.txt > /dev/null

    # Test case 3: Using the -f flag to read dates from a file and display them
    echo "2021-02-07" > $DIR/date_input.txt
    echo "2021-02-08" >> $DIR/date_input.txt
    echo "2021-02-09" >> $DIR/date_input.txt
    LLVM_PROFILE_FILE="$DIR/profile3.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -f $DIR/date_input.txt > /dev/null

    return 0
}

function clean_env() {
    cd $DIR
    rm -rf $LOG $DIR/date_input.txt $ORIGINAL_BINARY $DIR/*.profraw $DIR/merged.profdata
    return 0
}

function compile() {
    cd $DIR
    CFLAGS="-w -fprofile-instr-generate -fcoverage-mapping"
    $CC $original_file $CFLAGS -o $ORIGINAL_BINARY >&$LOG || exit 1
    return 0
}

function generate_coverage() {
    cd $DIR
    llvm-profdata merge -sparse $DIR/profile*.profraw -o $DIR/merged.profdata
    llvm-cov show $ORIGINAL_BINARY -instr-profile=$DIR/merged.profdata > $DIR/coverage.txt
}

function main() {
    cd $DIR
    clean_env
    compile || exit 1
    run || exit 1
    generate_coverage
    clean_env
}

main