#!/bin/bash

PROGRAM_NAME="grep"
DIR=$(pwd)
ORIGINAL_FILE=$DIR/grep-org.c
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME-original
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log.txt

function run() {
    astyle -j -A4 $ORIGINAL_FILE >&$LOG

    # Creating a small test file with log entries
    echo -e "INFO: This is a log message\nERROR: This is an error message\nWARNING: This is a warning message" > $DIR/small_log.txt
    
    # Creating a directory with multiple test files
    mkdir -p $DIR/test_dir
    echo -e "ERROR: First error message" > $DIR/test_dir/file1.txt
    echo -e "INFO: Just an info message\nERROR: Second error message" > $DIR/test_dir/file2.txt
    echo -e "WARNING: Just a warning" > $DIR/test_dir/file3.txt

    # Test case 1: Simple pattern matching
    LLVM_PROFILE_FILE="$DIR/profile_simple_match.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "ERROR" $DIR/small_log.txt > /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi

    # Test case 2: Recursive search
    LLVM_PROFILE_FILE="$DIR/profile_recursive.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -r "ERROR" $DIR/test_dir > /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi


    return 0
}

function clean_env() {
    cd $DIR
    rm -rf $LOG $DIR/small_log.txt $DIR/test_dir $ORIGINAL_BINARY $DIR/*.profraw $DIR/merged.profdata
    return 0
}

function compile() {
    cd $DIR
    CFLAGS="-w -fprofile-instr-generate -fcoverage-mapping -D __msan_unpoison(s,z) -lpcre"
    $CC $ORIGINAL_FILE $CFLAGS -o $ORIGINAL_BINARY >&$LOG || exit 1
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