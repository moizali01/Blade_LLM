#!/bin/bash

PROGRAM_NAME=bzip2-8.16
DIR=$(pwd)
ORIGINAL_FILE=$DIR/bzip2-org.c
REDUCED_FILE=$DIR/bzip2-cov.c
ORIGINAL_BINARY=$DIR/original_binary
REDUCED_BINARY=$DIR/reduced_binary
CC=clang
TIMEOUT_LIMIT="-k 10 10"
LOG=$DIR/log

TOTAL_TESTS=0

TOTAL_FUNCTIONALITY=0
TOTAL_SECURITY=0
TOTAL_ROBUSTNESS=0

TOTAL_FUNCTIONALITY_PASSED=0
TOTAL_SECURITY_PASSED=0
TOTAL_ROBUSTNESS_PASSED=0

function compile() {
    $CC $REDUCED_FILE -w -o $REDUCED_BINARY >>${LOG} 2>&1 || exit 1
    $CC $ORIGINAL_FILE -w -o $ORIGINAL_BINARY >>${LOG} 2>&1 || exit 1
    return 0
}


function run_functionality() {
    ((TOTAL_TESTS++))

    echo "CASE: $TOTAL_TESTS" >>${LOG} 2>&1
    sec_flag="$1"       
    shift
    files=("$@") 
    if [ -n "$sec_flag" ] && [ "$sec_flag" -eq 1 ]; then
        ((TOTAL_SECURITY++))
    else
        ((TOTAL_FUNCTIONALITY++))
    fi
    rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
    mkdir -p temp >/dev/null 2>&1
    mkdir -p comparison >/dev/null 2>&1
    
    for file in "${files[@]}"; do
        cp -p "${file}" "temp/"
        filename=$(basename "$file")
        cp -p "$file" "comparison/original_$filename"
    done

    local compression_debloated="compression_debloated.txt"
    { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} temp/*; } &>>${compression_debloated}
    local a=$?
    if [[ $a -ne 0 ]]; then
        echo "Compression failed: ${files[@]}" >>${LOG} 2>&1

        rm -rf temp comparison ${compression_debloated} ${decompression_original}  >/dev/null 2>&1
        return 1
    fi

    local debloated_compressed_files=$(ls temp)
    if find temp -type f ! -name "*.bz2" | grep -q .; then
        echo "Not all files are .bz2: ${files[@]}" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original}  >/dev/null 2>&1
        return 1
    else
        echo "All files are .bz2" >>${LOG} 2>&1
    fi

    local decompression_original="decompression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORIGINAL_BINARY} -d temp/*; } &>>${decompression_original}
    local b=$?
    if [[ $b -ne 0 ]]; then
        echo "Decompression failed: ${files[@]}" >>${LOG} 2>&1
        cat $decompression_original >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original}  >/dev/null 2>&1
        return 1
    fi
    
    local original_decompressed_files=$(ls temp)
    if find temp -type f -name "*.bz2" | grep -q .; then
        echo "There are .bz2 files: ${files[@]}" >>${LOG} 2>&1
        rm -rf temp comparison ${compression_debloated} ${decompression_original}  >/dev/null 2>&1
        return 1
    else
        echo "There are no .bz2 files" >>${LOG} 2>&1
    fi

    for file in temp/*; do
        filename=$(basename "$file")
        cp -p "$file" "comparison/debloated_$filename"
    done

    for file in $files; do
        filename=$(basename "$file")

        # Determine file type (more robust than relying on extensions alone)
        filetype=$(file -b --mime-type "$file")

        if [[ $filetype =~ ^text/ ]]; then
            # Text file comparison using diff
            if diff "comparison/original_$filename" "comparison/debloated_$filename" >/dev/null; then
                echo "Decompressed file matched the original file" >/dev/null 2>&1
            else
                echo "Error: Decompressed file does not match the original file: $file"
                rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
                return 1
            fi
        else
            # Audio/Video file comparison using cmp
            if cmp -s "comparison/original_$filename" "comparison/debloated_$filename" >/dev/null; then
                echo "Decompressed file matched the original file" >/dev/null 2>&1
            else
                echo "Error: Decompressed file does not match the original file: $file"
                rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
                return 1
            fi
        fi
    done

    if [ -n "$sec_flag" ] && [ "$sec_flag" -eq 1 ]; then
        ((TOTAL_SECURITY_PASSED++))
    else
        ((TOTAL_FUNCTIONALITY_PASSED++))
    fi
    echo "Success" >>${LOG} 2>&1
    echo "" >>${LOG} 2>&1
    rm -rf temp comparison ${compression_debloated} ${decompression_original}  >/dev/null 2>&1
    return 0
}

function run_robustness() {
    ((TOTAL_TESTS++))
    ((TOTAL_ROBUSTNESS++))
    
    description=$1
    command=$2
    
    echo -e "CASE: $TOTAL_TESTS, $description" >>${LOG} 2>&1
    eval "$command" >>${LOG} 2>&1
    a=$?
    if [[ $a -ne 124 && $a -ne 137 ]]; then
        ((TOTAL_ROBUSTNESS_PASSED++))
    else
        echo "Test failed: $description" >>${LOG} 2>&1
        return
    fi
    
    
}
function functionality_cases() {
    echo "starting generality run" >>${LOG} 2>&1
    echo "=========================="
    echo "Functionality Related Tests"
    
    local functionality_files="functionality_files"

    for file in $functionality_files/*; do
        echo "Running test $file"
        run_functionality 0 $file
    done
    
    #5 files
    files=($(ls $functionality_files | shuf -n 5))
    files=("${files[@]/#/functionality_files/}")
    echo "Running test: Multiple files"
    run_functionality 0 ${files[@]}
    return 0
}
function security_cases() {
    #Non Existent file
    echo "=========================="
    echo "Security Related Tests"
    echo "=========================="
    
    local security_dir="security_cases"
    
    for file in $security_dir/*; do
        echo "Running test $file"
        run_functionality 1 $file
    done
    
    mkdir -p sticky_dir

    echo -e "apple\nbanana\ncherry" > setuid_file
    chmod u+s setuid_file

    echo -e "apple\nbanana\ncherry" > setgid_file
    chmod g+s setgid_file

    echo -e "apple\nbanana\ncherry" > sticky_dir/file
    chmod +t sticky_dir

    # Large buffer overflow input
    echo -e "$(printf '%0.s1' {1..1000000})\n$(printf '%0.s2' {1..1000000})" > buffer_overflow

    # Potential format string input
    echo -e "%s\n%s\n%s\n%s" > format_string


    for file in "setuid_file" \
                "setgid_file" \
                "sticky_dir/file" \
                "buffer_overflow" \
                "format_string" 
    do
        echo "Running test $file"
        run_functionality 1 $file
        rm -rf $file
    done
    rm -rf sticky_dir
        return 0
}
function robustness_cases() {
    echo "=========================="
    echo "Robustness Related Tests"
    echo "=========================="
    local robustness_dir="robustness_cases"
    for file in $robustness_dir/*; do
        cp -p $file $DIR
        #use the copied file
        file=$(basename $file)
        echo "Running test $file"
        run_robustness "Robustness test file: $file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $file > $DIR/temp_output.txt; }"
        rm -rf $file *.bz2

    done

    touch new_file.txt
    echo "Running test: Invalid Flag"
    run_robustness "Invalid Flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -a new_file.txt > $DIR/temp_output.txt; }"

    echo "Running test: No arguments"
    run_robustness "No arguments " \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -a > $DIR/temp_output.txt; }" 

    echo "Running test: -R flag"
    run_robustness "Invalid Flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -R new_file.txt > $DIR/temp_output.txt; }"
    
    echo "Running test: -z flag"
    run_robustness "Invalid Flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -z new_file.txt > $DIR/temp_output.txt; }"
    
    echo "Running test Non Existent file"
    run_robustness "Non Existent file" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY Nonexistent.txt > $DIR/temp_output.txt; }"
    
    bzip2 new_file.txt
    echo "Running test: decompression flag"
    run_robustness "Invalid Flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY -d new_file.txt.bzip2 > $DIR/temp_output.txt; }"

    #pass a dir
    mkdir temp_dir
    echo "Running test: Directory"
    run_robustness "Invalid Flag" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY temp_dir > $DIR/temp_output.txt; }"
    rm -rf temp_dir
    rm -rf new_file.txt new_file.txt.bz2
    
    touch file.txt
    flags=(-h -z -k -f -t -c -q -v -L -V -s -1 -2 -3 -4 -5 -6 -7 -8 -9 --help --license --version )
      for flag in ${flags[@]}; do
        touch file.txt
        echo "Running test: Invalid Flags"
        run_robustness "Invalid Flags" \
        "{ timeout $TIMEOUT_LIMIT $REDUCED_BINARY $flag file.txt > $DIR/temp_output.txt; }"
        rm file.txt file.txt.bz2 >/dev/null 2>&1
    done
}

function security_cases_run() {
    ((TOTAL_TESTS++))
    ((TOTAL_SECURITY++))
    
    echo "CASE: $TOTAL_TESTS" >>${LOG} 2>&1
    
    sec_flag="$1"       
    shift
    files=("$@") 
    
    rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
    mkdir -p temp >/dev/null 2>&1
    
    for file in "${files[@]}"; do
        cp -p "${file}" "temp/"
    done

    local compression_debloated="compression_debloated.txt"
    { timeout ${TIMEOUT_LIMIT} ${ORIGINAL_BINARY} temp/*; } &>>${compression_debloated}
    local a=$?

    local decompression_original="decompression_original.txt"
    { timeout ${TIMEOUT_LIMIT} ${REDUCED_BINARY} temp/*; } &>>${decompression_original}
    local b=$?

    if [ $a -ne $b ]; then
        echo "Test failed:" >>${LOG} 2>&1
        cat $compression_debloated >>${LOG} 2>&1
        cat $decompression_original >>${LOG} 2>&1
        return
    fi
        
    sed -i '/reduced_binary/d' $compression_debloated
    sed -i '/original_binary/d' $decompression_original
    
    if diff $compression_debloated $decompression_original > /dev/null; then 
        echo "Decompressed file matched the original file" >/dev/null 2>&1
    else
        echo "Error: Decompressed file does not match the original file: $file"
        rm -rf temp comparison ${compression_debloated} ${decompression_original} >/dev/null 2>&1
        return 1
    fi
    ((TOTAL_SECURITY_PASSED++))

    echo "Success" >>${LOG} 2>&1
    echo "" >>${LOG} 2>&1
    rm -rf temp comparison ${compression_debloated} ${decompression_original}  >/dev/null 2>&1
    return 0
}
function clean_env() {
    cd $DIR
    rm -rf  $REDUCED_BINARY $ORIGINAL_BINARY > /dev/null 2>&1
    return 0
}

function main() { 
    clean_env
    rm -rf $LOG
    compile || exit 1
    
    functionality_cases
    security_cases
    robustness_cases
    
    clean_env
    
    echo "Total tests: $TOTAL_TESTS"
    echo "=========================="
    echo "Total functionality tests Passed: $TOTAL_FUNCTIONALITY_PASSED/$TOTAL_FUNCTIONALITY"
    echo "Total security tests Passed: $TOTAL_SECURITY_PASSED/$TOTAL_SECURITY"
    echo "Total robustness tests Passed: $TOTAL_ROBUSTNESS_PASSED/$TOTAL_ROBUSTNESS"
    echo "=========================="
    echo "Total tests Passed: $((TOTAL_FUNCTIONALITY_PASSED + TOTAL_SECURITY_PASSED + TOTAL_ROBUSTNESS_PASSED))/$((TOTAL_FUNCTIONALITY + TOTAL_SECURITY + TOTAL_ROBUSTNESS))"
    return 0
}

main