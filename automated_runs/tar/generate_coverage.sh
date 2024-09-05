#!/bin/bash

# Define the source code for tar (assuming it's a C program)
tar_source="tar-util.c"
tar_executable="tar.rbin"

# Check if the source file exists
if [[ ! -f "$tar_source" ]]; then
    echo "Source file $tar_source does not exist."
    exit 1
fi

clean_env() {
    # Remove the generated files
    rm -rf "$tar_executable" *.profraw merged.profdata archive.tar temp comparison *.txt *.bin coverage.txt log
}

# Compile the source code with LLVM profiling
clang -fprofile-instr-generate -fcoverage-mapping -o "$tar_executable" "$tar_source"

# Create a function to run the tar command and generate profile
run_tar_and_profile() {
    local files=("$@")
    local profile_name="tar_$(basename ${files[0]}).profraw"
    
    # Remove any existing directories to ensure a clean run
    rm -rf temp comparison

    # Set the LLVM profile file environment variable
    export LLVM_PROFILE_FILE="$profile_name"

    # Create temporary directories
    mkdir -p temp comparison

    # Copy files to temp
    for file in "${files[@]}"; do
        cp "$file" "temp/"
    done

    # Run the tar command to compress and decompress
    local tar_archive="archive.tar"
    local compression_log="compression_log.txt"
    local decompression_log="decompression_log.txt"

    ./"$tar_executable" -cf "$tar_archive" -C temp . &>> "$compression_log"
    ./"$tar_executable" -xf "$tar_archive" -C temp &>> "$decompression_log"

    # Compare original and decompressed files
    for file in "${files[@]}"; do
        filename=$(basename "$file")
        cp "$file" "comparison/original_$filename"
        cp "temp/$filename" "comparison/debloated_$filename"
        
        if diff "comparison/original_$filename" "comparison/debloated_$filename" >/dev/null; then
            echo "Decompressed file $filename matched the original file" >>"$compression_log"
        else
            echo "Error: Decompressed file $filename does not match the original file" >>"$compression_log"
        fi
    done

    echo "Profile generated: $profile_name"
}

# Run the tasks and generate LLVM profiles for different test cases
echo "I am a test file for tar" >test1.txt
touch test2.txt
cp "$tar_source" test2.txt
dd if=/dev/urandom of=test3.bin bs=1M count=1 2>/dev/null
touch test4.txt

run_tar_and_profile "test1.txt"
run_tar_and_profile "test2.txt" "test3.bin" "test4.txt"

echo "All profiles generated."

# Merge the profiles into a single profile data file
llvm-profdata merge -output=merged.profdata *.profraw

echo "Merged profile data: merged.profdata"

# Generate a coverage report in text format
llvm-cov show ./"$tar_executable" -instr-profile=merged.profdata > coverage.txt

echo "Coverage report generated: coverage.txt"
