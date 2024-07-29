#!/bin/bash

PROGRAM_NAME=sort-8.16
DIR=$(pwd)
C_FILE=$DIR/sort-8.16.c.origin.c
O_FILE=$DIR/sort-original.c
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log

function run() {
    
    #Test Case 1: Sort the whole util with -f option
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f $DIR/sort-8.16.c.origin.c > $DIR/temp_output.txt; } >&$LOG
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -f $DIR/sort-8.16.c.origin.c > $DIR/temp_output_original.txt; } >&$LOG
    diff $DIR/temp_output.txt $DIR/temp_output_original.txt || return 1
    rm $DIR/temp_output.txt $DIR/temp_output_original.txt
    
    #Test Case 2: Sort three files with -f and -n options
    echo -e "13001\n10003\n25005\n17007\n31009\n15011\n27013\n19015\n35017\n33019\n29021\n21023\n23025\n11027\n15029\n7001\n9003\n2905\n3707\n3909" > $DIR/positive_numbers.txt
    echo -e "-13001\n-10003\n-25005\n-17007\n-31009\n-15011\n-27013\n-19015\n-35017\n-33019\n-29021\n-21023\n-23025\n-11027\n-15029\n-7001\n-9003\n-2905\n-3707\n-3909" > $DIR/negative_numbers.txt
    echo -e "cherry\nfig\norange\ntangerine\npapaya\nquince\napple\nlemon\nvanilla\nmango\nraspberry\nbanana\nhoneydew\nelderberry\nugli\ngrape\nnectarine\nkiwi\nstrawberry\ndate" > $DIR/words.txt

    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f -n $DIR/positive_numbers.txt $DIR/negative_numbers.txt $DIR/words.txt > $DIR/temp_output.txt; } >&$LOG
    r=$?
    if [[ $r -ne 0 ]]; then
        return 1
    fi
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -f -n $DIR/positive_numbers.txt $DIR/negative_numbers.txt $DIR/words.txt > $DIR/temp_output_original.txt; } >&$LOG
    diff $DIR/temp_output.txt $DIR/temp_output_original.txt || return 1   
    
    
    # # Test case 1: Case-insensitive sort with mixed cases
    
    # # echo -e "apple\nBanana\nbanana\nCherry\ncherry\nAPPLE\nBANANA\nCHERRY" > $DIR/case_insensitive.txt
    # { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f $DIR/case_insensitive.txt > $DIR/temp_output.txt; } >&$LOG
    # r=$?
    # if [[ $r -ne 0 ]]; then
    #     return 1
    # fi
    # echo -e "apple\nAPPLE\nbanana\nBanana\nBANANA\ncherry\nCherry\nCHERRY" > $DIR/case_insensitive_expected.txt
    # diff $DIR/temp_output.txt $DIR/case_insensitive_expected.txt || return 1
    # # Test case 2: Case-insensitive sort with duplicates and mixed cases
    # echo -e "dog\nDog\nDOG\nelephant\nElephant\nELEPHANT\ncat\nCat\nCAT\nFrog\nfrog\nFROG\nGiraffe\ngiraffe\nGIRAFFE" > $DIR/case_insensitive_2.txt
    # { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f $DIR/case_insensitive_2.txt > $DIR/temp_output_2.txt; } >&$LOG
    # r=$?
    # if [[ $r -ne 0 ]]; then
    #     return 1
    # fi
    # echo -e "cat\nCat\nCAT\ndog\nDog\nDOG\nelephant\nElephant\nELEPHANT\nfrog\nFrog\nFROG\ngiraffe\nGiraffe\nGIRAFFE" > $DIR/case_insensitive_2_expected.txt
    # diff $DIR/temp_output_2.txt $DIR/case_insensitive_2_expected.txt || return 1
    # # Test case 3: Numeric sort with unsorted numbers
    # echo -e "10\n2\n32\n4\n50\n6\n72\n15\n25\n35\n1\n3" > $DIR/numbers_1.txt
    # { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -n $DIR/numbers_1.txt > $DIR/num_sorted_1.txt; } >&$LOG
    # r=$?
    # if [[ $r -ne 0 ]]; then
    #     return 1
    # fi
    # echo -e "1\n2\n3\n4\n6\n10\n15\n25\n32\n35\n50\n72" > $DIR/num_1_expected.txt
    # diff $DIR/num_sorted_1.txt $DIR/num_1_expected.txt || return 1
    
    # # Test case 4: Numeric sort with negative and positive numbers
    # echo -e "10\n-2\n32\n-4\n50\n6\n-12\n8\n14\n-6\n0" > $DIR/numbers_2.txt
    # { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -n $DIR/numbers_2.txt > $DIR/num_sorted_2.txt; } >&$LOG
    # r=$?
    # if [[ $r -ne 0 ]]; then
    #     return 1
    # fi
    # echo -e "-12\n-6\n-4\n-2\n0\n6\n8\n10\n14\n32\n50" > $DIR/num_2_expected.txt
    # diff $DIR/num_sorted_2.txt $DIR/num_2_expected.txt || return 1
    
    return 0;
}

function clean_env() {
    cd $DIR
    # Cleanup all created files and directories
    rm -rf $LOG $REDUCED_BINARY $DIR/*.txt
    return 0
}

function compile() {
    cd $DIR
    case $COV in
        1) CFLAGS="-w $BIN_CFLAGS" ;;
        *) CFLAGS="-w $BIN_CFLAGS" ;;
    esac
    $CC $C_FILE -o $REDUCED_BINARY >&$LOG || exit 1
    $CC $O_FILE -o $ORIGINAL_BINARY >&$LOG || exit 1
    return 0
}

sanitizers=("")

function main() {
    cd $DIR
    clean_env
    compile || exit 1
    run || exit 1
    clean_env
    
}

main
