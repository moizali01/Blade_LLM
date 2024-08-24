#!/bin/bash

PROGRAM_NAME=bzip2
DIR=${PWD}
C_FILE=${DIR}/bzip2-util.c
REDUCED_BINARY=${DIR}/${PROGRAM_NAME}.rbin
ORG_BINARY=${DIR}/${PROGRAM_NAME}.bin
ORG_FILE=${DIR}/bzip2-org.c
CC=clang
TIMEOUT_LIMIT="-k 5 5"
LOG=${DIR}/log

FILE1="bzip2.bin"
FILE2="test2.txt"
# HARDCODED_FILES=("test2.txt" "test3.jpg" "test4")

function sed_command() {
    original_log=$1
    debloated_log=$2
    sed -i 's/^bzip2\.bin: //' ${original_log}
    sed -i 's/^bzip2\.rbin: //' ${debloated_log}
    file1_content=$(cat ${original_log})
    file2_content=$(cat ${debloated_log})
    if [[ "${file1_content}" != "${file2_content}" ]]; then
        echo "Mismatch in content of files before and after decompression" >>${LOG} 2>&1
        return 1
    fi
    return 0
}


function compress_and_decompress() {
    local files=("$@")
    rm -rf temp comparison >/dev/null 2>&1
    mkdir -p temp comparison >/dev/null 2>&1

    local file_list=""
    
    for file in "${files[@]}"; do
        cp "${file}" "temp/"
        file_list+="temp/$(basename ${file}) "
    done
    
    local compression_debloated="compression_debloated.txt"
    { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} temp/*; } &>>${compression_debloated} 
    a = $?
    if [[ $a -ne 0 ]]; then
        rm -rf temp comparison ${files[@]} >/dev/null 2>&1
        return 1
    fi
    local debloated_compressed_files=$(ls temp)

    if [[ $(ls temp | grep -v ".bz2" | wc -l) -ne 0 ]]; then
        echo "All files not compressed" >>${LOG} 2>&1
        rm -rf temp comparison ${files[@]} >/dev/null 2>&1
        return 1
    fi

    for file in temp/*; do
        filename=$(basename "$file")
        cp "$file" "comparison/debloated_$filename"
    done

    rm -rf temp >/dev/null 2>&1
    mkdir -p temp >/dev/null 2>&1

    file_list=""
    for file in "${files[@]}"; do
        cp "${file}" "temp/"
        file_list+="temp/$(basename ${file}) "
    done

    local compression_original="compression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} temp/*; } &>>${compression_original}
    a=$?
    if [[ $a -ne 0 ]]; then
        rm -rf temp comparison ${files[@]} >/dev/null 2>&1
        return 1
    fi
    local original_compressed_files=$(ls temp)

    for file in temp/*; do
        filename=$(basename "$file")
        cp "$file" "comparison/original_$filename"
    done

    if [[ "${original_compressed_files}" != "${debloated_compressed_files}" ]]; then
        echo "Mismatch in file names before and after compression" >>${LOG} 2>&1
        rm -rf temp comparison >/dev/null 2>&1
        return 1
    fi

    sed_command ${compression_original} ${compression_debloated} || return 1

    for file in $files; do
        filename=$(basename "$file")
        cmp "comparison/original_$filename.bz2" "comparison/debloated_$filename.bz2" &>>${LOG} || return 1
    done

    echo "Success" >>${LOG} 2>&1
    rm -rf temp comparison ${files[@]} >/dev/null 2>&1
    return 0

}

function clean_env() {
    cd ${DIR}
    rm -rf ${REDUCED_BINARY} ${ORG_BINARY} *.bz2 *.txt *.wav *.jpg log temp comparison >/dev/null 2>&1
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

    touch ${FILE2}
    echo "Processing single file:" >>${LOG} 2>&1
    compress_and_decompress "${FILE1}" || exit 1
    echo "Processing all files simultaneously:" >>${LOG} 2>&1
    compress_and_decompress "${FILE2}" || exit 1

    clean_env
}

main
