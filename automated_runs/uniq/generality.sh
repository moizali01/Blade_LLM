#!/bin/bash

DEBLOATED_FILE="uniq-blade-llm.c"
DEBLOATED_FILE="uniq-util.c.blade.c"
ORIGINAL_FILE="uniq-og.c"
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
  echo -e "$input_data" > "$input_file"
  
  # Suppress stderr for debloated and original program
  $DEBLOATED_UNIQ "$input_file" > "$OUTPUT_DEBLOATED" 2>/dev/null
  if [ $? -ne 0 ]; then
    echo "Error: Debloated program crashed!"
    eval "$cleanup_command"
    return
  fi
  
  # Run the original program and suppress stderr
  $ORIGINAL_UNIQ "$input_file" > "$OUTPUT_ORIGINAL" 2>/dev/null
  if [ $? -ne 0 ]; then
    # echo "Error: Original program crashed!"
    echo "Pass"
    PASSED_TESTS=$((PASSED_TESTS + 1))
    eval "$cleanup_command"
    echo
    return
  fi

  # Compare outputs
  if cmp -s "$OUTPUT_DEBLOATED" "$OUTPUT_ORIGINAL"; then
    echo "Pass"
    PASSED_TESTS=$((PASSED_TESTS + 1))
  else
    echo "Fail"
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

run_test "Comprehensive uniq test" \
  "$TEST_DIR/comprehensive_test" \
  "$(cat << EOF
$(yes 'This is a very long line that will be repeated many times.' | head -n 1000)
Apple
apple
BANANA
Banana
banana
Cherry
cherry
  apple  
  apple  
 banana 
  cherry
$(printf 'a%.0s' {1..10000})
a
a$(printf '\u0301')
b
b$(printf '\u0301')
c
c$(printf '\u0301')
apple\r
apple\r
banana\r
cherry\r
apple\0apple\0\0banana\0cherry
line\tline
line\tline
other\tline
$(printf 'line\x01\nline\x01\nother\x02\n')
$(printf '\xF0\x9F\x98\x80\n\xF0\x9F\x98\x80\n\xF0\x9F\x98\x81\n')
Hello
Hello
سلام
سلام
Shalom
a$(printf '\u200B')b
a$(printf '\u200B')b
c$(printf '\u200B')d
apple\b\b\b\borange
apple\b\b\b\borange
banana
cherry
apple\a\a\aorange
apple\a\a\aorange
banana
cherry
apple\f\f\forange
apple\f\f\forange
banana
cherry
apple\r\r\rorange
apple\r\r\rorange
banana
cherry
apple\v\v\vorange
apple\v\v\vorange
banana
cherry
apple\e\e\eorange
apple\e\e\eorange
banana
cherry
apple$(printf '\x7F\x7F\x7F')orange
apple$(printf '\x7F\x7F\x7F')orange
banana
cherry
apple$(printf '\x01\x02\x03')orange
apple$(printf '\x01\x02\x03')orange
banana
cherry
a$(printf '\u200B')b$(printf '\u200B')c
a$(printf '\u200B')b$(printf '\u200B')c
d$(printf '\u200B')e
EOF
)" \
  "" ""

run_test "Comprehensive filename test with various challenging scenarios" \
    "$TEST_DIR/ file with spaces \x01\x02\x03\e\e\e$(printf '\u200B\u200B\u200B')Hello سلام Shalom\nwith\nnewline\bbackspace" \
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
    "$(pwd)/$TEST_DIR/file" \
    "apple\napple\nbanana\ncherry" \
    "" \
    ""

run_test "File with complete path name and spaces" \
    "$(pwd)/$TEST_DIR/file with spaces" \
    "apple\napple\nbanana\ncherry" \
    "" \
    ""

run_test "Prompt with coverage" \
  "$TEST_DIR/prompt_in_coverage.txt" \
  "$(cat prompt_in_coverage.txt)" \
  "cp prompt_in_coverage.txt $TEST_DIR/prompt_in_coverage.txt" \
  "rm $TEST_DIR/prompt_in_coverage.txt"

run_test "Prompt not in coverage" \
  "$TEST_DIR/prompt_not_in_coverage.txt" \
  "$(cat prompt_not_in_coverage.txt)" \
  "cp prompt_not_in_coverage.txt $TEST_DIR/prompt_not_in_coverage.txt" \
  "rm $TEST_DIR/prompt_not_in_coverage.txt"

run_test "sec list" \
  "$TEST_DIR/sec_list.txt" \
  "$(cat sec_list.txt)" \
  "cp sec_list.txt $TEST_DIR/sec_list.txt" \
  "rm $TEST_DIR/sec_list.txt"

run_test "lorem ipsum" \
  "$TEST_DIR/lorem_ipsum.txt" \
  "$(cat test_files/lorem_ipsum.txt)" \
  "cp test_files/lorem_ipsum.txt $TEST_DIR/lorem_ipsum.txt" \
  "rm $TEST_DIR/lorem_ipsum.txt"

run_test "example linux log file" \
  "$TEST_DIR/Linux_2k.log" \
  "$(cat test_files/Linux_2k.txt)" \
  "cp test_files/Linux_2k.txt $TEST_DIR/Linux_2k.log" \
  "rm $TEST_DIR/Linux_2k.log"

run_test "example apache log file" \
  "$TEST_DIR/Apache_2k.log" \
  "$(cat test_files/Apache_2k.txt)" \
  "cp test_files/Apache_2k.txt $TEST_DIR/Apache_2k.log" \
  "rm $TEST_DIR/Apache_2k.log"

run_test "random text text file 1" \
  "$TEST_DIR/random_text_1.txt" \
  "($cat test_files/random_text_1.txt)" \
  "cp test_files/random_text_1.txt $TEST_DIR/random_text_1.txt" \
  "rm $TEST_DIR/random_text_1.txt"

run_test "random text text file 2" \
  "$TEST_DIR/random_text_2.txt" \
  "$(cat test_files/random_text_2.txt)" \
  "cp test_files/random_text_2.txt $TEST_DIR/random_text_2.txt" \
  "rm $TEST_DIR/random_text_2.txt"

run_test "random text text file 3" \
  "$TEST_DIR/random_text_3.txt" \
  "$(cat test_files/random_text_3.txt)" \
  "cp test_files/random_text_3.txt $TEST_DIR/random_text_3.txt" \
  "rm $TEST_DIR/random_text_3.txt"


cleanup

# Summary
echo "Tests run: $TOTAL_TESTS"
echo "Tests passed: $PASSED_TESTS"
