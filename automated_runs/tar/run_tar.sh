#!/bin/bash

DIR=$(pwd)

# Install Required libraries
# cd ../../
# chmod +x install_requirements.sh
# ./install_requirements.sh

# clear

# Copy all files need for run to relevant locations
cd $DIR
cp tar-util.c ../../src/target-program/tar-util.c
cp tar-org.c ../../src/target-program/tar-org.c
cp tar.sh ../../src/target-program/tar.sh
cp original.txt ../../src/original.txt
cp coverage.txt ../../LLM_Util/coverage.txt
# clear

# copy prompts to LLM_UTIL
cd $DIR
cp prompt_in_coverage.txt ../../LLM_Util/prompt_in_coverage.txt
cp prompt_not_in_coverage.txt ../../LLM_Util/prompt_not_in_coverage.txt
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
python3 blade.py -p target-program/tar-util.c -t target-program/tar.sh -u 1 -d 1
cp tar-util.c.blade.c ../automated_runs/tar/tar-util.c.blade.c
# clear

# run generality cases
# cd $DIR
# mkdir test_generality
# cp bzip2-util.c.blade.c test_generality/bzip2-util.c.blade.c
# cp bzip2-org.c test_generality/bzip2-org.c
# cp generality.sh test_generality/generality.sh
# cp diff.py test_generality/diff.py
# cd test_generality
# chmod +x generality.sh

# # ./generality.sh
# # cat log > generality_results.txt
# cp generality_results.txt ../generality_results.txt
# # clear
# cp bzip2-org.c bz2_org_copy.c
# python3 diff.py
# echo "Done"


exit 0

