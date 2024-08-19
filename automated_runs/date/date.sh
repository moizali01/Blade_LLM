#!/bin/bash

PROGRAM_NAME=date-8.21
DIR=$(pwd)
original_file=$DIR/date-org.c
C_FILE=$DIR/date-util.c
ORIGINAL_BINARY=$DIR/date-original
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log.txt

function run() {

    # Test case 1: Using -f flag to read dates from a file and display them
    echo "2024-07-01" > $DIR/date_input.txt
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f $DIR/date_input.txt > $DIR/temp_output.txt; }
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -f $DIR/date_input.txt > $DIR/expected_output.txt; }
    diff $DIR/temp_output.txt $DIR/expected_output.txt || return 1

    # # Test case 2: Using the -f flag to read dates from a file and display them
    echo "2024-06-01" > $DIR/date_input.txt
    echo "2024-07-02" >> $DIR/date_input.txt
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f $DIR/date_input.txt > $DIR/temp_output.txt; }
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -f $DIR/date_input.txt > $DIR/expected_output.txt; }
    diff $DIR/temp_output.txt $DIR/expected_output.txt || return 1

    # Test case 3: Using the -f flag to read dates from a file and display them
    echo "2021-02-07" > $DIR/date_input.txt
    echo "2021-02-08" >> $DIR/date_input.txt
    echo "2021-02-09" >> $DIR/date_input.txt
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f $DIR/date_input.txt > $DIR/temp_output.txt; }
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -f $DIR/date_input.txt > $DIR/expected_output.txt; }
    diff $DIR/temp_output.txt $DIR/expected_output.txt || return 1

    return 0
}

function args_test() {
    cd $DIR/
    run || exit 1
}

function clean_env() {
    cd $DIR
    rm -rf $LOG $REDUCED_BINARY $DIR/temp_output.txt $DIR/expected_output.txt $DIR/date_input.txt $ORIGINAL_BINARY
    return 0
}

function compile() {
    cd $DIR
    CFLAGS="-w $BIN_CFLAGS"
    $CC $original_file $CFLAGS -o $ORIGINAL_BINARY >&$LOG || exit 1
    $CC $C_FILE $CFLAGS -o $REDUCED_BINARY >&$LOG || exit 1
    return 0
}

function main() {
    cd $DIR
    clean_env
    compile || exit 1
    args_test || exit 1
    clean_env
}

main
