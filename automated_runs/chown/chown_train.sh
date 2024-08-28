#!/bin/bash

PROGRAM_NAME=chown-flagless
DIR=$(pwd)
C_FILE=$DIR/chown-debloated.c
C_OG_FILE=$DIR/chown-8.2.c.origin.c
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang
TIMEOUT_LIMIT="-k 1.2 1.2"
LOG=$DIR/log.txt

function run() {
    # Cleanup and setup
    rm -rf testdir
    mkdir -p testdir
    touch testdir/file1
    touch testdir/file2

    # Run the reduced binary and capture output, error, and directory listing
    reduced_output=$(mktemp)
    reduced_error=$(mktemp)
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $1 testdir >"$reduced_output" 2>"$reduced_error"; } >&$LOG || exit 1
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    temp1=$(ls -al testdir 2>/dev/null | cut -d ' ' -f 1,3,4)

    # Cleanup and setup again
    rm -rf testdir
    mkdir -p testdir
    touch testdir/file1
    touch testdir/file2

    # Run the original binary and capture output, error, and directory listing
    original_output=$(mktemp)
    original_error=$(mktemp)
    $ORIGINAL_BINARY $1 testdir >"$original_output" 2>"$original_error"
    temp2=$(ls -al testdir 2>/dev/null | cut -d ' ' -f 1,3,4)

    # Cleanup directory
    rm -rf testdir >&/dev/null

    # Compare directory listings
    if [[ $temp1 != $temp2 ]]; then
        echo "Directory listings do not match"
        return 1
    fi

    # Compare stdout
    if ! diff -q "$reduced_output" "$original_output" >& /dev/null; then
        echo "Stdout does not match"
        return 1
    fi

    # Compare stderr
    if ! diff -q "$reduced_error" "$original_error" >& /dev/null; then
        echo "Stderr does not match"
        return 1
    fi

    # Clean up temporary files
    rm -f "$reduced_output" "$reduced_error" "$original_output" "$original_error"
    return 0
}

function args_test() {
    run "user1" || exit 1
    run "user1:group1" || exit 1    
    # run ":group1" || exit 1
    return 0
}

function clean_env() {
    cd $DIR
    rm -rf testdir temp1 temp2 $REDUCED_BINARY $ORIGINAL_BINARY $LOG
    return 0
}

function compile() {
    cd $DIR
    $CC $C_FILE -w -o $REDUCED_BINARY >&$LOG || exit 1
    $CC $C_OG_FILE -w -o $ORIGINAL_BINARY >&$LOG || exit 1
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