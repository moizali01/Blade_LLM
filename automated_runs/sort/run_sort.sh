#!/bin/bash

DIR=$(pwd)

# Copy all files need for run to relevant locations
cd $DIR
cp sort-org.c ../../src/target-program/
cp sort-util.c ../../src/target-program/
cp sort.sh ../../src/target-program/
cp original.txt ../../src/original.txt
cp coverage.txt ../../LLM_Util/coverage.txt
# clear

mkdir -p gen

# copy prompts to LLM_UTIL
cd $DIR
cp prompt_in_coverage.txt ../../LLM_Util/prompt_in_coverage.txt
cp prompt_not_in_coverage.txt ../../LLM_Util/prompt_not_in_coverage.txt
cp sec_list.txt ../../LLM_Util/sec_list.txt
# clear

# clear cands
cd ../../LLM_Util

mkdir -p cands
cd cands
mkdir -p context
mkdir -p pretext_code
mkdir -p removed_code
mkdir -p llm_response
mkdir -p fifty_text

cd ..
chmod +x clear_cands.sh
./clear_cands.sh
cd $DIR
# clear

# run the program
cd ../../src
python3 blade.py -p target-program/sort-util.c -t target-program/sort.sh -u 1 -d 1
cp sort-util.c.blade.c ../automated_runs/sort/gen/sort-util.c.blade.c
# clear

# run deadcode removal
cd $DIR/gen
cp ../../../LLM_Util/deadcoderemoval.py deadcoderemoval.py
echo sort-util.c.blade.c > filename.txt
python3 deadcoderemoval.py < filename.txt
rm filename.txt

# run generality cases
chmod +x sort_generality.sh
mkdir -p results
./sort_generality.sh > results/generality_results.txt

# clean up
cp results/generality_results.txt ../generality_results.txt
cp sort-util.c.blade.c ../sort-util.c.blade.c
cp sort_generality.sh ../sort_generality.sh
rm -r results
cd $DIR
rm -r gen
# clear

echo "Results saved in generality_results.txt"
cat generality_results.txt | tail

exit 0
