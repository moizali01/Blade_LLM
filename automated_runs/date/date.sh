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

    # Test case 1: Formatting the current date in YYYY-MM-DD format
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY "+%Y-%m-%d" > $DIR/temp_output.txt; }
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "+%Y-%m-%d" > $DIR/expected_output.txt; }
    diff $DIR/temp_output.txt $DIR/expected_output.txt || return 1

    # Test case 2: Formatting the current time in HH:MM:SS format
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY "+%H:%M:%S" > $DIR/temp_output.txt; }
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "+%H:%M:%S" > $DIR/expected_output.txt; }
    diff $DIR/temp_output.txt $DIR/expected_output.txt || return 1

    # Test case 3: Displaying the Unix timestamp
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY "+%s" > $DIR/temp_output.txt; }
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "+%s" > $DIR/expected_output.txt; }
    diff $DIR/temp_output.txt $DIR/expected_output.txt || return 1

    # Test case 4: Date calculation for "yesterday"
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d "yesterday" "+%Y-%m-%d" > $DIR/temp_output.txt; }
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -d "yesterday" "+%Y-%m-%d" > $DIR/expected_output.txt; }
    diff $DIR/temp_output.txt $DIR/expected_output.txt || return 1

    # Test case 5: Date calculation for "next Monday"
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d "next Monday" "+%Y-%m-%d" > $DIR/temp_output.txt; }
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -d "next Monday" "+%Y-%m-%d" > $DIR/expected_output.txt; }
    diff $DIR/temp_output.txt $DIR/expected_output.txt || return 1

    # Test case 6: Date calculation for "last year"
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d "last year" "+%Y-%m-%d" > $DIR/temp_output.txt; }
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -d "last year" "+%Y-%m-%d" > $DIR/expected_output.txt; }
    diff $DIR/temp_output.txt $DIR/expected_output.txt || return 1

    return 0

}

function args_test() {
    cd $DIR/
    run || exit 1
}

function clean_env() {
    cd $DIR
    rm -rf $LOG $REDUCED_BINARY $DIR/temp_output.txt $DIR/expected_output.txt $ORIGINAL_BINARY
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
