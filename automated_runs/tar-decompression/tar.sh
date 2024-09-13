#!/bin/bash

PROGRAM_NAME=tar
DIR=${PWD}
C_FILE=${DIR}/tar-util.c
REDUCED_BINARY=${DIR}/${PROGRAM_NAME}.rbin
ORG_BINARY=${DIR}/${PROGRAM_NAME}.bin
ORG_FILE=${DIR}/tar-org.c
CC=clang
TIMEOUT_LIMIT="-k 5 5"
LOG=${DIR}/log

FILE1="test1.txt"
FILE2=("test2.txt" "test3.bin" "test4.txt")
# HARDCODED_FILES=("test2.txt" "test3.jpg" "test4")
function run() {
    ((TOTAL_TESTS++))
    
    echo "CASE: $TOTAL_TESTS" >>${LOG} 2>&1
    local files=("$@")
    rm -rf temp comparison  ${compression_debloated} ${decompression_original}  >/dev/null 2>&1
    mkdir -p temp >/dev/null 2>&1
    mkdir -p comparison >/dev/null 2>&1
    # echo ${files[@]}
    for file in "${files[@]}"; do
        cp "${file}" "temp/"
        filename=$(basename "$file")
        cp "$file" "comparison/original_$filename"
    done
    
    local tar_archive="archive.tar"
    local compression_debloated="compression_debloated.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -cf ${tar_archive} -C temp .; } &>>${compression_debloated}
    local a=$?
    if [[ $a -ne 0 ]]; then
        echo "Compression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
        return 1
    fi
    rm temp/*
    local decompression_original="decompression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -xf ${tar_archive} -C temp; } &>>${decompression_original}
    local b=$?
    if [[ $b -ne 0 ]]; then
        echo "Decompression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
        return 1
    fi
    # add a check to see if temp is empty
    if [ -z "$(ls -A temp)" ]; then
        echo "Decompression failed" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
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
            rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
            return 1
        fi
    done
    ((PASSED_COUNT++))
    echo "Success" >>${LOG} 2>&1
    echo "" >>${LOG} 2>&1
    rm -rf temp comparison ${compression_debloated} ${decompression_original} ${files[@]} >/dev/null 2>&1
    return 0
}

function clean_env() {
    cd ${DIR}
    rm -rf ${REDUCED_BINARY} ${ORG_BINARY} *.txt *.bin log temp comparison archive.tar >/dev/null 2>&1
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
    clean_env
    compile || exit 1

    echo "I am a test file for tar" >test1.txt
    touch test2.txt
    cp $ORG_FILE test2.txt
    dd if=/dev/urandom of=test3.bin bs=1M count=1 2>/dev/null
    touch test4.txt
    echo "Processing single file:" >>${LOG} 2>&1
    run "${FILE1}" || exit 1
    echo "Processing all files simultaneously:" >>${LOG} 2>&1
    run "${FILE2}" || exit 1

    clean_env
}

main
