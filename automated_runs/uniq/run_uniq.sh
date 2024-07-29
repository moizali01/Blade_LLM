#!/bin/bash

DIR=$(pwd)

# Install Required libraries
cd ../../
chmod +x install_requirements.sh
./install_requirements.sh

clear

# Copy all files need for run to relevant locations
cd $DIR
cp uniq-8.16-GPT.c ../../src/target-program/uniq-8.16-GPT.c
cp uniq-8.16.c.origin.c ../../src/target-program/uniq-8.16.c.origin.c
cp data.c ../../src/target-program/data.c
cp uniq.sh ../../src/target-program/uniq.sh
cp original.txt ../../src/original.txt
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
clear

# run the program
cd ../../src
python3 blade.py -p target-program/uniq-8.16-GPT.c -t target-program/uniq.sh -u 1 -d 1
cp uniq-8.16-GPT.c.blade.c ../automated_runs/sort/uniq-8.16-GPT.c.blade.c
clear

# run generality cases
cd $DIR
chmod +x uniq_generality.sh
./sort_generality.sh > generality_results.txt
clear

echo "Results saved in generality_results.txt"

exit 0

