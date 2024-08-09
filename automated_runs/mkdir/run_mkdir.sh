#!/bin/bash

DIR=$(pwd)

# Install Required libraries
cd ../../
# chmod +x install_requirements.sh
# ./install_requirements.sh

# clear

# Copy all files need for run to relevant locations
cd $DIR
cp mkdir-debloated.c ../../src/target-program/mkdir-debloated.c
cp mkdir-5.2.1.c.origin.c ../../src/target-program/mkdir-5.2.1.c.origin.c
cp mkdir.sh ../../src/target-program/mkdir.sh
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
python3 blade.py -p target-program/mkdir-debloated.c -t target-program/mkdir.sh -u 1 -d 1
cp mkdir-debloated.c ../automated_runs/rm/mkdir-debloated.c.blade.c
# clear

# run generality cases
cd $DIR
chmod +x mkdir_gen.sh


# ./mkdir_gen.sh > generality_results.txt
# clear

# echo "Results saved in generality_results.txt"

exit 0

