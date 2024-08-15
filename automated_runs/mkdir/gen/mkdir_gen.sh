#!/bin/bash

BINARY_DIR="bins"
LOG="log.txt"
C_FILE=mkdir-debloated.c.blade.c

# Compile the binary once
mkdir -p $BINARY_DIR
rm -rf $BINARY_DIR/*
clang -w $C_FILE -o $BINARY_DIR/mkdir-test
chmod +x $BINARY_DIR/mkdir-test

# List of commands to test
declare -A COMMANDS=(
    ["mkdir-ma=r"]="-m 444"
    #   ["mkdir-ma=rw"]="-m 644"
    ["mkdir-ma=rwx"]="-m 755"
    ["mkdir-ma=none"]="-m 000"
    ["mkdir-ma=owner-rw"]="-m 600"
    ["mkdir-ma=owner-rwx"]="-m 700"
    ["mkdir-ma=owner-rwx-group-x"]="-m 711"
    ["mkdir-ma=owner-rwx-group-rx"]="-m 750"
    ["mkdir-ma=owner-group-rwx"]="-m 770"
    ["mkdir-ma=owner-group-rwx-other-rx"]="-m 775"
    ["mkdir-ma=everyone-rwx"]="-m 777"
    ["mkdir-ma=owner-rw-group-other-r"]="-m 644"
    ["mkdir-ma=owner-rw-group-other-rx"]="-m 655"
)

order=(
    "mkdir-ma=r"
    #   "mkdir-ma=rw"
    "mkdir-ma=rwx"
    "mkdir-ma=none"
    "mkdir-ma=owner-rw"
    "mkdir-ma=owner-rwx"
    "mkdir-ma=owner-rwx-group-x"
    "mkdir-ma=owner-rwx-group-rx"
    "mkdir-ma=owner-group-rwx"
    "mkdir-ma=owner-group-rwx-other-rx"
    "mkdir-ma=everyone-rwx"
    "mkdir-ma=owner-rw-group-other-r"
    "mkdir-ma=owner-rw-group-other-rx"
)

function test()
{
    # Run the binary and capture stdout, stderr, and the directory listing
    binary_output=$(mktemp)
    binary_error=$(mktemp)
    $BINARY_DIR/mkdir-test $2 $3 > "$binary_output" 2> "$binary_error"
    temp1=$(ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}')
    
    # Clean up the created directory
    rm -rf $3 >& /dev/null
    
    # Create the directories with mkdir and capture stdout, stderr, and the directory listing
    mkdir_output=$(mktemp)
    mkdir_error=$(mktemp)
    mkdir $2 $3 > "$mkdir_output" 2> "$mkdir_error"
    temp2=$(ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}')
    
    # Compare the outputs
    if ! diff -q <(echo "$temp1") <(echo "$temp2") >& /dev/null; then
        return 1
    fi
    
    if ! diff -q "$binary_output" "$mkdir_output" >& /dev/null; then
        return 1
    fi
    
    if ! diff -q "$binary_error" "$mkdir_error" >& /dev/null; then
        # cat "$binary_error"
        return 1
    fi
    # rm -rf $3 >& /dev/null
    
    # Clean up temporary files
    rm -f "$binary_output" "$binary_error" "$mkdir_output" "$mkdir_error"
    return 0
}

function m_test()
{
    SCORE=4
    test "$1" "$2" "test" || SCORE=$(($SCORE-1))
    # echo $(ls)
    rm -rf test
    #   echo $(ls)
    
    passed=2
    test "$1" "$2" "test" || passed=$(($passed-1))
    test "$1" "$2" "test/test" || passed=$(($passed-1))
    rm -rf test
    if [ $passed != 2 ]; then
        SCORE=$(($SCORE - 1))
    fi
    
    passed=3
    test "$1" "$2" "test" || passed=$(($passed-1))
    test "$1" "$2" "test/test" || passed=$(($passed-1))
    test "$1" "$2" "test/test/test" || passed=$(($passed-1))
    rm -rf test
    if [ $passed != 3 ]; then
        SCORE=$(($SCORE - 1))
    fi
    
    passed=4
    test "$1" "$2" "test" || passed=$(($passed-1))
    test "$1" "$2" "test/test" || passed=$(($passed-1))
    test "$1" "$2" "test/test/test" || passed=$(($passed-1))
    test "$1" "$2" "test/test/test/test" || passed=$(($passed-1))
    rm -rf test
    if [ $passed != 4 ]; then
        SCORE=$(($SCORE - 1))
    fi
    
    #   test "$1" "$2" "test" || SCORE=$(($SCORE-1))
    #   rm -rf test
    
    echo "$2 tests       $SCORE / 4"
    return 0
}

function run_tests()
{
    for key in "${order[@]}"; do
        m_test "$key" "${COMMANDS[$key]}"
    done
}

function main()
{
    clear
    echo "#######################################################"
    echo "############### AUTOMATED TESTING #####################"
    echo "############## mkdir-8.2 testing ######################"
    echo "#######################################################"
    echo ""
    echo "starting..."
    echo ""
    
    run_tests
    
    echo ""
    echo "test run completed!"
}

main

