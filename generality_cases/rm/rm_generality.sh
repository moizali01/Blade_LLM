#!/bin/bash

DEBLOATED_FILE="rm-8.4.c"
ORIGINAL_FILE="rm-8.4.c"
CC=clang
DEBLOATED_RM="./debloated_rm"
ORIGINAL_RM="./original_rm"

# Directories and files for testing
TEST_DIR="rm_test_dir"
TEST_FILE="$TEST_DIR/rm_test_file.txt"
NUM_FILES=100
DEEP_DIR="$TEST_DIR/deep_dir"
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
  $CC -w $DEBLOATED_FILE -o debloated_rm
  if [ $? -ne 0 ]; then
    echo "Error: Compilation of $DEBLOATED_FILE failed"
    exit 1
  fi

  # Compile the original code
  $CC -w $ORIGINAL_FILE -o original_rm
  if [ $? -ne 0 ]; then
    echo "Error: Compilation of $ORIGINAL_FILE failed"
    exit 1
  fi

  # Check if executables exist
  if [ ! -f "$DEBLOATED_RM" ] || [ ! -f "$ORIGINAL_RM" ]; then
    echo "Error: One or both of the executables not found!"
    exit 1
  fi
}

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
  
  # echo "Running test: $description"
 
  # Setup test environment if needed
  eval "$setup_command"

  # Run on debloated file 
  { timeout "$TIMEOUT_VALUE" $DEBLOATED_RM $input_file; } >& /dev/null
  if [ $? -ne 0 ]; then
    eval "$cleanup_command"
    echo Fail: $description

    # echo "Error: Debloated program crashed!"
    return
  fi
  local debloated_ls=$(ls -a $TEST_DIR)
  
  eval "$cleanup_command"
  eval "$setup_command"
  
  # Run and capture output from original with timeout
  { timeout "$TIMEOUT_VALUE" $ORIGINAL_RM $input_file; } >& /dev/null
  if [ $? -ne 0 ]; then
    # echo "Error: Original program crashed!"
    # Do not consider this as a test case
    TOTAL_TESTS=$((TOTAL_TESTS - 1))
    eval "$cleanup_command"
    return
  fi
  local original_ls=$(ls -a $TEST_DIR)
 
  # Compare outputs
  if [[ "$debloated_ls" == "$original_ls" ]]; then
    echo "Pass: $description"
    if [ "$test_type" == "functionality" ]; then
      PASSED_FUNCTIONALITY_TESTS=$((PASSED_FUNCTIONALITY_TESTS + 1))
    elif [ "$test_type" == "security" ]; then
      PASSED_SECURITY_TESTS=$((PASSED_SECURITY_TESTS + 1))
    fi
  else
    echo "Fail: $description"
    # echo "Fail: $description" >> failed_tests.txt
    # echo "Debloated ls: $debloated_ls"
    # echo "Original ls: $original_ls"
    # echo "Debloated Output: $output_debloat"
    # echo "Original Output: $output_original"
  fi

  # Cleanup test environment if needed
  eval "$cleanup_command"
  
}

run_robustness() {
  local description="$1"
  local input_file="$2"
  local setup_command="$3"
  local cleanup_command="$4"

  TOTAL_ROBUSTNESS_TESTS=$((TOTAL_ROBUSTNESS_TESTS + 1))
  # echo "Running test: $description"

  # Setup test environment if needed
  eval "$setup_command"

  # Run the debloated program and see if it times out
  { timeout "$TIMEOUT_VALUE" $DEBLOATED_RM $input_file; } >& /dev/null
  a=$?
  if [ $a -ne 124 ]; then
    echo "Pass: $description"
    PASSED_ROBUSTNESS_TESTS=$((PASSED_ROBUSTNESS_TESTS + 1))
  else
    echo "Fail: $description"
  fi
  eval "$cleanup_command"
  
}

functionality_cases() {
  echo
  echo Functionality Cases
  run_functionality "Remove an empty file" \
  "$TEST_DIR/test_file_1.txt" \
  "mkdir -p $TEST_DIR; touch $TEST_DIR/test_file_1.txt" \
  "rm -rf $TEST_DIR/test_file_1.txt >& /dev/null" \
  "functionality"

  run_functionality "Remove an empty directory" \
  "-r $TEST_DIR/empty_dir" \
  "mkdir -p $TEST_DIR/empty_dir" \
  "rm -rf $TEST_DIR/empty_dir" \
  "functionality"
  
  run_functionality "Remove multiple files" \
  "-f $TEST_DIR/test_file_1.txt $TEST_DIR/test_file_2.txt $TEST_DIR/test_file_3.txt $TEST_DIR/test_file_4.txt $TEST_DIR/test_file_5.txt" \
  "mkdir -p $TEST_DIR; touch $TEST_DIR/test_file_{1..5}.txt" \
  "rm -f $TEST_DIR/test_file_{1..5}" \
  "functionality"

  run_functionality "Remove a directory recursively" \
  "-r $DEEP_DIR/" \
  "mkdir -p $DEEP_DIR; for i in \$(seq 1 10); do mkdir -p \"$DEEP_DIR/dir_\$i\"; touch \"$DEEP_DIR/dir_\$i/file_\$i.txt\"; done" \
  "rm -rf $DEEP_DIR/" \
  "functionality"

  run_functionality "Remove multiple directories with and without trailing slash recursively" \
  "-r $TEST_DIR/dir1/ $TEST_DIR/dir2 $TEST_DIR/dir3/ $TEST_DIR/dir4 $TEST_DIR/dir5" \
  "mkdir -p $TEST_DIR; mkdir -p $TEST_DIR/dir1 $TEST_DIR/dir2 $TEST_DIR/dir3 $TEST_DIR/dir4 $TEST_DIR/dir5" \
  "rm -rf $TEST_DIR/dir*" \
  "functionality"

  run_functionality "Remove files with special characters" \
  "-f $TEST_DIR/-!@#-$%^&*()_+-=[]{}|; :,.< >     ?.txt" \
  "mkdir -p $TEST_DIR; touch \"$TEST_DIR/-!@#-$%^&*()_+-=[]{}|; :,.< >     ?.txt\"" \
  "rm -f \"$TEST_DIR/-!@#-$%^&*()_+-=[]{}|; :,.< >     ?.txt\"" \
  "functionality"

  run_functionality "Remove files and folders with very long names" \
  "-rf $TEST_DIR/$(printf 'a%.0s' {1..250}).txt $TEST_DIR/$(printf 'b%.0s' {1..250})" \
  "mkdir -p $TEST_DIR; touch $TEST_DIR/$(printf 'a%.0s' {1..250}).txt; mkdir -p $TEST_DIR/$(printf 'b%.0s' {1..250})" \
  "rm -rf $TEST_DIR/$(printf 'a%.0s' {1..250}).txt; rm -rf $TEST_DIR/$(printf 'b%.0s' {1..250})" \
  "functionality"

  run_functionality "Remove hidden files" \
  "-f $TEST_DIR/.hidden_file" \
  "mkdir -p $TEST_DIR; touch $TEST_DIR/.hidden_file" \
  "rm -f $TEST_DIR/.hidden_file" \
  "functionality"

  run_functionality "Remove a big directory with big files" \
  "-rf $TEST_DIR/big_dir" \
  "mkdir -p $TEST_DIR; mkdir -p $TEST_DIR/big_dir; dd if=/dev/zero of='$TEST_DIR/big_dir/big_file' bs=1M count=1000 >& /dev/null; for i in \$(seq 1 $NUM_FILES); do touch $TEST_DIR/big_dir/file_\$i.txt && mkdir -p $TEST_DIR/big_dir/dir_\$i; done" \
  "rm -rf $TEST_DIR/big_dir" \
  "functionality"

  run_functionality "Remove files and directories using wildcard notation" \
  "-rf $TEST_DIR/*" \
  "mkdir -p $TEST_DIR; touch $TEST_DIR/test_file_{1..5}.txt; mkdir -p $TEST_DIR/dir_{1..5}" \
  "rm -rf $TEST_DIR/*" \
  "functionality"

  for file in test_files/* ; do
    run_functionality "File: $file" \
    "$TEST_DIR/$(basename $file)" \
    "cp $file $TEST_DIR/" \
    "rm -rf $TEST_DIR/$(basename $file)" \
    "functionality"
  done 

  run_functionality "Remove the test_filess directory" \
  "-rf $TEST_DIR/test_files" \
  "cp -r test_files $TEST_DIR/" \
  "rm -rf $TEST_DIR/test_files" \
  "functionality"

}

security_cases() {
  echo
  echo Security Cases
  run_functionality "Force remove file without any permissions" \
  "-rf $TEST_DIR/no_perms_file" \
  "touch $TEST_DIR/no_perms_file; chmod 000 $TEST_DIR/no_perms_file" \
  "chmod 777 $TEST_DIR/no_perms_file >& /dev/null; rm -f $TEST_DIR/no_perms_file" \
  "security"

  run_functionality "Force remove directory without any permissions" \
  "-rf $DEEP_DIR $TEST_DIR/no_perms" \
  "mkdir -p $DEEP_DIR; chmod 000 $DEEP_DIR; touch $TEST_DIR/no_perms; chmod 000 $TEST_DIR/no_perms" \
  "chmod 777 $DEEP_DIR $TEST_DIR/no_perms >& /dev/null; rm -rf $DEEP_DIR $TEST_DIR/no_perms" \
  "security"


  run_functionality "Remove files and directories with sticky bit set" \
  "-rf $TEST_DIR/sticky_dir" \
  "mkdir -p $TEST_DIR/sticky_dir; touch $TEST_DIR/sticky_dir/file; chmod +t $TEST_DIR/sticky_dir" \
  "chmod -t $TEST_DIR/sticky_dir >& /dev/null; rm -rf $TEST_DIR/sticky_dir" \
  "security"

  run_functionality "Remove symbolic link" \
  "-f $TEST_DIR/symlink" \
  "touch $TEST_DIR/test_file_1; ln -s $TEST_DIR/test_file_1.txt $TEST_DIR/symlink" \
  "rm -f $TEST_DIR/test_file_1.txt" \
  "security"

  run_functionality "Remove broken symbolic link" \
  "-f $TEST_DIR/broken_symlink" \
  "ln -s $TEST_DIR/nonexistent_file $TEST_DIR/broken_symlink" \
  "rm -f $TEST_DIR/broken_symlink" \
  "security"

}

robustness_cases() {
  echo
  echo Robustness Cases
  run_robustness "Remove a file that does not exist" \
  "$TEST_DIR/nonexistent_file" \
  "" \
  ""

  run_robustness "Remove a directory that does not exist" \
  "-r $TEST_DIR/nonexistent_dir" \
  "" \
  ""

  run_robustness "Invalid flag I" \
  "-I $TEST_DIR/test_file_1.txt" \
  "touch $TEST_DIR/test_file_1.txt" \
  "rm -f $TEST_DIR/test_file_1.txt"

  run_robustness "Invalid flag -v" \
  "-v $TEST_DIR/test_file_1.txt" \
  "touch $TEST_DIR/test_file_1.txt" \
  "rm -f $TEST_DIR/test_file_1.txt"

  run_robustness "Invalid flag help" \
  "--help $TEST_DIR/test_file_1.txt" \
  "touch $TEST_DIR/test_file_1.txt" \
  "rm -f $TEST_DIR/test_file_1.txt"

  run_robustness "Invalid flag --version" \
  "--version $TEST_DIR/test_file_1.txt" \
  "touch $TEST_DIR/test_file_1.txt" \
  "rm -f $TEST_DIR/test_file_1.txt" 

  run_robustness "Inexistent flag" \
  "-z $TEST_DIR/test_file_1.txt" \
  "touch $TEST_DIR/test_file_1.txt" \
  "rm -f $TEST_DIR/test_file_1.txt"


}


# Clean up test environment
cleanup() {
  rm -rf "$TEST_DIR" test_files
  rm -f debloated_rm original_rm 
}

main() {
  cleanup
  compile

  mkdir -p $TEST_DIR
  cp -r ../test_files .
  # Run the test cases
  functionality_cases
  security_cases
  robustness_cases

  # Clean up
  cleanup
  
  # Summary
  echo
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

