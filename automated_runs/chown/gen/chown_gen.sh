#!/bin/bash

BINARY_DIR="bins"
LOG="log.txt"
C_FILE=chown-blade.c

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
    ["chown-owner-group-different"]="-R user2:group2"
)

order=(
    "chown-owner"
    "chown-group"
    "chown-owner-group"
    "chown-owner-group-different"
)

function test()
{
    # Run the binary and capture stdout, stderr, and the directory listing
    binary_output=$(mktemp)
    binary_error=$(mktemp)
    $BINARY_DIR/chown-test $2 $3 > "$binary_output" 2> "$binary_error"
    temp1=$(ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}')
    
    # Reset ownership for comparison
    sudo chown -R $(whoami):$(id -gn) $3
    
    # Apply chown and capture stdout, stderr, and the directory listing
    chown_output=$(mktemp)
    chown_error=$(mktemp)
    sudo chown $2 $3 > "$chown_output" 2> "$chown_error"
    temp2=$(ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}')
    
    # Compare the outputs
    if ! diff -q <(echo "$temp1") <(echo "$temp2") >& /dev/null; then
        return 1
    fi
    
    if ! diff -q "$binary_output" "$chown_output" >& /dev/null; then
        return 1
    fi
    
    if ! diff -q "$binary_error" "$chown_error" >& /dev/null; then
        return 1
    fi
    
    # Clean up temporary files
    rm -f "$binary_output" "$binary_error" "$chown_output" "$chown_error"
    return 0
}

function c_test()
{
    SCORE=4
    test "$1" "$2" "testdir" || SCORE=$(($SCORE-1))
    rm -rf testdir
    mkdir -p testdir/testdir1/testdir2
    
    passed=2
    test "$1" "$2" "testdir" || passed=$(($passed-1))
    test "$1" "$2" "testdir/testdir1" || passed=$(($passed-1))
    rm -rf testdir
    if [ $passed != 2 ]; then
        SCORE=$(($SCORE - 1))
    fi
    
    passed=3
    test "$1" "$2" "testdir" || passed=$(($passed-1))
    test "$1" "$2" "testdir/testdir1" || passed=$(($passed-1))
    test "$1" "$2" "testdir/testdir1/testdir2" || passed=$(($passed-1))
    rm -rf testdir
    if [ $passed != 3 ]; then
        SCORE=$(($SCORE - 1))
    fi
    
    passed=4
    test "$1" "$2" "testdir" || passed=$(($passed-1))
    test "$1" "$2" "testdir/testdir1" || passed=$(($passed-1))
    test "$1" "$2" "testdir/testdir1/testdir2" || passed=$(($passed-1))
    test "$1" "$2" "testdir/testdir1/testdir2/testdir3" || passed=$(($passed-1))
    rm -rf testdir
    if [ $passed != 4 ]; then
        SCORE=$(($SCORE - 1))
    fi
    
    echo "$2 tests       $SCORE / 4"
    return 0
}

function run_tests()
{
    for key in "${order[@]}"; do
        c_test "$key" "${COMMANDS[$key]}"
    done
}

function main()
{
    clear
    echo "#######################################################"
    echo "############### AUTOMATED TESTING #####################"
    echo "############## chown-8.2 testing ######################"
    echo "#######################################################"
    echo ""
    echo "starting..."
    echo ""
    
    run_tests
    
    echo ""
    echo "test run completed!"
}

main
