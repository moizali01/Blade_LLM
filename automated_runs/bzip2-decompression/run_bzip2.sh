#!/bin/bash

DIR=$(pwd)

# Install Required libraries
# cd ../../
# chmod +x install_requirements.sh
# ./install_requirements.sh

# clear

# Copy all files need for run to relevant locations
cd $DIR
cp bzip2-util.c ../../src/target-program/bzip2-util.c
cp bzip2-org.c ../../src/target-program/bzip2-org.c
cp bzip2_train.sh ../../src/target-program/bzip2_train.sh
cp original.txt ../../src/original.txt
cp coverage.txt ../../LLM_Util/coverage.txt
# clear

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
python3 blade.py -p target-program/bzip2-util.c -t target-program/bzip2_train.sh -u 1 -d 1
cp bzip2-util.c.blade.c ../automated_runs/bzip2-decompression/bzip2-util.c.blade.c
# clear

# run generality cases
cd $DIR
mkdir test_generality
cp bzip2-util.c.blade.c test_generality/bzip2-util.c.blade.c
cp bzip2-org.c test_generality/bzip2-org.c
cp generality.sh test_generality/generality.sh
cd test_generality
chmod +x generality.sh

./generality.sh
cat log > generality_results.txt

echo "Done"


exit 0

