#!/bin/bash

DEBLOATED_FILE="uniq-og.c"
ORIGINAL_FILE="uniq-util.c.blade.c"
CC=clang

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

# Path to the executables
DEBLOATED_UNIQ="./debloated_uniq"
ORIGINAL_UNIQ="./original_uniq"

# Directories and files for testing
TEST_DIR="uniq_test_dir"
INPUT_FILE="$TEST_DIR/input.txt"
OUTPUT_DEBLOATED="$TEST_DIR/output_debloat.txt"
OUTPUT_ORIGINAL="$TEST_DIR/output_original.txt"

# Counters for tests
TOTAL_TESTS=0
PASSED_TESTS=0

# Check if executables exist
if [ ! -f "$DEBLOATED_UNIQ" ] || [ ! -f "$ORIGINAL_UNIQ" ]; then
  echo "Error: One or both of the executables not found!"
  exit 1
fi

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
run_test() {
  local description="$1"
  local input_file="$2"
  local input_data="$3"
  local setup_command="$4"
  local cleanup_command="$5"
  
  TOTAL_TESTS=$((TOTAL_TESTS + 1))
  echo "Running test: $description"
  
  # Setup test environment if needed
  eval "$setup_command"
  
  # Create input file
  echo -e "$input_data" > "$INPUT_FILE"
  
  # Run and capture output from both debloated and original
  timeout 1s $DEBLOATED_UNIQ "$INPUT_FILE" > "$OUTPUT_DEBLOATED" 2>&1
  timeout 1s $ORIGINAL_UNIQ "$INPUT_FILE" > "$OUTPUT_ORIGINAL" 2>&1

  # Compare outputs
  if cmp -s "$OUTPUT_DEBLOATED" "$OUTPUT_ORIGINAL"; then
    echo "Pass"
    PASSED_TESTS=$((PASSED_TESTS + 1))
  else
    echo "Fail"
    # Uncomment to debug failed cases
    # echo -e "\nDebloated Output:\n$(cat "$OUTPUT_DEBLOATED")"
    # echo -e "\nOriginal Output:\n$(cat "$OUTPUT_ORIGINAL")"
  fi
  
  # Cleanup test environment if needed
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
  rm -f debloated_uniq original_uniq
}

# Run tests
setup

run_test "File with extremely long lines" \
  "$TEST_DIR/extremely_long_lines" \
  "$(printf '%0.s1' {1..100000})\n$(printf '%0.s2' {1..100000})\n$(printf '%0.s3' {1..100000})" \
  "" ""

run_test "File with emoji in name" \
  "$TEST_DIR/file_😀_with_emoji.txt" \
  "apple\napple\nbanana\ncherry" \
  "" ""

run_test "File with extremely long name" \
  "$TEST_DIR/$(printf 'a%.0s' {1..250}).txt" \
  "apple\napple\nbanana\ncherry" \
  "" ""

run_test "File with all special characters in name" \
  "$TEST_DIR/!@#$%^&*()_+-=[]{}|;:,.<>?.txt" \
  "apple\napple\nbanana\ncherry" \
  "" ""

# Memory-related edge cases
run_test "Symlink attack" \
  "$TEST_DIR/symlink_file" \
  "apple\napple\nbanana\ncherry" \
  "ln -s /etc/passwd $TEST_DIR/symlink_file" \
  "rm -f $TEST_DIR/symlink_file"

run_test "Buffer overflow attempt" \
  "$TEST_DIR/buffer_overflow" \
  "$(printf '%0.sA' {1..10000})" \
  "" ""

# Security-related edge cases
run_test "Read from read-only file" \
  "$TEST_DIR/readonly_file" \
  "apple\napple\nbanana\ncherry" \
  "touch $TEST_DIR/readonly_file && chmod 444 $TEST_DIR/readonly_file" \
  "chmod 644 $TEST_DIR/readonly_file"

run_test "File in directory without read permission" \
  "$TEST_DIR/no_read_dir/file" \
  "apple\napple\nbanana\ncherry" \
  "mkdir $TEST_DIR/no_read_dir && touch $TEST_DIR/no_read_dir/file && chmod 333 $TEST_DIR/no_read_dir" \
  "chmod 755 $TEST_DIR/no_read_dir"

run_test "File with setuid bit" \
  "$TEST_DIR/setuid_file" \
  "apple\napple\nbanana\ncherry" \
  "touch $TEST_DIR/setuid_file && chmod u+s $TEST_DIR/setuid_file" \
  "chmod u-s $TEST_DIR/setuid_file"

run_test "File with setgid bit" \
  "$TEST_DIR/setgid_file" \
  "apple\napple\nbanana\ncherry" \
  "touch $TEST_DIR/setgid_file && chmod g+s $TEST_DIR/setgid_file" \
  "chmod g-s $TEST_DIR/setgid_file"

run_test "File in sticky bit directory" \
  "$TEST_DIR/sticky_dir/file" \
  "apple\napple\nbanana\ncherry" \
  "mkdir $TEST_DIR/sticky_dir && chmod +t $TEST_DIR/sticky_dir && touch $TEST_DIR/sticky_dir/file" \
  "chmod -t $TEST_DIR/sticky_dir"

run_test "File with non-printable characters in name" \
  "$TEST_DIR/$(printf 'file_\x01\x02\x03.txt')" \
  "apple\napple\nbanana\ncherry" \
  "" ""

run_test "File with path traversal attempt" \
  "$TEST_DIR/path_traversal" \
  "apple\napple\nbanana\ncherry" \
  "echo 'This is not /etc/passwd' > $TEST_DIR/path_traversal" \
  ""

run_test "File with very long content" \
  "$TEST_DIR/very_long_content" \
  "$(yes 'This is a very long line that will be repeated many times.' | head -n 100000)" \
  "" ""

run_test "File with mixed case duplicates" \
  "$TEST_DIR/mixed_case" \
  "Apple\napple\nBANANA\nBanana\nbanana\nCherry\ncherry" \
  "" ""

run_test "File with leading/trailing whitespace" \
  "$TEST_DIR/whitespace" \
  "  apple  \n  apple  \n banana \n  cherry" \
  "" ""

run_test "File with empty content" \
  "$TEST_DIR/empty" \
  "" \
  "" ""

run_test "File with only one very long line" \
  "$TEST_DIR/one_long_line" \
  "$(printf 'a%.0s' {1..1000000})" \
  "" ""

run_test "File with Unicode combining characters" \
  "$TEST_DIR/unicode_combining" \
  "a\na\u0301\nb\nb\u0301\nc\nc\u0301" \
  "" ""

run_test "File with CRLF line endings" \
  "$TEST_DIR/crlf_endings" \
  "apple\r\napple\r\nbanana\r\ncherry\r\n" \
  "" ""

run_test "File with null characters" \
  "$TEST_DIR/null_chars" \
  "apple\0apple\0\0banana\0cherry" \
  "" ""

run_test "File with escape sequences" \
  "$TEST_DIR/escape_sequences" \
  "line\tline\nline\tline\nother\tline" \
  "" ""

run_test "File with control characters" \
  "$TEST_DIR/control_chars" \
  "$(printf 'line\x01\nline\x01\nother\x02\n')" \
  "" ""

run_test "File with surrogate pairs" \
  "$TEST_DIR/surrogate_pairs" \
  "$(printf '\xF0\x9F\x98\x80\n\xF0\x9F\x98\x80\n\xF0\x9F\x98\x81\n')" \
  "" ""

run_test "File with bidirectional text" \
  "$TEST_DIR/bidi_text" \
  "Hello\nHello\nسلام\nسلام\nShalom\n" \
  "" ""

run_test "File with zero-width characters" \
  "$TEST_DIR/zero_width" \
  "a\u200Bb\na\u200Bb\nc\u200Bd\n" \
  "" ""

run_test "File with newline in name" \
    "$TEST_DIR/file_with_newline\n" \
    "apple\napple\nbanana\ncherry" \
    "" ""

run_test "File with backspace characters" \
    "$TEST_DIR/backspace_chars" \
    "apple\b\b\b\borange\napple\b\b\b\borange\nbanana\ncherry" \
    "" ""

run_test "File with bell characters" \
    "$TEST_DIR/bell_chars" \
    "apple\a\a\aorange\napple\a\a\aorange\nbanana\ncherry" \
    "" ""

run_test "File with form feed characters" \
    "$TEST_DIR/form_feed_chars" \
    "apple\f\f\forange\napple\f\f\forange\nbanana\ncherry" \
    "" ""

run_test "File with carriage return characters" \
    "$TEST_DIR/carriage_return_chars" \
    "apple\r\r\rorange\napple\r\r\rorange\nbanana\ncherry" \
    "" ""

run_test "File with vertical tab characters" \
    "$TEST_DIR/vertical_tab_chars" \
    "apple\v\v\vorange\napple\v\v\vorange\nbanana\ncherry" \
    "" ""

run_test "File with escape characters" \
    "$TEST_DIR/escape_chars" \
    "apple\e\e\eorange\napple\e\e\eorange\nbanana\ncherry" \
    "" ""

run_test "File with delete characters" \
    "$TEST_DIR/delete_chars" \
    "apple\x7F\x7F\x7Forange\napple\x7F\x7F\x7Forange\nbanana\ncherry" \
    "" ""

run_test "File with multiple control characters" \
    "$TEST_DIR/multiple_control_chars" \
    "apple\x01\x02\x03orange\napple\x01\x02\x03orange\nbanana\ncherry" \
    "" ""

run_test "File with multiple escape sequences" \
    "$TEST_DIR/multiple_escape_seqs" \
    "apple\e\e\eorange\napple\e\e\eorange\nbanana\ncherry" \
    "" ""

run_test "File with multiple zero-width characters" \
    "$TEST_DIR/multiple_zero_width" \
    "a\u200Bb\u200Bc\na\u200Bb\u200Bc\nd\u200Be\n" \
    "" ""

run_test "File with multiple bidirectional text" \
    "$TEST_DIR/multiple_bidi_text" \
    "Hello\nHello\nسلام\nسلام\nShalom\n" \
    "" ""

run_test "File with multiple surrogate pairs" \
    "$TEST_DIR/multiple_surrogate_pairs" \
    "$(printf '\xF0\x9F\x98\x80\n\xF0\x9F\x98\x80\n\xF0\x9F\x98\x81\n')" \
    "" ""

run_test "File with multiple Unicode combining characters" \
    "$TEST_DIR/multiple_unicode_combining" \
    "a\na\u0301\nb\nb\u0301\nc\nc\u0301" \
    "" ""

run_test "Filename with spaces" \
    "$TEST_DIR/file with spaces" \
    "apple\napple\nbanana\ncherry" \
    "" ""

run_test "Filename with leading/trailing whitespace" \
    "$TEST_DIR/ file with spaces " \
    "apple\napple\nbanana\ncherry" \
    "" ""

run_test "Filename with newline" \
    "$TEST_DIR/file\nwith\nnewline" \
    "apple\napple\nbanana\ncherry" \
    "" ""

run_test "Filename with backspace characters" \
    "$TEST_DIR/file\bwith\bbackspace" \
    "apple\napple\nbanana\ncherry" \
    "" ""

run_test "Debloated source code file" \
    "$TEST_DIR/$DEBLOATED_FILE" \
    "$(cat $DEBLOATED_FILE)" \
    "cp $DEBLOATED_FILE $TEST_DIR/" "rm -f $TEST_DIR/$DEBLOATED_FILE"

run_test "File with multiple control characters in name" \
    "$TEST_DIR/file\x01\x02\x03" \
    "apple\napple\nbanana\ncherry" \
    "" ""

run_test "File with multiple escape sequences in name" \
    "$TEST_DIR/file\e\e\e" \
    "apple\napple\nbanana\ncherry" \
    "" ""

run_test "File with multiple zero-width characters in name" \
    "$TEST_DIR/file\u200B\u200B\u200B" \
    "apple\napple\nbanana\ncherry" \
    "" ""

run_test "File with multiple bidirectional text in name" \
    "$TEST_DIR/fileHelloسلامShalom" \
    "apple\napple\nbanana\ncherry" \
    "" ""

run_test "File with no lines" \
    "$TEST_DIR/no_lines" \
    "" \
    "" ""

run_test "File with only one line" \
    "$TEST_DIR/one_line" \
    "apple" \
    "" ""

run_test "Big File with no duplicates" \
    "$TEST_DIR/big_no_duplicates" \
    "$(generate_unique_random_lines 500 $TEST_DIR/big_no_duplicates && cat $TEST_DIR/big_no_duplicates)" \
    "" \
    "rm -f $TEST_DIR/big_no_duplicates"

run_test "Big File with all duplicates" \
    "$TEST_DIR/big_all_duplicates" \
    "$(yes 'apple' | head -n 10000)" \
    "" \
    ""

run_test "File with extremely long lines" \
    "$TEST_DIR/extremely_long_lines" \
    "$(printf '%0.s1' {1..100000})\n$(printf '%0.s2' {1..100000})\n$(printf '%0.s3' {1..100000})" \
    "" \
    ""

run_test "File with long lines and repeating patterns" \
    "$TEST_DIR/long_repeating_lines" \
    "$(printf '%0.sABC' {1..100000})\n$(printf '%0.sABC' {1..10000})\n$(printf '%0.sDEF' {1..10000})" \
    "" \
    ""

run_test "File with very long unique lines" \
    "$TEST_DIR/long_unique_lines" \
    "$(for i in {1..100}; do printf '%0.s'"$i"'' {1..1000}; echo; done)" \
    "" \
    ""

run_test "File with potential buffer overflow input" \
    "$TEST_DIR/buffer_overflow" \
    "$(printf '%0.s%x' {1..10000})\n$(printf '%0.s%x' {1..10000})" \
    "" \
    ""

run_test "File with long lines containing special characters" \
    "$TEST_DIR/long_special_chars" \
    "$(printf '%0.s!@#$%%^&*()' {1..1000})\n$(printf '%0.s!@#$%%^&*()' {1..1000})\n$(printf '%0.s[]{}|;:,.<>?' {1..1000})" \
    "" \
    ""

run_test "File with long lines of Unicode characters" \
    "$TEST_DIR/long_unicode" \
    "$(printf '%0.s😀' {1..1000})\n$(printf '%0.s😀' {1..10000})\n$(printf '%0.s🚀' {1..10000})" \
    "" \
    ""


run_test "File with maximum allowed filename length" \
    "$TEST_DIR/$(printf 'a%.0s' {1..255})" \
    "line1\nline1\nline2\nline3" \
    "" \
    ""

run_test "File with large number of unique lines" \
    "$TEST_DIR/many_unique_lines" \
    "$(for i in {1..10000}; do echo "Unique line $i"; done)" \
    "" \
    ""

run_test "File with complete path as name" \
    "$TEST_DIR/$(pwd)/file" \
    "apple\napple\nbanana\ncherry" \
    "" \
    ""

run_test "File with complete path name and spaces" \
    "$TEST_DIR/$(pwd)/file with spaces" \
    "apple\napple\nbanana\ncherry" \
    "" \
    ""

cleanup

# Summary
echo "Tests run: $TOTAL_TESTS"
echo "Tests passed: $PASSED_TESTS"
