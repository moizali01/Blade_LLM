#!/bin/bash

DIR=$(pwd)

# Copy all files need for run to relevant locations
cd $DIR
cp grep-org.c ../../src/target-program/
cp grep-util.c ../../src/target-program/
cp grep.sh ../../src/target-program/
cp grep-org.c ../../src/original.txt
cp coverage.txt ../../LLM_Util/coverage.txt


# copy prompts to LLM_UTIL
cd $DIR
cp prompt_in_coverage.txt ../../LLM_Util/prompt_in_coverage.txt
cp prompt_not_in_coverage.txt ../../LLM_Util/prompt_not_in_coverage.txt
cp sec_list.txt ../../LLM_Util/sec_list.txt

# clear cands
cd ../../LLM_Util

mkdir -p cands
cd cands
mkdir -p context
mkdir -p pretext_code
mkdir -p removed_code
mkdir -p llm_response
mkdir -p fifty_text

# clear cands
cd ..
chmod +x clear_cands.sh
./clear_cands.sh
cd $DIR

# run the program
cd ../../src
python3 blade.py -p target-program/grep-util.c -t target-program/grep.sh -u 1 -d 1

mkdir -p ../automated_runs/grep/gen
cp grep-util.c.blade.c ../automated_runs/grep/gen/grep-util.c.blade.c

# run generality cases
cd $DIR
cp ../../LLM_Util/deadcoderemoval.py gen/deadcoderemoval.py
cp grep_generality.sh gen/grep_generality.sh
cp grep-org.c gen/grep-org.c
cd gen
echo grep-util.c.blade.c > tempfile.txt
python3 deadcoderemoval.py < tempfile.txt
rm tempfile.txt
chmod +x grep_generality.sh
./grep_generality.sh > generality_results.txt
cd ..
rm gen/grep_generality.sh
rm gen/grep-org.c
mv gen/grep-util.c.blade.c grep-util.c.blade.c
mv gen/generality_results.txt generality_results.txt
rm -r gen

cat generality_results.txt
echo "Results saved in gen/generality_results.txt"
