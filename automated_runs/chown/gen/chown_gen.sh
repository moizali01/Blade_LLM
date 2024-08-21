#!/bin/bash
BINARY_DIR="bins"
LOG="log.txt"
C_FILE=chown-debloated.c.blade.c
# C_FILE=chown-8.2.c.origin.c

# Compile the binary once
mkdir -p $BINARY_DIR
rm -rf $BINARY_DIR/*
clang -w $C_FILE -o $BINARY_DIR/chown-test
chmod +x $BINARY_DIR/chown-test

# List of commands to test
declare -A COMMANDS=(
    ["chown-owner"]="-R user1"
    ["chown-group"]="-R :group1"
    ["chown-owner-group"]="-R user1:group1"
)

order=(
    "chown-owner"
    "chown-group"
    "chown-owner-group"
)

function create_test_structure() {
    local base_dir="$1"
    mkdir -p "$base_dir/dir1/dir2/dir3"
    touch "$base_dir/file1"
    touch "$base_dir/dir1/file2"
    touch "$base_dir/dir1/dir2/file3"
    touch "$base_dir/dir1/dir2/dir3/file4"
}

function test() {
    local cmd="$1"
    local args="$2"
    local test_dir="$3"

    echo "Testing command: chown $args \"$test_dir\"" >> $LOG

    # Create the test directory structure
    rm -rf "$test_dir"
    create_test_structure "$test_dir"

    # Run the binary and capture stdout, stderr, and the directory listing
    binary_output=$(mktemp)
    binary_error=$(mktemp)
    $BINARY_DIR/chown-test $args "$test_dir" > "$binary_output" 2> "$binary_error"
    temp1=$(ls -alR "$test_dir" | awk '{print $1, $2, $3, $4, $5, $7, $9}')

    echo "Custom chown output:" >> $LOG
    cat "$binary_output" >> $LOG
    echo "Custom chown error:" >> $LOG
    cat "$binary_error" >> $LOG
    echo "Directory listing after custom chown:" >> $LOG
    echo "$temp1" >> $LOG

    # Reset ownership for comparison
    
    chown -R $(whoami):$(id -gn) "$test_dir"
    rm -rf "$test_dir"
    create_test_structure "$test_dir"

    # Apply system chown and capture stdout, stderr, and the directory listing
    chown_output=$(mktemp)
    chown_error=$(mktemp)
    chown $args "$test_dir" > "$chown_output" 2> "$chown_error"
    temp2=$(ls -alR "$test_dir" | awk '{print $1, $2, $3, $4, $5, $7, $9}')

    echo "System chown output:" >> $LOG
    cat "$chown_output" >> $LOG
    echo "System chown error:" >> $LOG
    cat "$chown_error" >> $LOG
    echo "Directory listing after system chown:" >> $LOG
    echo "$temp2" >> $LOG

    # Compare the outputs
    if ! diff -q <(echo "$temp1") <(echo "$temp2") >& /dev/null; then
        echo "Directory listings do not match" >> $LOG
        rm -rf "$test_dir"
        return 1
    fi
    if ! diff -q "$binary_output" "$chown_output" >& /dev/null; then
        echo "Stdout does not match" >> $LOG
        rm -rf "$test_dir"
        return 1
    fi

    # Clean up temporary files and directory
    rm -f "$binary_output" "$binary_error" "$chown_output" "$chown_error"
    rm -rf "$test_dir"
    return 0
}

function c_test() {
    local cmd="$1"
    local args="$2"
    local SCORE=0
    local TOTAL=3

    test "$cmd" "$args" "testdir_shallow" && ((SCORE++))
    test "$cmd" "$args" "testdir_deep/level1/level2/level3" && ((SCORE++))
    test "$cmd" "$args" "testdir_mixed/level1/level2 with spaces/level3" && ((SCORE++))

    echo "$cmd tests $SCORE / $TOTAL"
    return 0
}

function run_tests() {
    for key in "${order[@]}"; do
        c_test "$key" "${COMMANDS[$key]}" 
    done
}

function main() {
    clear
    rm -f $LOG
    rm -rf testdir_*
    touch $LOG
    echo "#######################################################" >> $LOG
    echo "############### AUTOMATED TESTING #####################" >> $LOG
    echo "############## chown-8.2 testing ######################" >> $LOG
    echo "#######################################################" >> $LOG
    echo "" >> $LOG
    echo "starting..." >> $LOG
    echo "" >> $LOG
    run_tests
    echo "" >> $LOG
    echo "test run completed!" >> $LOG
}

main