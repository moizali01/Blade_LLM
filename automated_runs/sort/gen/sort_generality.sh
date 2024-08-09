#!/bin/bash

PROGRAM_NAME=sort-8.16
DIR=$(pwd)
C_FILE=$DIR/sort-org.c
REDUCED_FILE=$DIR/sort-util.c.blade.c
ORIGINAL_BINARY=$DIR/original_binary
REDUCED_BINARY=$DIR/reduced_binary
CC=clang
TIMEOUT_LIMIT="-k 1 1"
LOG=$DIR/log

TOTAL_TESTS=0
PASSED_TESTS=0

function run_test() {
    ((TOTAL_TESTS++))
    local a=0
    local b=0
    description=$1
    command=$2
    expected_command=$3
    fail_log=$DIR/fail_log_$TOTAL_TESTS.log
    echo -e "CASE: $TOTAL_TESTS, $description" >>${LOG} 2>&1
    eval "$command" >>${LOG} 2>&1
    if [ $? -ne 0 ]; then
        a=1
    fi

    eval "$expected_command" >>${LOG} 2>&1
    if [ $? -ne 0 ]; then
        b=1
    fi

    #check if both a and b are same
    if [ $a -ne $b ]; then
        echo "Test failed: $description" >>${LOG} 2>&1
        return
    fi

    sed -i '/reduced_binary/d' $DIR/temp_output.txt
    sed -i '/original_binary/d' $DIR/expected_output.txt

    if diff $DIR/temp_output.txt $DIR/expected_output.txt >/dev/null; then
        ((PASSED_TESTS++))
    else
        echo "Test failed: $description" >>${LOG} 2>&1
    fi
    rm $DIR/temp_output.txt $DIR/expected_output.txt >/dev/null 2>&1
}

function run_test1() {
    echo "starting generality run" >>${LOG} 2>&1

    # Generality Test Case 1: Numeric Sort with Mixed Positive and Negative Small and Large Numbers
    echo -e "10\n-200\n32\n4000\n-50\n60000\n-100\n500\n-300\n10000" >$DIR/mixed_small_large.txt
    run_test "Numeric sort with mixed positive and negative small and large numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/mixed_small_large.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/mixed_small_large.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 2: Numeric Sort with Negative Decimals
    echo -e "-10.1\n-2.2\n-32.3\n-4.4\n-50.5\n-6.6\n-7.7\n-8.8\n-9.9\n-0.1" >$DIR/negative_decimals.txt
    run_test "Numeric sort with negative decimals" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/negative_decimals.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/negative_decimals.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 3: Numeric Sort with Mixed Decimals
    echo -e "10.1\n-2.2\n32.3\n-4.4\n50.5\n-6.6\n7.7\n-8.8\n9.9\n0.1" >$DIR/mixed_decimals.txt
    run_test "Numeric sort with mixed decimals" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/mixed_decimals.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/mixed_decimals.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 4: Numeric Sort with Positive and Negative Scientific Notation
    echo -e "1e2\n-3e1\n2e2\n-1e3\n2e3\n-3e2\n1e1\n-2e1\n3e3\n-1e2" >$DIR/mixed_scientific.txt
    run_test "Numeric sort with positive and negative scientific notation" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/mixed_scientific.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/mixed_scientific.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 5: Numeric Sort with Large Positive and Negative Numbers
    echo -e "1000000\n-200000\n3000000\n-400000\n5000000\n-600000\n700000\n-800000\n900000\n-100000" >$DIR/large_positive_negative.txt
    run_test "Numeric sort with large positive and negative numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/large_positive_negative.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/large_positive_negative.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 6: Numeric Sort with Numbers Including Leading Zeros
    echo -e "0010\n-0002\n00032\n-0004\n0050\n-0006\n0070\n-0008\n0090\n-0010" >$DIR/leading_zeros_mixed.txt
    run_test "Numeric sort with numbers including leading zeros" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/leading_zeros_mixed.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/leading_zeros_mixed.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 7: Numeric Sort with Mixed Length Positive and Negative Numbers
    echo -e "10\n-2\n32\n-4000\n50\n-60000\n70\n-8000\n90\n-100" >$DIR/mixed_length.txt
    run_test "Numeric sort with mixed length positive and negative numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/mixed_length.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/mixed_length.txt > $DIR/expected_output.txt; }"

    # # Generality Test Case 8: Numeric Sort with Large Range of Numbers
    echo -e "1\n1000\n1000000\n200\n300000\n4000\n50000\n600\n700000\n8000\n90000\n100000" >$DIR/large_range.txt
    run_test "Numeric sort with large range of numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/large_range.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/large_range.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 9: Numeric Sort with Duplicate and Unique Numbers
    echo -e "10\n2\n32\n2\n50\n10\n70\n5\n90\n5" >$DIR/duplicate_unique.txt
    run_test "Numeric sort with duplicate and unique numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/duplicate_unique.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/duplicate_unique.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 10: Numeric Sort with Mixed Positive and Negative Numbers of Varying Lengths
    echo -e "10\n-200\n32\n-4000\n50\n-60000\n70\n-8000\n90\n-100\n15\n-250\n35\n-4500\n55\n-65000\n75\n-8500\n95\n-105" >$DIR/mixed_varying_lengths.txt
    run_test "Numeric sort with mixed positive and negative numbers of varying lengths" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/mixed_varying_lengths.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/mixed_varying_lengths.txt > $DIR/expected_output.txt; }"

    # # Generality Test Case 11: Numeric Sort with Random Numbers
    echo -e "15\n33\n24\n57\n89\n13\n67\n29\n45\n98\n71\n36\n84\n20\n61" >$DIR/random_numbers.txt
    run_test "Numeric sort with random numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/random_numbers.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/random_numbers.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 12: Numeric Sort with Consecutive Numbers
    echo -e "1\n2\n3\n4\n5\n6\n7\n8\n9\n10\n11\n12\n13\n14\n15\n16\n17\n18\n19\n20\n21\n22\n23\n24\n25" >$DIR/consecutive_numbers.txt
    run_test "Numeric sort with consecutive numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/consecutive_numbers.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/consecutive_numbers.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 13: Numeric Sort with Alternating Positive and Negative Numbers
    echo -e "10\n-20\n30\n-40\n50\n-60\n70\n-80\n90\n-100\n110\n-120\n130\n-140\n150" >$DIR/alternating_numbers.txt
    run_test "Numeric sort with alternating positive and negative numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/alternating_numbers.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/alternating_numbers.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 14: Numeric Sort with Decimals and Whole Numbers
    echo -e "10.5\n20\n30.5\n40\n50.5\n60\n70.5\n80\n90.5\n100" >$DIR/decimals_whole.txt
    run_test "Numeric sort with decimals and whole numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/decimals_whole.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/decimals_whole.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 15: Numeric Sort with Large Negative and Small Positive Numbers
    echo -e "-100000\n1\n-200000\n2\n-300000\n3\n-400000\n4\n-500000\n5\n-600000\n6\n-700000\n7\n-800000\n8" >$DIR/large_negative_small_positive.txt
    run_test "Numeric sort with large negative and small positive numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/large_negative_small_positive.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/large_negative_small_positive.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 16: Numeric Sort with Repeated Numbers
    echo -e "10\n10\n10\n20\n20\n20\n30\n30\n30\n40\n40\n40\n50\n50\n50\n60\n60\n60\n70\n70\n70" >$DIR/repeated_numbers.txt
    run_test "Numeric sort with repeated numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/repeated_numbers.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/repeated_numbers.txt > $DIR/expected_output.txt; }"

    #generality test case 17: Numeric sort with on 100000 numbers
    shuf -i 1-100000 >$DIR/100000_numbers.txt
    run_test "Numeric sort with 100000 numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/100000_numbers.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/100000_numbers.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 18: Numeric Sort with Very Small Fractions
    echo -e "0.0001\n-0.0002\n0.0003\n-0.0004\n0.0005\n-0.0006\n0.0007\n-0.0008\n0.0009\n-0.0010" >$DIR/very_small_fractions.txt
    run_test "Numeric sort with very small fractions" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/very_small_fractions.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/very_small_fractions.txt > $DIR/expected_output.txt; }"

    # # Generality Test Case 19: Numeric Sort with Very Large and Small Integers
    echo -e "999999999\n-888888888\n777777777\n-666666666\n555555555\n-444444444\n333333333\n-222222222\n111111111\n-1000000000" >$DIR/random_large_integers.txt
    run_test "Numeric sort with random large integers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/random_large_integers.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/random_large_integers.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 20: Numeric Sort with Rational Numbers
    echo -e "1/2\n-2/3\n3/4\n-4/5\n5/6\n-6/7\n7/8\n-8/9\n9/10\n-10/11" >$DIR/rational_numbers.txt
    run_test "Numeric sort with rational numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/rational_numbers.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/rational_numbers.txt > $DIR/expected_output.txt; }"

    # Generality test case 21: sort with small letters
    echo -e "apple\nBanana\nbanana\nCherry\ncherry\nAPPLE\nBANANA\nCHERRY" >$DIR/case_insensitive.txt
    run_test " sort with small letters" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive.txt > $DIR/expected_output.txt; }"

    # Generality test case 22: sort with large letters
    echo -e "A\nb\nC\nd\nE\nf" >$DIR/case_insensitive_large.txt
    run_test " sort with large letters" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_large.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_large.txt > $DIR/expected_output.txt; }"

    # Generality test case 23: sort with special characters
    echo -e "a#\nb!\nc@\nd*\ne&\nf$" >$DIR/case_insensitive_special.txt
    run_test " sort with special characters" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_special.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_special.txt > $DIR/expected_output.txt; }"

    # Generality test case 24: sort with spaces
    echo -e "apple\n Banana\n cherry\n  Apple" >$DIR/case_insensitive_spaces.txt
    run_test " sort with spaces" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_spaces.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_spaces.txt > $DIR/expected_output.txt; }"

    # Generality test case 25: sort with punctuation
    echo -e "apple.\nBanana,\ncherry!\nApple?\nBanana:" >$DIR/case_insensitive_punctuation.txt
    run_test " sort with punctuation" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_punctuation.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_punctuation.txt > $DIR/expected_output.txt; }"

    # Generality test case 26: sort with tabs
    echo -e "apple\t\nBanana\t\ncherry\t\nApple\t" >$DIR/case_insensitive_tabs.txt
    run_test " sort with tabs" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_tabs.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_tabs.txt > $DIR/expected_output.txt; }"

    # Generality test case 27: sort with mixed alphanumeric content
    echo -e "a1\nB2\nc3\nA2\nb1\nC2" >$DIR/case_insensitive_mixed_alpha.txt
    run_test " sort with mixed alphanumeric content" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_mixed_alpha.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_mixed_alpha.txt > $DIR/expected_output.txt; }"

    # Generality test case 28: sort with repeated lines
    echo -e "apple\nBanana\ncherry\nApple\nbanana\nCherry" >$DIR/case_insensitive_repeated.txt
    run_test " sort with repeated lines" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_repeated.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_repeated.txt > $DIR/expected_output.txt; }"

    # Generality test case 29: sort with numeric and alpha mixed content
    echo -e "1apple\n2Banana\n3cherry\n1Apple\n2banana\n3Cherry" >$DIR/case_insensitive_mixed.txt
    run_test " sort with numeric and alpha mixed content" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_mixed.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_mixed.txt > $DIR/expected_output.txt; }"

    # Generality test case 30: sort with special mixed content
    echo -e "1apple.\n2Banana,\n3cherry!\n1Apple?\n2banana:\n3Cherry" >$DIR/case_insensitive_special_mixed.txt
    run_test " sort with special mixed content" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_special_mixed.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_special_mixed.txt > $DIR/expected_output.txt; }"

    # Generality test case 31: sort with mixed case sensitivity
    echo -e "apple\nBanana\nCHERRY\nApple\nbanana\ncherry\nAPPLE\nBANANA" >$DIR/case_insensitive_mixed_case.txt
    run_test " sort with mixed case sensitivity" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_mixed_case.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_mixed_case.txt > $DIR/expected_output.txt; }"

    # Generality test case 32: sort with numbers and special characters
    echo -e "1#apple\n2!Banana\n3@cherry\n4$Apple\n5%banana\n6^Cherry" >$DIR/case_insensitive_numbers_special.txt
    run_test " sort with numbers and special characters" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_numbers_special.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_numbers_special.txt > $DIR/expected_output.txt; }"

    # Generality test case 33: sort with leading spaces
    echo -e " apple\n Banana\n cherry\n Apple\n banana\n cherry" >$DIR/case_insensitive_leading_spaces.txt
    run_test " sort with leading spaces" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_leading_spaces.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_leading_spaces.txt > $DIR/expected_output.txt; }"

    # Generality test case 34: sort with mixed tabs and spaces
    echo -e "apple\t\nBanana \ncherry\t\nApple \nbanana\t\nCherry " >$DIR/case_insensitive_tabs_spaces.txt
    run_test " sort with mixed tabs and spaces" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_tabs_spaces.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_tabs_spaces.txt > $DIR/expected_output.txt; }"

    # Generality test case 35: sort with mixed special characters and spaces
    echo -e " apple.\n Banana,\n cherry!\n  Apple?\n  Banana:" >$DIR/case_insensitive_special_spaces.txt
    run_test " sort with mixed special characters and spaces" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_special_spaces.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_special_spaces.txt > $DIR/expected_output.txt; }"

    # Generality test case 36: sort with accented characters
    echo -e "éclair\nBanana\nÈclair\napple\nAPPLE\nÉclair\nBANANA" >$DIR/case_insensitive_accented.txt
    run_test " sort with accented characters" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_accented.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_accented.txt > $DIR/expected_output.txt; }"

    # Generality test case 37: sort with different encodings
    echo -e "apple\nBanana\nbanana\nCherry\ncherry\nAPPLE\nBANANA\nCHERRY" | iconv -t UTF-16LE >$DIR/case_insensitive_utf16.txt
    run_test " sort with different encodings" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_utf16.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_utf16.txt > $DIR/expected_output.txt; }"

    # Generality test case 38: sort with numeric strings
    echo -e "1apple\n2banana\n10cherry\n5Apple\n20banana\n15Cherry" >$DIR/case_insensitive_numeric_strings.txt
    run_test " sort with numeric strings" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_numeric_strings.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_numeric_strings.txt > $DIR/expected_output.txt; }"

    # Generality test case 39: sort with Unicode characters
    echo -e "αlpha\nBeta\nbeta\nGamma\nΔelta\nalpha\nγamma\nβeta" >$DIR/case_insensitive_unicode.txt
    run_test " sort with Unicode characters" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_unicode.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_unicode.txt > $DIR/expected_output.txt; }"

    # Generality test case 40: sort with empty lines
    echo -e "apple\n\nBanana\n\ncherry\n\nApple" >$DIR/case_insensitive_empty_lines.txt
    run_test " sort with empty lines" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/case_insensitive_empty_lines.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/case_insensitive_empty_lines.txt > $DIR/expected_output.txt; }"

    # Generality test case 41: sort with simple numbers
    echo -e "5\n3\n9\n1\n7" >$DIR/simple_numbers.txt
    run_test "Sort simple numbers" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/simple_numbers.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/simple_numbers.txt > $DIR/expected_output.txt; }"

    # Generality test case 42: Sorting Alphabetically
    echo -e "banana\napple\ncarrot\ndate" >$DIR/simple_strings.txt
    run_test "Sort strings alphabetically" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/simple_strings.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/simple_strings.txt > $DIR/expected_output.txt; }"

    # Generality test case 43: Sorting With Mixed Content
    echo -e "banana\n2\nApple\n1" >$DIR/mixed_content.txt
    run_test "Sort mixed content" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/mixed_content.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/mixed_content.txt > $DIR/expected_output.txt; }"

    # Generality test case 44: Sorting With Duplicate Lines
    echo -e "apple\nbanana\napple\nbanana" >$DIR/duplicates.txt
    run_test "Sort with duplicate lines" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/duplicates.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/duplicates.txt > $DIR/expected_output.txt; }"

    # Generality test case 45: Large File Sort
    seq 1 100000 >$DIR/large_file.txt
    run_test "Sort a large file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/large_file.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/large_file.txt > $DIR/expected_output.txt; }"

    # Generality test case 46: Sort Very Long Lines
    yes | head -n 100000 | tr -d '\n' | fold -w 500 >$DIR/long_lines.txt
    run_test "Sort file with very long lines" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/long_lines.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/long_lines.txt > $DIR/expected_output.txt; }"

    return 0
}

function exception_handling() {

    # Generality Test Case 47: File Not Found
    run_test "File not found" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/non_existent_file.txt > $DIR/temp_error.txt 2> $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/non_existent_file.txt > $DIR/expected_error.txt 2> $DIR/expected_output.txt; }"

    # Generality Test Case 48: Invalid Flag
    echo -e "apple\nBanana\nbanana\nCherry\ncherry\nAPPLE\nBANANA\nCHERRY" >$DIR/invalid_flag.txt
    run_test "Invalid flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -x $DIR/invalid_flag.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -x $DIR/invalid_flag.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 49: Permission Denied
    touch $DIR/protected_file.txt
    chmod 000 $DIR/protected_file.txt
    run_test "Permission denied" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/protected_file.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/protected_file.txt > $DIR/expected_output.txt; }"
    chmod 644 $DIR/protected_file.txt # Reset permissions for cleanup

    # Generality Test Case 50: Invalid Option Combination
    echo -e "apple\nBanana\ncherry\nApple\nbanana\nCherry" >$DIR/invalid_option_combination.txt
    run_test "Invalid option combination" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -M $DIR/invalid_option_combination.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -M $DIR/invalid_option_combination.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 51: Empty File
    touch $DIR/empty_file.txt
    run_test "Sort an empty file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/empty_file.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/empty_file.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 52: Single Line File
    echo "singleline" >$DIR/single_line.txt
    run_test "Sort a single line file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/single_line.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/single_line.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 53: Non-ASCII Characters
    echo -e "naïve\ncafé\nresume\nexposé" >$DIR/non_ascii_chars.txt
    run_test "Sort a file with non-ASCII characters" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/non_ascii_chars.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/non_ascii_chars.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 54: Sorting Files with Very Long Lines
    echo -e "$(openssl rand -base64 1000)\n$(openssl rand -base64 1000)\n$(openssl rand -base64 1000)" >$DIR/very_long_lines.txt
    run_test "Sort files with very long lines" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/very_long_lines.txt > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/very_long_lines.txt > $DIR/expected_output.txt; }"

    # Generality Test Case 55: Sorting with Header Line (Assuming the header is non-numeric)
    echo -e "Header\n10\n2\n30\n4" >$DIR/header_included.txt
    run_test "Sort with header line skipped" \
        "{ timeout $TIMEOUT_LIMIT tail -n +2 $DIR/header_included.txt | $REDUCED_BINARY > $DIR/temp_output.txt; }" \
        "{ timeout $TIMEOUT_LIMIT tail -n +2 $DIR/header_included.txt | $ORIGINAL_BINARY > $DIR/expected_output.txt; }"

}

function clean_env() {
    cd $DIR
    # Cleanup all created files and directories except fail logs
    rm -rf $REDUCED_BINARY $ORIGINAL_BINARY $DIR/*.txt
    return 0
}

function compile() {
    # cd $DIR
    case $COV in
    1) CFLAGS="-w $BIN_CFLAGS" ;;
    *) CFLAGS="-w $BIN_CFLAGS" ;;
    esac
    $CC $REDUCED_FILE -lpthread -w -o $REDUCED_BINARY >>${LOG} 2>&1 || exit 1
    $CC $C_FILE -lpthread -w -o $ORIGINAL_BINARY >>${LOG} 2>&1 || exit 1
    return 0
}

sanitizers=("")

function main() {
    # cd $DIR
    clean_env
    rm -f $LOG
    compile || exit 1
    run_test1
    exception_handling
    clean_env
    echo "Total tests: $TOTAL_TESTS"
    echo "Passed tests: $PASSED_TESTS"

}

main
