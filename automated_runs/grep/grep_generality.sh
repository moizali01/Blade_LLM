#!/bin/bash

DEBLOATED_FILE="grep-util.c.blade.c"
ORIGINAL_FILE="grep-org.c"
CC=clang


# Compile the debloated code
CFLAGS="-w $1 -D __msan_unpoison(s,z) -lpcre"
$CC -w $DEBLOATED_FILE $CFLAGS -o debloated_grep
if [ $? -ne 0 ]; then
  echo "Error: Compilation of $DEBLOATED_FILE failed"
  exit 1
fi

# Compile the original code
$CC -w $ORIGINAL_FILE $CFLAGS -o original_grep
if [ $? -ne 0 ]; then
  echo "Error: Compilation of $ORIGINAL_FILE failed"
  exit 1
fi

# Path to the executables
DEBLOATED_GREP="./debloated_grep"
ORIGINAL_GREP="./original_grep"

# Directories and files for testing
TEST_DIR="security_test_dir"
TEST_FILE="$TEST_DIR/security_test_file.txt"
SYMLINK_FILE="$TEST_DIR/symlink_test_file.txt"
NUM_FILES=1000
NUM_LINES=10000
LONG_LINE_LENGTH=1000000

# Counters for tests
TOTAL_TESTS=0
PASSED_TESTS=0

# Check if executables exist
if [ ! -f "$DEBLOATED_GREP" ] || [ ! -f "$ORIGINAL_GREP" ]; then
  echo "Error: One or both of the executables not found!"
  exit 1
fi

# Function to run a single test case
run_test() {
  local description="$1"
  local command_debloat="$2"
  local command_original="$3"
  local expected="$4"
 
  TOTAL_TESTS=$((TOTAL_TESTS + 1))
  echo "Running test: $description"
 
  # Run and capture output from both debloated and original
  output_debloat=$(eval "$command_debloat" 2>&1 | sed "s|$DEBLOATED_GREP: ||")
  output_original=$(eval "$command_original" 2>&1 | sed "s|$ORIGINAL_GREP: ||")
 
  # Compare outputs
  if [[ "$output_debloat" == "$output_original" ]]; then
    echo "Pass"
    PASSED_TESTS=$((PASSED_TESTS + 1))
  else
    echo "Fail"
    echo "Debloated Output: $output_debloat"
    echo "Original Output: $output_original"
  fi
  echo
}

# Setup test environment
setup() {
  rm -rf "$TEST_DIR"
  mkdir -p "$TEST_DIR/subdir"
 
  # Create a large file
  for i in $(seq 1 $NUM_LINES); do
    echo "This is a test line $i" >> "$TEST_FILE"
  done
 
  # Create many files
  for i in $(seq 1 $NUM_FILES); do
    echo "File number $i" > "$TEST_DIR/test_file_$i.txt"
    echo "Pattern in file $i" >> "$TEST_DIR/test_file_$i.txt"
  done
 
  # Create a file with a very long line
  head -c $LONG_LINE_LENGTH < /dev/urandom | tr -dc 'a-zA-Z0-9' > "$TEST_DIR/long_line.txt"
}

# Clean up test environment
cleanup() {
  rm -rf "$TEST_DIR"
  rm -rf security_test_dir traversal_test debloated_grep original_grep
}

# Run tests
setup

run_test "Buffer overflow test with long line" \
  "$DEBLOATED_GREP 'a' $TEST_DIR/long_line.txt | wc -l" \
  "$ORIGINAL_GREP 'a' $TEST_DIR/long_line.txt | wc -l" \
  "$(grep -o 'a' "$TEST_DIR/long_line.txt" | wc -l)"

touch "$SYMLINK_FILE"
ln -s "$SYMLINK_FILE" "$TEST_DIR/symlink"
run_test "Symlink attack test" \
  "$DEBLOATED_GREP 'Pattern' $TEST_DIR/symlink" \
  "$ORIGINAL_GREP 'Pattern' $TEST_DIR/symlink" \
  ""

run_test "Invalid file path test" \
  "$DEBLOATED_GREP 'test' /invalid/file/path" \
  "$ORIGINAL_GREP 'test' /invalid/file/path" \
  "/invalid/file/path: No such file or directory"

run_test "Memory leak test with large file" \
  "$DEBLOATED_GREP 'test' $TEST_FILE | head -n 10" \
  "$ORIGINAL_GREP 'test' $TEST_FILE | head -n 10" \
  "$(head -n 10 "$TEST_FILE")"

mkdir -p "$TEST_DIR/../traversal_test"
echo "Traversal test file" > "$TEST_DIR/../traversal_test/traversal_test.txt"
run_test "Directory traversal attack test" \
  "$DEBLOATED_GREP 'Traversal' $TEST_DIR/../traversal_test/traversal_test.txt" \
  "$ORIGINAL_GREP 'Traversal' $TEST_DIR/../traversal_test/traversal_test.txt" \
  "Traversal test file"

touch "$TEST_DIR/empty_file.txt"
run_test "Search in empty file" \
  "$DEBLOATED_GREP 'test' $TEST_DIR/empty_file.txt" \
  "$ORIGINAL_GREP 'test' $TEST_DIR/empty_file.txt" \
  ""

LONG_FILE_NAME="$TEST_DIR/$(head -c 255 < /dev/urandom | tr -dc 'a-zA-Z0-9').txt"
touch "$LONG_FILE_NAME"
echo "Pattern in very long file name" > "$LONG_FILE_NAME"
run_test "Very long file name" \
  "$DEBLOATED_GREP 'Pattern' \"$LONG_FILE_NAME\"" \
  "$ORIGINAL_GREP 'Pattern' \"$LONG_FILE_NAME\"" \
  "Pattern in very long file name"

run_test "Search in many small files" \
  "$DEBLOATED_GREP -r 'Pattern' $TEST_DIR | head -n 10" \
  "$ORIGINAL_GREP -r 'Pattern' $TEST_DIR | head -n 10" \
  "$(for i in $(seq 1 10); do echo "$TEST_DIR/test_file_$i.txt:Pattern in file $i"; done)"

mkdir -p "$TEST_DIR/deep/subdir"
for i in $(seq 1 50); do
  mkdir -p "$TEST_DIR/deep/subdir/$i"
  echo "Pattern in deep file $i" > "$TEST_DIR/deep/subdir/$i/deep_file_$i.txt"
done
run_test "Search in deep directory structure" \
  "$DEBLOATED_GREP -r 'Pattern' $TEST_DIR/deep | head -n 10" \
  "$ORIGINAL_GREP -r 'Pattern' $TEST_DIR/deep | head -n 10" \
  "$(for i in $(seq 1 10); do echo "$TEST_DIR/deep/subdir/$i/deep_file_$i.txt:Pattern in deep file $i"; done)"

dd if=/dev/urandom of="$TEST_DIR/binary_file.bin" bs=1M count=1
run_test "Search in binary file" \
  "$DEBLOATED_GREP 'randompattern' $TEST_DIR/binary_file.bin" \
  "$ORIGINAL_GREP 'randompattern' $TEST_DIR/binary_file.bin" \
  ""

run_test "Invalid pattern" \
  "$DEBLOATED_GREP '[' $TEST_FILE" \
  "$ORIGINAL_GREP '[' $TEST_FILE" \
  "Invalid regular expression"

mkdir -p "$TEST_DIR/many_files"
for i in $(seq 1 1000); do
  echo "Pattern in file $i" > "$TEST_DIR/many_files/file_$i.txt"
done
run_test "Search in extremely large number of files" \
  "$DEBLOATED_GREP -r 'Pattern' $TEST_DIR/many_files | head -n 10" \
  "$ORIGINAL_GREP -r 'Pattern' $TEST_DIR/many_files | head -n 10" \
  "$(for i in $(seq 1 10); do echo "$TEST_DIR/many_files/file_$i.txt:Pattern in file $i"; done)"

mkdir -p "$TEST_DIR/deep_structure"
for i in $(seq 1 50); do
  dir_path="$TEST_DIR/deep_structure/$(printf '%0.s1/' $(seq 1 $i))"
  mkdir -p "$dir_path"
  echo "Pattern in deep structure file $i" > "${dir_path}file_$i.txt"
done

run_test "Search in extremely deep directory structure" \
  "$DEBLOATED_GREP -r 'Pattern' $TEST_DIR/deep_structure | head -n 10" \
  "$ORIGINAL_GREP -r 'Pattern' $TEST_DIR/deep_structure | head -n 10" \
  "$(for i in $(seq 1 10); do echo "$TEST_DIR/deep_structure/$(printf '%0.s1/' $(seq 1 $i))file_$i.txt:Pattern in deep structure file $i"; done)"

# Simple functionality tests
run_test "Basic grep functionality" \
  "$DEBLOATED_GREP 'test' $TEST_FILE | wc -l" \
  "$ORIGINAL_GREP 'test' $TEST_FILE | wc -l" \
  "$NUM_LINES"


run_test "Multiple file search" \
  "$DEBLOATED_GREP 'Pattern' $TEST_DIR/test_file_1.txt $TEST_DIR/test_file_2.txt" \
  "$ORIGINAL_GREP 'Pattern' $TEST_DIR/test_file_1.txt $TEST_DIR/test_file_2.txt" \
  "$TEST_DIR/test_file_1.txt:Pattern in file 1
$TEST_DIR/test_file_2.txt:Pattern in file 2"

run_test "Recursive search" \
  "$DEBLOATED_GREP -r 'Pattern' $TEST_DIR | wc -l" \
  "$ORIGINAL_GREP -r 'Pattern' $TEST_DIR | wc -l" \
  "$NUM_FILES"


# Edge cases
run_test "Empty pattern" \
  "$DEBLOATED_GREP '' $TEST_FILE | wc -l" \
  "$ORIGINAL_GREP '' $TEST_FILE | wc -l" \
  "$NUM_LINES"

run_test "Null character in file" \
  "echo -e 'abc\0def' > $TEST_DIR/null_char.txt && $DEBLOATED_GREP 'abc' $TEST_DIR/null_char.txt" \
  "echo -e 'abc\0def' > $TEST_DIR/null_char.txt && $ORIGINAL_GREP 'abc' $TEST_DIR/null_char.txt" \
  "abc"

run_test "File with only newlines" \
  "printf '\n%.0s' {1..100} > $TEST_DIR/newlines.txt && $DEBLOATED_GREP '^$' $TEST_DIR/newlines.txt | wc -l" \
  "printf '\n%.0s' {1..100} > $TEST_DIR/newlines.txt && $ORIGINAL_GREP '^$' $TEST_DIR/newlines.txt | wc -l" \
  "100"

run_test "File with very long lines" \
  "yes 'very long line ' | head -n 10 | tr '\n' ' ' > $TEST_DIR/long_lines.txt && $DEBLOATED_GREP 'long' $TEST_DIR/long_lines.txt | wc -l" \
  "yes 'very long line ' | head -n 10 | tr '\n' ' ' > $TEST_DIR/long_lines.txt && $ORIGINAL_GREP 'long' $TEST_DIR/long_lines.txt | wc -l" \
  "1"

run_test "File with non-ASCII characters" \
  "echo 'áéíóú' > $TEST_DIR/non_ascii.txt && $DEBLOATED_GREP '[áéíóú]' $TEST_DIR/non_ascii.txt" \
  "echo 'áéíóú' > $TEST_DIR/non_ascii.txt && $ORIGINAL_GREP '[áéíóú]' $TEST_DIR/non_ascii.txt" \
  "áéíóú"

run_test "Matching at file boundary" \
  "printf 'abc' > $TEST_DIR/boundary.txt && $DEBLOATED_GREP 'abc$' $TEST_DIR/boundary.txt" \
  "printf 'abc' > $TEST_DIR/boundary.txt && $ORIGINAL_GREP 'abc$' $TEST_DIR/boundary.txt" \
  "abc"

run_test "Pattern with backslashes" \
  "$DEBLOATED_GREP '\\\\' $TEST_FILE" \
  "$ORIGINAL_GREP '\\\\' $TEST_FILE" \
  ""

run_test "File with mixed line endings" \
  "printf 'line1\nline2\r\nline3\rline4\n' > $TEST_DIR/mixed_endings.txt && $DEBLOATED_GREP 'line' $TEST_DIR/mixed_endings.txt | wc -l" \
  "printf 'line1\nline2\r\nline3\rline4\n' > $TEST_DIR/mixed_endings.txt && $ORIGINAL_GREP 'line' $TEST_DIR/mixed_endings.txt | wc -l" \
  "4"


run_test "Whitespace-only file" \
  "printf ' \t\n' > $TEST_DIR/whitespace.txt && $DEBLOATED_GREP '\\s' $TEST_DIR/whitespace.txt | wc -l" \
  "printf ' \t\n' > $TEST_DIR/whitespace.txt && $ORIGINAL_GREP '\\s' $TEST_DIR/whitespace.txt | wc -l" \
  "1"

run_test "File with control characters" \
  "printf 'line1\x01line2\x02line3\n' > $TEST_DIR/control_chars.txt && $DEBLOATED_GREP 'line' $TEST_DIR/control_chars.txt | wc -l" \
  "printf 'line1\x01line2\x02line3\n' > $TEST_DIR/control_chars.txt && $ORIGINAL_GREP 'line' $TEST_DIR/control_chars.txt | wc -l" \
  "3"

run_test "Matching empty lines" \
  "printf 'line1\n\nline2\n\nline3\n' > $TEST_DIR/empty_lines.txt && $DEBLOATED_GREP '^$' $TEST_DIR/empty_lines.txt | wc -l" \
  "printf 'line1\n\nline2\n\nline3\n' > $TEST_DIR/empty_lines.txt && $ORIGINAL_GREP '^$' $TEST_DIR/empty_lines.txt | wc -l" \
  "2"

run_test "File with long file name and spaces" \
  "touch '$TEST_DIR/this is a very long file name with spaces.txt' && $DEBLOATED_GREP 'test' '$TEST_DIR/this is a very long file name with spaces.txt'" \
  "touch '$TEST_DIR/this is a very long file name with spaces.txt' && $ORIGINAL_GREP 'test' '$TEST_DIR/this is a very long file name with spaces.txt'" \
  ""

run_test "Binary files detection" \
  "$DEBLOATED_GREP 'test' $TEST_DIR/binary_file.bin" \
  "$ORIGINAL_GREP 'test' $TEST_DIR/binary_file.bin" \
  "Binary file $TEST_DIR/binary_file.bin matches"

run_test "Grep with no newline at EOF" \
  "printf 'test' > $TEST_DIR/no_newline.txt && $DEBLOATED_GREP 'test' $TEST_DIR/no_newline.txt" \
  "printf 'test' > $TEST_DIR/no_newline.txt && $ORIGINAL_GREP 'test' $TEST_DIR/no_newline.txt" \
  "test"

# Clean up
cleanup

# Final report
echo "Total tests: $TOTAL_TESTS"
echo "Passed tests: $PASSED_TESTS"
echo "Failed tests: $((TOTAL_TESTS - PASSED_TESTS))"