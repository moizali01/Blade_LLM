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

FILE="bzip2.bin"
HARDCODED_FILES=("test2.txt" "test3.txt" "test4.txt" "test5.txt")

function sed_command() {
    original_log=$1
    debloated_log=$2
    a=$3
    b=$4
    if [[ $a -ne $b ]]; then
        echo "Mismatch in return code between original and debloated binaries" >>${LOG} 2>&1
        return 1
    fi
    sed -i 's/^bzip2\.bin: //' ${original_log} 
    sed -i 's/^bzip2\.rbin: //' ${debloated_log} 
    compare_two_files ${original_log} ${debloated_log} || return 1
    return 0
}

function compare_two_files() {
    file1=$1
    file2=$2
    file1_content=$(cat ${file1})
    file2_content=$(cat ${file2})
    if [[ "${file1_content}" != "${file2_content}" ]]; then
        echo "Mismatch in content of files before and after decompression" >>${LOG} 2>&1
        return 1
    fi
}


function compress_and_decompress() {
    local files=("$@") 
    rm -rf temp comparison >/dev/null 2>&1
    mkdir -p temp >/dev/null 2>&1
    mkdir -p comparison >/dev/null 2>&1
    local file_list=""
    for file in "${files[@]}"; do
        cp "${file}" "temp/"
        file_list+="temp/$(basename ${file}) "
        filename=$(basename "$file")
        cp "$file" "comparison/original_$filename"
    done

    local compression_original="compression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} temp/*; } &>>${compression_original}
    local a=$?
    local original_compressed_files=$(ls temp)
    
    local decompression_original="decompression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -d temp/*; } &>>${decompression_original}
    local b=$?
    local original_decompressed_files=$(ls temp)

    rm -rf temp >/dev/null 2>&1
    mkdir -p temp >/dev/null 2>&1
    file_list=""
    for file in "${files[@]}"; do
        cp "${file}" "temp/"
        file_list+="temp/$(basename ${file}) "
    done


    local compression_debloated="compression_debloated.txt"
    { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} temp/*; } &>>${compression_debloated}
    local c=$?
    local debloated_compressed_files=$(ls temp)
    
    local decompression_debloated="decompression_debloated.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -d temp/*; } &>>${decompression_debloated}
    local d=$?
    local debloated_decompressed_files=$(ls temp)

    for file in temp/*; do
        filename=$(basename "$file")
        cp "$file" "comparison/debloated_$filename"
    done

    if [[ "${original_compressed_files}" != "${debloated_compressed_files}" ]]; then
        echo "Mismatch in file names before and after compression" >>${LOG} 2>&1
        rm -rf temp comparison >/dev/null 2>&1
        return 1
    fi

    if [[ "${original_decompressed_files}" != "${debloated_decompressed_files}" ]]; then
        echo "Mismatch in file names before and after decompression" >>${LOG} 2>&1
        rm -rf temp comparison >/dev/null 2>&1
        return 1
    fi
    sed_command ${compression_original} ${compression_debloated} $a $c || return 1
    sed_command ${decompression_original} ${decompression_debloated} $b $d || return 1

    for file in $files; do
        filename=$(basename "$file")
        diff "comparison/original_$filename" "comparison/debloated_$filename" > /dev/null || return 1
    done

    echo "Success" >>${LOG} 2>&1
    rm -rf temp comparison >/dev/null 2>&1
    return 0

}

function clean_env() {
    cd ${DIR}
    rm -rf ${REDUCED_BINARY} ${ORG_BINARY} *.bz2 *.txt temp comparison >/dev/null 2>&1
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
    for i in {1..5}; do
        clean_env
        compile || exit 1

        touch ${HARDCODED_FILES[0]}
        touch ${HARDCODED_FILES[4]}
        cp ${org_file} ${HARDCODED_FILES[0]}
        dd if=/dev/urandom of=${HARDCODED_FILES[1]} bs=1M count=1
        dd if=/dev/urandom of=${HARDCODED_FILES[2]} bs=1M count=1
        echo "Hello World I am test file" > ${HARDCODED_FILES[3]}
        echo "Processing single file:" >>${LOG} 2>&1
        compress_and_decompress "${FILE}" || exit 1
        echo "Processing all files simultaneously:" >>${LOG} 2>&1
        compress_and_decompress "${HARDCODED_FILES[@]}" || exit 1

        clean_env
    done
}

main