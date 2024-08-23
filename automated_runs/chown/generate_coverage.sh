#!/bin/bash

# Define the source code for chown (assuming it's a C program)
chown_source="chown-8.2.c.origin.c"
chown_executable="chown-8.2"

# Check if the source file exists
if [[ ! -f "$chown_source" ]]; then
    echo "Source file $chown_source does not exist."
    exit 1
fi

clean_env() {
    # Remove the generated files
    rm -rf "$chown_executable" *.profraw merged.profdata test_chown* d1
}

# Compile the source code with LLVM profiling
clang -fprofile-instr-generate -fcoverage-mapping -o "$chown_executable" "$chown_source"

# Create a function to run the chown command with the -R flag and generate profile
run_chown_and_profile() {
    local dir_name="$1"
    local owner_group="$2"
    local profile_name="$3"

    # Remove any existing directories to ensure a clean run
    rm -rf "$dir_name"
    
    # Create the directory structure
    mkdir -p "$dir_name"
    touch d1/file1
    touch d1/file2

    # Set the LLVM profile file environment variable
    export LLVM_PROFILE_FILE="$profile_name"

    # Run the chown command with the -R flag to change ownership recursively
    ./"$chown_executable" -R "$owner_group" "$dir_name"

    echo "Profile generated: $profile_name"
}

# Run the tasks and generate LLVM profiles for the specified -R flag test cases
# run_chown_and_profile "d1/" "user1" "chown_1.profraw"
run_chown_and_profile "d1/" "user1:group1" "chown_2.profraw"
# run_chown_and_profile "d1/" ":group1" "chown_3.profraw"

echo "All profiles generated."

# Merge the profiles into a single profile data file
llvm-profdata merge -output=merged.profdata chown_2.profraw

echo "Merged profile data: merged.profdata"

# Generate a coverage report in text format
llvm-cov show ./"$chown_executable" -instr-profile=merged.profdata > coverage.txt

echo "Coverage report generated: coverage.txt"

# Clean up the environment
clean_env