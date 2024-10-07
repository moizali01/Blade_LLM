BINARY_DIR="bins"
LOG="log.txt"
# C_FILE=chown-llm2.c
# C_FILE=chown-blade.c
C_FILE=chown-debloated.c.blade.c
TIMEOUT_LIMIT="-k 5 5"

TOTAL_SCORE_FUNCTIONALITY=0
TOTAL_SEC_CASES=0

# Compile the binary once
mkdir -p $BINARY_DIR
rm -rf $BINARY_DIR/*
clang -w $C_FILE -o $BINARY_DIR/chown-test
chmod +x $BINARY_DIR/chown-test

# List of commands to test
declare -A COMMANDS=(
    ["chown-owner"]="user1:"
    ["chown-group"]=":group1"
    ["chown-owner-group"]="user1:group1"
)
order=( "chown-owner" "chown-group" "chown-owner-group" )

function create_test_structure_simple() {
    local base_dir="$1"
    mkdir -p "$base_dir"
    touch "$base_dir/file1"
    touch "$base_dir/file2"
    touch "$base_dir/file4.tmp"
    touch "$base_dir/file3.txt"
}

function create_test_structure_read_only() {
    local base_dir="$1"
    mkdir -p "$base_dir"
    
    # Create files
    touch "$base_dir/file1"
    touch "$base_dir/file2"
    touch "$base_dir/file3.txt"
    
    # Make the files and directory read-only
    chmod 444 "$base_dir/file1"
    chmod 444 "$base_dir/file2"
    chmod 444 "$base_dir/file3.txt"
    chmod 000 "$base_dir"
}

function create_test_structure_nested() {
    local base_dir="$1"
    mkdir -p "$base_dir/subdir1/subsubdir"
    mkdir -p "$base_dir/subdir2"
    touch "$base_dir/file1"
    touch "$base_dir/subdir1/file2"
    touch "$base_dir/subdir1/subsubdir/file3"
    touch "$base_dir/subdir2/file4"
}

function create_test_structure_symlinks() {
    local base_dir="$1"
    mkdir -p "$base_dir/target_dir"
    touch "$base_dir/target_file"
    touch "$base_dir/target_dir/nested_file"
    ln -s "$base_dir/target_file" "$base_dir/symlink_file"
    ln -s "$base_dir/target_dir" "$base_dir/symlink_dir"
}

function create_test_structure_special_files() {
    local base_dir="$1"
    mkdir -p "$base_dir"
    touch "$base_dir/regular_file"
    mkfifo "$base_dir/named_pipe"
    mknod "$base_dir/block_device" b 7 0
    mknod "$base_dir/char_device" c 1 3
}

function create_test_structure_permissions() {
    local base_dir="$1"
    mkdir -p "$base_dir"
    touch "$base_dir/file_644"
    chmod 644 "$base_dir/file_644"
    touch "$base_dir/file_755"
    chmod 755 "$base_dir/file_755"
    touch "$base_dir/file_400"
    chmod 400 "$base_dir/file_400"
    mkdir "$base_dir/dir_755"
    chmod 755 "$base_dir/dir_755"
}

function test() {
    local cmd="$1"
    local args="$2"
    local test_dir="$3"
    local structure_type="$4"

    echo "Testing command: chown $args \"$test_dir\"" >> $LOG
    echo "Structure type: $structure_type" >> $LOG

    # Create the test directory structure
    rm -rf "$test_dir"
    case $structure_type in
        "simple")
            create_test_structure_simple "$test_dir"
            ;;
        "nested")
            create_test_structure_nested "$test_dir"
            ;;
        "symlinks")
            create_test_structure_symlinks "$test_dir"
            ;;
        "special")
            create_test_structure_special_files "$test_dir"
            ;;
        "permissions")
            create_test_structure_permissions "$test_dir"
            ;;
        "read-only")
            create_test_structure_read_only "$test_dir"
            ;;
        "numeric-gid")
            touch $test_dir
            ;;
        "numeric-uid")
            touch $test_dir
            ;;
        
    esac

    # Run the binary and capture stdout, stderr, and the directory listing
    binary_output=$(mktemp)
    binary_error=$(mktemp)
    { timeout ${TIMEOUT_LIMIT} $BINARY_DIR/chown-test -R $args "$test_dir"; } > "$binary_output" 2> "$binary_error"
    temp1=$(ls -alR "$test_dir" | awk '{print $1, $2, $3, $4, $5, $7, $9}')

    echo "Custom chown output:" >> $LOG
    cat "$binary_output" >> $LOG
    echo "Custom chown error:" >> $LOG
    cat "$binary_error" >> $LOG
    echo "Directory listing after custom chown:" >> $LOG
    echo "$temp1" >> $LOG

    # Reset ownership for comparison
    chown -R $(whoami):$(id -gn) "$test_dir"
    rm -rf "$test_dir"
    case $structure_type in
        "simple")
            create_test_structure_simple "$test_dir"
            ;;
        "nested")
            create_test_structure_nested "$test_dir"
            ;;
        "symlinks")
            create_test_structure_symlinks "$test_dir"
            ;;
        "special")
            create_test_structure_special_files "$test_dir"
            ;;
        "permissions")
            create_test_structure_permissions "$test_dir"
            ;;
        "read-only")
            create_test_structure_read_only "$test_dir"
            ;;
        "numeric-gid")
            touch $test_dir
            ;;
        "numeric-uid")
            touch $test_dir
            ;;
        
    esac

    # Apply system chown and capture stdout, stderr, and the directory listing
    chown_output=$(mktemp)
    chown_error=$(mktemp)
    chown -R $args "$test_dir" > "$chown_output" 2> "$chown_error"
    temp2=$(ls -alR "$test_dir" | awk '{print $1, $2, $3, $4, $5, $7, $9}')

    echo "System chown output:" >> $LOG
    cat "$chown_output" >> $LOG
    echo "System chown error:" >> $LOG
    cat "$chown_error" >> $LOG
    echo "Directory listing after system chown:" >> $LOG
    echo "$temp2" >> $LOG

    # Compare the outputs
    if ! diff -q <(echo "$temp1") <(echo "$temp2") >& /dev/null; then
        echo "Directory listings do not match" >> $LOG
        rm -rf "$test_dir"
        return 1
    fi

    if ! diff -q "$binary_output" "$chown_output" >& /dev/null; then
        echo "Stdout does not match" >> $LOG
        rm -rf "$test_dir"
        return 1
    fi

    # Clean up temporary files and directory
    rm -f "$binary_output" "$binary_error" "$chown_output" "$chown_error"
    rm -rf "$test_dir"
    return 0
}

# Function to create a test structure with multiple files for this case
function create_test_structure_multiple_files() {
    local base_dir="$1"
    mkdir -p "$base_dir"
    touch "$base_dir/file1"
    touch "$base_dir/file2"
    touch "$base_dir/file3"
    mkdir -p "$base_dir/subdir"
}

# Function to run the test
function test_multiple_files() {
    local test_dir="$1"

    echo "Testing command: chown user1:group1 file1 file2 file3" >> $LOG

    # Create the test directory structure with multiple files
    rm -rf "$test_dir"
    create_test_structure_multiple_files "$test_dir"

    # Run the binary with multiple files
    binary_output=$(mktemp)
    binary_error=$(mktemp)
    cd $test_dir

    { timeout ${TIMEOUT_LIMIT} ../$BINARY_DIR/chown-test -R user1:group1 file1 file2 file3 subdir; } > "$binary_output" 2> "$binary_error"

    cd ..

    # Capture the directory listing after applying custom chown
    temp1=$(ls -al "$test_dir" | awk '{print $1, $2, $3, $4, $9}')

    echo "Custom chown output:" >> $LOG
    cat "$binary_output" >> $LOG
    echo "Custom chown error:" >> $LOG
    cat "$binary_error" >> $LOG
    echo "Directory listing after custom chown:" >> $LOG
    echo "$temp1" >> $LOG

    # Reset ownership for comparison
    chown -R $(whoami):$(id -gn) "$test_dir"
    rm -rf "$test_dir"
    create_test_structure_multiple_files "$test_dir"

    # Apply system chown for comparison
    chown_output=$(mktemp)
    chown_error=$(mktemp)
    cd $test_dir
    chown -R user1:group1 file1 file2 file3 subdir > "$chown_output" 2> "$chown_error"
    cd ..
    temp2=$(ls -al "$test_dir" | awk '{print $1, $2, $3, $4, $9}')

    echo "System chown output:" >> $LOG
    cat "$chown_output" >> $LOG
    echo "System chown error:" >> $LOG
    cat "$chown_error" >> $LOG
    echo "Directory listing after system chown:" >> $LOG
    echo "$temp2" >> $LOG

    # Compare the outputs
    if ! diff -q <(echo "$temp1") <(echo "$temp2") >& /dev/null; then
        echo "Directory listings do not match" >> $LOG
        rm -rf "$test_dir"
        return 1
    fi

    if ! diff -q "$binary_output" "$chown_output" >& /dev/null; then
        echo "Stdout does not match" >> $LOG
        rm -rf "$test_dir"
        return 1
    fi

    # Clean up temporary files and directory
    rm -f "$binary_output" "$binary_error" "$chown_output" "$chown_error"
    rm -rf "$test_dir"
    return 0
}

# Funtion to run 7 test cases with different directory names and permissions
function c_test() {
    local cmd="$1"
    local args="$2"
    local SCORE=0
    local TOTAL=7

    
    test "$cmd" "$args" "testdir_simple" "simple" && ((SCORE = SCORE + 1)) && echo "simple"
    test "$cmd" "$args" "testdir_nested" "nested" && ((SCORE = SCORE + 1)) && echo "nested"
    test "$cmd" "$args" "testdir_special" "special" && ((SCORE = SCORE + 1)) && echo "special"
    test "$cmd" "$args" "testdir_permissions" "permissions" && ((SCORE = SCORE + 1)) && echo "permissions"
    test "$cmd" "$args" "testdir_special _chars!@#$%^&*()" "nested" && ((SCORE = SCORE + 1)) && echo "special chars"
    
    TOTAL_SCORE_FUNCTIONALITY=$((TOTAL_SCORE_FUNCTIONALITY + SCORE))
    # echo
    echo "total:  $TOTAL_SCORE_FUNCTIONALITY"

    # echo "$cmd tests $SCORE / $TOTAL"
    return 0
}

function run_tests() {

    

    # Test Cases 1-15 : different types of directory names,permissions and edge cases
    c_test "chown-owner-group" "${COMMANDS["chown-owner-group"]}"

    # Test Cases 1-5 : different types of directory names,permissions and edge cases
    c_test "chown-owner" "${COMMANDS["chown-owner"]}"

    # Test Cases 1-5 : different types of directory names,permissions and edge cases
    c_test "chown-group" "${COMMANDS["chown-group"]}"

    # Test Case 16: Change owner and group of a directory with read-only files
    test "chown-owner-group" "user1:group1" "testdir_read_only" "read-only" && ((TOTAL_SCORE_FUNCTIONALITY++))

    # Test Case 17: Change owner and group of a directory using numeric UID and GID
    test "chown-uid-gid" "1000:1000" "testdir_nested" "nested" && ((TOTAL_SCORE_FUNCTIONALITY++))

    # Test Case 18: Change owner and group of a directory using numeric UID and GID
    test "chown-uid-gid" ":1000" "testdir_nested" "nested" && ((TOTAL_SCORE_FUNCTIONALITY++))

    # Test Case 19: Change owner and group of a directory using numeric UID and GID
    test "chown-uid-gid" "1000:" "testdir_nested" "nested" && ((TOTAL_SCORE_FUNCTIONALITY++))

    # Test Case 20: Change owner and group of a directory with multiple files
    test_multiple_files "testdir_multiple_files" && ((TOTAL_SCORE_FUNCTIONALITY++))


    return 0
    
}

function run_security_cases(){

    # Test Case 1: Change owner and group of a directory with read-only files
    test "chown-owner-group" "user1:group1" "testdir_read_only" "read-only" && ((TOTAL_SEC_CASES++))

    # Test Case 2: Change owner and group of a directory with Non-existent File
    test "chown-owner-group" "user1:group1" "non-existent" "simple" && ((TOTAL_SEC_CASES++))

    return 0

}

function test_robustness(){
    local args="$1"
    timeout ${TIMEOUT_LIMIT} $BINARY_DIR/chown-test $args testdir_simple 2>/dev/null
    a=$?
    # echo "$a"
    if [[ $a -ne 124 && $a -ne 137 ]]; then
        ((TOTAL_SEC_CASES++))
        echo "Robustness Test Passed"
        return 0
    fi

    
    return 1

}

function run_robustness_cases() {

    # Test Case 1: use invalid flag
    create_test_structure_nested testdir_simple
    test_robustness "-X user1:group1"
    rm -rf "$test_dir"

    # Test Case 2: use invalid owner
    create_test_structure_nested testdir_simple
    test_robustness "hahaha:" 
    rm -rf "$test_dir"

    
        # Test Case 3: use invalid group
    create_test_structure_nested testdir_simple
    test_robustness "-R :hahaha"
    rm -rf "$test_dir"


    # Test Case 4: use invalid owner:group codes
    create_test_structure_simple testdir_simple
    test_robustness "-R 5000:5000"
    rm -rf "$test_dir"

    # Test Case 5: removed flag functionality
    create_test_structure_nested testdir_simple
    test_robustness "-v user1:group1"
    rm -rf "$test_dir"

    # Test Case 7: Test -f (suppress error messages) flag
    create_test_structure_nested testdir_simple
    test_robustness "-f nonexistent_user:nonexistent_group"  
    rm -rf "$test_dir"

    # Test Case 8: Test -H flag (follow symbolic links on command line)
    create_test_structure_nested symlink_dir
    ln -s symlink_dir testdir_simple
    test_robustness "-H -R user1:group1"
    rm -rf "$test_dir" testdir_simple

    # Test Case 9: Test --from flag
    create_test_structure_nestedcreate_test_structure_nested testdir_simple
    chown user2:group2 testdir_simple
    test_robustness "--from=user2:group2 user1:group1"
    rm -rf "$test_dir"

}


# function run_tests() {
#     for key in "${order[@]}"; do
#         c_test "$key" "${COMMANDS[$key]}"
#     done
# }

function main() {
    clear
    rm -f $LOG
    rm -rf testdir_*
    touch $LOG
    echo "#######################################################" >> $LOG
    echo "############### AUTOMATED TESTING #####################" >> $LOG
    echo "############## chown-8.2 testing ######################" >> $LOG
    echo "#######################################################" >> $LOG
    echo "" >> $LOG
    echo "starting..." >> $LOG
    echo "" >> $LOG
    run_tests
    run_security_cases
    run_robustness_cases
    echo "Functionality: $TOTAL_SCORE_FUNCTIONALITY / 20"
    echo "Security & Robustness: $TOTAL_SEC_CASES / 10"
    echo "" >> $LOG
    echo "test run completed!" >> $LOG
}

main