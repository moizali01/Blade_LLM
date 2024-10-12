#!/bin/bash

PROGRAM_NAME=date-8.21
DIR=$(pwd)
C_FILE=$DIR/date-org.c
ORIGINAL_FILE=$DIR/date-org.c
ORIGINAL_BINARY=$DIR/date-original
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
CC=clang
TIMEOUT_LIMIT="-k 2 2"
TIMEOUT_VALUE=2
LOG=$DIR/log

# Counters for tests
TOTAL_FUNCTIONALITY_TESTS=0
PASSED_FUNCTIONALITY_TESTS=0

TOTAL_ROBUSTNESS_TESTS=0
PASSED_ROBUSTNESS_TESTS=0

compile() {
    # Compile the original and reduced binaries
    $CC -w $ORIGINAL_FILE -o $ORIGINAL_BINARY >&$LOG || exit 1
    $CC -w $C_FILE -o $REDUCED_BINARY >&$LOG || exit 1

}


# Function to run a single test case
run_functionality() {
    local command=("$@")
    local description="${command[-1]}"
    unset 'command[-1]'
    
    ((TOTAL_FUNCTIONALITY_TESTS++))

    # Run both commands simultaneously and capture their outputs
    { 
        paste <(timeout $TIMEOUT_LIMIT $REDUCED_BINARY "${command[@]}" ) \
              <(timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY "${command[@]}" )
    } >& $DIR/combined_output.txt

    # Check if either command timed out or failed
    if [[ ${PIPESTATUS[0]} -ne 0 || ${PIPESTATUS[1]} -ne 0 ]]; then
        echo "Fail: $description"
        echo "One or both commands failed or timed out."
        return 1
    fi

    # Separate the outputs
    cut -f1 $DIR/combined_output.txt > $DIR/temp_output.txt
    cut -f2 $DIR/combined_output.txt > $DIR/expected_output.txt

    # Compare the outputs
    diff $DIR/temp_output.txt $DIR/expected_output.txt
    
    if [[ $? -eq 0 ]]; then
        echo "Pass: $description"
        # echo "Output: $(cat $DIR/temp_output.txt)"
        # echo "Reduced output: $(cat $DIR/temp_output.txt)"
        # echo "Original output: $(cat $DIR/expected_output.txt)"
        ((PASSED_FUNCTIONALITY_TESTS++))
    else
        echo "Fail: $description"
        # echo "Reduced output: $(cat $DIR/temp_output.txt)"
        # echo "Original output: $(cat $DIR/expected_output.txt)"
    fi

}

run_robustness() {
    local description="$1"
    local command="$2"

    TOTAL_ROBUSTNESS_TESTS=$((TOTAL_ROBUSTNESS_TESTS + 1))
    # echo "Running test: $description"

    # Setup test environment if needed
    eval "$setup_command"

    # Run the debloated program and see if it times out
    { timeout "$TIMEOUT_VALUE" $REDUCED_BINARY $command; } >& /dev/null
    a=$?
    if [ $a -ne 124 ]; then
        echo "Pass: $description"
        PASSED_ROBUSTNESS_TESTS=$((PASSED_ROBUSTNESS_TESTS + 1))
    else
        echo "Fail: $description"
    fi
    eval "$cleanup_command"

}

# Function to run date formatting tests
functionality_cases() {
    echo
    echo "Running date formatting tests..."
    
    run_functionality "+%Y-%m-%d" "Format date in YYYY-MM-DD"
    run_functionality "+%H:%M:%S" "Format time in HH:MM:SS"
    run_functionality "+%s" "Display Unix timestamp"
    run_functionality "+%Y-%m-%d+%H:%M:%S" "Format full date and time"
    run_functionality "+%A, Week %U" "Format with weekday and week number"
    run_functionality "+%F +%T" "ISO 8601 date and time format"
    run_functionality "+%c" "Locale-specific date and time format"


    run_functionality "+%Y年%m月%d日 %H時%M分%S秒" "Custom format with non-ASCII characters"
    run_functionality "+It's %A, the %d of %B, %Y" "Custom format with literal text"
    run_functionality "+%c (en_US) + %c (fr_FR) + %c (de_DE) + %c (es_ES) + %c (it_IT) + %c (ja_JP) + %c (zh_CN) + %c (ru_RU) + %c (pt_PT)" "Date in multiple locales"

    echo
    echo "Running date calculation tests..."
    
    # Relative date tests
    run_functionality -d "yesterday" "+%Y-%m-%d" "Calculate yesterday's date"
    run_functionality -d "tomorrow" "+%Y-%m-%d" "Calculate tomorrow's date"
    run_functionality -d "next Monday" "+%Y-%m-%d" "Calculate next Monday's date"
    run_functionality -d "last Friday" "+%Y-%m-%d" "Calculate last Friday's date"
    run_functionality -d "2024-01-01 + 5 days" "+%Y-%m-%d" "Calculate 5 days from 2024-01-01"
    run_functionality -d "2024-02-28 + 1 day" "+%Y-%m-%d" "Leap year: Calculate 1 day after Feb 28, 2024"
    run_functionality -d "2023-02-28 + 1 day" "+%Y-%m-%d" "Non-leap year: Calculate 1 day after Feb 28, 2023"
    run_functionality -d "2024-01-31 + 1 month" "+%Y-%m-%d" "End-of-month transition: Jan 31 to Feb"
    run_functionality -d "2024-04-30 + 1 day" "+%Y-%m-%d" "End-of-month transition: Apr 30 to May 1"
    run_functionality -d "2023-12-31 + 1 day" "+%Y-%m-%d" "New Year's Eve to New Year's Day"
    run_functionality -d "100 years ago" "+%Y" "Calculate the year 100 years ago"
    run_functionality -d "2024-01-01 - 2 weeks" "+%Y-%m-%d" "Subtract 2 weeks from 2024-01-01"
    run_functionality -d "2024-01-01 + 1 year" "+%Y-%m-%d" "Add 1 year to 2024-01-01"
    run_functionality -d "-1 day" "+%Y-%m-%d" "Negative offset: Calculate the previous day"
    run_functionality -d "-1 month" "+%Y-%m-%d" "Negative offset: Calculate the previous month"
    run_functionality -d "2024-01-01 + 1 month - 3 days" "+%Y-%m-%d" "Compound calculation: Add 1 month and subtract 3 days"
    run_functionality -d "now + 3 months 2 weeks 4 days" "+%Y-%m-%d" "Complex relative date calculation"
    run_functionality -d "today - 100 years" "+%Y-%m-%d" "Long-term past date calculation"

    # Leap year tests
    run_functionality -d "2000-02-29" "+%Y-%m-%d" "Verify leap year 2000"
    run_functionality -d "2100-02-28 + 1 day" "+%Y-%m-%d" "Verify non-leap year 2100"
    run_functionality -d "2400-02-29" "+%Y-%m-%d" "Verify leap year 2400"

    # Large date ranges
    run_functionality -d "9999-12-31" "+%Y-%m-%d" "Far future date"
    run_functionality -d "0000-01-01" "+%Y-%m-%d" "Earliest representable date"
    run_functionality -d "@-62167219200" "+%Y-%m-%d" "Unix epoch for 0000-01-01"

    # Date comparisons
    run_functionality -d "2023-01-01" -d "2024-01-01" "+%Y-%m-%d" "Compare two dates"

    # Extreme Date range calculations
    run_functionality -d "@-1" "+%Y-%m-%d %H:%M:%S" "One second before Unix epoch"
    run_functionality -d "9999-12-31 23:59:59" "+%Y-%m-%d %H:%M:%S" "Last second of year 9999"
    run_functionality -d "10000-01-01" "+%Y-%m-%d" "First day of year 10000"
    
    # Centrury transition tests
    run_functionality -d "2099-12-31 + 1 day" "+%Y-%m-%d" "Transition to year 2100"
    run_functionality -d "yesterday" "+%F +%T" "Combination of date calculation and formatting"
    run_functionality -d "2024-12-31 + 1 day" "+%A, %d %B %Y" "Calculate New Year's Day with full date formatting"

    # Display Date tests with various formats
    run_functionality -d "2023-01-01" "+%Y-W%V-%u" "First day of 2023 (ISO week)"
    run_functionality -d "2023-12-31" "+%Y-W%V-%u" "Last day of 2023 (ISO week)"
    run_functionality -d "Tue, 1 Jul 2003 10:52:37 +0200" "+%Y-%m-%d %H:%M:%S %z" "Parse RFC 2822 date"
    run_functionality -d "2023-W01-1" "+%Y-%m-%d" "First day of ISO week 1, 2023"
    run_functionality -d "2023-12-31" "+%G-W%V-%u" "Format as ISO week date"
    run_functionality -d "2023-001" "+%Y-%m-%d" "First day of 2023 (ordinal)"
    run_functionality -d "2023-12-31" "+%Y-%j" "Format as ordinal date"
    run_functionality -d "@1631234567" "+%Y-%m-%d %H:%M:%S" "Unix timestamp input"
    run_functionality -d "15 Sep 2023 14:30:00" "+%Y-%m-%d %H:%M:%S" "Human-readable date input"
    run_functionality -d "now" "+%s.%M"  "Unix timestamp with microseconds"
    run_functionality -d "2023-02-30" "+%Y-%m-%d" "Invalid date (February 30th)"
    run_functionality -d "2023-04-31" "+%Y-%m-%d" "Invalid date (April 31st)" 
}

robustness_cases(){
    echo
    echo "Running robustness tests..."

    # Test cases for date utility flags
    run_robustness "Debug flag" "--debug"
    run_robustness "File flag" "-f /dev/null"
    run_robustness "ISO 8601 flag" "-I"
    run_robustness "RFC email flag" "-R"
    run_robustness "RFC 3339 flag" "--rfc-3339=seconds"
    run_robustness "Reference file flag" "-r /dev/null"
    run_robustness "Set time flag" "-s '2023-01-01 00:00:00'"
    run_robustness "UTC flag" "-u"
    run_robustness "Help flag" "--help"
    run_robustness "Version flag" "--version"

    # Test case for multiple flags and format
    run_robustness "Multiple flags and format" "-u -R +%Y-%m-%d"

    # Test case for invalid flag (to check error handling)
    run_robustness "Invalid flag" "--invalid-flag"

}

# Function to clean up test files
cleanup() {
    rm -f $LOG $REDUCED_BINARY $ORIGINAL_BINARY $DIR/temp_output.txt $DIR/expected_output.txt $DIR/combined_output.txt
}


function main() {
    cleanup
    compile

    # Run the test cases
    functionality_cases
    robustness_cases

    cleanup

    # Summary
    echo
    echo "Functionality tests run: $TOTAL_FUNCTIONALITY_TESTS"
    echo "Functionality tests passed: $PASSED_FUNCTIONALITY_TESTS"
    echo "Percentage functionality tests passed: $((PASSED_FUNCTIONALITY_TESTS * 100 / TOTAL_FUNCTIONALITY_TESTS))%"
    echo
    echo "Robustness tests run: $TOTAL_ROBUSTNESS_TESTS"
    echo "Robustness tests passed: $PASSED_ROBUSTNESS_TESTS"
    echo "Percentage robustness tests passed: $((PASSED_ROBUSTNESS_TESTS * 100 / TOTAL_ROBUSTNESS_TESTS))%"

    local passed=$((PASSED_FUNCTIONALITY_TESTS + PASSED_SECURITY_TESTS + PASSED_ROBUSTNESS_TESTS))
    local total=$((TOTAL_FUNCTIONALITY_TESTS + TOTAL_SECURITY_TESTS + TOTAL_ROBUSTNESS_TESTS))  
    echo
    echo "Total tests run: $total"
    echo "Total tests passed: $passed"
    if [ $total -eq $passed ]; then
        echo "All tests passed successfully."
    else
        echo "Some tests failed!"
    fi
}

main
