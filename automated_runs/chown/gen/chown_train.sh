#!/bin/bash

PROGRAM_NAME=chown-8.2
DIR=$(pwd)
C_FILE=$DIR/chown-debloated.c
C_OG_FILE=$DIR/chown-8.2.c.origin.c
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang
TIMEOUT_LIMIT="-k 1.2 1.2"
LOG=$DIR/log.txt

function clean() {
  rm -rf d1 d* temp1 temp2 $LOG $REDUCED_BINARY
  return 0
}

function run() {
  # Cleanup and setup
  rm -rf d1 d2
  mkdir -p d1/d2/d3
  touch d1/d2/file1
  touch d1/d2/d3/file2

  # Run the reduced binary and capture output, error, and directory listing
  reduced_output=$(mktemp)
  reduced_error=$(mktemp)
  { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $1 d1 >"$reduced_output" 2>"$reduced_error"; } >&$LOG || exit 1

  r=$?
  if [[ $r -ne 0 ]]; then
    return 1
  fi

  temp1=$(ls -alR d1 2>/dev/null | cut -d ' ' -f 1,3,4)



  # Cleanup and setup again
  rm -rf d1 d2
  mkdir -p d1/d2/d3
  touch d1/d2/file1
  touch d1/d2/d3/file2

  # Run the original binary and capture output, error, and directory listing
  original_output=$(mktemp)
  original_error=$(mktemp)
  $ORIGINAL_BINARY $1 d1 >"$original_output" 2>"$original_error"
  temp2=$(ls -alR d1 2>/dev/null | cut -d ' ' -f 1,3,4)

  # Cleanup directories
  rm -rf d1 d2 >&/dev/null

  # Compare directory listings
  if [[ $temp1 != $temp2 ]]; then
    # echo $temp1 >> $LOG
    # echo ======= >> $LOG
    # echo $temp2 >> $LOG
    echo "Directory listings do not match"
    return 1
  fi

  # Compare stdout
  if ! diff -q "$reduced_output" "$original_output" >& /dev/null; then
    echo "Stdout does not match"
    return 1
  fi

  # Compare stderr
  if ! diff -q "$reduced_error" "$original_error" >& /dev/null; then
    echo "Stderr does not match"
    return 1
  fi

  # Clean up temporary files
  rm -f "$reduced_output" "$reduced_error" "$original_output" "$original_error"

  return 0
}

function args_test() {
  run "-R user1" d1 || exit 1
  run "-R user1:group1" d1 || exit 1
  run "-R :group1" d1 || exit 1

  return 0
}

sanitizers=("-fsanitize=cfi -flto -fvisibility=hidden" "-fsanitize=address"
  "-fsanitize=memory -fsanitize-memory-use-after-dtor"
  "-fno-sanitize-recover=undefined,nullability"
  "-fsanitize=leak")

function clean_env() {
  cd $DIR
  rm -rf d1 temp1 temp2 $REDUCED_BINARY  $ORIGINAL_BINARY $LOG
  
  return 0
}

function compile() {
  cd $DIR
  case $COV in
  1) CFLAGS="-w -fprofile-arcs -ftest-coverage --coverage $BIN_CFLAGS" ;;
  *) CFLAGS="-w $1 $BIN_CFLAGS" ;;
  esac
  $CC $C_FILE -w -o $REDUCED_BINARY >&$LOG || exit 1
  $CC $C_OG_FILE -w -o $ORIGINAL_BINARY >&$LOG || exit 1
  return 0
}

function main() {
  cd $DIR
  clean_env
  compile || exit 1
  args_test || exit 1
  clean_env
}

main
