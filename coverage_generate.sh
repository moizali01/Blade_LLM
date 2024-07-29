#!/bin/bash

DEB_TARGET=original.c # Source file to be debloated
RED_BIN=original # Executable to be debloated (keep the name same as the source file name without extension)
LOG=log.txt

count=0

rm -rf $RED_BIN temp* $LOG

# Compile the code
clang -fprofile-instr-generate -fcoverage-mapping -w $DEB_TARGET -o $RED_BIN

# Add test cases here

mkdir testfold
touch ./testfold/hello
{ timeout -k 0.3 0.3 env LLVM_PROFILE_FILE="default_$count.profraw" ./$RED_BIN ./testfold/hello; } || exit 1 # Before RED_BIN add this line
count=$((count + 1))
cd testfold
count=$(ls -l | grep "^-" | wc -l)
cd ..
echo $count > temp5
echo "0" > temp6
diff temp5 temp6 || exit 1

# Test cases finished


# Loop to merge all the profraw files
command="llvm-profdata merge -sparse "
for i in $(seq 0 $count)
do
    command="$command default_$i.profraw"
done
command="$command -o $RED_BIN.profdata"

# Execute the command
eval $command

llvm-cov show ./$RED_BIN -instr-profile=$RED_BIN.profdata $DEB_TARGET > coverage_file.txt

echo Coverage file generated
rm -rf $RED_BIN temp* $LOG
rm -rf testfold *.profraw *.profdata
mv coverage_file.txt ./LLM_Util/coverage.txt
cp original.c ./LLM_Util/original.txt

exit 0
