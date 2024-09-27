#!/bin/bash

DEBLOATED_FILE="grep-org.c"
ORIGINAL_FILE="grep-org.c"
CC=clang

# Path to the executables
DEBLOATED_GREP="./debloated_grep"
ORIGINAL_GREP="./original_grep"

OUTPUT_DEBLOATED="$TEST_DIR/output_debloat.txt"
OUTPUT_ORIGINAL="$TEST_DIR/output_original.txt"

# Directories and files for testing
TEST_DIR="grep_test_dir"
TEST_FILE="$TEST_DIR/security_test_file.txt"
SYMLINK_FILE="$TEST_DIR/symlink_target.txt"
NUM_FILES=1000
NUM_LINES=10000
LONG_LINE_LENGTH=50
TIMEOUT_VALUE=5

# Counters for tests
TOTAL_FUNCTIONALITY_TESTS=0
PASSED_FUNCTIONALITY_TESTS=0

TOTAL_ROBUSTNESS_TESTS=0
PASSED_ROBUSTNESS_TESTS=0

compile() {
  # Compile the debloated code
  CFLAGS="-w -D __msan_unpoison(s,z) -lpcre"
  $CC $CFLAGS -o debloated_grep "$DEBLOATED_FILE" || { echo "Error: Compilation of $DEBLOATED_FILE failed"; exit 1; }

  # Compile the original code
  $CC $CFLAGS -o original_grep "$ORIGINAL_FILE" || { echo "Error: Compilation of $ORIGINAL_FILE failed"; exit 1; }

  # Check if executables exist
  [[ -x "$DEBLOATED_GREP" ]] || { echo "Error: $DEBLOATED_GREP not found or not executable!"; exit 1; }
  [[ -x "$ORIGINAL_GREP" ]] || { echo "Error: $ORIGINAL_GREP not found or not executable!"; exit 1; }
}

# Function to run a single test case
run_functionality() {
  local description="$1"
  local flag="$2"
  local pattern="$3"
  local input_file="$4"
  local setup_command="$5"
  local cleanup_command="$6"
  local test_type="$7"

  if [ "$test_type" == "functionality" ]; then
  TOTAL_FUNCTIONALITY_TESTS=$((TOTAL_FUNCTIONALITY_TESTS + 1))
  elif [ "$test_type" == "security" ]; then
    TOTAL_SECURITY_TESTS=$((TOTAL_SECURITY_TESTS + 1))
  fi  

  # Setup test environment if needed
  eval "$setup_command"

  timeout "$TIMEOUT_VALUE" $DEBLOATED_GREP $flag "$pattern" $input_file >& "$OUTPUT_DEBLOATED" 
  if [ $? -ne 0 ]; then
    eval "$cleanup_command"
    echo Fail: $description
    # cat "$OUTPUT_DEBLOATED"
    # echo "Error: Debloated program crashed!"
    # echo
    return
  fi

  # Run the original program and suppress stderr
  timeout "$TIMEOUT_VALUE" $ORIGINAL_GREP $flag "$pattern" $input_file >& "$OUTPUT_ORIGINAL"
  if [ $? -ne 0 ]; then
    echo "Error: Original program crashed!"
    # Do not consider this as a test case
    TOTAL_TESTS=$((TOTAL_TESTS - 1))
    eval "$cleanup_command"
    echo
    return
  fi

  # Compare outputs
  if cmp -s "$OUTPUT_DEBLOATED" "$OUTPUT_ORIGINAL"; then
    echo "Pass: $description"
    # cat "$OUTPUT_DEBLOATED"
    # echo ____________
    # cat "$OUTPUT_ORIGINAL"
    PASSED_TESTS=$((PASSED_TESTS + 1))
    if [ "$test_type" == "functionality" ]; then
      PASSED_FUNCTIONALITY_TESTS=$((PASSED_FUNCTIONALITY_TESTS + 1))
    elif [ "$test_type" == "security" ]; then
      PASSED_SECURITY_TESTS=$((PASSED_SECURITY_TESTS + 1))
    fi
  else
    echo "Fail: $description"
    # cat "$OUTPUT_DEBLOATED"
    # echo ...
    # cat "$OUTPUT_ORIGINAL"
  fi
  # Cleanup test environment if needed
  eval "$cleanup_command"
  # echo
}

run_robustness() {
  local description="$1"
    local flag="$2"
    local pattern="$3"
    local input_file="$4"
    local setup_command="$5"
    local cleanup_command="$6"
    local test_type="$7"

  TOTAL_ROBUSTNESS_TESTS=$((TOTAL_ROBUSTNESS_TESTS + 1))
  # echo "Running test: $description"

  # Setup test environment if needed
  eval "$setup_command"

  # Run the debloated program and see if it times out
  timeout "$TIMEOUT_VALUE" $DEBLOATED_GREP $flag $pattern "$input_file" >& "$OUTPUT_DEBLOATED"
  a=$?
  if [ $a -ne 124 ]; then
    echo "Pass: $description"
    # cat "$OUTPUT_DEBLOATED"
    PASSED_ROBUSTNESS_TESTS=$((PASSED_ROBUSTNESS_TESTS + 1))
  else
    echo "Fail: $description"
  fi
  eval "$cleanup_command"
  # echo
}

functionality_cases() {

  run_functionality "Basic grep functionality in a small file" \
  "" \
  "error" \
  "$TEST_DIR/test_file_1.txt" \
  "echo 'error: this is a sample line' > $TEST_DIR/test_file_1.txt && echo this is the second sample line >> $TEST_DIR/test_file_1.txt" \
  "" \
  "functionality"

  run_functionality "Basic grep functionality in a large file" \
    "" \
    "test" \
    "$TEST_FILE" \
    "seq 1 $NUM_LINES | sed 's/^/This is a test line /' > $TEST_FILE" \
    "" \
    "functionality"

  run_functionality "Basic grep functionality in multiple files" \
    "" \
    "line" \
    "$TEST_DIR/test_file_1.txt $TEST_DIR/test_file_2.txt" \
    "echo 'this is a sample line' > $TEST_DIR/test_file_1.txt && echo 'this is the second sample line' > $TEST_DIR/test_file_2.txt" \
    "" \
    "functionality"

    run_functionality "Searching patterns across multiple files using wildcard expansion" \
    "" \
    "error" \
    "test_files/*.txt" \
    "" \
    "" \
    "functionality"


  run_functionality "Searching kernel in linux log file" \
    "" \
    "kernel" \
    "test_files/Linux_2k.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Searching POSIX in linux log file" \
    "" \
    "POSIX" \
    "test_files/Linux_2k.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Searching Version in linux log file" \
    "" \
    "Version" \
    "test_files/Linux_2k.txt" \
    "" \
    "" \
    "functionality" 

  run_functionality "Searching error in apache log file" \
    "" \
    "error" \
    "test_files/Apache_2k.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Searching notice in apache log file" \
    "" \
    "notice" \
    "test_files/Apache_2k.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Searching in file with very long lines" \
    "" \
    "long" \
    "$TEST_DIR/long_lines.txt" \
    "yes 'very long line ' | head -n 10 | tr '\n' ' ' > $TEST_DIR/long_lines.txt" \
    "" \
    "functionality"

  run_functionality "Searching for multiple words" \
    "" \
    "did not pass" \
    "test_files/removal_log.txt" \
    "" \
    "" \
    "functionality"

  # Some edge case testing
  run_functionality "Searching for ^ in a file" \
    "" \
    "^" \
    "test_files/edge_cases.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Searching for lines ending with $ in a file" \
    "" \
    "\$$" \
    "test_files/edge_cases.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Match lines containing a single character ." \
    "" \
    "c.t" \
    "test_files/edge_cases.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Match lines starting with a ." \
    "" \
    "^." \
    "test_files/edge_cases.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Match lines containing multiple dots in a row" \
    "" \
    "\.\.\." \
    "test_files/edge_cases.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Match lines containing special characters" \
    "" \
    "[^a-zA-Z0-9]" \
    "test_files/edge_cases.txt" \
    "" \
    "" \
    "functionality"

  run_functionality "Match lines in csv files 1" \
    "" \
    "SF1AA2CA" \
    "test_files/csv1.csv" \
    "" \
    "" \
    "functionality"

  run_functionality "Match lines in csv files 2" \
    "" \
    "SF3QQ1CA" \
    "test_files/csv1.csv" \
    "" \
    "" \
    "functionality"

  run_functionality "Match lines in csv files 3" \
    "" \
    "SF3*" \
    "test_files/csv1.csv" \
    "" \
    "" \
    "functionality"

  run_functionality "Match lines in csv files 4" \
    "" \
    "result of climate" \
    "test_files/csv2.csv" \
    "" \
    "" \
    "functionality"

  run_functionality "Match lines in csv files 5" \
    "" \
    "exp*" \
    "test_files/csv2.csv" \
    "" \
    "" \
    "functionality"

  echo
  echo Running test cases for directory traversal and recursive search

  run_functionality "Simple recursive search" \
    "-r" \
    "error" \
    "$TEST_DIR" \
    "echo 'error: this is a sample line' > $TEST_DIR/test_file_1.txt && echo this is the second sample line > $TEST_DIR/test_file_2.txt" \
    "" \
    "functionality"

  run_functionality "Recursive search for error in test_files directory" \
    "-r" \
    "error" \
    "test_files" \
    "" \
    "" \
    "functionality"


  run_functionality "Recursive search for pattern in a huge directory" \
    "-r" \
    "pattern" \
    "$TEST_DIR" \
    "seq 1 $NUM_FILES | xargs -I {} sh -c 'echo pattern > $TEST_DIR/file_{}.txt'" \
    "" \
    "functionality"


  run_functionality "Recursive search for error in /etc directory" \
    "-r" \
    "error" \
    "/etc" \
    "" \
    "" \
    "functionality"
  
}

robustness_cases() {
  echo
  echo Running robustness test cases
  # Create a sample input file
  echo -e "Hello\nWorld\nGrep\nTest" > sample.txt

  # Pattern selection and interpretation flags
  run_robustness "Extended regexp" "-E" "(Hello|World)" "sample.txt" "" "" "robustness"
  run_robustness "Fixed strings" "-F" "Hello" "sample.txt" "" "" "robustness"
  run_robustness "Basic regexp" "-G" "^G.*p$" "sample.txt" "" "" "robustness"
  run_robustness "Perl regexp" "-P" "\w+\s" "sample.txt" "" "" "robustness"
  run_robustness "Regexp" "-e" "Hello" "sample.txt" "" "" "robustness"
  run_robustness "File with patterns" "-f" "patterns.txt" "sample.txt" "echo -e 'Hello\nWorld' > patterns.txt" "rm patterns.txt" "robustness"
  run_robustness "Ignore case" "-i" "hello" "sample.txt" "" "" "robustness"
  run_robustness "Word regexp" "-w" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Line regexp" "-x" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Null data" "-z" "Hello" "sample.txt" "" "" "robustness"

  # Miscellaneous flags
  run_robustness "No messages" "-s" "NonExistentPattern" "sample.txt" "" "" "robustness"
  run_robustness "Invert match" "-v" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Version" "-V" "" "" "" "" "robustness"
  run_robustness "Help" "--help" "" "" "" "" "robustness"

  # Output control flags
  run_robustness "Max count" "-m 2" "$TEST_DIR" "sample.txt" "" "" "robustness"
  run_robustness "Byte offset" "-b" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Line number" "-n" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Line buffered" "--line-buffered" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "With filename" "-H" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "No filename" "-h" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Label" "--label=CustomLabel" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Only matching" "-o" "Gre" "sample.txt" "" "" "robustness"
  run_robustness "Quiet" "-q" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Binary files" "--binary-files=text" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Text" "-a" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Binary files without match" "-I" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Directories" "-d recurse" "line" "$TEST_DIR/" "" "" "robustness"
  run_robustness "Devices" "-r -D read" "pattern" "$TEST_DIR/" "" "" "robustness"
  run_robustness "Dereference recursive" "-R" "Grep" "$TEST_DIR" "" "" "robustness"
  run_robustness "Include" "-r --include=$TEST_DIR/*.txt" "Grep" "$TEST_DIR/" "" "" "robustness"
  run_robustness "Exclude" "-r --exclude=$TEST_DIR/*.log" "Grep" "$TEST_DIR/" "" "" "robustness"
  run_robustness "Exclude from" "-r --exclude-from=$TEST_DIR/exclude.txt" "Grep" "$TEST_DIR/" "echo '*.log' > $TEST_DIR/exclude.txt" "rm $TEST_DIR/exclude.txt" "robustness"
  run_robustness "Exclude dir" "-r --exclude-dir=temp" "Grep" "$TEST_DIR/" "" "" "robustness"
  run_robustness "Files without match" "-L" "NonExistentPattern" "sample.txt" "" "" "robustness"
  run_robustness "Files with matches" "-l" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Count" "-c" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Initial tab" "-T" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Null" "-Z" "Grep" "sample.txt" "" "" "robustness"

  # Context control flags
  run_robustness "Before context" "-B 1" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "After context" "-A 1" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Context" "-C 1" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Numeric context" "-1" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Color" "--color=always" "Grep" "sample.txt" "" "" "robustness"
  run_robustness "Binary" "-U" "Grep" "sample.txt" "" "" "robustness"

  # Inexistent flag
  run_robustness "Inexistent flag" "-z" "Grep" "sample.txt" "" "" "robustness"

  for file in crash_inputs/*; do
    run_robustness "File: $file" "" "abc" "$file" "" "" "robustness"
  done
  # Clean up
  rm sample.txt
}

# Clean up test environment
cleanup() {
    rm -rf "$TEST_DIR" security_test_dir traversal_test debloated_grep original_grep test_files crash_inputs
}

main() {
  cleanup
  compile 

  mkdir -p "$TEST_DIR"
  cp -r ../test_files crash_inputs
  mkdir -p test_files
  mv crash_inputs/*.txt test_files/
  mv crash_inputs/*.csv test_files/

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

  # if [ $PASSED_TESTS -eq $TOTAL_TESTS ]; then
  #   echo All tests passed successfully.
  #   exit 0
  # fi
  # echo Some tests failed.
}

main