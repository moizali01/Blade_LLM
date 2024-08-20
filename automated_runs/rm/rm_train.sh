#!/bin/bash

PROGRAM_NAME=rm-8.4
DIR=/$(pwd)
C_FILE=$DIR/deb.c
REDUCED_BINARY=$DIR/$PROGRAM_NAME.rbin
CC=clang-14
TIMEOUT_LIMIT="-k 0.5 0.5"
LOG=$DIR/log.txt

function run() {
  mkdir dir
  { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -rf dir; } >&$LOG
  
 r=$?
 a=1
 b=1

 if [[ $r -eq 0 && ! -d dir ]]; then
    a=0
  fi
grep -E error $LOG

 if [[ $? -eq 0 ]]; then
    a=1
  fi


rm -rf dir 
mkdir dir 
mkdir -p dir/dir/dir/dir/dir/dir/dir/dir/dir
cp rm-8.4.c.origin.c dir/dir
cp rm-8.4.c.origin.c dir/dir/dir/
touch file1 file2 dir/1 dir/2

  { timeout $TIMEOUT_LIMIT $REDUCED_BINARY -rf dir file1 file2 ; } >&$LOG
  r=$?
  if [[ $r -eq 0 && ! -d dir && ! -e file1 && ! -e file2 ]]; then
    b=0
  fi
  rm -rf dir file1 file2

   if [[ $a -eq 0 && $b -eq 0 ]]; then
    return 0
  else
    return 1
  fi
}

function args_test() {
    cd $DIR/
  run || exit 1
}

function clean_env() {
  cd $DIR
  rm -rf $LOG $REDUCED_BINARY dir* file*
  return 0
}
function compile() {
  cd $DIR
  case $COV in
  1) CFLAGS="-w -fprofile-arcs -ftest-coverage --coverage $BIN_CFLAGS" ;;
  *) CFLAGS="-w $1 $BIN_CFLAGS" ;;
  esac
  $CC $C_FILE -fPIE $CFLAGS -o $REDUCED_BINARY >&$LOG || exit 1
  return 0
}
sanitizers=("-fsanitize=cfi -flto -fvisibility=hidden" "-fsanitize=address"
  "-fsanitize=memory -fsanitize-memory-use-after-dtor"
  "-fno-sanitize-recover=undefined,nullability"
  "-fsanitize=leak")

function main() {
  cd $DIR
  for ((i = 0; i < ${#sanitizers[@]}; i++)); do
    clean_env
    compile "${sanitizers[$i]}" || exit 1
    echo "compile hogaya"
    # args_test || exit 1
    clean_env
  done
}

main

