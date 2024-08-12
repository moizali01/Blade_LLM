#!/bin/bash

PROGRAM_NAME=sort-8.16
DIR=$(pwd)
C_FILE=$DIR/sort-util.c
O_FILE=$DIR/sort-org.c
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log

function run() {

  #Test Case 1: Sort the whole util without a flag
  { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $O_FILE >$DIR/temp_output_original.txt; } &>>${LOG}
  { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $O_FILE >$DIR/temp_output.txt; } &>>${LOG}
  r=$?
  if [[ $r -ne 0 ]]; then
    return 1
  fi
  if diff -q $DIR/temp_output.txt $DIR/temp_output_original.txt >/dev/null; then
    echo "Files are the same" &>>${LOG}
  else
    # echo "Files are different"
    return 1
  fi
  rm $DIR/temp_output.txt $DIR/temp_output_original.txt

  #Test Case 2: Sort three files with a flag
  echo -e "13001\n10003\n25005\n17007\n31009\n15011\n27013\n19015\n35017\n33019\n29021\n21023\n23025\n11027\n15029\n7001\n9003\n2905\n3707\n3909" >$DIR/data.txt
  echo -e "cherry\nfig\norange\ntangerine\npapaya\nquince\napple\nlemon\nvanilla\nmango\nraspberry\nbanana\nhoneydew\nelderberry\nugli\ngrape\nnectarine\nkiwi\nstrawberry\ndate" >>$DIR/data.txt

  { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $DIR/data.txt >$DIR/temp_output.txt; } &>>${LOG}
  r=$?
  if [[ $r -ne 0 ]]; then
    return 1
  fi
  { timeout $TIMEOUT_LIMIT $ORIGINAL_BINARY $DIR/data.txt >$DIR/temp_output_original.txt; } &>>${LOG}
  if diff -q $DIR/temp_output.txt $DIR/temp_output_original.txt >/dev/null; then
    echo "Files are the same" &>>${LOG}
  else
    # echo "Files are different"
    return 1
  fi
  return 0
}

function clean_env() {
  cd $DIR
  # Cleanup all created files and directories
  rm -rf $LOG $REDUCED_BINARY $DIR/*.txt $ORIGINAL_BINARY
  return 0
}

function compile() {
  cd ${DIR}
  ${CC} ${C_FILE} -lpthread -w -o ${REDUCED_BINARY} &>>${LOG} || exit 1
  ${CC} ${O_FILE} -lpthread -w -o ${ORIGINAL_BINARY} &>>${LOG} || exit 1
  return 0
}

sanitizers=("")

function main() {
  for i in {1..3}; do
    cd $DIR
    clean_env
    compile || exit 1
    run || exit 1
    clean_env
  done
}
# sanitizers=("-fsanitize=cfi -flto -fvisibility=hidden" "-fsanitize=address"
#   "-fsanitize=memory -fsanitize-memory-use-after-dtor"
#   "-fno-sanitize-recover=undefined,nullability"
#   "-fsanitize=leak")

# function main() {
#   cd $DIR
#   for ((i = 0; i < ${#sanitizers[@]}; i++)); do
#     clean_env
#     compile "${sanitizers[$i]}" || exit 1
#     run || exit 1
#     clean_env
#   done
# }

main
