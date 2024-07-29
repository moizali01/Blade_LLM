#!/bin/bash

# Paths to the files
PROGRAM_NAME="mkdir-8.30"
DIR=$(pwd)
ORIGINAL_FILE="mkdir-5.2.1.c.origin.c"
DEBLOATED_FILE="mkdir-debloated.c.blade.c"
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log.txt
TOTAL_TESTS=0
PASSED_TESTS=0


compile_files(){
    echo "Compiling original file..."
    $CC -w $ORIGINAL_FILE -o $ORIGINAL_BINARY 
    if [ $? -ne 0 ]; then
        echo "Error: Compilation of $ORIGINAL_FILE failed"
        exit 1
    fi

    echo "Compiling debloated file..."
    $CC -w $DEBLOATED_FILE -o $REDUCED_BINARY 
    if [ $? -ne 0 ]; then
        echo "Error: Compilation of $DEBLOATED_FILE failed"
        exit 1
    fi
}

# Function to check directory creation
check_directories() {
    local dir_name=$1

    # Check if the directory exists
    if [[ ! -d "$dir_name" ]]; then
        echo "Error: The directory $dir_name does not exist."
        return 1
    else
        echo "The directory $dir_name exists."
    fi
}

# Function to compare verbose output
test_mkdir_v() {
    TOTAL_TESTS=$((TOTAL_TESTS+1))
    
    local options=$1
    local dir_name=$2
    local verbose_output=$3
    local parent_dir=$4
    mkdir -p $parent_dir
    # Executing: mkdir with the given options for the original binary
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $options $dir_name; } 2> "$verbose_output.orig" 
    # if [ $? -ne 0 ]; then
    #     echo "Error: mkdir $options $dir_name failed for original binary"
    #     return 1
    # fi

    # Removing the created directories to test with the reduced binary
    rm -rf $DIR/directory
    mkdir -p $parent_dir
    # Executing: mkdir with the given options for the reduced binary
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $options $dir_name; } 2> "$verbose_output.reduced" 
    # if [ $? -ne 0 ]; then
    #     echo "Error: mkdir $options $dir_name failed for reduced binary"
    #     return 1
    # fi


    # remove the binary name from the files
    sed -i "s/$(basename $ORIGINAL_BINARY)/$PROGRAM_NAME/g" "$verbose_output.orig"
    sed -i "s/$(basename $REDUCED_BINARY)/$PROGRAM_NAME/g" "$verbose_output.reduced"


    echo "Comparing verbose output of mkdir $options $dir_name..."
    echo "Original:"
    cat "$verbose_output.orig"
    echo "Reduced:"
    cat "$verbose_output.reduced"
    # Comparing the verbose outputs
    diff "$verbose_output.orig" "$verbose_output.reduced"
    if [ $? -ne 0 ]; then
        echo "Error: Verbose output of mkdir $options $dir_name is different"
        return 1
    fi
    PASSED_TESTS=$((PASSED_TESTS+1))
    rm -rf $DIR/directory
    return 0
}

# Function to test -p flag
test_mkdir_p() {
    TOTAL_TESTS=$((TOTAL_TESTS+1))

    local dir_name=$1

    # Executing: mkdir with the -p option for the reduced binary
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -p $dir_name; }
    if [ $? -ne 0 ]; then
        echo "Error: mkdir -p $dir_name failed for reduced binary"
        return 1
    fi
    # Checking if the directories were created successfully
    check_directories $dir_name
    if [ $? -ne 0 ]; then
        return 1
    fi
    PASSED_TESTS=$((PASSED_TESTS+1))
    rm -rf $DIR/directory
    return 0
}

# Function to test -pv flag
test_mkdir_pv() {
    TOTAL_TESTS=$((TOTAL_TESTS+1))
    local dir_name=$1

    # Executing: mkdir with the -pv option for the reduced binary
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -pv $dir_name; } 2> verbose_nested.reduced
    # if [ $? -ne 0 ]; then
    #     echo "Error: mkdir -pv $dir_name failed for reduced binary"
    #     return 1
    # fi
    # Checking if the directories were created successfully
    check_directories $dir_name
    if [ $? -ne 0 ]; then
        return 1
    fi

    rm -rf $DIR/directory

    # Executing: mkdir with the -pv option for the original binary
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -pv $dir_name; } 2> verbose_nested.orig
    # if [ $? -ne 0 ]; then
    #     echo "Error: mkdir -pv $dir_name failed for original binary"
    #     return 1
    # fi

    
    # remove the binary names from the files
    sed -i "s/$(basename $ORIGINAL_BINARY)/$PROGRAM_NAME/g" verbose_nested.orig
    sed -i "s/$(basename $REDUCED_BINARY)/$PROGRAM_NAME/g" verbose_nested.reduced

    echo "Comparing verbose output of mkdir -pv $dir_name"
    echo "Original:"
    cat verbose_nested.orig
    echo "Reduced:"
    cat verbose_nested.reduced
    # Comparing the verbose outputs
    diff verbose_nested.orig verbose_nested.reduced
    if [ $? -ne 0 ]; then
        echo "Error: Verbose output of mkdir -pv $dir_name is different"
        return 1
    fi
    PASSED_TESTS=$((PASSED_TESTS+1))
    rm -rf $DIR/directory
    return 0
}

run(){
{
    # Test cases for mkdir with the -p flag using the reduced and original binaries

    # Test case 1: Create a simple directory
    echo "Test Case 1: mkdir -p directory"
    test_mkdir_p "$DIR/directory"
    
    # Test case 2: Create nested directories
    echo "Test Case 2: mkdir -p directory/nested"
    test_mkdir_p "$DIR/directory/nested"

    # Test case 3: Create deeply nested directories
    echo "Test Case 3: mkdir -p directory/deep/nest1/nest2/nest3"
    test_mkdir_p "$DIR/directory/deep/nest1/nest2/nest3"

    # Test case 4   : Create multiple nested directories at once
    echo "Test Case 4: mkdir -p directory/multi1 directory/multi2"
    test_mkdir_p "$DIR/directory/multi1"
    # test_mkdir_p "$DIR/directory/multi2"

    # Test case 5: Create directories with special characters
    echo "Test Case 5: mkdir -p directory/special_@_#"
    test_mkdir_p "$DIR/directory/special_@_#"

    # Test case 6: Create directories with mixed cases
    echo "Test Case 6: mkdir -p directory/MixedCase/AnotherCase"
    test_mkdir_p "$DIR/directory/MixedCase/AnotherCase"

    # Test case 7: Create a directory with spaces
    echo "Test Case 7: mkdir -p 'directory/with spaces'"
    test_mkdir_p "$DIR/directory/with spaces"

    # Test case 8: Create directories with dashes and underscores
    echo "Test Case 8: mkdir -p directory/with-dashes_and_underscores"
    test_mkdir_p "$DIR/directory/with-dashes_and_underscores"

    # Test case 9: Create directories with numeric names
    echo "Test Case 9: mkdir -p directory/12345/67890"
    test_mkdir_p "$DIR/directory/12345/67890"

    # Test case 10: Create directories with dot characters
    echo "Test Case 10: mkdir -p directory/with.dots/another.dot"
    test_mkdir_p "$DIR/directory/with.dots/another.dot"
}
    {
    # Test cases for mkdir with the -v flag using the reduced and original binaries

    # Test case 11: Create a simple directory with verbose output
    echo "Test Case 11: mkdir -v directory"
    test_mkdir_v "-v" "$DIR/directory" "verbose_output_1"

    # Test case 12: Create nested directories with verbose output
    echo "Test Case 12: mkdir -v directory/nested"
    test_mkdir_v "-v" "$DIR/directory/nested" "verbose_output_2" "$DIR/directory"
 
    # Test case 13: Create deeply nested directories with verbose output
    echo "Test Case 13: mkdir -v directory/deep/nest1/nest2/nest3"
    test_mkdir_v "-v" "$DIR/directory/deep/nest1/nest2/nest3" "verbose_output_3" "$DIR/directory/deep/nest1/nest2"

    # Test case 14: Create multiple nested directories at once with verbose output
    echo "Test Case 14: mkdir -v directory/multi1 directory/multi2"
    test_mkdir_v "-v" "$DIR/directory/multi1 $DIR/directory/multi2" "verbose_output_4a" "$DIR/directory"

    # Test case 15: Create directories with special characters and verbose output
    echo "Test Case 15: mkdir -v directory/special_@_#"
    test_mkdir_v "-v" "$DIR/directory/special_@_#" "verbose_output_5" "$DIR/directory"

    # Test case 16: Create directories with mixed cases and verbose output
    echo "Test Case 16: mkdir -v directory/MixedCase/AnotherCase"
    test_mkdir_v "-v" "$DIR/directory/MixedCase/AnotherCase" "verbose_output_6" "$DIR/directory"

    # Test case 17: Create a directory with spaces and verbose output
    echo "Test Case 17: mkdir -v 'directory/with spaces'"
    test_mkdir_v "-v" "$DIR/directory/with spaces" "verbose_output_7" "$DIR/directory"

    # Test case 18: Create directories with dashes and underscores and verbose output
    echo "Test Case 18: mkdir -v directory/with-dashes_and_underscores"
    test_mkdir_v "-v" "$DIR/directory/with-dashes_and_underscores" "verbose_output_8" "$DIR/directory"

    # Test case 19: Create directories with numeric names and verbose output
    echo "Test Case 19: mkdir -v directory/12345/67890"
    test_mkdir_v "-v" "$DIR/directory/12345/67890" "verbose_output_9" "$DIR/directory/12345"

    # Test case 20: Create directories with dot characters and verbose output
    echo "Test Case 20: mkdir -v directory/with.dots/another.dot"
    test_mkdir_v "-v" "$DIR/directory/with.dots/another.dot" "verbose_output_10" "$DIR/directory/with.dots"
    }
{

    # Test cases for mkdir with the -pv flag using the reduced and original binaries

    # Test case 1: Create a simple directory with verbose and parent options
    echo "Test Case 21: mkdir -pv directory"
    test_mkdir_pv "$DIR/directory"

    # Test case 2: Create nested directories with verbose and parent options
    echo "Test Case 22: mkdir -pv directory/nested"
    test_mkdir_pv "$DIR/directory/nested"

    # Test case 23: Create deeply nested directories with verbose and parent options
    echo "Test Case 23: mkdir -pv directory/deep/nest1/nest2/nest3"
    test_mkdir_pv "$DIR/directory/deep/nest1/nest2/nest3"

    # Test case 24: Create multiple nested directories at once with verbose and parent options
    echo "Test Case 24: mkdir -pv directory/multi1 directory/multi2"
    test_mkdir_pv "$DIR/directory/multi1 $DIR/directory/multi2"

    # Test case 25: Create directories with special characters with verbose and parent options
    echo "Test Case 25: mkdir -pv directory/special_@_#"
    test_mkdir_pv "$DIR/directory/special_@_#"

    # Test case 26: Create directories with mixed cases with verbose and parent options
    echo "Test Case 26: mkdir -pv directory/MixedCase/AnotherCase"
    test_mkdir_pv "$DIR/directory/MixedCase/AnotherCase"

    # Test case 27: Create a directory with spaces with verbose and parent options
    echo "Test Case 27: mkdir -pv 'directory/with spaces'"
    test_mkdir_pv "$DIR/directory/with spaces"

    # Test case 28: Create directories with dashes and underscores with verbose and parent options
    echo "Test Case 28: mkdir -pv directory/with-dashes_and_underscores"
    test_mkdir_pv "$DIR/directory/with-dashes_and_underscores"

    # Test case 29: Create directories with numeric names with verbose and parent options
    echo "Test Case 29: mkdir -pv directory/12345/67890"
    test_mkdir_pv "$DIR/directory/12345/67890"

    # Test case 30: Create directories with dot characters with verbose and parent options
    echo "Test Case 30: mkdir -pv directory/with.dots/another.dot"
    test_mkdir_pv "$DIR/directory/with.dots/another.dot"
}

    echo "Test Passed: $PASSED_TESTS/$TOTAL_TESTS"
    return 0
}

clean_env(){
    echo "Cleaning environment..."
    rm -rf test_mkdir_single_p $REDUCED_BINARY $ORIGINAL_BINARY $LOG verbose_nested.orig verbose_nested.reduced verbose_single.orig verbose_single.reduced
}

main(){
    clean_env
    compile_files
    run
    if [ $? -ne 0 ]; then
        echo "Error: Test failed"
        clean_env
        exit 1
    fi
    clean_env
    exit 0
}

main