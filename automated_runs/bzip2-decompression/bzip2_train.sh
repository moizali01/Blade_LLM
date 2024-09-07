#!/bin/bash

PROGRAM_NAME=bzip2
DIR=${PWD}
C_FILE=${DIR}/bzip2-util.c
REDUCED_BINARY=${DIR}/${PROGRAM_NAME}.rbin
ORG_BINARY=${DIR}/${PROGRAM_NAME}.bin
ORG_FILE=${DIR}/bzip2-org.c
CC=clang
TIMEOUT_LIMIT="-k 15 15"
LOG=${DIR}/log

FILE1="test1.txt"
FILE2=("test2.txt" "test3.bin" "test4.txt")

function compress_and_decompress() {
    # ((TOTAL_TESTS++))

    # echo "CASE: $TOTAL_TESTS" >>${LOG} 2>&1
    local files=("$@")
    rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
    mkdir -p temp >/dev/null 2>&1
    mkdir -p comparison >/dev/null 2>&1
    for file in "${files[@]}"; do
        cp "${file}" "temp/"
        filename=$(basename "$file")
        cp "$file" "comparison/original_$filename"
    done

    local compression_debloated="compression_debloated.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} temp/*; } &>>${compression_debloated}
    local a=$?
    if [[ $a -ne 0 ]]; then
        echo "Compression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
        return 1
    fi
    local debloated_compressed_files=$(ls temp)
    if find temp -type f ! -name "*.bz2" | grep -q .; then
        echo "Not all files are .bz2" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
        return 1

    else
        echo "All files are .bz2" >>${LOG} 2>&1
    fi

    local decompression_original="decompression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -d temp/*; } &>>${decompression_original}
    local b=$?
    if [[ $b -ne 0 ]]; then
        echo "Decompression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
        return 1
    fi
    local original_decompressed_files=$(ls temp)
    if find temp -type f -name "*.bz2" | grep -q .; then
        echo "There are .bz2 files" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
        return 1
    else
        echo "There are no .bz2 files" >>${LOG} 2>&1
    fi

    for file in temp/*; do
        filename=$(basename "$file")
        cp "$file" "comparison/debloated_$filename"
    done

    for file in $files; do
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
            rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1

            return 1
        fi
    done
    # ((PASSED_COUNT++))
    echo "Success" >>${LOG} 2>&1
    echo "" >>${LOG} 2>&1
    rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
    return 0

}

function clean_env() {
    local initial_state="$1"
    local final_state="$2"
    
    cd "${DIR}"
    
    # Function to clean ls output
    clean_ls_output() {
        awk '{print $NF}' | sed 's/^.*[0-9] //'
    }
    
    # Clean the input states
    initial_state=$(echo "$initial_state" | clean_ls_output)
    final_state=$(echo "$final_state" | clean_ls_output)
    
    # Find the differences
    local to_remove=$(comm -13 <(echo "$initial_state" | sort) <(echo "$final_state" | sort))
    
    # Remove the differences
    if [[ -n "$to_remove" ]]; then
        while IFS= read -r file; do
            if [[ -e "$file" ]]; then
                rm -rf -- "$file"
                echo "Removed: $file" > /dev/null
            else
                echo "File not found: $file" > /dev/null
            fi
        done <<< "$to_remove"
    else
        echo "No new files or directories to remove." > /dev/null
    fi
    
    return 0
}

function compile() {
    cd ${DIR}
    echo "Compiling ${C_FILE} into ${REDUCED_BINARY}" >/dev/null 2>&1
    ${CC} ${C_FILE} -w -o ${REDUCED_BINARY} &>>${LOG} || exit 1
    echo "Compiling ${ORG_FILE} into ${ORG_BINARY}" >/dev/null 2>&1
    ${CC} ${ORG_FILE} -w -o ${ORG_BINARY} &>>${LOG} || exit 1
    return 0
}

function main() {
    rm -rf temp comparison >/dev/null 2>&1
    rm -rf log
    compile || exit 1
    local initial_state=$(ls -al)
    local final_state=$(ls -al)
    clean_env "$initial_state" "$initial_state"

      # Empty File Test
    echo "Case: Empty File Test" >>${LOG} 2>&1
    touch empty_file.txt
    if compress_and_decompress "empty_file.txt"; then
        echo "Empty file test passed" > /dev/null
    else
        echo "Empty file test failed" > /dev/null
        final_state=$(ls -al)
        clean_env "$initial_state" "$final_state"
        exit 1
    fi

    echo "I am a test file for bzip2" >test1.txt
    touch test2.txt
    cp $ORG_FILE test2.txt
    cp $ORG_BINARY test3.bin
    touch test4.txt
    echo "Processing single file:" >>${LOG} 2>&1
    if compress_and_decompress "${FILE1}"; then
        echo "Processing single file test passed" > /dev/null
    else
        echo "Processing single file test failed" > /dev/null
        final_state=$(ls -al)
        clean_env "$initial_state" "$final_state"
        exit 1
    fi
    echo "Processing all files simultaneously:" >>${LOG} 2>&1
    if compress_and_decompress "${FILE2[@]}"; then
        echo "Processing all files simultaneously test passed" > /dev/null
    else
        echo "Processing all files simultaneously test failed" > /dev/null
        final_state=$(ls -al)
        clean_env "$initial_state" "$final_state"
        exit 1
    fi
    return 0
}

main
