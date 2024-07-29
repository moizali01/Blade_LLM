#!/bin/bash

DEB_TARGET=test6-Gzip.c
RED_BIN=deb-3
LOG=log.tx

rm -rf $RED_BIN temp* $LOG

# Compile the code
clang -w $DEB_TARGET -o $RED_BIN || exit 1

# Test case 1: 
echo -e "hello world from filename1" > filename1.txt
{ timeout -k 0.3 0.3 ./$RED_BIN filename1.txt ;} || exit 1
ls -1 | grep '\.gz$' > temp1
echo -e "filename1.txt.gz" > temp2
diff temp2 temp1 || exit

# Test case 2: 
echo -e "hello world from filename2" > filename2.txt
{ timeout -k 0.3 0.3 ./$RED_BIN filename2.txt ;} || exit 1
gunzip -k filename2.txt.gz || exit 1
cp filename2.txt temp3 || exit 1
echo -e "hello world from filename2" > temp4
diff temp3 temp4 || exit

#rm filename1.txt.gz
rm filename2.txt.gz
rm filename2.txt

rm -rf $RED_BIN temp* $LOG

exit 0
