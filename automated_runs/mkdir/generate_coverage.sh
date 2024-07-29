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
    rm -rf "$mkdir_executable" *.profraw merged.profdata test_mkdir*
}

# Compile the source code with LLVM profiling
clang-18 -fprofile-instr-generate -fcoverage-mapping -o "$mkdir_executable" "$mkdir_source"

# Create a function to run the mkdir command and generate profile
run_mkdir_and_profile() {
    local nested_dir="$1"
    local profile_name="$2"

    # Remove any existing directories to ensure clean run
    rm -rf "$nested_dir"

    # Set the LLVM profile file environment variable
    export LLVM_PROFILE_FILE="$profile_name"

    # Run the mkdir command to create the nested directory
    ./"$mkdir_executable" -p "$nested_dir"

    echo "Profile generated: $profile_name"
}

# Run the tasks and generate LLVM profiles
run_mkdir_and_profile "test_mkdir/level1/level2/level3/level4" "5_step_nested_directory.profraw"
run_mkdir_and_profile "test_mkdir_single_p/dir2" "2_step_nested_directory.profraw"

echo "All profiles generated."

# Merge the profiles into a single profile data file
llvm-profdata merge -output=merged.profdata 5_step_nested_directory.profraw 2_step_nested_directory.profraw

echo "Merged profile data: merged.profdata"

# Generate a coverage report in text format
llvm-cov show ./"$mkdir_executable" -instr-profile=merged.profdata > coverage.txt

echo "Coverage report generated: coverage_report.txt"
clean_env
