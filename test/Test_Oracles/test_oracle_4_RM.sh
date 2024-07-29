#!/bin/bash

DEB_TARGET=test4-RM.c
RED_BIN=deb-3
LOG=log.tx

rm -rf $RED_BIN temp* $LOG

# Compile the code
clang -w $DEB_TARGET -o $RED_BIN || exit 1

# Test case 1:
touch hello.txt
{ timeout -k 0.3 0.3 ./$RED_BIN hello.txt; } || exit 1
ls -l | grep "^-" | wc -l >& temp1
echo "5"  >& temp2
diff temp2 temp1 || exit 1

# Test case 2: 
ls -l | grep "^-" | wc -l >& temp3
mkdir hello
{ timeout -k 0.3 0.3 ./$RED_BIN -r hello; } || exit 1
count=$(ls -l | grep "^-" | wc -l)
echo $count > temp4
diff temp3 temp4 || exit 1

# Test case 3: 
mkdir testfold
touch ./testfold/hello
{ timeout -k 0.3 0.3 ./$RED_BIN ./testfold/hello; } || exit 1
cd testfold
count=$(ls -l | grep "^-" | wc -l)
cd ..
echo $count > temp5
echo "0" > temp6
diff temp5 temp6 || exit 1

rm -rf $RED_BIN temp* $LOG
rm -rf testfold

exit 0
