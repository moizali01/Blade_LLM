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
  rm -rf d1 d2
  mkdir -p d1/d2/d3
  touch d1/d2/file1
  { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $1 d1 ; } >&$LOG || exit 1
  temp1=$(ls -alR d1 2>/dev/null | cut -d ' ' -f 1,3,4)

  rm -rf d1 d2
  mkdir -p d1/d2/d3
  touch d1/d2/file1

  $ORIGINAL_BINARY $1 d1
  temp2=$(ls -alR d1 2>/dev/null | cut -d ' ' -f 1,3,4)
  rm -rf d1 d2 >&/dev/null
  # echo $temp1 >> $LOG
  # echo ===== >> $LOG
  # echo $temp2 >> $LOG
  if [[ $temp1 == $temp2 ]]; then
    return 0
  else
    return 1
  fi
}

function run_error() {
  rm -rf d1 >&/dev/null
  mkdir d1
  { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $1 d1 ; } >&temp1 && exit 1
  { $ORIGINAL_BINARY $1 d1; } >&temp2
  temp1=$(head -n 1 temp1 | cut -d ' ' -f 2,3)
  temp2=$(head -n 1 temp2 | cut -d ' ' -f 2,3)
  rm -rf d1 >&/dev/null
  if [[ $temp1 == $temp2 ]]; then
    return 0
  else
    return 1
  fi
}

function args_test() {
  run "-R user1" d1 || exit 1
  run "-R user1:group1" d1 || exit 1
  run "-R :group1" d1 || exit 1

#   run_error "-R" d1 || exit 1
#   run_error "-R user1:invalidgroup" d1 || exit 1

  return 0
}

sanitizers=("-fsanitize=cfi -flto -fvisibility=hidden" "-fsanitize=address"
  "-fsanitize=memory -fsanitize-memory-use-after-dtor"
  "-fno-sanitize-recover=undefined,nullability"
  "-fsanitize=leak")

function clean_env() {
  cd $DIR
  rm -rf d1 temp1 temp2 $REDUCED_BINARY $LOG $ORIGINAL_BINARY
  
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
