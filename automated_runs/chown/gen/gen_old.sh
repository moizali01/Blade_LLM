#!/bin/bash
BINARY_DIR="bins"
LOG="log.txt"
# C_FILE=chown-8.2.c.origin.c
C_FILE=chown-debloated.c.blade.c
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
function test() {
    echo "Testing command: chown $2 $3" >>$LOG
    # Create the test directory structure
    mkdir -p $3/testdir_shallow/testdir2/testdir3
    touch $3/testdir_shallow/file1
    # touch $3/testdir_shallow/testdir2/file2
    # Run the binary and capture stdout, stderr, and the directory listing
    binary_output=$(mktemp)
    binary_error=$(mktemp)
    $BINARY_DIR/chown-test $2 $3 >"$binary_output" 2>"$binary_error"
    temp1=$(ls -alR $3 | awk '{print $1, $2, $3, $4, $5, $7, $9}')
    echo "Custom chown output:" >>$LOG
    cat "$binary_output" >>$LOG
    echo "Custom chown error:" >>$LOG
    cat "$binary_error" >>$LOG
    echo "Directory listing after custom chown:" >>$LOG
    echo "$temp1" >>$LOG
    # Reset ownership for comparison
    chown -R $(whoami):$(id -gn) $3
    rm -rf $3
    mkdir -p $3/testdir_shallow/testdir2/testdir3
    touch $3/testdir_shallow/file1
    # Apply chown and capture stdout, stderr, and the directory listing
    chown_output=$(mktemp)
    chown_error=$(mktemp)
    chown $2 $3 >"$chown_output" 2>"$chown_error"
    temp2=$(ls -alR $3 | awk '{print $1, $2, $3, $4, $5, $7, $9}')
    echo "System chown output:" >>$LOG
    cat "$chown_output" >>$LOG
    echo "System chown error:" >>$LOG
    cat "$chown_error" >>$LOG
    echo "Directory listing after system chown:" >>$LOG
    echo "$temp2" >>$LOG
    # Compare the outputs
    if ! diff -q <(echo "$temp1") <(echo "$temp2") >&/dev/null; then
        echo "Directory listings do not match" >>$LOG
        rm -rf $3
        return 1
    fi
    if ! diff -q "$binary_output" "$chown_output" >&/dev/null; then
        echo "Stdout does not match" >>$LOG
        rm -rf $3
        return 1
    fi
    # Clean up temporary files and directory
    rm -f "$binary_output" "$binary_error" "$chown_output" "$chown_error"
    rm -rf $3
    return 0
}
function c_test() {
    SCORE=1
    test "$1" "$2" "testdir" || SCORE=$(($SCORE - 1))
    echo "$2 tests $SCORE / 1"
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
    touch $LOG
    echo "#######################################################" >>$LOG
    echo "############### AUTOMATED TESTING #####################" >>$LOG
    echo "############## chown-8.2 testing ######################" >>$LOG
    echo "#######################################################" >>$LOG
    echo "" >>$LOG
    echo "starting..." >>$LOG
    echo "" >>$LOG
    run_tests
    echo "" >>$LOG
    echo "test run completed!" >>$LOG
}
main
