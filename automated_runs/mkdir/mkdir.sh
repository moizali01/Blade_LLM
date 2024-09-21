#!/bin/bash

PROGRAM_NAME=mkdir-5.2.1
DIR=$(pwd)
C_FILE=$DIR/mkdir-debloated.c
C_OG_FILE=$DIR/mkdir-5.2.1.c.origin.c
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
ORIGINAL_BINARY=$DIR/$PROGRAM_NAME.obin
CC=clang
TIMEOUT_LIMIT="-k 1.2 1.2"
LOG=$DIR/log.txt

function clean() {
  rm -rf d1 d* temp1 temp2 $LOG $REDUCED_BIN
  return 0
}

function run() {
  rm -rf d1
  { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $1 $2 ; } >&$LOG || exit 1
  temp1=$(ls -ald $2 2>/dev/null | cut -d ' ' -f 1,2,3,4)
  rm -rf d1 >&/dev/null
  /bin/mkdir $1 $2
  temp2=$(ls -ald $2 2>/dev/null | cut -d ' ' -f 1,2,3,4)
  rm -rf $2 >&/dev/null
  if [[ $temp1 == $temp2 ]]; then
    return 0
  else
    return 1
  fi
}

function run_error() {
  rm -rf d1  >&/dev/null
  { timeout $TIMEOUT_LIMIT $REDUCED_BINARY $1 $2 ; } >&temp1 && exit 1
  rm -rf d1  >&/dev/null
  { $ORIGINAL_BINARY $1 $2; } >&temp2
  temp1=$(head -n 1 temp1 | cut -d ' ' -f 2,3)
  temp2=$(head -n 1 temp2 | cut -d ' ' -f 2,3)
  if [[ $temp1 == $temp2 ]]; then
    return 0
  else
    return 1
  fi
}

# Test cases focused on the -m flag for setting permissions
function args_test() {
  run "-m 400" d1 || exit 1
  run "-m 500" d1 || exit 1
  # run "-m 644" d1 || exit 1
  run "-m 700" d1 || exit 1
  run "-m u=rw,g=r,o=r" d1 || exit 1

  # run "-m 755" d1 || exit 1
  # run "-m 777" d1 || exit 1



  # Test invalid usage of -m flag
  # run_error "-m" d1 || exit 1  # Missing permission value
  # run_error "-m 999" d1 || exit 1  # Invalid permission value

  return 0
}

sanitizers=("-fsanitize=cfi -flto -fvisibility=hidden" "-fsanitize=address"
  "-fsanitize=memory -fsanitize-memory-use-after-dtor"
  "-fno-sanitize-recover=undefined,nullability"
  "-fsanitize=leak")

function clean_env() {
  cd $DIR
  rm -rf d1 temp1 temp2 $LOG $REDUCED_BINARY
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
  # for ((i = 0; i < ${#sanitizers[@]}; i++)); do
  clean_env
  compile "${sanitizers[$i]}" || exit 1
  args_test || exit 1
  clean_env
  # done
}

main
