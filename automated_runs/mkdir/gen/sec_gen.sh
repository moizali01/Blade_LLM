#!/bin/bash

ORIGINAL_FILE="mkdir-5.2.1.c.origin.c"
DEBLOATED_FILE="mkdir-debloated.c.blade.c"


CC=clang

# Compile the debloated code
$CC -w $DEBLOATED_FILE -o debloated_mkdir
if [ $? -ne 0 ]; then
  echo "Error: Compilation of $DEBLOATED_FILE failed"
  exit 1
fi

# Compile the original code
$CC -w $ORIGINAL_FILE -o original_mkdir
if [ $? -ne 0 ]; then
  echo "Error: Compilation of $ORIGINAL_FILE failed"
  exit 1
fi

# Path to the executables
DEBLOATED_MKDIR="./debloated_mkdir"
ORIGINAL_MKDIR="./original_mkdir"

# Directories and files for testing
TEST_DIR="mkdir_test_dir"
OUTPUT_DEBLOATED="$TEST_DIR/output_debloat.txt"
OUTPUT_ORIGINAL="$TEST_DIR/output_original.txt"

# Counters for tests
TOTAL_TESTS=0
PASSED_TESTS=0

# Check if executables exist
if [ ! -f "$DEBLOATED_MKDIR" ] || [ ! -f "$ORIGINAL_MKDIR" ]; then
  echo "Error: One or both of the executables not found!"
  exit 1
fi

# Function to run a single test case
run_test() {
  local description="$1"
  local args="$2"
  local setup_command="$3"
  local cleanup_command="$4"
  local expect_failure="${5:-0}"

  TOTAL_TESTS=$((TOTAL_TESTS + 1))
  echo "Running test: $description"

  # Setup test environment if needed
  eval "$setup_command"

  # Run and capture output from the original binary
  $ORIGINAL_MKDIR $args > "$OUTPUT_ORIGINAL" 2>&1
  local original_exit_code=$?

  # Cleanup test environment after running the original binary
  eval "$cleanup_command"

  # Setup test environment again if needed
  eval "$setup_command"

  # Run and capture output from the debloated binary
  $DEBLOATED_MKDIR $args > "$OUTPUT_DEBLOATED" 2>&1
  local debloated_exit_code=$?

  # Compare outputs or exit codes based on expectation
  if [ "$expect_failure" -eq 1 ]; then
    if [ $original_exit_code -ne 0 ] && [ $debloated_exit_code -ne 0 ]; then
      echo "Pass"
      PASSED_TESTS=$((PASSED_TESTS + 1))
    else
      echo "Fail"
      cat "$OUTPUT_DEBLOATED"
      cat "$OUTPUT_ORIGINAL"
    fi
  else
    if cmp -s "$OUTPUT_DEBLOATED" "$OUTPUT_ORIGINAL" && [ $original_exit_code -eq $debloated_exit_code ]; then
      echo "Pass"
      PASSED_TESTS=$((PASSED_TESTS + 1))
    else
      echo "Fail"
      cat "$OUTPUT_DEBLOATED"
      cat "$OUTPUT_ORIGINAL"
    fi
  fi

  # Final cleanup of the test environment
  eval "$cleanup_command"
  echo
}

# Setup test environment
setup() {
  rm -rf "$TEST_DIR"
  mkdir -p "$TEST_DIR"
}

# Clean up test environment
cleanup() {
  rm -rf "$TEST_DIR"
}

# Run tests
setup

# Functionality tests related to the -m flag
run_test "Create directory with specific permissions using -m" \
  "-m 755 $TEST_DIR/dir1" \
  "" \
  "rm -rf $TEST_DIR/dir1"

run_test "Create directory with restricted permissions using -m" \
  "-m 700 $TEST_DIR/dir2" \
  "" \
  "rm -rf $TEST_DIR/dir2"

run_test "Create directory with all permissions using -m" \
  "-m 777 $TEST_DIR/dir3" \
  "" \
  "rm -rf $TEST_DIR/dir3"

# Error and exception checks
run_test "Attempt to create directory without permissions" \
  "-m 000 $TEST_DIR/dir4" \
  "" \
  "chmod 755 $TEST_DIR/dir4 && rm -rf $TEST_DIR/dir4"

run_test "Create directory in read-only directory" \
  "$TEST_DIR/read_only_dir/dir5" \
  "mkdir $TEST_DIR/read_only_dir && chmod 555 $TEST_DIR/read_only_dir" \
  "chmod 755 $TEST_DIR/read_only_dir && rm -rf $TEST_DIR/read_only_dir"

run_test "Create directory with invalid permissions using -m" \
  "-m 999 $TEST_DIR/dir6" \
  "" \
  "rm -rf $TEST_DIR/dir6" \
  1

run_test "Create directory with a very long name" \
  "$TEST_DIR/$(printf 'a%.0s' {1..255})" \
  "" \
  "rm -rf \"$TEST_DIR/$(printf 'a%.0s' {1..255})\""

run_test "Create directory with existing permissions using -m" \
  "-m 755 $TEST_DIR/dir7" \
  "mkdir $TEST_DIR/dir7 && chmod 755 $TEST_DIR/dir7" \
  "rm -rf $TEST_DIR/dir7" \
  1

run_test "Create directory with same name as existing file" \
  "$TEST_DIR/dir8" \
  "touch $TEST_DIR/dir8" \
  "rm -f $TEST_DIR/dir8" \
  1

run_test "Create directory without specifying -m flag (default permissions)" \
  "$TEST_DIR/dir9" \
  "" \
  "rm -rf $TEST_DIR/dir9"

run_test "Create directory with excessive permissions using -m" \
  "-m 1777 $TEST_DIR/dir10" \
  "" \
  "rm -rf $TEST_DIR/dir10"

run_test "Create directory with backslash in the name" \
  "$TEST_DIR/dir\\with\\backslash" \
  "" \
  "rm -rf \"$TEST_DIR/dir\\with\\backslash\""

# Summary
cleanup
echo "Tests run: $TOTAL_TESTS"
echo "Tests passed: $PASSED_TESTS"
cleanup
