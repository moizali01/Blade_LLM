#!/bin/bash

DEB_TARGET=test5.c
RED_BIN=deb-3
LOG=log.tx

rm -rf $RED_BIN temp* $LOG

# Compile the code
clang -w $DEB_TARGET -o $RED_BIN || exit 1

# Test case 1: 
echo -e "1\nhassan lovely\n3\n2\n4\nhello\n5\nhassan1\n6\nahmer 012\na\n1\nahmer\n2" > filename.txt
{ timeout -k 0.3 0.3 ./$RED_BIN -g filename.txt > temp1; } || exit 1 
echo -e "a\nahmer\nahmer 012\nhassan1\nhassan lovely\nhello\n1\n1\n2\n2\n3\n4\n5\n6" > temp2
diff temp2 temp1 || exit

rm -rf $RED_BIN temp* $LOG

exit 0

