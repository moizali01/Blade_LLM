BINARY_DIR="bins"
LOG="log.txt"
C_FILE=chown-debloated.c.blade.c
# C_FILE=chown-8.2.c.origin.c

# Compile the binary once
mkdir -p $BINARY_DIR
rm -rf $BINARY_DIR/*
clang -w $C_FILE -o $BINARY_DIR/chown-test
chmod +x $BINARY_DIR/chown-test

# List of commands to test
declare -A COMMANDS=(
    ["chown-owner"]="user1"
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
    esac

    # Run the binary and capture stdout, stderr, and the directory listing
    binary_output=$(mktemp)
    binary_error=$(mktemp)
    $BINARY_DIR/chown-test $args "$test_dir" > "$binary_output" 2> "$binary_error"
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
    esac

    # Apply system chown and capture stdout, stderr, and the directory listing
    chown_output=$(mktemp)
    chown_error=$(mktemp)
    chown $args "$test_dir" > "$chown_output" 2> "$chown_error"
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

function c_test() {
    local cmd="$1"
    local args="$2"
    local SCORE=0
    local TOTAL=7

    test "$cmd" "$args" "testdir_simple" "simple" && ((SCORE++))
    test "$cmd" "$args" "testdir_with spaces" "simple" && ((SCORE++))
    test "$cmd" "$args" "testdir_nested" "nested" && ((SCORE++))
    test "$cmd" "$args" "testdir_symlinks" "symlinks" && ((SCORE++))
    test "$cmd" "$args" "testdir_special" "special" && ((SCORE++))
    test "$cmd" "$args" "testdir_permissions" "permissions" && ((SCORE++))
    test "$cmd" "$args" "testdir_special_chars!@#$%^&*()" "simple" && ((SCORE++))

    echo "$cmd tests $SCORE / $TOTAL"
    return 0
}

function run_tests() {
    for key in "${order[@]}"; do
        c_test "$key" "${COMMANDS[$key]}"
    done
}

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
    echo "" >> $LOG
    echo "test run completed!" >> $LOG
}

main