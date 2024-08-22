#!/bin/bash

DIR=$(pwd)

# Copy all files need for run to relevant locations
cd $DIR
cp date-org.c ../../src/target-program/
cp date-util.c ../../src/target-program/
cp date.sh ../../src/target-program/
cp date-org.c ../../src/original.txt
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
python3 blade.py -p target-program/date-util.c -t target-program/date.sh -u 1 -d 1

mkdir -p ../automated_runs/date/gen
cp date-util.c.blade.c ../automated_runs/date/gen/date-util.c.blade.c

# run generality cases
cd $DIR
cp date_generality.sh gen/date_generality.sh
cp date-org.c gen/date-org.c
cd gen
chmod +x date_generality.sh
./date_generality.sh > generality_results.txt
cd ..
rm gen/date_generality.sh
rm gen/date-org.c
mv gen/date-util.c.blade.c date-util.c.blade.c
mv gen/generality_results.txt generality_results.txt
rm -r gen

echo "Results saved in gen/generality_results.txt"