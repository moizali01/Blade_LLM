#!/bin/bash

PROGRAM_NAME=tar
DIR=${PWD}
C_FILE=${DIR}/tar-cov.c
REDUCED_BINARY=${DIR}/${PROGRAM_NAME}.rbin
ORG_BINARY=${DIR}/${PROGRAM_NAME}.bin
ORG_FILE=${DIR}/tar-org.c
CC=clang
TIMEOUT_LIMIT="-k 15 15"
LOG=${DIR}/log

# Hardcoded files
FUNCTIONALITY_PASSED_COUNT=0
FUNCTIONALITY_TOTAL_TESTS=0

SECURITY_PASSED_COUNT=0
SECURITY_TOTAL_TESTS=0

FUNCTIONALITY_DIR=${DIR}/compression_tests/functionality_files
SECURITY_DIR=${DIR}/compression_tests/security_cases
ROBUSTNESS_DIR=${DIR}/compression_tests/robustness_cases


function run_functionality_single_folder() {
    
    echo "CASE: $FUNCTIONALITY_TOTAL_TESTS" >>${LOG} 2>&1
    local files=("$@")
    rm -rf temp comparison  ${compression_debloated} ${decompression_original}  >/dev/null 2>&1
    mkdir -p temp >/dev/null 2>&1
    mkdir -p comparison >/dev/null 2>&1
    # echo ${files[@]}
    for file in "${files[@]}"; do
        # echo up
        cp "${file}" "temp/"
        filename=$(basename "$file")
        # echo $filename
        cp "$file" "comparison/original_$filename"
    done
    
    local tar_archive="archive.tar"
    local compression_debloated="compression_debloated.txt"
    # compression with reduced binary for debloating
    { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -cf ${tar_archive} -C temp .; } &>>${compression_debloated}
    local a=$?
    if [[ $a -ne 0 ]]; then
        echo "Compression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi
    rm temp/*

    # decompression with original binary to see results
    local decompression_original="decompression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -xf ${tar_archive} -C temp; } &>>${decompression_original}
    local b=$?
    if [[ $b -ne 0 ]]; then
        echo "Decompression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi
    # add a check to see if temp is empty
    if [ -z "$(ls -A temp)" ]; then
        echo "Decompression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi

    for file in temp/*; do
        filename=$(basename "$file")
        cp "$file" "comparison/debloated_$filename"
    done
    
    for file in "${files[@]}"; do
        filename=$(basename "$file")
        if diff "comparison/original_$filename" "comparison/debloated_$filename" >/dev/null; then
            echo "Decompressed file matched the original file" >/dev/null 2>&1
        else
            echo "Error: Decompressed file does not match the original file" >>${LOG} 2>&1
            echo "Original:" >>${LOG} 2>&1
            echo "====================" >>${LOG} 2>&1
            echo "$(cat comparison/original_$filename)" >>${LOG} 2>&1
            echo "====================" >>${LOG} 2>&1
            echo "Debloated:" >>${LOG} 2>&1
            echo "====================" >>${LOG} 2>&1
            echo "$(cat comparison/debloated_$filename)" >>${LOG} 2>&1
            echo "====================" >>${LOG} 2>&1
            rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
            return 1
        fi
    done
    echo "Success" >>${LOG} 2>&1
    echo "" >>${LOG} 2>&1
    rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
    return 0
}

function run_functionality_sparse_nested_folders() {
    echo "CASE: $FUNCTIONALITY_TOTAL_TESTS" >>${LOG} 2>&1
    local file="$1"
    
    if [ -z "$file" ]; then
        echo "Error: One file is required for this test" >>${LOG} 2>&1
        return 1
    fi
    
    rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
    mkdir -p temp/dir1/subdir1 temp/dir2/subdir2 temp/dir3/subdir3 temp/dir4 >/dev/null 2>&1
    mkdir -p comparison >/dev/null 2>&1
    
    # Place the file in a random subdirectory
    local dirs=(
        "temp/"
        "temp/dir1/"
        "temp/dir1/subdir1/"
        "temp/dir2/subdir2/"
        "temp/dir3/subdir3/"
    )
    local random_dir=${dirs[$RANDOM % ${#dirs[@]}]}
    cp "$file" "$random_dir"
    filename=$(basename "$file")
    cp "$file" "comparison/original_$filename"
    
    local tar_archive="archive.tar"
    local compression_debloated="compression_debloated.txt"
    
    # Compression with reduced binary for debloating
    { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -cf ${tar_archive} -C temp .; } &>>${compression_debloated}
    local a=$?
    if [[ $a -ne 0 ]]; then
        echo "Compression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi
    
    rm -rf temp/*
    
    # Decompression with original binary to see results
    local decompression_original="decompression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -xf ${tar_archive} -C temp; } &>>${decompression_original}
    local b=$?
    if [[ $b -ne 0 ]]; then
        echo "Decompression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi
    
    # Check if temp is empty
    if [ -z "$(find temp -type f)" ]; then
        echo "Decompression failed: No files found" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi
    
    # Compare original and decompressed file
    decompressed_file=$(find temp -name "$filename")
    if [ -z "$decompressed_file" ]; then
        echo "Error: Decompressed file $filename not found" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi
    
    if ! diff "comparison/original_$filename" "$decompressed_file" >/dev/null; then
        echo "Error: Decompressed file $filename does not match the original file" >>${LOG} 2>&1
        echo "Original:" >>${LOG} 2>&1
        echo "====================" >>${LOG} 2>&1
        cat "comparison/original_$filename" >>${LOG} 2>&1
        echo "====================" >>${LOG} 2>&1
        echo "Debloated:" >>${LOG} 2>&1
        echo "====================" >>${LOG} 2>&1
        cat "$decompressed_file" >>${LOG} 2>&1
        echo "====================" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi
    
    echo "Success: File matched after compression and decompression" >>${LOG} 2>&1
    echo "" >>${LOG} 2>&1
    rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
    return 0
}

function run_functionality_nested_folders() {
    echo "CASE: $FUNCTIONALITY_TOTAL_TESTS" >>${LOG} 2>&1
    local files=("$@")
    
    if [ ${#files[@]} -lt 5 ]; then
        echo "Error: At least 5 files are required for this test" >>${LOG} 2>&1
        return 1
    fi

    rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
    mkdir -p temp/dir1/subdir1 temp/dir2/subdir2 temp/dir3 >/dev/null 2>&1
    mkdir -p comparison >/dev/null 2>&1

    # Array of target directories
    local dirs=("temp/" "temp/dir1/" "temp/dir1/subdir1/" "temp/dir2/subdir2/" "temp/dir3/")
    local dir_count=${#dirs[@]}

    # Distribute files across nested directories
    for i in "${!files[@]}"; do
        local target_dir=${dirs[$((i % dir_count))]}
        cp "${files[i]}" "$target_dir"
        filename=$(basename "${files[i]}")
        cp "${files[i]}" "comparison/original_$filename"
    done

    local tar_archive="archive.tar"
    local compression_debloated="compression_debloated.txt"

    # Compression with reduced binary for debloating
    { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -cf ${tar_archive} -C temp .; } &>>${compression_debloated}
    local a=$?
    if [[ $a -ne 0 ]]; then
        echo "Compression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi

    rm -rf temp/*

    # Decompression with original binary to see results
    local decompression_original="decompression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -xf ${tar_archive} -C temp; } &>>${decompression_original}
    local b=$?
    if [[ $b -ne 0 ]]; then
        echo "Decompression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi

    # Check if temp is empty
    if [ -z "$(find temp -type f)" ]; then
        echo "Decompression failed: No files found" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi

    # Compare original and decompressed files
    for file in "${files[@]}"; do
        filename=$(basename "$file")
        decompressed_file=$(find temp -name "$filename")
        if [ -z "$decompressed_file" ]; then
            echo "Error: Decompressed file $filename not found" >>${LOG} 2>&1
            rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
            return 1
        fi
        if ! diff "comparison/original_$filename" "$decompressed_file" >/dev/null; then
            echo "Error: Decompressed file $filename does not match the original file" >>${LOG} 2>&1
            echo "Original:" >>${LOG} 2>&1
            echo "====================" >>${LOG} 2>&1
            cat "comparison/original_$filename" >>${LOG} 2>&1
            echo "====================" >>${LOG} 2>&1
            echo "Debloated:" >>${LOG} 2>&1
            echo "====================" >>${LOG} 2>&1
            cat "$decompressed_file" >>${LOG} 2>&1
            echo "====================" >>${LOG} 2>&1
            rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
            return 1
        fi
    done

    echo "Success: All files matched after compression and decompression" >>${LOG} 2>&1
    echo "" >>${LOG} 2>&1
    rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
    return 0
}

function clean_env() {
    cd ${DIR}
    rm -rf ${REDUCED_BINARY} ${ORG_BINARY} *.txt.gz *.txt binary_file *.tar *.jpg *.wav *.png *.mp3 *.csv *.json *.bin *exe *tar *.flac *.bmp *tar *.ogg *.pdf *.gif >/dev/null 2>&1
    rm -rf temp comparison ${compression_original} ${compression_debloated} ${decompression_original} ${decompression_debloated} >/dev/null 2>&1
    rm -rf *.jpg *.wav >/dev/null 2>&1
    return 0
}

function compile() {
    touch ${LOG}
    cd ${DIR}
    echo "Compiling ${C_FILE} into ${REDUCED_BINARY}" 2>&1
    ${CC} ${C_FILE} -w -o ${REDUCED_BINARY} &>>${LOG} || exit 1
    echo "Compiling ${ORG_FILE} into ${ORG_BINARY}" 2>&1
    ${CC} ${ORG_FILE} -w -o ${ORG_BINARY} &>>${LOG} || exit 1
    return 0
}

function execute_tests_functionality() {
    
    echo "=========================="
    echo "Functionality Related Tests"
    echo "=========================="

    all_files=($(ls "$FUNCTIONALITY_DIR" | shuf))
    all_files=("${all_files[@]/#/${FUNCTIONALITY_DIR}/}")
    selected_files=($(printf "%s\n" "${all_files[@]}" | shuf -n 5))

    # but 1-2 files in a nested Directory
    for file in "${selected_files[@]}"; do
        echo "Running test on random file: $file"
        run_functionality_sparse_nested_folders ${file} && ((FUNCTIONALITY_PASSED_COUNT++))
        ((FUNCTIONALITY_TOTAL_TESTS++))
    done

    # but 1-2 files in a nested Directory
    for file in "${selected_files[@]}"; do
        echo "Running test on random file: $file"
        run_functionality_single_folder ${file} && ((FUNCTIONALITY_PASSED_COUNT++))
        ((FUNCTIONALITY_TOTAL_TESTS++))
    done

    # Test Case 1: Two Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 2))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_single_folder ${files[@]} && ((FUNCTIONALITY_PASSED_COUNT++))

    # Test Case 2: Five Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 5))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_single_folder ${files[@]}  && ((FUNCTIONALITY_PASSED_COUNT++))

    # Test Case 3: 10 Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 10))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_single_folder ${files[@]} && ((FUNCTIONALITY_PASSED_COUNT++))

    # Test Case 3: 20 Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 20))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_single_folder ${files[@]} && ((FUNCTIONALITY_PASSED_COUNT++))

    # Test Case 3: 30 Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 20))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_single_folder ${files[@]} && ((FUNCTIONALITY_PASSED_COUNT++))


    #### Nested Folders
    
    # Test Case 4: 5 Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 5))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_nested_folders ${files[@]}  && ((FUNCTIONALITY_PASSED_COUNT++))

    # Test Case 5: 10 Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 10))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_nested_folders ${files[@]} && ((FUNCTIONALITY_PASSED_COUNT++))

    # Test Case 6: 15 Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 15))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_nested_folders ${files[@]} && ((FUNCTIONALITY_PASSED_COUNT++))

    # Test Case 7: 20 Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 20))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_nested_folders ${files[@]} && ((FUNCTIONALITY_PASSED_COUNT++))

    # Test Case 8: 30 Files
    ((FUNCTIONALITY_TOTAL_TESTS++))
    files=($(ls $FUNCTIONALITY_DIR | shuf -n 30))
    files=("${files[@]/#/${FUNCTIONALITY_DIR}/}")
    echo "Running test: Multiple files"
    # echo "File List: ${files[@]}"
    run_functionality_nested_folders ${files[@]} && ((FUNCTIONALITY_PASSED_COUNT++))

    # Test Case: Symlinks
    ((FUNCTIONALITY_TOTAL_TESTS++))
    echo "Symlink target" > "$FUNCTIONALITY_DIR/symlink_target.txt"
    ln -s "$FUNCTIONALITY_DIR/symlink_target.txt" "$FUNCTIONALITY_DIR/symlink.txt"
    echo "Running test: Symlinks"
    run_functionality_single_folder "$FUNCTIONALITY_DIR/symlink_target.txt" "$FUNCTIONALITY_DIR/symlink.txt" && ((FUNCTIONALITY_PASSED_COUNT++))
    rm "$FUNCTIONALITY_DIR/symlink_target.txt" "$FUNCTIONALITY_DIR/symlink.txt"

    # Test Case: Files with special characters in names
    ((FUNCTIONALITY_TOTAL_TESTS++))
    touch "$FUNCTIONALITY_DIR/file with spaces.txt" "$FUNCTIONALITY_DIR/file_with_$ymbols.txt" "$FUNCTIONALITY_DIR/file_with_ñöñ_äscïï.txt"
    echo "Running test: Files with special characters in names"
    run_functionality_single_folder "$FUNCTIONALITY_DIR/file with spaces.txt" "$FUNCTIONALITY_DIR/file_with_$ymbols.txt" "$FUNCTIONALITY_DIR/file_with_ñöñ_äscïï.txt" && ((FUNCTIONALITY_PASSED_COUNT++))
    rm "$FUNCTIONALITY_DIR/file with spaces.txt" "$FUNCTIONALITY_DIR/file_with_$ymbols.txt" "$FUNCTIONALITY_DIR/file_with_ñöñ_äscïï.txt"



}


function execute_tests_security() {

    echo "=========================="
    echo "Security Related Tests"
    echo "=========================="
    
    for file in $SECURITY_DIR/*; do
        echo "Running test $file"
        run_functionality_single_folder $file && ((SECURITY_PASSED_COUNT++))
        ((SECURITY_TOTAL_TESTS++))
    done

    # randomly pick two files from the functionality_files
    files=($(ls $SECURITY_DIR | shuf -n 2))
    files=("${files[@]/#/${SECURITY_DIR}/}")
    echo "Running test: Multiple files"
    run_functionality_single_folder ${files[@]} && ((SECURITY_PASSED_COUNT++))
    ((SECURITY_TOTAL_TESTS++))
    
    #randomly pick four files from the security_dir
    files=($(ls $SECURITY_DIR | shuf -n 4))
    files=("${files[@]/#/${SECURITY_DIR}/}")
    echo "Running test: Multiple files"
    run_functionality_single_folder ${files[@]} && ((SECURITY_PASSED_COUNT++))
    ((SECURITY_TOTAL_TESTS++))

    files=($(ls $SECURITY_DIR | shuf -n 5))
    files=("${files[@]/#/${SECURITY_DIR}/}")
    echo "Running test: Multiple files"
    run_functionality_single_folder ${files[@]} && ((SECURITY_PASSED_COUNT++))
    ((SECURITY_TOTAL_TESTS++))

    files=($(ls $SECURITY_DIR | shuf -n 5))
    files=("${files[@]/#/${SECURITY_DIR}/}")
    echo "Running test: Multiple files"
    run_functionality_nested_folders ${files[@]} && ((SECURITY_PASSED_COUNT++))
    ((SECURITY_TOTAL_TESTS++))
    
}

function run_robustness() {
    ((ROBUSTNESS_TOTAL_TESTS++))
    
    description=$1
    command=$2
    
    echo -e "CASE: $TOTAL_TESTS, $description" >>${LOG} 2>&1
    eval "$command" >>${LOG} 2>&1
    a=$?
    echo $a
    if [[ $a -ne 124 && $a -ne 137 ]]; then
        ((ROBUSTNESS_PASSED_COUNT++))
        return 0
    else
        echo "Test failed: $description" >>${LOG} 2>&1
        return 1
    fi
    
}

function robustness_cases() {
    echo "=========================="
    echo "Robustness Related Tests"
    echo "=========================="
    local robustness_dir="robustness_cases"
    local tar_archive="test_archive.tar"

    # Create a temporary directory for test files
    mkdir -p temp
    touch temp/file1.txt temp/file2.txt

    for file in $robustness_dir/*; do
        echo "Running test $file"
        run_robustness "Robustness test file: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -cf $tar_archive -C $robustness_dir $(basename $file); }"
        rm -rf temp $tar_archive
    done

    echo "Running test: Invalid Flag"
    run_robustness "Invalid Flag" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -X $tar_archive -C temp .; }"
    rm -rf temp $tar_archive

    echo "Running test: No arguments"
    run_robustness "No arguments" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY; }"
    rm -rf temp $tar_archive

    echo "Running test: Non-existent file"
    run_robustness "Non-existent file" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -cf $tar_archive nonexistent.txt; }"
    rm -rf temp $tar_archive

    echo "Running test: Extract non-existent archive"
    run_robustness "Extract non-existent archive" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -xf nonexistent.tar; }"
    rm -rf temp $tar_archive

    echo "Running test: Create archive from directory"
    run_robustness "Create archive from directory" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -cf $tar_archive temp; }"
    rm -rf temp $tar_archive

    flags=(-v -z -j -W --help --version)
    for flag in "${flags[@]}"; do
        echo "Running test: Various Flags"
        run_robustness "Various Flags" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $flag $tar_archive -C temp .; }"
        rm -rf temp $tar_archive
    done

    # Test with different compression options
    compression_flags=(a z j J)
    for flag in "${compression_flags[@]}"; do
        echo "Running test: Compression Flag $flag"
        run_robustness "Compression Flag $flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -c$flag $tar_archive -C temp .; }"
        rm -rf temp $tar_archive
    done

    # Test extraction
    echo "Running test: Extract archive"
    run_robustness "Extract archive" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -xf $tar_archive; }"
    rm -rf temp $tar_archive

    # Test listing contents
    echo "Running test: List archive contents"
    run_robustness "List archive contents" \
    "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -tf $tar_archive; }"
    rm -rf temp $tar_archive

    # Clean up
    # rm -rf temp $tar_archive
}


function main() {
    rm -rf temp log *.log
    clean_env
    compile || exit 1
    execute_tests_functionality 
    execute_tests_security 
    robustness_cases 
    echo "Total Functionality Tests: $FUNCTIONALITY_TOTAL_TESTS, Passed: $FUNCTIONALITY_PASSED_COUNT, Failed: $(($FUNCTIONALITY_TOTAL_TESTS - $FUNCTIONALITY_PASSED_COUNT))"
    echo "Total Security Tests: $SECURITY_TOTAL_TESTS, Passed: $SECURITY_PASSED_COUNT, Failed: $(($SECURITY_TOTAL_TESTS - $SECURITY_PASSED_COUNT))"
    echo "Total Robustness Tests: $ROBUSTNESS_TOTAL_TESTS, Passed: $ROBUSTNESS_PASSED_COUNT, Failed: $(($ROBUSTNESS_TOTAL_TESTS - $ROBUSTNESS_PASSED_COUNT))"
    if [ $FUNCTIONALITY_PASSED_COUNT -eq $FUNCTIONALITY_TOTAL_TESTS ]; then
        echo "All tests passed successfully."
    else
        echo "Some tests failed"
    fi
    
    echo "Total Passed: $(($FUNCTIONALITY_PASSED_COUNT + $SECURITY_PASSED_COUNT + $ROBUSTNESS_PASSED_COUNT))"
    echo "Total Tests: $(($FUNCTIONALITY_TOTAL_TESTS + $SECURITY_TOTAL_TESTS + $ROBUSTNESS_TOTAL_TESTS))"
    rm -rf temp
    clean_env
}

main