#!/bin/bash

ORIGINAL_FILE="uniq-og.c"
DEBLOATED_FILE="uniq-covl.c"
CC=clang
DEBLOATED_UNIQ="./debloated_uniq"
ORIGINAL_UNIQ="./original_uniq"

# Directories and files for testing
TEST_DIR="uniq_test_dir"
INPUT_FILE="$TEST_DIR/input.txt"
OUTPUT_DEBLOATED="$TEST_DIR/output_debloat.txt"
OUTPUT_ORIGINAL="$TEST_DIR/output_original.txt"
TIMEOUT_VALUE=3

# Counters for tests
TOTAL_FUNCTIONALITY_TESTS=0
PASSED_FUNCTIONALITY_TESTS=0

TOTAL_SECURITY_TESTS=0
PASSED_SECURITY_TESTS=0

TOTAL_ROBUSTNESS_TESTS=0
PASSED_ROBUSTNESS_TESTS=0

compile() {
  # Compile the debloated code
  $CC -w $DEBLOATED_FILE -o debloated_uniq
  if [ $? -ne 0 ]; then
    echo "Error: Compilation of $DEBLOATED_FILE failed"
    exit 1
  fi

  # Compile the original code
  $CC -w $ORIGINAL_FILE -o original_uniq
  if [ $? -ne 0 ]; then
    echo "Error: Compilation of $ORIGINAL_FILE failed"
    exit 1
  fi
  # Check if executables exist
  if [ ! -f "$DEBLOATED_UNIQ" ] || [ ! -f "$ORIGINAL_UNIQ" ]; then
    echo "Error: One or both of the executables not found!"
    exit 1
  fi
}

# Function to generate a random string
generate_random_string() {
    cat /dev/urandom | tr -dc 'a-zA-Z0-9' | fold -w 32 | head -n 1
}

# Function to generate a file with unique random lines
generate_unique_random_lines() {
    local num_lines=$1
    local output_file=$2
    
    for i in $(seq 1 $num_lines); do
        generate_random_string >> "$output_file"
    done
    
    # Sort and remove any potential duplicates (extremely unlikely, but just to be sure)
    sort -u "$output_file" -o "$output_file"
}

# Function to run a single test case
run_functionality() {
  local description="$1"
  local input_file="$2"
  local setup_command="$3"
  local cleanup_command="$4"
  local test_type="$5"

  if [ "$test_type" == "functionality" ]; then
    TOTAL_FUNCTIONALITY_TESTS=$((TOTAL_FUNCTIONALITY_TESTS + 1))
  elif [ "$test_type" == "security" ]; then
    TOTAL_SECURITY_TESTS=$((TOTAL_SECURITY_TESTS + 1))
  fi  

  echo "Running test: $description"
  
  # Setup test environment if needed
  eval "$setup_command"
  
  timeout "$TIMEOUT_VALUE" $DEBLOATED_UNIQ "$input_file" >& "$OUTPUT_DEBLOATED" 
  if [ $? -ne 0 ]; then
    eval "$cleanup_command"
    echo Fail
    # echo "Error: Debloated program crashed!"
    echo
    return
  fi
  
  # Run the original program and suppress stderr
  timeout "$TIMEOUT_VALUE" $ORIGINAL_UNIQ "$input_file" >& "$OUTPUT_ORIGINAL"
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
    echo "Pass"
    PASSED_TESTS=$((PASSED_TESTS + 1))
    if [ "$test_type" == "functionality" ]; then
      PASSED_FUNCTIONALITY_TESTS=$((PASSED_FUNCTIONALITY_TESTS + 1))
    elif [ "$test_type" == "security" ]; then
      PASSED_SECURITY_TESTS=$((PASSED_SECURITY_TESTS + 1))
    fi
  else
    echo "Fail"
  fi
  
  # Cleanup test environment if needed
  eval "$cleanup_command"
  echo
}

run_robustness() {
  local description="$1"
  local input_file="$2"
  local setup_command="$3"
  local cleanup_command="$4"

  TOTAL_ROBUSTNESS_TESTS=$((TOTAL_ROBUSTNESS_TESTS + 1))
  echo "Running test: $description"

  # Setup test environment if needed
  eval "$setup_command"

  # Run the debloated program and see if it times out
  { timeout "$TIMEOUT_VALUE" $DEBLOATED_UNIQ $input_file; } >& $OUTPUT_DEBLOATED
  a=$?
  if [ $a -ne 124 ]; then
    echo "Pass"
    PASSED_ROBUSTNESS_TESTS=$((PASSED_ROBUSTNESS_TESTS + 1))
  else
    echo "Fail"
  fi
  eval "$cleanup_command"
  echo
}

functionality_cases() {
  run_functionality "File with extremely long lines" \
  "$TEST_DIR/extremely_long_lines" \
  "echo -e \"$(printf '%0.s1' {1..100000})\n$(printf '%0.s2' {1..100000})\n$(printf '%0.s3' {1..100000})\" > $TEST_DIR/extremely_long_lines" \
  "rm -rf $TEST_DIR/extremely_long_lines" \
  "functionality"

  run_functionality "File with extremely long name" \
  "$(pwd)/$TEST_DIR/$(printf 'a%.0s' {1..250}).txt" \
  "echo -e \"apple\napple\nbanana\ncherry\" > $TEST_DIR/$(printf 'a%.0s' {1..250}).txt" \
  "rm -rf $TEST_DIR/$(printf 'a%.0s' {1..250}).txt" \
  "functionality"


  run_functionality "File with all special characters in name" \
  "$TEST_DIR/!@#$%^&*()_+-=[]{}|; :,.< >?.txt" \
  "echo -e \"apple\napple\nbanana\ncherry\" > \"$TEST_DIR/!@#$%^&*()_+-=[]{}|; :,.< >?.txt\"" \
  "rm -rf \"$TEST_DIR/!@#$%^&*()_+-=[]{}|; :,.< >?.txt\"" \
  "functionality"

  run_functionality "File with unexpected inputs" \
  "$TEST_DIR/comprehensive_test" \
  "cp test_files/comprehensive_test $TEST_DIR/" \
  "rm -rf $TEST_DIR/comprehensive_test" \
  "functionality"


  for file in test_files/*.txt; do
    run_functionality "File: $file" \
    "$TEST_DIR/$(basename $file)" \
    "cp $file $TEST_DIR/" \
    "rm -rf $TEST_DIR/$(basename $file)" \
    "functionality"
  done  

}

security_cases() {
  run_functionality "Read from read-only file" \
  "$TEST_DIR/readonly_file" \
  "echo -e \"apple\napple\nbanana\ncherry\" > $TEST_DIR/readonly_file && chmod 444 $TEST_DIR/readonly_file" \
  "chmod 644 $TEST_DIR/readonly_file && rm -rf $TEST_DIR/readonly_file" \
  "security"

  # run_functionality "File in directory without read permission" \
  #   "$TEST_DIR/no_read_dir/file" \
  #   "mkdir -p $TEST_DIR/no_read_dir && echo -e \"apple\napple\nbanana\ncherry\" > $TEST_DIR/no_read_dir/file && chmod 000 $TEST_DIR/no_read_dir" \
  #   "chmod 700 $TEST_DIR/no_read_dir && rm -rf $TEST_DIR/no_read_dir" \
  #   "security"

  run_functionality "File with setuid bit" \
    "$TEST_DIR/setuid_file" \
    "echo -e \"apple\napple\nbanana\ncherry\" > $TEST_DIR/setuid_file && chmod u+s $TEST_DIR/setuid_file" \
    "chmod u-s $TEST_DIR/setuid_file && rm -rf $TEST_DIR/setuid_file" \
    "security"

  run_functionality "File with setgid bit" \
    "$TEST_DIR/setgid_file" \
    "echo -e \"apple\napple\nbanana\ncherry\" > $TEST_DIR/setgid_file && chmod g+s $TEST_DIR/setgid_file" \
    "chmod g-s $TEST_DIR/setgid_file && rm -rf $TEST_DIR/setgid_file" \
    "security"

  run_functionality "File in sticky bit directory" \
    "$TEST_DIR/sticky_dir/file" \
    "mkdir -p $TEST_DIR/sticky_dir && echo -e \"apple\napple\nbanana\ncherry\" > $TEST_DIR/sticky_dir/file && chmod +t $TEST_DIR/sticky_dir" \
    "chmod -t $TEST_DIR/sticky_dir && rm -rf $TEST_DIR/sticky_dir" \
    "security"

  run_functionality "File with potential buffer overflow input" \
    "$TEST_DIR/buffer_overflow" \
    "echo -e \"$(printf '%0.s1' {1..1000000})\n$(printf '%0.s2' {1..1000000})\" > $TEST_DIR/buffer_overflow" \
    "rm -rf $TEST_DIR/buffer_overflow" \
    "security"

  run_functionality "File with potential format string input" \
    "$TEST_DIR/format_string" \
    "echo -e \"%s\n%s\n%s\n%s\" > $TEST_DIR/format_string" \
    "rm -rf $TEST_DIR/format_string" \
    "security"

  run_functionality "File with maximum allowed filename length" \
    "$TEST_DIR/$(printf 'a%.0s' {1..255})" \
    "echo -e \"apple\napple\nbanana\ncherry\" > $TEST_DIR/$(printf 'a%.0s' {1..255})" \
    "rm -rf $TEST_DIR/$(printf 'a%.0s' {1..255})" \
    "security"


}

robustness_cases() {
  run_robustness "Invalid flag c" \
  "-c $TEST_DIR/invalid_flag" \
  "echo -e \"apple\napple\nbanana\ncherry\" > $TEST_DIR/invalid_flag" \
  ""

  run_robustness "Invalid flag d" \
  "-d $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid flag D" \
  "-D $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid flag f" \
  "-f $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid flag i" \
  "-i $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid flag s" \
  "-s $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid flag u" \
  "-u $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid flag z" \
  "-z $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid flag w" \
  "-w $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid flag help" \
  "--help" \
  "" ""

  run_robustness "Invalid flag version" \
  "--version" \
  "" ""

  run_robustness "Invalid flag x" \
  "-x $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid multiple flags together" \
  "-cdf $TEST_DIR/invalid_flag" \
  "" ""

  run_robustness "Invalid multiple flags seperately" \
  "-D -c -i -u $TEST_DIR/invalid_flag" \
  "" "rm -rf $TEST_DIR/invalid_flag"


  for file in crash_inputs/*; do
    run_robustness "File: $file" \
    "$TEST_DIR/$(basename $file)" \
    "cp $file $TEST_DIR/" \
    "rm -rf $TEST_DIR/$(basename $file)"
  done  

}


# Clean up test environment
cleanup() {
  rm -rf "$TEST_DIR"
  rm -f debloated_uniq original_uniq
}

main() {

  cleanup
  compile

  # Create the test directory
  mkdir -p "$TEST_DIR"

  # Run the test cases
  functionality_cases
  security_cases
  robustness_cases

  # Clean up
  cleanup
  
  # Summary
  echo "Functionality tests run: $TOTAL_FUNCTIONALITY_TESTS"
  echo "Functionality tests passed: $PASSED_FUNCTIONALITY_TESTS"
  echo "Percentage functionality tests passed: $((PASSED_FUNCTIONALITY_TESTS * 100 / TOTAL_FUNCTIONALITY_TESTS))%"
  echo
  echo "Security tests run: $TOTAL_SECURITY_TESTS"
  echo "Security tests passed: $PASSED_SECURITY_TESTS"
  echo "Percentage security tests passed: $((PASSED_SECURITY_TESTS * 100 / TOTAL_SECURITY_TESTS))%" 
  echo
  echo "Robustness tests run: $TOTAL_ROBUSTNESS_TESTS"
  echo "Robustness tests passed: $PASSED_ROBUSTNESS_TESTS"
  echo "Percentage robustness tests passed: $((PASSED_ROBUSTNESS_TESTS * 100 / TOTAL_ROBUSTNESS_TESTS))%"

}

main

