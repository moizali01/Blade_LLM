#!/bin/bash

BINARY_DIR="bins"
LOG="log.txt"
C_FILE=mkdir-ground-truth.c
# C_FILE=../mkdir-5.2.1.c.origin.c
# C_FILE=testing.c
TIMEOUT_LIMIT="-k 5 5"


# Compile the binary once
mkdir -p $BINARY_DIR
rm -rf $BINARY_DIR/*
clang -w $C_FILE -o $BINARY_DIR/mkdir-test
chmod +x $BINARY_DIR/mkdir-test


MAX_SCORE_FUNCTIONALITY=0
TOTAL_SCORE_FUNCTIONALITY=0

MAX_SECURITY_CASES=0
TOTAL_SECURITY_SCORE=0

# List of commands to test
declare -A COMMANDS=(
    ["mkdir-ma=r"]="-m 444"
    ["mkdir-ma=rw"]="-m 644"
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
declare -A COMMANDS_2=(
    ["mkdir-ma=r"]="-m u=r,g=r,o=r"                        # Equivalent to -m 444
    #   ["mkdir-ma=rw"]="u=rw,g=r,o=r"                  # Equivalent to -m 644 (commented out)
    ["mkdir-ma=rwx"]="-m u=rwx,g=rx,o=rx"                  # Equivalent to -m 755
    ["mkdir-ma=none"]="-m u=,g=,o="                        # Equivalent to -m 000
    ["mkdir-ma=owner-rw"]="-m u=rw,g=,o="                  # Equivalent to -m 600
    ["mkdir-ma=owner-rwx"]="-m u=rwx,g=,o="                # Equivalent to -m 700
    ["mkdir-ma=owner-rwx-group-x"]="-m u=rwx,g=x,o=x"      # Equivalent to -m 711
    ["mkdir-ma=owner-rwx-group-rx"]="-m u=rwx,g=rx,o="     # Equivalent to -m 750
    ["mkdir-ma=owner-group-rwx"]="-m u=rwx,g=rwx,o="       # Equivalent to -m 770
    ["mkdir-ma=owner-group-rwx-other-rx"]="-m u=rwx,g=rwx,o=rx"  # Equivalent to -m 775
    ["mkdir-ma=everyone-rwx"]="-m u=rwx,g=rwx,o=rwx"       # Equivalent to -m 777
    ["mkdir-ma=owner-rw-group-other-r"]="-m u=rw,g=r,o=r"  # Equivalent to -m 644
    ["mkdir-ma=owner-rw-group-other-rx"]="-m u=rw,g=rx,o=rx"  # Equivalent to -m 655
)


order=(
    "mkdir-ma=r"
    # "mkdir-ma=rw"
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

order_2=(
    "mkdir-ma=r"
    # "mkdir-ma=rw"
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
        return 1
    fi
    # rm -rf $3 >& /dev/null
    
    # Clean up temporary files
    rm -f "$binary_output" "$binary_error" "$mkdir_output" "$mkdir_error"
    # echo "returning"
    return 0
}

function m_test()
{
    # Basic Test
    SCORE=2
    MAX_SCORE_FUNCTIONALITY=$(($MAX_SCORE_FUNCTIONALITY + 2))
    test "$1" "$2" "test" || SCORE=$(($SCORE-1))
    rm -rf test

    # Nested Test
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
    
    TOTAL_SCORE_FUNCTIONALITY=$(($TOTAL_SCORE_FUNCTIONALITY + $SCORE))

    echo "$2 tests       $SCORE / 2"
    return 0
}

function run_tests()
{
    # 26 TEST CASES: Numeric mode
    for key in "${order[@]}"; do
        m_test "$key" "${COMMANDS[$key]}"
    done

    # 26 TEST CASES: Symbolic mode
    for key in "${order_2[@]}"; do
        m_test "$key" "${COMMANDS_2[$key]}"
    done

    # Test 53: Multiple directories mkdir
    ((MAX_SCORE_FUNCTIONALITY++))
    test "mkdir-ma=r" "-m 444" "test1" "test2" && ((TOTAL_SCORE_FUNCTIONALITY++)) || echo "Test failed: Multiple directories mkdir"
    rm -rf test1 test2 2> /dev/null

    return 0


}


function test_robustness(){
    ((MAX_SECURITY_CASES++))
    local binary_output="$1"
    a=$?
    if [[ $a -ne 124 && $a -ne 137 ]]; then
        ((TOTAL_SECURITY_SCORE++))
        return 0
    fi

    return 1

}

test_compare_overwrite(){
    mkdir testdir
    mkdir testdir/testdir2
    touch testdir/testdir2/testfile
    touch testdir/testfile
    echo "test" > testdir/testfile

    # store ls of testdir
    ls_testdir=$(ls -al testdir | awk '{print $1, $2, $3, $4, $9}')
    # echo $(ls -al testdir | awk '{print $1, $2, $3, $4, $9}')
    # Test 1: Overwrite file with directory
    { $BINARY_DIR/mkdir-test -m 555 testdir; } 2>/dev/null
    # echo $(ls -al testdir | awk '{print $1, $2, $3, $4, $9}')
    ls_updated=$(ls -al testdir | awk '{print $1, $2, $3, $4, $9}')

    if [[ "$ls_testdir" != "$ls_updated" ]]; then
        echo ls_testdir: $ls_testdir
        echo ls_updated: $ls_updated
        echo "Test failed: Overwrite file with directory"
        rm -rf testdir
        return 1
    fi

    rm -rf testdir

    return 0

}



function security_tests()
{
    MAX_SECURITY_CASES=$((MAX_SECURITY_CASES + 7))

    rm -rf testdir 2> /dev/null

    # Test 1: Test without permissions
    if test "temp" "-m 000" "testdir"; then
        ((TOTAL_SECURITY_SCORE++))
    else
        echo "Test failed: Test without permissions"
    fi
    rm -rf testdir 2> /dev/null

    # Test 2: Test with very long name
    if test "temp" "-m 777" "$(printf 'a%.0s' {1..100})"; then
        ((TOTAL_SECURITY_SCORE++))
    else
        echo "Test failed: Test with very long name"
    fi
    rm -rf $(printf 'a%.0s' {1..100})

    # Test 3: Directory with special characters
    if test "temp" "-m 555" "test#%^&*(dir"; then
        ((TOTAL_SECURITY_SCORE++))
    else
        echo "Test failed: Directory with special characters"
    fi
    rm -rf "test#%^&*(dir"

    # Test 4: recreate directory with same name but different permissions
    if test "temp" "-m 755" "testdir"; then
        ((TOTAL_SECURITY_SCORE++))
    else
        echo "Test failed: recreate directory with same name but different permissions"
    fi
    rm -rf testdir 2> /dev/null

    # Test 5: recreate directory with same name but different permissions
    if test_compare_overwrite; then
        ((TOTAL_SECURITY_SCORE++))
    else
        echo "Test failed: recreate directory with same name but different permissions"
    fi

    # Test 6: Test with sticky bit and immutable flag
    if test "temp" "-m 1777" "testdir"; then
        ((TOTAL_SECURITY_SCORE++))
    else
        echo "Test failed: Test with sticky bit and immutable flag"
    fi

    # # Test 7: Test with empty file
    # if test "temp" "-m 700" ""; then
    #     ((TOTAL_SECURITY_SCORE++))
    # else
    #     echo "Test failed: Empty directory name"
    # fi

    return 0
}
function robustness_tests()
{
    # Test 1: non existent flag
    output_debloat=$(timeout ${TIMEOUT_LIMIT} $BINARY_DIR/mkdir-text -X testdir 2>/dev/null)
    test_robustness "$output_debloat"
    rm -r testdir 2> /dev/null

    # Test 2: non existent mode
    output_debloat=$(timeout ${TIMEOUT_LIMIT} $BINARY_DIR/mkdir-text -m 999 testdir 2>/dev/null)
    test_robustness "$output_debloat"
    rm -r testdir 2> /dev/null

    # Test 3: partial non existent mode
    output_debloat=$(timeout ${TIMEOUT_LIMIT} $BINARY_DIR/mkdir-text -m 699 testdir 2>/dev/null)
    test_robustness "$output_debloat"
    rm -r testdir 2> /dev/null

    # Test 4: invalid mode
    output_debloat=$(timeout ${TIMEOUT_LIMIT} $BINARY_DIR/mkdir-text -m 9999 testdir 2>/dev/null)
    test_robustness "$output_debloat"
    rm -r testdir 2> /dev/null

    # Test 5: create directory in non-existent directory
    output_debloat=$(timeout ${TIMEOUT_LIMIT} $BINARY_DIR/mkdir-text testdir/testdir2 2>/dev/null)
    test_robustness "$output_debloat"
    rm -r testdir 2> /dev/null

    # Test 6: test on removed flag
    output_debloat=$(timeout ${TIMEOUT_LIMIT} $BINARY_DIR/mkdir-text -p testdir/testdir2 2>/dev/null)
    test_robustness "$output_debloat"
    rm -r testdir 2> /dev/null

    # Test 7: test on removed flag
    output_debloat=$(timeout ${TIMEOUT_LIMIT} $BINARY_DIR/mkdir-text -vp testdir/testdir2 2>/dev/null)
    test_robustness "$output_debloat"
    rm -r testdir 2> /dev/null

    return 0

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
    security_tests
    robustness_tests
    
    echo "Total Score: $TOTAL_SCORE_FUNCTIONALITY / $MAX_SCORE_FUNCTIONALITY"
    echo "Total Security Score: $TOTAL_SECURITY_SCORE / $MAX_SECURITY_CASES"

    echo "test run completed!"
}

main

