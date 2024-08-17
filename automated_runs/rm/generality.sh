#!/bin/bash

DEBLOATED_FILE="deb.c.blade.c"
ORIGINAL_FILE="rm-8.4.c.origin.c"
CC=clang

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

# Path to the executables
DEBLOATED_RM="./debloated_rm"
ORIGINAL_RM="./original_rm"

# Directories and files for testing
TEST_DIR="rm_test_dir"
TEST_FILE="$TEST_DIR/rm_test_file.txt"
NUM_FILES=100
DEEP_DIR="$TEST_DIR/deep_dir"

# Counters for tests
TOTAL_TESTS=0
PASSED_TESTS=0

# Check if executables exist
if [ ! -f "$DEBLOATED_RM" ] || [ ! -f "$ORIGINAL_RM" ]; then
  echo "Error: One or both of the executables not found!"
  exit 1
fi

run_test() {
  local description="$1"
  local command_debloat="$2"
  local command_original="$3"
  local setup_command="$4"
  local cleanup_command="$5"
 
  TOTAL_TESTS=$((TOTAL_TESTS + 1))
  echo "Running test: $description"
 
  # Setup test environment if needed
  eval "$setup_command"

  # Run and capture output from both debloated and original
  output_debloat=$(eval "$command_debloat" 2>&1)
  if [[ $? -ne 0 ]]; then
    output_debloat="Error: $output_debloat"
  fi
  local debloated_ls=$(ls -a $TEST_DIR)
  eval "$cleanup_command"
  eval "$setup_command"
  output_original=$(eval "$command_original" 2>&1)
  if [[ $? -ne 0 ]]; then
    output_original="Error: $output_original"
  fi
  local original_ls=$(ls -a $TEST_DIR)
 
  # Compare outputs
  # remove binary name from the error and keep the remaining error
  # output_debloat=$(echo "$output_debloat" | sed "s/.*debloated_rm: //")
  # output_original=$(echo "$output_original" | sed "s/.*original_rm: //")
  # if [[ "$output_debloat" == "$output_original" ]]; then
  if [[ "$debloated_ls" == "$original_ls" ]]; then
    echo "Pass"
    PASSED_TESTS=$((PASSED_TESTS + 1))
  else
    echo "Fail: $description ">>failed_tests.txt
    echo "Debloated ls: $debloated_ls"
    echo "Original ls: $original_ls"
  fi
  # else
    # echo "Fail: "
    # echo "Debloated Output: $output_debloat"
    # echo "Original Output: $output_original"
  # fi
  echo

  # Cleanup test environment if needed
  eval "$cleanup_command"
}

# Setup test environment
setup() {
  rm -rf "$TEST_DIR"
  mkdir -p "$TEST_DIR"
  for i in $(seq 1 $NUM_FILES); do
    touch "$TEST_DIR/test_file_$i.txt"
  done
  mkdir -p "$DEEP_DIR"
  for i in $(seq 1 10); do
    mkdir -p "$DEEP_DIR/dir_$i"
    touch "$DEEP_DIR/dir_$i/file_$i.txt"
  done
}

# Clean up test environment
cleanup() {
  rm -rf "$TEST_DIR"
  rm -f debloated_rm original_rm
}

# Run tests
setup

run_test "Remove single file" \
  "$DEBLOATED_RM -f $TEST_DIR/test_file_1.txt" \
  "$ORIGINAL_RM -f $TEST_DIR/test_file_1.txt" \
  "mkdir -p $TEST_DIR; touch $TEST_DIR/test_file_1.txt" \
  "rm -f $TEST_DIR/test_file_1.txt"

run_test "Remove multiple files" \
  "$DEBLOATED_RM -f $TEST_DIR/test_file_{2..10}.txt" \
  "$ORIGINAL_RM -f $TEST_DIR/test_file_{2..10}.txt" \
  "mkdir -p $TEST_DIR; touch $TEST_DIR/test_file_{2..10}.txt" \
  "rm -f $TEST_DIR/test_file_{2..10}"

run_test "Remove directory recursively" \
  "$DEBLOATED_RM -rf $DEEP_DIR" \
  "$ORIGINAL_RM -rf $DEEP_DIR" \
  "mkdir -p $DEEP_DIR; for i in \$(seq 1 10); do mkdir -p \"$DEEP_DIR/dir_\$i\"; touch \"$DEEP_DIR/dir_\$i/file_\$i.txt\"; done" \
  "rm -rf $DEEP_DIR"

run_test "Remove non-existent file with force" \
  "$DEBLOATED_RM -f $TEST_DIR/non_existent_file.txt" \
  "$ORIGINAL_RM -f $TEST_DIR/non_existent_file.txt" \
  "" ""

run_test "Remove directory with trailing slash" \
  "$DEBLOATED_RM -rf $DEEP_DIR/" \
  "$ORIGINAL_RM -rf $DEEP_DIR/" \
  "mkdir -p $DEEP_DIR; for i in \$(seq 1 10); do mkdir -p \"$DEEP_DIR/dir_\$i\"; touch \"$DEEP_DIR/dir_\$i/file_\$i.txt\"; done" \
  "rm -rf $DEEP_DIR"

run_test "Remove directory without write permission" \
  "$DEBLOATED_RM -rf $DEEP_DIR" \
  "$ORIGINAL_RM -rf $DEEP_DIR" \
  "mkdir -p $DEEP_DIR; chmod -w $DEEP_DIR" \
  "chmod +w $DEEP_DIR >& /dev/null; rm -rf $DEEP_DIR"

run_test "Remove files with spaces in names" \
  "$DEBLOATED_RM -f '$TEST_DIR/file with spaces 1.txt' '$TEST_DIR/file with spaces 2.txt'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file with spaces 1.txt' '$TEST_DIR/file with spaces 2.txt'" \
  "touch '$TEST_DIR/file with spaces 1.txt' '$TEST_DIR/file with spaces 2.txt'" \
  "rm -f '$TEST_DIR/file with spaces 1.txt' '$TEST_DIR/file with spaces 2.txt'"

run_test "Remove deeply nested directory" \
  "$DEBLOATED_RM -rf $TEST_DIR/deep_nested_dir" \
  "$ORIGINAL_RM -rf $TEST_DIR/deep_nested_dir" \
  "mkdir -p $TEST_DIR/deep_nested_dir; for i in \$(seq 1 100); do mkdir -p \"$TEST_DIR/deep_nested_dir/dir_\$i\"; touch \"$TEST_DIR/deep_nested_dir/dir_\$i/file_\$i.txt\"; done" \
  "rm -rf $TEST_DIR/deep_nested_dir"

run_test "Remove files with special characters" \
  "$DEBLOATED_RM -f '$TEST_DIR/file_@!.txt'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file_@!.txt'" \
  "touch '$TEST_DIR/file_@!.txt'" \
  "rm -f '$TEST_DIR/file_@!.txt'"

run_test "Remove symbolic link" \
  "$DEBLOATED_RM -f $TEST_DIR/symlink" \
  "$ORIGINAL_RM -f $TEST_DIR/symlink" \
  "ln -s $TEST_DIR/test_file_1.txt $TEST_DIR/symlink" \
  "rm -f $TEST_DIR/test_file_1.txt"

run_test "Remove empty directory" \
  "$DEBLOATED_RM -rf $TEST_DIR/empty_dir" \
  "$ORIGINAL_RM -rf $TEST_DIR/empty_dir" \
  "mkdir -p $TEST_DIR/empty_dir" \
  "rm -rf $TEST_DIR/empty_dir"

run_test "Remove directory with hidden files" \
  "$DEBLOATED_RM -rf $TEST_DIR/hidden_dir" \
  "$ORIGINAL_RM -rf $TEST_DIR/hidden_dir" \
  "mkdir -p $TEST_DIR/hidden_dir; touch $TEST_DIR/hidden_dir/.hidden_file" \
  "rm -rf $TEST_DIR/hidden_dir"

run_test "Remove read-only files" \
  "$DEBLOATED_RM -f $TEST_DIR/read_only_file" \
  "$ORIGINAL_RM -f $TEST_DIR/read_only_file" \
  "touch $TEST_DIR/read_only_file; chmod -w $TEST_DIR/read_only_file" \
  "chmod +w $TEST_DIR/read_only_file >& /dev/null; rm -f $TEST_DIR/read_only_file"

run_test "Remove files in read-only directory" \
  "$DEBLOATED_RM -rf $TEST_DIR/read_only_dir" \
  "$ORIGINAL_RM -rf $TEST_DIR/read_only_dir" \
  "mkdir -p $TEST_DIR/read_only_dir; touch $TEST_DIR/read_only_dir/file1; chmod -w $TEST_DIR/read_only_dir" \
  "chmod +w $TEST_DIR/read_only_dir >& /dev/null; rm -rf $TEST_DIR/read_only_dir"

run_test "Remove files in nested read-only directory" \
  "$DEBLOATED_RM -rf $TEST_DIR/nested_read_only_dir" \
  "$ORIGINAL_RM -rf $TEST_DIR/nested_read_only_dir" \
  "mkdir -p $TEST_DIR/nested_read_only_dir/subdir; touch $TEST_DIR/nested_read_only_dir/subdir/file; chmod -w $TEST_DIR/nested_read_only_dir/subdir" \
  "chmod +w $TEST_DIR/nested_read_only_dir/subdir >& /dev/null; rm -rf $TEST_DIR/nested_read_only_dir"

run_test "Remove files with null character in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file_with_null\0character'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file_with_null\0character'" \
  "touch '$TEST_DIR/file_with_null\0character'" \
  "rm -f '$TEST_DIR/file_with_null\0character'"

run_test "Remove directory with subdirectories and files" \
  "$DEBLOATED_RM -rf $TEST_DIR/subdirs" \
  "$ORIGINAL_RM -rf $TEST_DIR/subdirs" \
  "mkdir -p $TEST_DIR/subdirs/subdir1 $TEST_DIR/subdirs/subdir2; touch $TEST_DIR/subdirs/subdir1/file1.txt $TEST_DIR/subdirs/subdir2/file2.txt" \
  "rm -rf $TEST_DIR/subdirs"

run_test "Remove files with special permissions" \
  "$DEBLOATED_RM -f $TEST_DIR/special_perms_file" \
  "$ORIGINAL_RM -f $TEST_DIR/special_perms_file" \
  "touch $TEST_DIR/special_perms_file; chmod +s $TEST_DIR/special_perms_file" \
  "chmod -s $TEST_DIR/special_perms_file >& /dev/null; rm -f $TEST_DIR/special_perms_file"

run_test "Remove files in a directory with sticky bit set" \
  "$DEBLOATED_RM -rf $TEST_DIR/sticky_bit_dir" \
  "$ORIGINAL_RM -rf $TEST_DIR/sticky_bit_dir" \
  "mkdir -p $TEST_DIR/sticky_bit_dir; chmod +t $TEST_DIR/sticky_bit_dir; touch $TEST_DIR/sticky_bit_dir/file" \
  "chmod -t $TEST_DIR/sticky_bit_dir >& /dev/null; rm -rf $TEST_DIR/sticky_bit_dir"

run_test "Remove files after changing working directory" \
  "(cd $TEST_DIR && $(pwd)/debloated_rm -f test_file_2.txt)" \
  "(cd $TEST_DIR && $(pwd)/original_rm -f test_file_2.txt)" \
  "touch $TEST_DIR/test_file_2.txt" \
  "rm -f $TEST_DIR/test_file_2.txt"

run_test "Remove files using absolute paths" \
  "$DEBLOATED_RM -f $(pwd)/$TEST_DIR/test_file_3.txt" \
  "$ORIGINAL_RM -f $(pwd)/$TEST_DIR/test_file_3.txt" \
  "touch $TEST_DIR/test_file_3.txt" \
  "rm -f $TEST_DIR/test_file_3.txt"

run_test "Remove directory containing only empty subdirectories" \
  "$DEBLOATED_RM -rf $TEST_DIR/empty_subdirs" \
  "$ORIGINAL_RM -rf $TEST_DIR/empty_subdirs" \
  "mkdir -p $TEST_DIR/empty_subdirs/subdir1 $TEST_DIR/empty_subdirs/subdir2" \
  "rm -rf $TEST_DIR/empty_subdirs"
run_test "Remove file with spaces in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file with spaces.txt'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file with spaces.txt'" \
  "touch '$TEST_DIR/file with spaces.txt'" \
  "rm -f '$TEST_DIR/file with spaces.txt'"

run_test "Remove file with special characters" \
  "$DEBLOATED_RM -f '$TEST_DIR/file!@#$%^&*.txt'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file!@#$%^&*.txt'" \
  "touch '$TEST_DIR/file!@#$%^&*.txt'" \
  "rm -f '$TEST_DIR/file!@#$%^&*.txt'"

run_test "Remove file with very long name" \
  "$DEBLOATED_RM -f '$TEST_DIR/$(printf 'a%.0s' {1..251}).txt'" \
  "$ORIGINAL_RM -f '$TEST_DIR/$(printf 'a%.0s' {1..251}).txt'" \
  "touch '$TEST_DIR/$(printf 'a%.0s' {1..251}).txt'" \
  "rm -f '$TEST_DIR/$(printf 'a%.0s' {1..251}).txt'"

run_test "Remove hidden file" \
  "$DEBLOATED_RM -f '$TEST_DIR/.hidden_file'" \
  "$ORIGINAL_RM -f '$TEST_DIR/.hidden_file'" \
  "touch '$TEST_DIR/.hidden_file'" \
  "rm -f '$TEST_DIR/.hidden_file'"

run_test "Remove file with no read permissions" \
  "$DEBLOATED_RM -f '$TEST_DIR/no_read_file'" \
  "$ORIGINAL_RM -f '$TEST_DIR/no_read_file'" \
  "touch '$TEST_DIR/no_read_file' && chmod -r '$TEST_DIR/no_read_file'" \
  "rm -f '$TEST_DIR/no_read_file'"

run_test "Remove file with no write permissions" \
  "$DEBLOATED_RM -f '$TEST_DIR/no_write_file'" \
  "$ORIGINAL_RM -f '$TEST_DIR/no_write_file'" \
  "touch '$TEST_DIR/no_write_file' && chmod -w '$TEST_DIR/no_write_file'" \
  "rm -f '$TEST_DIR/no_write_file'"

run_test "Remove symbolic link" \
  "$DEBLOATED_RM -f '$TEST_DIR/symlink'" \
  "$ORIGINAL_RM -f '$TEST_DIR/symlink'" \
  "touch '$TEST_DIR/target_file' && ln -s '$TEST_DIR/target_file' '$TEST_DIR/symlink'" \
  "rm -f '$TEST_DIR/target_file'"

run_test "Remove broken symbolic link" \
  "$DEBLOATED_RM -f '$TEST_DIR/broken_symlink'" \
  "$ORIGINAL_RM -f '$TEST_DIR/broken_symlink'" \
  "ln -s '$TEST_DIR/nonexistent_file' '$TEST_DIR/broken_symlink'" \
  "rm -f '$TEST_DIR/broken_symlink'"

run_test "Remove file in directory with no execute permissions" \
  "mkdir '$TEST_DIR/no_exec_dir' && touch '$TEST_DIR/no_exec_dir/file' && chmod -x '$TEST_DIR/no_exec_dir' && $DEBLOATED_RM -f '$TEST_DIR/no_exec_dir/file'" \
  "mkdir '$TEST_DIR/no_exec_dir' && touch '$TEST_DIR/no_exec_dir/file' && chmod -x '$TEST_DIR/no_exec_dir' && $ORIGINAL_RM -f '$TEST_DIR/no_exec_dir/file'" \
  "rm -rf '$TEST_DIR/no_exec_dir'" \
  "chmod +x '$TEST_DIR/no_exec_dir' >& /dev/null"

run_test "Remove directory with mixed permission files" \
  "$DEBLOATED_RM -rf '$TEST_DIR/mixed_perms'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/mixed_perms'" \
  "mkdir '$TEST_DIR/mixed_perms' && touch '$TEST_DIR/mixed_perms/file1' '$TEST_DIR/mixed_perms/file2' '$TEST_DIR/mixed_perms/file3' && chmod 000 '$TEST_DIR/mixed_perms/file1' && chmod 444 '$TEST_DIR/mixed_perms/file2' && chmod 222 '$TEST_DIR/mixed_perms/file3'" \
  "rm -rf '$TEST_DIR/mixed_perms'"

run_test "Remove file with name starting with dash" \
  "$DEBLOATED_RM -f '$TEST_DIR/--file-with-dash'" \
  "$ORIGINAL_RM -f '$TEST_DIR/--file-with-dash'" \
  "touch '$TEST_DIR/--file-with-dash'" \
  "rm -f '$TEST_DIR/--file-with-dash'"

run_test "Remove directory with no-write subdirectories" \
  "$DEBLOATED_RM -rf '$TEST_DIR/parent_dir'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/parent_dir'" \
  "mkdir -p '$TEST_DIR/parent_dir/sub_dir' && chmod -w '$TEST_DIR/parent_dir/sub_dir'" \
  "rm -rf '$TEST_DIR/parent_dir'"

run_test "Remove multiple files and directories" \
  "$DEBLOATED_RM -rf '$TEST_DIR/file1' '$TEST_DIR/dir1' '$TEST_DIR/file2' '$TEST_DIR/dir2'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/file1' '$TEST_DIR/dir1' '$TEST_DIR/file2' '$TEST_DIR/dir2'" \
  "touch '$TEST_DIR/file1' '$TEST_DIR/file2' && mkdir '$TEST_DIR/dir1' '$TEST_DIR/dir2'" \
  "rm -rf '$TEST_DIR/file1' '$TEST_DIR/dir1' '$TEST_DIR/file2' '$TEST_DIR/dir2'"

run_test "Remove file with newline in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file\nwith\nnewlines'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file\nwith\nnewlines'" \
  "touch '$TEST_DIR/file\nwith\nnewlines'" \
  "rm -f '$TEST_DIR/file\nwith\nnewlines'"

run_test "Remove file with tab in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file	with	tab'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file	with	tab'" \
  "touch '$TEST_DIR/file	with	tab'" \
  "rm -f '$TEST_DIR/file	with	tab'"

run_test "Remove file with backspace in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file\bwith\backspace'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file\bwith\backspace'" \
  "touch '$TEST_DIR/file\bwith\backspace'" \
  "rm -f '$TEST_DIR/file\bwith\backspace'"

run_test "Remove file with carriage return in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file\rwith\rcarriage\rreturn'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file\rwith\rcarriage\rreturn'" \
  "touch '$TEST_DIR/file\rwith\rcarriage\rreturn'" \
  "rm -f '$TEST_DIR/file\rwith\rcarriage\rreturn'"

run_test "Remove file with form feed in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file\fwith\fform\ffeed'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file\fwith\fform\ffeed'" \
  "touch '$TEST_DIR/file\fwith\fform\ffeed'" \
  "rm -f '$TEST_DIR/file\fwith\fform\ffeed'"

run_test "Remove file with vertical tab in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file\vwith\vvertical\vtab'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file\vwith\vvertical\vtab'" \
  "touch '$TEST_DIR/file\vwith\vvertical\vtab'" \
  "rm -f '$TEST_DIR/file\vwith\vvertical\vtab'"

run_test "Remove file with bell in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file\awith\abell'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file\awith\abell'" \
  "touch '$TEST_DIR/file\awith\abell'" \
  "rm -f '$TEST_DIR/file\awith\abell'"

run_test "Remove really big directory" \
  "$DEBLOATED_RM -rf '$TEST_DIR/big_dir'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/big_dir'" \
  "mkdir -p '$TEST_DIR/big_dir'; for i in {1..1000}; do mkdir -p '$TEST_DIR/big_dir/dir_$i'; touch '$TEST_DIR/big_dir/dir_$i/file_$i.txt'; done" \
  "rm -rf '$TEST_DIR/big_dir'"

run_test "Remove a really big file" \
  "$DEBLOATED_RM -f '$TEST_DIR/big_file'" \
  "$ORIGINAL_RM -f '$TEST_DIR/big_file'" \
  "dd if=/dev/zero of='$TEST_DIR/big_file' bs=1M count=1000" \
  "rm -f '$TEST_DIR/big_file'"
run_test "Remove file with multiple spaces in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file  with  multiple  spaces'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file  with  multiple  spaces'" \
  "touch '$TEST_DIR/file  with  multiple  spaces'" \
  "rm -f '$TEST_DIR/file  with  multiple  spaces'"

run_test "Remove directory with multiple spaces in name" \
  "$DEBLOATED_RM -rf '$TEST_DIR/dir  with  multiple  spaces'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/dir  with  multiple  spaces'" \
  "mkdir -p '$TEST_DIR/dir  with  multiple  spaces'" \
  "rm -rf '$TEST_DIR/dir  with  multiple  spaces'"

run_test "Remove file with multiple tabs in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file	with	multiple	tabs'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file	with	multiple	tabs'" \
  "touch '$TEST_DIR/file	with	multiple	tabs'" \
  "rm -f '$TEST_DIR/file	with	multiple	tabs'"

run_test "Remove directory with multiple tabs in name" \
  "$DEBLOATED_RM -rf '$TEST_DIR/dir	with	multiple	tabs'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/dir	with	multiple	tabs'" \
  "mkdir -p '$TEST_DIR/dir	with	multiple	tabs'" \
  "rm -rf '$TEST_DIR/dir	with	multiple	tabs'"

run_test "Remove file with multiple newlines in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file\n\nwith\n\nmultiple\n\nnewlines'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file\n\nwith\n\nmultiple\n\nnewlines'" \
  "touch '$TEST_DIR/file\n\nwith\n\nmultiple\n\nnewlines'" \
  "rm -f '$TEST_DIR/file\n\nwith\n\nmultiple\n\nnewlines'"

run_test "Remove directory with multiple newlines in name" \
  "$DEBLOATED_RM -rf '$TEST_DIR/dir\n\nwith\n\nmultiple\n\nnewlines'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/dir\n\nwith\n\nmultiple\n\nnewlines'" \
  "mkdir -p '$TEST_DIR/dir\n\nwith\n\nmultiple\n\nnewlines'" \
  "rm -rf '$TEST_DIR/dir\n\nwith\n\nmultiple\n\nnewlines'"

run_test "Remove file with multiple carriage returns in name" \
  "$DEBLOATED_RM -f '$TEST_DIR/file\r\rwith\r\rmultiple\r\rcarriage\r\nreturns'" \
  "$ORIGINAL_RM -f '$TEST_DIR/file\r\rwith\r\rmultiple\r\rcarriage\r\nreturns'" \
  "touch '$TEST_DIR/file\r\rwith\r\rmultiple\r\rcarriage\r\nreturns'" \
  "rm -f '$TEST_DIR/file\r\rwith\r\rmultiple\r\rcarriage\r\nreturns'"

run_test "Remove directory with multiple carriage returns in name" \
  "$DEBLOATED_RM -rf '$TEST_DIR/dir\r\rwith\r\rmultiple\r\rcarriage\r\nreturns'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/dir\r\rwith\r\rmultiple\r\rcarriage\r\nreturns'" \
  "mkdir -p '$TEST_DIR/dir\r\rwith\r\rmultiple\r\rcarriage\r\nreturns'" \
  "rm -rf '$TEST_DIR/dir\r\rwith\r\rmultiple\r\rcarriage\r\nreturns'"

run_test "Remove file and directory with null character in name" \
  "$DEBLOATED_RM -rf '$TEST_DIR/file\0with\0null\0character' '$TEST_DIR/dir\0with\0null\0character'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/file\0with\0null\0character' '$TEST_DIR/dir\0with\0null\0character'" \
  "touch '$TEST_DIR/file\0with\0null\0character' && mkdir '$TEST_DIR/dir\0with\0null\0character'" \
  "rm -rf '$TEST_DIR/file\0with\0null\0character' '$TEST_DIR/dir\0with\0null\0character'"

run_test "Remove file and directories with mixed special characters in name" \
  "$DEBLOATED_RM -rf '$TEST_DIR/file!@#$%^&*.txt' '$TEST_DIR/file\nwith\nnewlines' '$TEST_DIR/file\r\rwith\r\rmultiple\r\rcarriage\r\nreturns' '$TEST_DIR/file\vwith\vvertical\vtab' '$TEST_DIR/file\fwith\fform\ffeed' '$TEST_DIR/file\bwith\backspace' '$TEST_DIR/file\awith\abell' '$TEST_DIR/file\rwith\rcarriage\rreturn' '$TEST_DIR/file	with	tab' '$TEST_DIR/file  with  multiple  spaces' '$TEST_DIR/file_with_null\0character' '$TEST_DIR/file\0with\0null\0character'" \
  "$ORIGINAL_RM -rf '$TEST_DIR/file!@#$%^&*.txt' '$TEST_DIR/file\nwith\nnewlines' '$TEST_DIR/file\r\rwith\r\rmultiple\r\rcarriage\r\nreturns' '$TEST_DIR/file\vwith\vvertical\vtab' '$TEST_DIR/file\fwith\fform\ffeed' '$TEST_DIR/file\bwith\backspace' '$TEST_DIR/file\awith\abell' '$TEST_DIR/file\rwith\rcarriage\rreturn' '$TEST_DIR/file	with	tab' '$TEST_DIR/file  with  multiple  spaces' '$TEST_DIR/file_with_null\0character' '$TEST_DIR/file\0with\0null\0character'" \
  "touch '$TEST_DIR/file!@#$%^&*.txt' '$TEST_DIR/file\nwith\nnewlines' '$TEST_DIR/file\r\rwith\r\rmultiple\r\rcarriage\r\nreturns' '$TEST_DIR/file\vwith\vvertical\vtab' '$TEST_DIR/file\fwith\fform\ffeed' '$TEST_DIR/file\bwith\backspace' '$TEST_DIR/file\awith\abell' '$TEST_DIR/file\rwith\rcarriage\rreturn' '$TEST_DIR/file	with	tab' '$TEST_DIR/file  with  multiple  spaces' '$TEST_DIR/file_with_null\0character' '$TEST_DIR/file\0with\0null\0character'" \
  "rm -rf '$TEST_DIR/file!@#$%^&*.txt' '$TEST_DIR/file\nwith\nnewlines' '$TEST_DIR/file\r\rwith\r\rmultiple\r\rcarriage\r\nreturns' '$TEST_DIR/file\vwith\vvertical\vtab' '$TEST_DIR/file\fwith\fform\ffeed' '$TEST_DIR/file\bwith\backspace' '$TEST_DIR/file\awith\abell' '$TEST_DIR/file\rwith\rcarriage\rreturn' '$TEST_DIR/file	with	tab' '$TEST_DIR/file  with  multiple  spaces' '$TEST_DIR/file_with_null\0character' '$TEST_DIR/file\0with\0null\0character'"





# Summary of test results
echo "Total tests: $TOTAL_TESTS"
echo "Passed tests: $PASSED_TESTS"
echo "Failed tests: $((TOTAL_TESTS - PASSED_TESTS))"

# Cleanup after tests
cleanup