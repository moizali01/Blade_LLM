#!/bin/bash

PROGRAM_NAME=uniq-8.16
DIR=$(pwd)
C_FILE=$DIR/uniq-8.16.c.origin.c
REDUCED_FILE=$DIR/uniq-8.16-GPT.c
ORIGINAL_BINARY=$DIR/original_binary
REDUCED_BINARY=$DIR/reduced_binary
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log

TOTAL_TESTS=0
PASSED_TESTS=0

function run_test() {
    ((TOTAL_TESTS++))
    description=$1
    command=$2
    expected_command=$3
    fail_log=$DIR/fail_log_$TOTAL_TESTS.txt
    echo -e "$description" >> $LOG
    eval "$command" &> $LOG
    eval "$expected_command" &> $LOG
   
    sed -i '/reduced_binary/d' $DIR/temp_output.txt
    sed -i '/original_binary/d' $DIR/expected_output.txt
   
    if diff $DIR/temp_output.txt $DIR/expected_output.txt &> $LOG; then
        ((PASSED_TESTS++))
    else
        echo "Test failed: $description" >> $fail_log
        echo "Expected:" >> $fail_log
        cat $DIR/expected_output.txt >> $fail_log
        echo "Got:" >> $fail_log
        cat $DIR/temp_output.txt >> $fail_log
    fi
    # rm -f $DIR/temp_output.txt $DIR/expected_output.txt
}

function desired() {
    run_test "desired_run ''" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' data.txt > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY '' data.txt > $DIR/expected_output.txt; }"
   
    run_test "desired_run '-c'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -c data.txt > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -c data.txt > $DIR/expected_output.txt; }"
   
    run_test "desired_run '-d'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d data.txt > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -d data.txt > $DIR/expected_output.txt; }"
   
    run_test "desired_run '-u'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -u data.txt > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -u data.txt > $DIR/expected_output.txt; }"
   
    run_test "desired_run '-i'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -i data.txt > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -i data.txt > $DIR/expected_output.txt; }"
   
    run_test "desired_run '-f 5'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 5 data.txt > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -f 5 data.txt > $DIR/expected_output.txt; }"
   
    run_test "desired_run '-s 10'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -s 10 data.txt > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -s 10 data.txt > $DIR/expected_output.txt; }"
   
    run_test "desired_run '-w 10'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -w 10 data.txt > $DIR/temp_output.txt; }" \
    "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -w 10 data.txt > $DIR/expected_output.txt; }"
}

function desired_disaster() {
    case $1 in
    memory)
        MESSAGE="memory exhausted"
        ;;
    file)
        MESSAGE="write error"
        ;;
    *)
        return 1
        ;;
    esac

    run_test "desired_disaster_run ''" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' data.txt > $DIR/temp_output.txt 2>&1; }" \
    "{ grep -E -q '$MESSAGE' $DIR/temp_output.txt; }"

    run_test "desired_disaster_run '-c'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -c data.txt > $DIR/temp_output.txt 2>&1; }" \
    "{ grep -E -q '$MESSAGE' $DIR/temp_output.txt; }"

    run_test "desired_disaster_run '-d'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d data.txt > $DIR/temp_output.txt 2>&1; }" \
    "{ grep -E -q '$MESSAGE' $DIR/temp_output.txt; }"

    run_test "desired_disaster_run '-u'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -u data.txt > $DIR/temp_output.txt 2>&1; }" \
    "{ grep -E -q '$MESSAGE' $DIR/temp_output.txt; }"

    run_test "desired_disaster_run '-i'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -i data.txt > $DIR/temp_output.txt 2>&1; }" \
    "{ grep -E -q '$MESSAGE' $DIR/temp_output.txt; }"

    run_test "desired_disaster_run '-f 5'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 5 data.txt > $DIR/temp_output.txt 2>&1; }" \
    "{ grep -E -q '$MESSAGE' $DIR/temp_output.txt; }"

    run_test "desired_disaster_run '-s 10'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -s 10 data.txt > $DIR/temp_output.txt 2>&1; }" \
    "{ grep -E -q '$MESSAGE' $DIR/temp_output.txt; }"

    run_test "desired_disaster_run '-w 10'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -w 10 data.txt > $DIR/temp_output.txt 2>&1; }" \
    "{ grep -E -q '$MESSAGE' $DIR/temp_output.txt; }"
}

function undesired() {
    run_test "undesired ''" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' > $DIR/temp_output.txt; }" \
    "{ infinite $?; }"

    run_test "undesired 'notexist'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY notexist > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'notexist: No such file or directory'; }"

    run_test "undesired 'notexist1 notexist2 notexist3'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY notexist1 notexist2 notexist3 > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'extra operand'; }"

    run_test "undesired '-f1'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired ''" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '' 'a\na'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '' 'a\nb'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '' 'a\na\nb'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '' 'b\na\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '' 'a\nb\nc\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '-z'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -z temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-z' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -z temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-z' 'a\na'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -z temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-z' 'a\nb'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -z temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-z' 'a\na\nb'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -z temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-dz' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -dz temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '' 'ö\nv\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '-u' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -u temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '-u' 'a\nb\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -u temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-u' 'a\nb\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -u temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-u' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -u temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-u' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -u temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-d' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-d' 'a\nb\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-d' 'a\nb\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-d' 'a\na\nb\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-1' 'a a\nb a\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-f 1' 'a a\nb a\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-f 1' 'a a\nb b\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-f 1' 'a a a\nb a c\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-f 1' 'b a\na a\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-f 2' 'a a c\nb a c\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 2 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '+1' 'aaa\naaa\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY +1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '+1: No such file or directory'; }"

    run_test "undesired '+1' 'baa\naaa\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY +1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '+1: No such file or directory'; }"

    run_test "undesired '-s 1' 'aaa\naaa\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -s 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-s 2' 'baa\naaa\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -s 2 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '+1 --' 'aaa\naaa\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY +1 -- temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '+1 --: No such file or directory'; }"

    run_test "undesired '+1 --' 'baa\naaa\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY +1 -- temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '+1 --: No such file or directory'; }"

    run_test "undesired '-f 1 -s 1' 'a aaa\nb ab\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 -s 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '1 -s 1: invalid number of fields to skip'; }"

    run_test "undesired '-f 1 -s 1' 'a aaa\nb aaa\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 -s 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '1 -s 1: invalid number of fields to skip'; }"

    run_test "undesired '-s 1 -f 1' 'a aaa\nb ab\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -s 1 -f 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '1 -f 1: invalid number of fields to skip'; }"

    run_test "undesired '-s 1 -f 1' 'a aaa\nb aaa\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -s 1 -f 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '1 -s 1: invalid number of fields to skip'; }"

    run_test "undesired '-s 4' 'abc\nabcd\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -s 4 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-s 0' 'abc\nabcd\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -s 0 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-s 0' 'abc\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -s 0 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-w 0' 'abc\nabcd\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -w 0 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-w 1' 'a a\nb a\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -w 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-w 3' 'a a\nb a\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -w 3 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

        run_test "undesired '-w 1 -f 1' 'a a a\nb a c\n' '1 -f 1: invalid number of bytes to compare'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -w 1 -f 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '1 -f 1: invalid number of bytes to compare'; }"

    run_test "undesired '-f 1 -w 1' 'a a a\nb a c\n' '1 -w 1: invalid number of fields to skip'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 -w 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '1 -w 1: invalid number of fields to skip'; }"

    run_test "undesired '-f 1 -w 4' 'a a a\nb a c\n' '1 -w 4: invalid number of fields to skip'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 -w 4 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '1 -w 4: invalid number of fields to skip'; }"

    run_test "undesired '-f 1 -w 3' 'a a a\nb a c\n' '1 -w 3: invalid number of fields to skip'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 -w 3 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror '1 -w 3: invalid number of fields to skip'; }"

    run_test "undesired '' 'a\0a\na\n' 'No such file or directory'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '' 'a\ta\na a\n' 'No such file or directory'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY '' temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'No such file or directory'; }"

    run_test "undesired '-f 1' 'a\ta\na a\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-f 2' 'a\ta a\na a a\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 2 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-f 1' 'a\ta\na\ta\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -f 1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-c' 'a\nb\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -c temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-c' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -c temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-D' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -D temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-D -w1' 'a a\na b\n' 'invalid option --'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -D -w1 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'invalid option --'; }"

    run_test "undesired '-D -c' 'a a\na b\n' 'invalid option --'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -D -c temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'invalid option --'; }"

    run_test "undesired '--all-repeated=separate' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY --all-repeated=separate temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '--all-repeated=separate' 'a\na\nb\nc\nc\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY --all-repeated=separate temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '--all-repeated=separate' 'a\na\nb\nb\nc\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY --all-repeated=separate temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '--all-repeated=prepend' 'a\na\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY --all-repeated=prepend temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '--all-repeated=prepend' 'a\na\nb\nc\nc\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY --all-repeated=prepend temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '--all-repeated=prepend' 'a\nb\n'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY --all-repeated=prepend temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-d -u' 'a\na\n\b'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d -u temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"

    run_test "undesired '-d -u -w1111111111111111111111111111111111111111' 'a\na\n\b' 'invalid option --'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d -u -w1111111111111111111111111111111111111111 temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'invalid option --'; }"

    run_test "undesired '--zero-terminated' 'a\na\nb' 'invalid option --'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY --zero-terminated temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror 'invalid option --'; }"

    run_test "undesired '--zero-terminated' 'a\0a\0b'" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY --zero-terminated temp > $DIR/temp_output.txt; }" \
    "{ outputcheckerror ''; }"
}

function clean_env() {
    cd $DIR
    # Cleanup all created files and directories except fail logs
    rm -rf $LOG $REDUCED_BINARY $ORIGINAL_BINARY $DIR/*.txt
    return 0
}

function compile() {
    # cd $DIR
    case $COV in
        1) CFLAGS="-w $BIN_CFLAGS" ;;
        *) CFLAGS="-w $BIN_CFLAGS" ;;
    esac
    $CC $REDUCED_FILE -o $REDUCED_BINARY &> $LOG || exit 1
    $CC $C_FILE -o $ORIGINAL_BINARY &> $LOG || exit 1
    return 0
}

sanitizers=("")

function main() {
    # cd $DIR
    
    compile || exit 1
    desired || exit 1
    echo "Tests Passed For Desired Behavior: $PASSED_TESTS"

    
    compile || exit 1
    desired_disaster memory || exit 1
    echo "Tests Passed For Desired Disaster Memory: $PASSED_TESTS"

    
    compile || exit 1
    desired_disaster file || exit 1
    echo "Tests Passed For Desired Disaster File: $PASSED_TESTS"

    
    compile || exit 1
    undesired || exit 1
    echo "Tests Passed For Undesired Behavior: $PASSED_TESTS"
   
    # Calculate and print the score
    echo "Total tests: $TOTAL_TESTS"
    echo "Passed tests: $PASSED_TESTS"
    SCORE=$(echo "scale=2; ($PASSED_TESTS/$TOTAL_TESTS)*100" | bc)
    echo "Score: $SCORE%"
   
    echo "clean up"
    clean_env 
}

main

