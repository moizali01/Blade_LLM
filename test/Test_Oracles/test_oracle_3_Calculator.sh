#!/bin/bash

DEB_TARGET=test3-Calculator.c
RED_BIN=deb-3
LOG=log.tx

rm -rf $RED_BIN temp* $LOG

# Compile the code
clang -w $DEB_TARGET -o $RED_BIN || exit 1

# Test case 1: 
{ timeout -k 0.3 0.3 ./$RED_BIN 4 2 '-' >& temp1 ; } || exit 1
echo -n "2" >& temp2
diff temp2 temp1 || exit 1

# Test case 2: 
{ timeout -k 0.3 0.3 ./$RED_BIN 10 2 '*' >& temp3 ; } || exit 1
echo -n "20" >& temp4
diff temp4 temp3 || exit 1

# Test case 2: 
{ timeout -k 0.3 0.3 ./$RED_BIN 1 2 '+' >& temp5 ; } || exit 1
echo -n "3" >& temp6
diff temp6 temp5 || exit 1

# Test case 2: 
{ timeout -k 0.3 0.3 ./$RED_BIN 10 2 '/' >& temp7 ; } || exit 1
echo -n "5" >& temp8
diff temp8 temp7 || exit 1


rm -rf $RED_BIN temp* $LOG

exit 0

