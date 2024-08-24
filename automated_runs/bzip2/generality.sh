#!/bin/bash

PROGRAM_NAME=bzip2
DIR=${PWD}
C_FILE=${DIR}/bzip2-util.c
REDUCED_BINARY=${DIR}/${PROGRAM_NAME}.rbin
ORG_BINARY=${DIR}/${PROGRAM_NAME}.bin
ORG_FILE=${DIR}/bzip2-org.c
CC=clang
TIMEOUT_LIMIT="-k 100 100"
LOG=${DIR}/log

# Hardcoded files
FILE="test1.txt"
HARDCODED_FILES=("test2.txt" "test3.txt" "test4.txt" "test5.txt")
PASSED_COUNT=0
PASSED_EXCEPTION=0
TOTAL_EXCEPTIONS=4
TOTAL_TESTS=0

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
    if diff ${original_log} ${debloated_log} >/dev/null; then
        echo "" >/dev/null 2>&1
    else
        echo "Mismatch in decompression output between original and debloated binaries" >>${LOG} 2>&1
        echo "Original:" >>${LOG} 2>&1
        echo "====================" >>${LOG} 2>&1
        echo "$(cat ${original_log})" >>${LOG} 2>&1
        echo "====================" >>${LOG} 2>&1

        echo "Debloated:" >>${LOG} 2>&1
        echo "====================" >>${LOG} 2>&1
        echo "$(cat ${debloated_log})" >>${LOG} 2>&1
        echo "====================" >>${LOG} 2>&1
        return 1
    fi
    return 0
}

function compress_and_decompress() {
    ((TOTAL_TESTS++))
    
    echo "CASE: $TOTAL_TESTS" >>${LOG} 2>&1
    local files=("$@")
    rm -rf temp comparison ${compression_original} ${compression_debloated} ${decompression_original} ${decompression_debloated} >/dev/null 2>&1
    mkdir -p temp >/dev/null 2>&1
    mkdir -p comparison >/dev/null 2>&1
    local file_list=""
    for file in "${files[@]}"; do
        cp "${file}" "temp/"
        file_list+="temp/$(basename ${file}) "
        filename=$(basename "$file")
        cp "$file" "comparison/original_$filename"
    done
    echo "TEMPDIR: $(ls temp)" >>${LOG} 2>&1

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
    if sed_command ${compression_original} ${compression_debloated} $a $c && sed_command ${decompression_original} ${decompression_debloated} $b $d; then
        echo "" >/dev/null 2>&1
    else
        echo "Mismatch in compression output between original and debloated binaries" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_original} ${compression_debloated} ${decompression_original} ${decompression_debloated} ${files[@]} >/dev/null 2>&1
        return 1
    fi

    if [[ "${original_compressed_files}" != "${debloated_compressed_files}" ]]; then
        echo "Mismatch in file names before and after compression" >>${LOG} 2>&1
        echo "Original: ${original_compressed_files}" >>${LOG} 2>&1
        echo "Debloated: ${debloated_compressed_files}" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_original} ${compression_debloated} ${decompression_original} ${decompression_debloated} ${files[@]} >/dev/null 2>&1
        return 1
    fi

    if [[ "${original_decompressed_files}" != "${debloated_decompressed_files}" ]]; then
        echo "Mismatch in file names before and after decompression" >>${LOG} 2>&1
        echo "Original: ${original_decompressed_files}" >>${LOG} 2>&1
        echo "Debloated: ${debloated_decompressed_files}" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_original} ${compression_debloated} ${decompression_original} ${decompression_debloated} ${files[@]} >/dev/null 2>&1
        return 1
    fi

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
            rm -rf temp comparison ${compression_original} ${compression_debloated} ${decompression_original} ${decompression_debloated} ${files[@]} >/dev/null 2>&1

            return 1
        fi
    done
    ((PASSED_COUNT++))
    echo "Success" >>${LOG} 2>&1
    echo "" >>${LOG} 2>&1
    rm -rf temp comparison ${compression_original} ${compression_debloated} ${decompression_original} ${decompression_debloated} ${files[@]} >/dev/null 2>&1
    return 0

}

function clean_env() {
    cd ${DIR}
    rm -rf ${REDUCED_BINARY} ${ORG_BINARY} *.txt.gz *.txt binary_file *.tar >/dev/null 2>&1
    rm -rf temp comparison ${compression_original} ${compression_debloated} ${decompression_original} ${decompression_debloated} ${files[@]} >/dev/null 2>&1
    rm -rf *.jpg *.wav >/dev/null 2>&1
    return 0
}

function compile() {
    cd ${DIR}
    echo "Compiling ${C_FILE} into ${REDUCED_BINARY}" 2>&1
    ${CC} ${C_FILE} -w -o ${REDUCED_BINARY} &>>${LOG} || exit 1
    echo "Compiling ${ORG_FILE} into ${ORG_BINARY}" 2>&1
    ${CC} ${ORG_FILE} -w -o ${ORG_BINARY} &>>${LOG} || exit 1
    return 0
}

function execute_tests() {
    # 1 Byte File Test
    echo "Case: 1 Byte File Test" >>${LOG} 2>&1
    echo -n "x" >tiny_1.txt # Writes exactly one byte without a newline
    compress_and_decompress "tiny_1.txt" || echo "Test failed: 1 Byte File" >>${LOG}

    # Single Word File Test
    echo "Case: Single Word File Test" >>${LOG} 2>&1
    echo "example" >tiny_2.txt # Writes the word 'example' followed by a newline
    compress_and_decompress "tiny_2.txt" || echo "Test failed: Single Word File" >>${LOG}

    # 10 Byte File Test
    echo "Case: 10 Byte File Test" >>${LOG} 2>&1
    echo -n "1234567890" >tiny_10.txt # Writes exactly 10 bytes without a newline
    compress_and_decompress "tiny_10.txt" || echo "Test failed: 10 Byte File" >>${LOG}

    # Short Sentence File Test
    echo "Case: Short Sentence File Test" >>${LOG} 2>&1
    echo "This is a test." >tiny_50.txt # Writes a short sentence
    compress_and_decompress "tiny_50.txt" || echo "Test failed: Short Sentence File" >>${LOG}

    # 100 Byte File Test
    echo "Case: 100 Byte File Test" >>${LOG} 2>&1
    # Use printf to ensure exactly 100 bytes without newlines
    printf "%-100s" "This text fills the specified number of bytes without exceeding." >tiny_100.txt
    compress_and_decompress "tiny_100.txt" || echo "Test failed: 100 Byte File" >>${LOG}

    # Small Text Files
    echo "Case: Small 1KB Text File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_1kb.txt bs=1024 count=1 2>/dev/null
    compress_and_decompress "small_1kb.txt" || echo "Test failed: 1KB Text File" >>${LOG}

    echo "Case: Small 2KB Text File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_2kb.txt bs=2048 count=1 2>/dev/null
    compress_and_decompress "small_2kb.txt" || echo "Test failed: 2KB Text File" >>${LOG}

    echo "Case: Small 5KB Text File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_5kb.txt bs=5120 count=1 2>/dev/null
    compress_and_decompress "small_5kb.txt" || echo "Test failed: 5KB Text File" >>${LOG}

    echo "Case: Small 10KB Text File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_10kb.txt bs=10240 count=1 2>/dev/null
    compress_and_decompress "small_10kb.txt" || echo "Test failed: 10KB Text File" >>${LOG}

    echo "Case: Small 20KB Text File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_20kb.txt bs=20480 count=1 2>/dev/null
    compress_and_decompress "small_20kb.txt" || echo "Test failed: 20KB Text File" >>${LOG}

    # Small Image, Audio, and Binary Files
    echo "Case: Small 1KB JPEG File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_1kb.jpg bs=1024 count=1 2>/dev/null
    compress_and_decompress "small_1kb.jpg" || echo "Test failed: 1KB JPEG File" >>${LOG}

    echo "Case: Small 2KB PNG File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_2kb.png bs=2048 count=1 2>/dev/null
    compress_and_decompress "small_2kb.png" || echo "Test failed: 2KB PNG File" >>${LOG}

    echo "Case: Small 5KB MP3 File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_5kb.mp3 bs=5120 count=1 2>/dev/null
    compress_and_decompress "small_5kb.mp3" || echo "Test failed: 5KB MP3 File" >>${LOG}

    echo "Case: Small 10KB WAV File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_10kb.wav bs=10240 count=1 2>/dev/null
    compress_and_decompress "small_10kb.wav" || echo "Test failed: 10KB WAV File" >>${LOG}

    # Small Data Files
    echo "Case: Small 1KB CSV File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_1kb.csv bs=1024 count=1 2>/dev/null
    compress_and_decompress "small_1kb.csv" || echo "Test failed: 1KB CSV File" >>${LOG}

    echo "Case: Small 2KB JSON File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=small_2kb.json bs=2048 count=1 2>/dev/null
    compress_and_decompress "small_2kb.json" || echo "Test failed: 2KB JSON File" >>${LOG}

    # Randomly Generated Binary Files
    echo "Case: Small 5KB Binary File Test" >>${LOG} 2>&1
    dd if=/dev/urandom of=small_5kb.bin bs=5120 count=1 2>/dev/null
    compress_and_decompress "small_5kb.bin" || echo "Test failed: 5KB Binary File" >>${LOG}

    echo "Case: Small 10KB Binary File Test" >>${LOG} 2>&1
    dd if=/dev/urandom of=small_10kb.bin bs=10240 count=1 2>/dev/null
    compress_and_decompress "small_10kb.bin" || echo "Test failed: 10KB Binary File" >>${LOG}

    echo "Case: Small 20KB Binary File Test" >>${LOG} 2>&1
    dd if=/dev/urandom of=small_20kb.bin bs=20480 count=1 2>/dev/null
    compress_and_decompress "small_20kb.bin" || echo "Test failed: 20KB Binary File" >>${LOG}

    # Medium Text Files
    echo "Case: Medium 1MB Text File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_1mb.txt bs=1048576 count=1 2>/dev/null
    compress_and_decompress "medium_1mb.txt" || echo "Test failed: 1MB Text File" >>${LOG}

    echo "Case: Medium 2MB Text File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_2mb.txt bs=2097152 count=1 2>/dev/null
    compress_and_decompress "medium_2mb.txt" || echo "Test failed: 2MB Text File" >>${LOG}

    echo "Case: Medium 5MB Text File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_5mb.txt bs=5242880 count=1 2>/dev/null
    compress_and_decompress "medium_5mb.txt" || echo "Test failed: 5MB Text File" >>${LOG}

    echo "Case: Medium 10MB Text File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_10mb.txt bs=10485760 count=1 2>/dev/null
    compress_and_decompress "medium_10mb.txt" || echo "Test failed: 10MB Text File" >>${LOG}

    # Medium Image Files
    echo "Case: Medium 1MB PNG File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_1mb.png bs=1048576 count=1 2>/dev/null
    compress_and_decompress "medium_1mb.png" || echo "Test failed: 1MB PNG File" >>${LOG}

    echo "Case: Medium 2MB JPEG File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_2mb.jpg bs=2097152 count=1 2>/dev/null
    compress_and_decompress "medium_2mb.jpg" || echo "Test failed: 2MB JPEG File" >>${LOG}

    echo "Case: Medium 5MB GIF File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_5mb.gif bs=5242880 count=1 2>/dev/null
    compress_and_decompress "medium_5mb.gif" || echo "Test failed: 5MB GIF File" >>${LOG}

    echo "Case: Medium 10MB BMP File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_10mb.bmp bs=10485760 count=1 2>/dev/null
    compress_and_decompress "medium_10mb.bmp" || echo "Test failed: 10MB BMP File" >>${LOG}

    # Medium Audio Files
    echo "Case: Medium 1MB WAV File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_1mb.wav bs=1048576 count=1 2>/dev/null
    compress_and_decompress "medium_1mb.wav" || echo "Test failed: 1MB WAV File" >>${LOG}

    echo "Case: Medium 2MB MP3 File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_2mb.mp3 bs=2097152 count=1 2>/dev/null
    compress_and_decompress "medium_2mb.mp3" || echo "Test failed: 2MB MP3 File" >>${LOG}

    echo "Case: Medium 5MB OGG File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_5mb.ogg bs=5242880 count=1 2>/dev/null
    compress_and_decompress "medium_5mb.ogg" || echo "Test failed: 5MB OGG File" >>${LOG}

    echo "Case: Medium 10MB FLAC File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_10mb.flac bs=10485760 count=1 2>/dev/null
    compress_and_decompress "medium_10mb.flac" || echo "Test failed: 10MB FLAC File" >>${LOG}

    # Medium Archive and Document Files
    echo "Case: Medium 1MB ZIP File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_1mb.zip bs=1048576 count=1 2>/dev/null
    compress_and_decompress "medium_1mb.zip" || echo "Test failed: 1MB ZIP File" >>${LOG}

    echo "Case: Medium 2MB TAR.GZ File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_2mb.tar.gz bs=2097152 count=1 2>/dev/null
    compress_and_decompress "medium_2mb.tar.gz" || echo "Test failed: 2MB TAR.GZ File" >>${LOG}

    echo "Case: Medium 5MB PDF File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=medium_5mb.pdf bs=5242880 count=1 2>/dev/null
    compress_and_decompress "medium_5mb.pdf" || echo "Test failed: 5MB PDF File" >>${LOG}

    # Medium Randomly Generated Binary Files
    echo "Case: Medium 1MB Binary File Test" >>${LOG} 2>&1
    dd if=/dev/urandom of=medium_1mb.bin bs=1048576 count=1 2>/dev/null
    compress_and_decompress "medium_1mb.bin" || echo "Test failed: 1MB Binary File" >>${LOG}

    echo "Case: Medium 2MB Binary File Test" >>${LOG} 2>&1
    dd if=/dev/urandom of=medium_2mb.bin bs=2097152 count=1 2>/dev/null
    compress_and_decompress "medium_2mb.bin" || echo "Test failed: 2MB Binary File" >>${LOG}

    echo "Case: Medium 5MB Binary File Test" >>${LOG} 2>&1
    dd if=/dev/urandom of=medium_5mb.bin bs=5242880 count=1 2>/dev/null
    compress_and_decompress "medium_5mb.bin" || echo "Test failed: 5MB Binary File" >>${LOG}

    echo "Case: Medium 10MB Binary File Test" >>${LOG} 2>&1
    dd if=/dev/urandom of=medium_10mb.bin bs=10485760 count=1 2>/dev/null
    compress_and_decompress "medium_10mb.bin" || echo "Test failed: 10MB Binary File" >>${LOG}

    # English Text File Test
    echo "Case: English Text File Test" >>${LOG} 2>&1
    echo "Example content that might be found in a book..." >english_text.txt
    compress_and_decompress "english_text.txt" || echo "Test failed: English Text File" >>${LOG}

    # Programming Code Files
    echo "Case: C Code File Test" >>${LOG} 2>&1
    echo "#include <stdio.h>\nint main() { return 0; }" >code_c.txt
    compress_and_decompress "code_c.txt" || echo "Test failed: C Code File" >>${LOG}

    echo "Case: Python Code File Test" >>${LOG} 2>&1
    echo "print('Hello, World')" >code_python.txt
    compress_and_decompress "code_python.txt" || echo "Test failed: Python Code File" >>${LOG}

    echo "Case: JavaScript Code File Test" >>${LOG} 2>&1
    echo "console.log('Hello, World');" >code_javascript.txt
    compress_and_decompress "code_javascript.txt" || echo "Test failed: JavaScript Code File" >>${LOG}

    echo "Case: HTML Code File Test" >>${LOG} 2>&1
    echo "<!DOCTYPE html><html><body>Hello, World!</body></html>" >code_html.txt
    compress_and_decompress "code_html.txt" || echo "Test failed: HTML Code File" >>${LOG}

    # Special Text Cases
    echo "Case: English Text with Lots of Spaces Test" >>${LOG} 2>&1
    printf 'word %.0s' {1..1000} >english_text_with_lots_of_spaces.txt
    compress_and_decompress "english_text_with_lots_of_spaces.txt" || echo "Test failed: English Text with Lots of Spaces" >>${LOG}

    echo "Case: English Text with Lots of Line Breaks Test" >>${LOG} 2>&1
    yes "line" | head -n 1000 | tr '\n' '\n' >english_text_with_lots_of_line_breaks.txt
    compress_and_decompress "english_text_with_lots_of_line_breaks.txt" || echo "Test failed: English Text with Lots of Line Breaks" >>${LOG}

    echo "Case: English Text with Lots of Punctuation Test" >>${LOG} 2>&1
    printf '%-50s' {1..20} | tr ' ' '.' >english_text_with_lots_of_punctuation.txt
    compress_and_decompress "english_text_with_lots_of_punctuation.txt" || echo "Test failed: English Text with Lots of Punctuation" >>${LOG}

    echo "Case: English Text with Lots of Numbers Test" >>${LOG} 2>&1
    seq 1 1000 >english_text_with_lots_of_numbers.txt
    compress_and_decompress "english_text_with_lots_of_numbers.txt" || echo "Test failed: English Text with Lots of Numbers" >>${LOG}

    # Random Text Files
    echo "Case: 1KB Random Text File Test" >>${LOG} 2>&1
    head -c 1024 </dev/urandom | tr -dc 'a-zA-Z0-9 ' >random_text_1kb.txt
    compress_and_decompress "random_text_1kb.txt" || echo "Test failed: 1KB Random Text File" >>${LOG}

    echo "Case: 2KB Random Text File Test" >>${LOG} 2>&1
    head -c 2048 </dev/urandom | tr -dc 'a-zA-Z0-9 ' >random_text_2kb.txt
    compress_and_decompress "random_text_2kb.txt" || echo "Test failed: 2KB Random Text File" >>${LOG}

    # Binary Data Files
    echo "Case: JPEG Image File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=image_jpeg.jpg bs=1024 count=500 2>/dev/null
    compress_and_decompress "image_jpeg.jpg" || echo "Test failed: JPEG Image File" >>${LOG}

    echo "Case: PNG Image File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=image_png.png bs=1024 count=500 2>/dev/null
    compress_and_decompress "image_png.png" || echo "Test failed: PNG Image File" >>${LOG}

    echo "Case: MP3 Audio File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=audio_mp3.mp3 bs=1024 count=500 2>/dev/null
    compress_and_decompress "audio_mp3.mp3" || echo "Test failed: MP3 Audio File" >>${LOG}

    echo "Case: WAV Audio File Test" >>${LOG} 2>&1
    dd if=/dev/zero of=audio_wav.wav bs=1024 count=1000 2>/dev/null
    compress_and_decompress "audio_wav.wav" || echo "Test failed: WAV Audio File" >>${LOG}

    echo "Case: Executable File Test" >>${LOG} 2>&1
    echo "echo Hello World!" >executable_file.exe
    chmod +x executable_file.exe
    compress_and_decompress "executable_file.exe" || echo "Test failed: Executable File" >>${LOG}

    # Empty File Test
    echo "Case: Empty File Test" >>${LOG} 2>&1
    touch empty_file.txt
    compress_and_decompress "empty_file.txt" || echo "Test failed: Empty File" >>${LOG}

    # Files with Special Names
    # echo "Case: File with Spaces Test" >>${LOG} 2>&1
    # touch "file. with. spaces.txt"
    # compress_and_decompress "file. with. spaces.txt" || echo "Test failed: File with Spaces" >>${LOG}

    echo "Case: File with Special Characters Test" >>${LOG} 2>&1
    touch "file_with_special_characters@#$.txt"
    compress_and_decompress "file_with_special_characters@#$.txt" || echo "Test failed: File with Special Characters" >>${LOG}

    # echo "Case: File with Very Long Name Test" >>${LOG} 2>&1
    # touch "$(printf 'a%.0s' {1..100}).txt"
    # compress_and_decompress "$(printf 'a%.0s' {1..255}).txt" || echo "Test failed: File with Very Long Name" >>${LOG}

    # Files with Non-Standard Permissions
    echo "Case: Read-Only File Test" >>${LOG} 2>&1
    echo "Read-only content" >readonly_file.txt
    chmod 444 readonly_file.txt
    compress_and_decompress "readonly_file.txt" || echo "Test failed: Read-Only File" >>${LOG}

    echo "Case: Executable File Test" >>${LOG} 2>&1
    echo "echo Hello World!" >executable_file.sh
    chmod +x executable_file.sh
    compress_and_decompress "executable_file.sh" || echo "Test failed: Executable File" >>${LOG}

    # Files with Specific Line Endings
    echo "Case: Unix Line Endings File Test" >>${LOG} 2>&1
    echo -e "Line 1\nLine 2\nLine 3" >file_with_unix_line_endings.txt
    compress_and_decompress "file_with_unix_line_endings.txt" || echo "Test failed: Unix Line Endings File" >>${LOG}

    echo "Case: Windows Line Endings File Test" >>${LOG} 2>&1
    echo -e "Line 1\r\nLine 2\r\nLine 3" >file_with_windows_line_endings.txt
    compress_and_decompress "file_with_windows_line_endings.txt" || echo "Test failed: Windows Line Endings File" >>${LOG}

    # File with Corrupted Data
    echo "Case: Corrupted Data File Test" >>${LOG} 2>&1
    echo "Good data" >corrupted_data_file.txt
    echo "Corrupted data" >>corrupted_data_file.txt
    # Intentionally corrupt the file
    dd if=/dev/urandom of=corrupted_data_file.txt bs=1 count=10 seek=10 conv=notrunc 2>/dev/null
    compress_and_decompress "corrupted_data_file.txt" || echo "Test failed: Corrupted Data File" >>${LOG}

    # Only New Lines in a File Test
    echo "Processing file with only new lines:" >>${LOG} 2>&1
    yes "" | head -n 1000 >new_lines.txt # Create a file with 1000 new lines
    compress_and_decompress "new_lines.txt" || echo "Test failed: File with only new lines" >>${LOG}

    # Different Encodings Test
    echo "Processing different encodings test:" >>${LOG} 2>&1
    echo "你好，世界！" >utf8_encoded.txt # UTF-8 encoded content
    compress_and_decompress "utf8_encoded.txt" || echo "Test failed: Different encodings" >>${LOG}

    # Very Long Lines in a File Test
    echo "Processing very long lines in a file test:" >>${LOG} 2>&1
    echo "$(printf '%*s' 10000 | tr ' ' 'x')" >long_line.txt # Create a line 10,000 characters long
    compress_and_decompress "long_line.txt" || echo "Test failed: Very long lines in a file" >>${LOG}

    # Invalid Data Test
    echo "Processing invalid data file:" >>${LOG} 2>&1
    echo "This is not a compressed file" >invalid_data.txt
    compress_and_decompress "invalid_data.txt" || echo "Test failed: Invalid data file" >>${LOG}

    # Sparse File Test
    echo "Processing sparse file:" >>${LOG} 2>&1
    dd if=/dev/zero of=sparse_file.txt bs=1M count=1 seek=100 >/dev/null 2>&1
    compress_and_decompress "sparse_file.txt" || echo "Test failed: Sparse file" >>${LOG}

    # Standard tests
    touch ${HARDCODED_FILES[@]}
    cp $ORG_FILE ${HARDCODED_FILES[0]}
    cp $ORG_FILE ${HARDCODED_FILES[2]}
    echo "Case 9" >>${LOG} 2>&1
    echo "Processing all files simultaneously:" >>${LOG} 2>&1
    compress_and_decompress "${HARDCODED_FILES[@]}" || echo "Test failed: Multiple files" >>${LOG}

    echo "Processing single file:" >>${LOG} 2>&1
    touch "${FILE}"
    cp $ORG_FILE ${FILE}
    compress_and_decompress "${FILE}" || echo "Test failed: Single file" >>${LOG}

    # Multi-language text decompression
    echo "Processing multiple languages text file:" >>${LOG} 2>&1
    echo "Bonjour! Hallo! Hola! Ciao!" >multi_lang.txt
    compress_and_decompress "multi_lang.txt" || echo "Test failed: Multi-language text" >>${LOG}

    #  Simple Unicode text decompression
    echo "Processing simple Unicode text file:" >>${LOG} 2>&1
    echo -e "Hello, World! 😊👍" >unicode_simple.txt
    compress_and_decompress "unicode_simple.txt" || echo "Test failed: Simple Unicode text" >>${LOG}

    # Complex Unicode text decompression
    echo "Processing complex Unicode text file:" >>${LOG} 2>&1
    echo -e "你好，世界！مرحبا بالعالم" >unicode_complex.txt
    compress_and_decompress "unicode_complex.txt" || echo "Test failed: Complex Unicode text" >>${LOG}

    # Basic Empty File Test
    echo "Processing empty file:" >>${LOG} 2>&1
    touch empty.txt
    compress_and_decompress "empty.txt" || echo "Test failed: Empty file" >>${LOG}

    #  Repeated Empty File Test
    echo "Processing multiple empty files:" >>${LOG} 2>&1
    touch empty1.txt empty2.txt empty3.txt
    compress_and_decompress "empty1.txt" "empty2.txt" "empty3.txt" || echo "Test failed: Multiple empty files" >>${LOG}

    #  Special Characters Basic Test
    echo "Processing filename with special characters:" >>${LOG} 2>&1
    echo "Test content for special characters" >"filewith@#$.txt"
    compress_and_decompress "filewith@#$.txt" || echo "Test failed: Filename with special characters" >>${LOG}

    # Non-ASCII Filename Test
    echo "Processing filename with non-ASCII characters:" >>${LOG} 2>&1
    echo "Test content for non-ASCII characters" >"файл中文.txt"
    compress_and_decompress "файл中文.txt" || echo "Test failed: Filename with non-ASCII characters" >>${LOG}

}

# function execute_exceptional_tests() {

#     # Case 22: Archive File Test
#     echo "Case 22" >>${LOG} 2>&1

#     mkdir -p temp_dir && echo "Test content for archive" >temp_dir/test_file.txt
#     rm -rf archive_file.tar.bz2
#     tar -cf archive_file.tar temp_dir
#     bzip2 -9 archive_file.tar

#     local debloated_log="debloated.log"
#     { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -c -9 archive_file.tar.bz2; } >>${debloated_log} 2>&1
#     a=$?

#     rm -rf temp_dir archive_file.tar.bz2

#     mkdir -p temp_dir && echo "Test content for archive" >temp_dir/test_file.txt
#     tar -cf archive_file.tar temp_dir
#     bzip2 -9 archive_file.tar
#     echo "Decompressing archive file with original binary" >>${LOG} 2>&1
#     local original_log="original.log"
#     { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -c -9 archive_file.tar.bz2; } >>${original_log} 2>&1
#     b=$?

#     if sed_command $original_log $debloated_log $a $b; then
#         echo "Decompression output matched between original and debloated binaries" >>${LOG} 2>&1
#     else
#         echo "Mismatch in decompression output between original and debloated binaries" >>${LOG} 2>&1
#         return 1
#     fi
#     ((PASSED_EXCEPTION++))

#     # Case 23: Nested Compression Test
#     echo "Case 23" >>${LOG} 2>&1

#     rm -f nested_file.txt.bz2
#     echo "Nested compression test content" >nested_file.txt
#     bzip2 -9 nested_file.txt

#     local debloated_log="debloated.log"
#     { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -c -9 nested_file.txt.bz2; } >>${debloated_log} 2>&1
#     a=$?

#     rm -f nested_file.txt.bz2
#     echo "Nested compression test content" >nested_file.txt
#     bzip2 -9 nested_file.txt

#     local original_log="original.log"
#     { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -c -9 nested_file.txt.bz2; } >>${original_log} 2>&1
#     b=$?

#     if sed_command $original_log $debloated_log $a $b; then
#         echo "Decompression output matched between original and debloated binaries" >>${LOG} 2>&1
#     else
#         echo "Mismatch in decompression output between original and debloated binaries" >>${LOG} 2>&1
#         return 1
#     fi
#     ((PASSED_EXCEPTION++))

#     # Case 24: Corrupted File Test
#     echo "Case 24" >>${LOG} 2>&1
#     rm -f corrupted.txt.bz2
#     echo "Corrupted content" >corrupted.txt
#     bzip2 -9 corrupted.txt
#     echo "garbage" >>corrupted.txt.bz2

#     local debloated_log="debloated.log"
#     { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -d corrupted.txt.bz2; } >>${debloated_log} 2>&1
#     a=$?

#     rm -f corrupted.txt.bz2
#     echo "Corrupted content" >corrupted.txt
#     bzip2 -9 corrupted.txt
#     echo "garbage" >>corrupted.txt.bz2

#     local original_log="original.log"
#     { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -d corrupted.txt.bz2; } >>${original_log} 2>&1
#     b=$?

#     if sed_command $original_log $debloated_log $a $b; then
#         echo "Decompression output matched between original and debloated binaries" >>${LOG} 2>&1
#     else
#         echo "Mismatch in decompression output between original and debloated binaries" >>${LOG} 2>&1
#         return 1
#     fi
#     ((PASSED_EXCEPTION++))

#     # Case 25: Permission Denied Error
#     echo "Case 25" >>${LOG} 2>&1

#     rm -rf no_permission_dir
#     mkdir -p no_permission_dir
#     touch no_permission_dir/no_permission_file.txt
#     chmod 000 no_permission_dir/no_permission_file.txt

#     local debloated_log="debloated.log"
#     { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -c -9 no_permission_dir/no_permission_file.txt; } >>${debloated_log} 2>&1
#     a=$?

#     rm -rf no_permission_dir no_permission_dir.bz2
#     mkdir -p no_permission_dir
#     touch no_permission_dir/no_permission_file.txt
#     chmod 000 no_permission_dir/no_permission_file.txt

#     local original_log="original.log"
#     { timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -c -9 no_permission_dir/no_permission_file.txt; } >>${original_log} 2>&1
#     b=$?

#     if sed_command $original_log $debloated_log $a $b; then
#         echo "Decompression output matched between original and debloated binaries" >>${LOG} 2>&1
#     else
#         echo "Mismatch in decompression output between original and debloated binaries" >>${LOG} 2>&1
#         return 1
#     fi
#     ((PASSED_EXCEPTION++))

#     chmod 755 no_permission_dir/no_permission_file.txt

#     # Case 26: Very Long Filenames Test
#     echo "Case 26" >>${LOG} 2>&1
#     rm -f decompressed.txt compressed.bz2
#     long_filename=$(printf '%*s' 100 | tr ' ' 'a')".txt"
#     echo "Test content for very long filename" >"$long_filename"
#     echo "Compressing files with debloated bzip2: ${long_filename}" >>${LOG} 2>&1
#     { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} -c -9 ${long_filename} >compressed.bz2; } &>>${LOG}
#     if [ $? -ne 0 ]; then
#         echo "Error during compression of files" >>${LOG} 2>&1
#         return 1
#     fi

#     echo "Decompressing files with original binary: ${long_filename}" >>${LOG} 2>&1
#     timeout ${TIMEOUT_LIMIT} ${ORG_BINARY} -d compressed.bz2 -c >>decompressed.txt 2>&1
#     if [ $? -ne 0 ]; then
#         return 1
#     fi
#     sed -i '/^$/d' decompressed.txt
#     sed -i '/^$/d' "${long_filename}"

#     if diff ${long_filename} decompressed.txt &>/dev/null; then
#         echo "Decompressed file matched the original file" >>${LOG} 2>&1
#     else
#         echo "Error: Decompressed file does not match the original file" >>${LOG} 2>&1
#         return 1
#     fi
#     ((PASSED_COUNT++))

#     return 0
# }

function main() {
    rm -rf temp log *.log
    clean_env
    compile || exit 1
    execute_tests
    # execute_exceptional_tests
    # echo "Total Exceptional Tests: $TOTAL_EXCEPTIONS, Passed: $PASSED_EXCEPTION, Failed: $(($TOTAL_EXCEPTIONS - $PASSED_EXCEPTION))"
    echo "Total Functionality Tests: $TOTAL_TESTS, Passed: $PASSED_COUNT, Failed: $(($TOTAL_TESTS - $PASSED_COUNT))"
    rm -rf temp
    clean_env
}

main
