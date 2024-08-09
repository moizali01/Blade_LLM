#!/bin/bash

# Define the source code for mkdir (assuming it's a C program)
mkdir_source="mkdir-5.2.1.c.origin.c"
mkdir_executable="mkdir-5.2.1"

# Check if the source file exists
if [[ ! -f "$mkdir_source" ]]; then
    echo "Source file $mkdir_source does not exist."
    exit 1
fi

clean_env() {
    # Remove the generated files
    rm -rf "$mkdir_executable" *.profraw merged.profdata test_mkdir* coverage.txt
}

# Compile the source code with LLVM profiling
clang-18 -fprofile-instr-generate -fcoverage-mapping -o "$mkdir_executable" "$mkdir_source"

# Create a function to run the mkdir command with the -m flag and generate profile
run_mkdir_and_profile() {
    local dir_name="$1"
    local permissions="$2"
    local profile_name="$3"

    # Remove any existing directories to ensure a clean run
    rm -rf "$dir_name"

    # Set the LLVM profile file environment variable
    export LLVM_PROFILE_FILE="$profile_name"

    # Run the mkdir command with the -m flag to create the directory
    ./"$mkdir_executable" -m "$permissions" "$dir_name"

    echo "Profile generated: $profile_name"
}

# Run the tasks and generate LLVM profiles for the -m flag test cases
run_mkdir_and_profile "test_mkdir_400" "400" "mkdir_400.profraw"
run_mkdir_and_profile "test_mkdir_500" "500" "mkdir_500.profraw"
run_mkdir_and_profile "test_mkdir_644" "644" "mkdir_644.profraw"
run_mkdir_and_profile "test_mkdir_700" "700" "mkdir_700.profraw"
run_mkdir_and_profile "test_mkdir_755" "755" "mkdir_755.profraw"
run_mkdir_and_profile "test_mkdir_777" "777" "mkdir_777.profraw"

echo "All profiles generated."

# Merge the profiles into a single profile data file
llvm-profdata merge -output=merged.profdata mkdir_400.profraw mkdir_500.profraw mkdir_644.profraw mkdir_700.profraw mkdir_755.profraw mkdir_777.profraw

echo "Merged profile data: merged.profdata"

# Generate a coverage report in text format
llvm-cov show ./"$mkdir_executable" -instr-profile=merged.profdata > coverage.txt

echo "Coverage
