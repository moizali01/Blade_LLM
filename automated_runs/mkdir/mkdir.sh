#!/bin/bash

# Paths to the files
PROGRAM_NAME="mkdir-8.30"
DIR=$(pwd)
ORIGINAL_FILE="mkdir-5.2.1.c.origin.c"
DEBLOATED_FILE="mkdir-debloated.c"
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang-14
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log.txt
NESTED_DIR="test_mkdir/level1/level2/level3/level4/level5"
SINGLE_DIR_P="test_mkdir_single_p/dir2"
SINGLE_DIR_V="test_mkdir_single_v"

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
compare_verbose_output() {
    local options=$1
    local dir_name=$2
    local verbose_output=$3

    # Executing: mkdir with the given options for the original binary
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $options $dir_name; } 2> "$verbose_output.orig" 
    if [ $? -ne 0 ]; then
        echo "Error: mkdir $options $dir_name failed for original binary"
        return 1
    fi

    # Removing the created directories to test with the reduced binary
    rm -rf $(echo $dir_name | cut -d'/' -f1)

    # Executing: mkdir with the given options for the reduced binary
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $options $dir_name; } 2> "$verbose_output.reduced" 
    if [ $? -ne 0 ]; then
        echo "Error: mkdir $options $dir_name failed for reduced binary"
        return 1
    fi


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

    return 0
}

# Function to test -p flag
test_mkdir_p() {
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

    return 0
}

# Function to test -pv flag
test_mkdir_pv() {
    local dir_name=$1

    # Executing: mkdir with the -pv option for the reduced binary
    { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -pv $dir_name; } 2> verbose_nested.reduced
    if [ $? -ne 0 ]; then
        echo "Error: mkdir -pv $dir_name failed for reduced binary"
        return 1
    fi
    # Checking if the directories were created successfully
    check_directories $dir_name
    if [ $? -ne 0 ]; then
        return 1
    fi

    rm -rf $(echo $dir_name | cut -d'/' -f1)

    # Executing: mkdir with the -pv option for the original binary
    { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY -pv $dir_name; } 2> verbose_nested.orig
    if [ $? -ne 0 ]; then
        echo "Error: mkdir -pv $dir_name failed for original binary"
        return 1
    fi

    rm -rf $(echo $dir_name | cut -d'/' -f1)
    
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

    return 0
}

run(){

    # Test case 2: Create a single folder with the -p flag
    echo "Test Case 1: mkdir -pv $SINGLE_DIR_P"
    test_mkdir_p $SINGLE_DIR_P
    if [ $? -ne 0 ]; then
        return 1
    fi

    # # Test case 3: Create a single folder with the -v flag
    # echo "Test Case 2: mkdir -v $SINGLE_DIR_V"
    # compare_verbose_output "-v" $SINGLE_DIR_V "verbose_single"
    # if [ $? -ne 0 ]; then
    #     return 1
    # fi
    # Test case 1: Create a 5-level nested directory with the -pv flag
    echo "Test Case 2: mkdir -pv $NESTED_DIR"
    test_mkdir_p $NESTED_DIR
    if [ $? -ne 0 ]; then
        return 1
    fi
}

clean_env(){
    echo "Cleaning environment..."
    rm -rf test_mkdir_single_p $REDUCED_BINARY $ORIGINAL_BINARY $LOG test_mkdir $SINGLE_DIR_P $SINGLE_DIR_V verbose_nested.orig verbose_nested.reduced verbose_single.orig verbose_single.reduced
}

# sanitizers=("-fsanitize=cfi -flto -fvisibility=hidden" "-fsanitize=address"
#   "-fsanitize=memory -fsanitize-memory-use-after-dtor"
#   "-fno-sanitize-recover=undefined,nullability"
#   "-fsanitize=leak")

main(){
    # for sanitizer in "${sanitizers[@]}"; do
    #     clean_env
    #     compile_files
    #     run
    #     if [ $? -ne 0 ]; then
    #         echo "Error: Test failed"
    #         clean_env
    #         exit 1
    #     fi
    #     clean_env
    # done
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
