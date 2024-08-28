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

    # Test case 1: Formatting the current date in YYYY-MM-DD format
    LLVM_PROFILE_FILE="$DIR/profile_format_date.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "+%Y-%m-%d" > /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi

    # Test case 2: Formatting the current time in HH:MM:SS format
    LLVM_PROFILE_FILE="$DIR/profile_format_time.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "+%H:%M:%S" > /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi

    # Test case 3: Displaying the Unix timestamp
    LLVM_PROFILE_FILE="$DIR/profile_unix_timestamp.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "+%s" > /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi

    # Test case 4: Date calculation for "yesterday"
    LLVM_PROFILE_FILE="$DIR/profile_yesterday.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -d "yesterday" "+%Y-%m-%d" > /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi

    # Test case 5: Date calculation for "next Monday"
    LLVM_PROFILE_FILE="$DIR/profile_next_monday.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -d "next Monday" "+%Y-%m-%d" > /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi

    # Test case 6: Date calculation for "last year"
    LLVM_PROFILE_FILE="$DIR/profile_last_year.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -d "last year" "+%Y-%m-%d" > /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi

    # Test case 7: Date calculation for "Adding 5 days"
    LLVM_PROFILE_FILE="$DIR/profile_add_5_days.profraw" timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -d "2024-08-27 +5 days" "+%Y-%m-%d" > /dev/null
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi

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