#!/bin/bash


#add binares to this folder formatted as rm{{flag}} i-e rm-f
BIN_DIR="bins" 
FLAGS=("-rf" "-r" "-f" "-i")
TOTAL=0
SCORE=0
LOG="log"
TIMEOUT="-k 2 2"


function test-f() {
	FLAG=$1
	BIN=$BIN_DIR/rm$1
	LC=0
	mkdir -p dir dir/dir dir/dir/dir
	files=("file1 dir/1 dir/dir/2 dir/dir/dir/3")
	touch dir/1 dir/dir/2 file1 dir/dir/dir/3

	for file in $files; do 
	{ timeout $TIMEOUT  $BIN $file ; } >&/dev/null
	 if [[ $? -eq 0 && ! -e $file ]]; then
		echo "$file deleted from the command $BIN $file" >> $LOG
	    LC=$((LC+1))
	 else
	 	echo "$file not deleted from the command $BIN $file" >> $LOG
	 fi
	done;
	rm -rf  file1 dir

 echo $LC
}

function test-rf() {
	FLAG=$1
	BIN=$BIN_DIR/rm$1
	LC=0
	mkdir -p dir dir/dir dir1/dir/dir dir2/dir/dir/dir
	files=("file1 dir dir1 dir2")
	touch dir/1 dir1/dir/dir/2 dir2/dir/dir/dir/3 

	for file in $files; do 
	{ timeout $TIMEOUT  $BIN $file ; } >&/dev/null
	 if [[ $? -eq 0 && ! -e $file ]]; then
		echo "$file deleted from the command $BIN $file" >> $LOG
	    LC=$((LC+1))
	 else 
	 	echo "$file not deleted from the command $BIN $file" >> $LOG
	 fi
	done;
	rm -rf  file1 dir dir1 dir2 

 echo $LC
}

function test-r() {
	FLAG=$1
	BIN=$BIN_DIR/rm$1
	LC=0
	mkdir -p dir dir/dir dir1/dir/dir dir2/dir/dir/dir
	files=("file1 dir dir1 dir2")
	touch dir/1 dir1/dir/dir/2 dir2/dir/dir/dir/3 file1

	for file in $files; do 
	{ timeout $TIMEOUT  $BIN $file ; } >&/dev/null
	 if [[ $? -eq 0 && ! -e $file ]]; then
		echo "$file deleted from the command $BIN $file" >> $LOG
	    LC=$((LC+1))
	 else
	 	echo "$file not deleted from the command $BIN $file" >> $LOG
	 fi
	done;
	rm -rf  file1 dir dir1 dir2 
	
 echo $LC
}

function test-i() {
	FLAG=$1
	BIN=$BIN_DIR/rm$1
	LC=0
	mkdir -p dir dir/dir dir/dir/dir
	files=("file1 dir/1 dir/dir/2 dir/dir/dir/3")
	touch dir/1 dir/dir/2 file1 dir/dir/dir/3

	for file in $files; do 
	{ timeout $TIMEOUT echo "N" | timeout $TIMEOUT $BIN $file ; } >&/dev/null

	{ timeout $TIMEOUT  echo "N" | timeout $TIMEOUT $BIN $file ; } >&/dev/null
	 if [[ $? -eq 0 && -e $file ]]; then
	    LC=$((LC+1))
		echo "$file not deleted from the command $BIN $file" >> $LOG
	 else 
	 	echo "$file deleted from the command $BIN $file when it should not have" >> $LOG
	 fi
	rm -rf  file1 dir
	mkdir -p dir dir/dir dir/dir/dir
	touch dir/1 dir/dir/2 file1 dir/dir/dir/3
	{ timeout $TIMEOUT  echo "Y" | timeout $TIMEOUT $BIN $file ; } >&/dev/null
	 if [[ $? -eq 0 && ! -e $file ]]; then
	    LC=$((LC+1))
		echo "$file deleted from the command $BIN $file" >> $LOG
	 else 
	 	echo "$file not deleted from the command $BIN $file" >> $LOG
	 fi
	done;
	rm -rf  file1 dir

 echo $LC
}

function flags_check() {
  for flag in "${FLAGS[@]}"; do
    LOCAL_SCORE=4
    LOCAL_TESTS=0
    LT=0
    LOCAL_MEM=0 
   	LOCAL_SCORE=$(test$flag $flag)
   	SCORE=$((SCORE+$LOCAL_SCORE))
   	if [[ $flag == "-i" ]];  then
   		LT=8
   	else
   		LT=4
   	fi
   	TOTAL=$((TOTAL+$LT))
#   for massif in $(ls massif*); do
#   LOCAL_TESTS=$(($LOCAL_TESTS+1))
#   grep -E mem_ $massif | cut -d '=' -f 2 > vals.txt
#   t_mem=0
#   for val in $(cat vals.txt); do
#       t_mem=$(($t_mem+$val))
#     done;
#   LOCAL_MEM=$(($t_mem+$LOCAL_MEM))
#   done;
#   if [[ $LOCAL_TESTS -ne 0 ]]; then
#     LOCAL_MEM=$(($LOCAL_MEM/$LOCAL_TESTS))
#   fi;
#    echo "ROP gadget count for $flag flag:" > rop_w.txt
#   ROPgadget --binary $BIN_DIR/rm$flag | grep -E Unique | cut -d ':' -f 2 > rop.txt

  rm -rf massif*
#   echo "Memory used for $flag flag: $LOCAL_MEM bytes"
  echo "$LOCAL_SCORE/$LT tests passed for $flag flag"
#   cat rop_w.txt rop.txt | tr '\n' ' '
  echo -e '\n'
done

}
function main() {
echo "############### AUTOMATED TESTING #################"
echo "########### rm-8.4 testing starting ###########"
echo "###################################################"
echo -e "Memory used is the average total memeory used in all \nsnapshots for all test runs of a variant"
echo "###################################################"
rm -rf massif*
flags_check
echo "$SCORE/$TOTAL tests passed for all variants"
rm -rf file1 dir* *.txt

}

main
