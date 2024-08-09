#!/bin/bash

DIR=$(pwd)

# Copy all files need for run to relevant locations
cd $DIR
mkdir -p ../../src/target-program/
cp uniq-util.c ../../src/target-program/
cp uniq-og.c ../../src/target-program/
cp uniq.sh ../../src/target-program/
cp original.txt ../../src/

cp coverage.txt ../../LLM_Util/coverage.txt
clear

# copy prompts to LLM_UTIL
cd $DIR
cp prompt_in_coverage.txt ../../LLM_Util/prompt_in_coverage.txt
cp prompt_not_in_coverage.txt ../../LLM_Util/prompt_not_in_coverage.txt
clear

# clear cands
cd ../../LLM_Util

mkdir -p cands
cd cands
mkdir -p context
mkdir -p pretext_code
mkdir -p removed_code
mkdir -p llm_response

cd ..
chmod +x clear_cands.sh
./clear_cands.sh
cd $DIR
cp sec_list.txt ../../LLM_Util/sec_list.txt
clear

# run the program
cd ../../src
python3 blade.py -p target-program/uniq-util.c -t target-program/uniq.sh -u 1 -d 1
cp uniq-util.c.blade.c ../automated_runs/uniq/uniq-util.c.blade.c
# clear

# run generality cases
cd $DIR
chmod +x generality.sh
./generality.sh > generality_results.txt
# clear

echo "Results saved in generality_results.txt"

exit 0

