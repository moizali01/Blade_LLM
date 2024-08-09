# #!/bin/bash

# BINARY_DIR="bins"
# LOG="log.txt"
# # path to debloated binaries can be added here
# declare -A COMMANDS=( ["mkdir-ma=r"]="-m 444" ["mkdir-ma=rw"]="-m 644" ["mkdir-ma=rwx"]="-m 755" ["mkdir-pma=r"]="-m 444" ["mkdir-pma=rw"]="-m 644" ["mkdir-pma=rwx"]="-m 755" )
# order=(
#   "mkdir-ma=r"
#   "mkdir-ma=rw"
#   "mkdir-ma=rwx"
#   "mkdir-pma=r"
#   "mkdir-pma=rw"
#   "mkdir-pma=rwx"
# )

# # function test()
# # {
# #   $BINARY_DIR/$1 $2 $3
# #   temp1=`ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}'`
# #   rm -rf $3 >&/dev/null

# #   mkdir $2 $3
# #   temp2=`ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}'`
# #   diff -q <(echo "$temp1") <(echo "$temp2")>&/dev/null || return 1

# #   return 0;
# # }
# function test()
# {
#   # Run the binary and capture stdout, stderr, and the directory listing
#   binary_output=$(mktemp)
#   binary_error=$(mktemp)
#   $BINARY_DIR/$1 $2 $3 > "$binary_output" 2> "$binary_error"
#   temp1=$(ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}')
  
#   # Clean up the created directory
#   rm -rf $3 >& /dev/null
  
#   # Create the directories with mkdir and capture stdout, stderr, and the directory listing
#   mkdir_output=$(mktemp)
#   mkdir_error=$(mktemp)
#   mkdir $2 $3 > "$mkdir_output" 2> "$mkdir_error"
#   temp2=$(ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}')
  
#   # Compare the outputs
#   if ! diff -q <(echo "$temp1") <(echo "$temp2") >& /dev/null; then
#     # echo "Directory listing mismatch"
#     return 1
#   fi
  
#   if ! diff -q "$binary_output" "$mkdir_output" >& /dev/null; then
#     # echo "Output mismatch"
#     return 1
#   fi

#   if ! diff -q "$binary_error" "$mkdir_error" >& /dev/null; then
#     # echo "Error mismatch"
#     return 1
#   fi

#   # Clean up temporary files
#   rm -f "$binary_output" "$binary_error" "$mkdir_output" "$mkdir_error"
#   return 0
# }


# function m_test()
# {
#   SCORE=11
#   test "$1" "$2" "test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   echo "$2 tests       $SCORE / 11"
#   return 0;
# }

# function mp_test()
# {
#   SCORE=12
#   test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test/test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test/test/test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test/test/test" || SCORE=$(($SCORE-1))
#   test "$1" "$2" "test/test/test/test/test" || SCORE=$(($SCORE-1))
#   rm -rf test

#   local output="$2 tests   $SCORE / 12"
#   output="${output/-m/-pm}"
#   echo "$output"
#   return 0;
# }

# function run_tests()
# {
#   count=0
#   for key in "${order[@]}"; do
#     if (( count < 3 )); then
#         m_test "$key" "${COMMANDS[$key]}"
#     else
#         mp_test "$key" "${COMMANDS[$key]}"
#     fi
#     ((count++))
#   done

# }

# function main()
# {
#   clear
#   echo "#######################################################"
#   echo "############### AUTOMATED TESTING #####################"
#   echo "############## mkdir-8.2 testing ######################"
#   echo "#######################################################"
#   echo ""
#   echo "starting..."
#   echo ""

#   run_tests

#   echo ""
#   echo "test run completed!"
# }

# main

#!/bin/bash

BINARY_DIR="bins"
LOG="log.txt"
# path to debloated binaries can be added here
declare -A COMMANDS=( ["mkdir-ma=r"]="-m 444" ["mkdir-ma=rw"]="-m 644" ["mkdir-ma=rwx"]="-m 755" )
order=(
  "mkdir-ma=r"
  "mkdir-ma=rw"
  "mkdir-ma=rwx"
)

function test()
{
  # Run the binary and capture stdout, stderr, and the directory listing
  binary_output=$(mktemp)
  binary_error=$(mktemp)
  $BINARY_DIR/$1 $2 $3 > "$binary_output" 2> "$binary_error"
  temp1=$(ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}')
  
  # Clean up the created directory
  rm -rf $3 >& /dev/null
  
  # Create the directories with mkdir and capture stdout, stderr, and the directory listing
  mkdir_output=$(mktemp)
  mkdir_error=$(mktemp)
  mkdir $2 $3 > "$mkdir_output" 2> "$mkdir_error"
  temp2=$(ls -alR | awk '{print $1, $2, $3, $4, $5, $7, $9}')
  
  # Compare the outputs
  if ! diff -q <(echo "$temp1") <(echo "$temp2") >& /dev/null; then
    echo "Test case: $1 $2 $3"
    echo "Directory listing mismatch:"
    diff <(echo "$temp1") <(echo "$temp2")
    return 1
  fi
  
  if ! diff -q "$binary_output" "$mkdir_output" >& /dev/null; then
    echo "Test case: $1 $2 $3"
    echo "Output mismatch:"
    diff "$binary_output" "$mkdir_output"
    return 1
  fi
  if ! diff -q "$binary_error" "$mkdir_error" >& /dev/null; then
    echo "Test case: $1 $2 $3"
    echo "Error mismatch:"
    diff "$binary_error" "$mkdir_error"
    return 1
  fi
  # Clean up temporary files
  rm -f "$binary_output" "$binary_error" "$mkdir_output" "$mkdir_error"
  return 0
}

function m_test()
{
  SCORE=9
  test "$1" "$2" "test/test" || SCORE=$(($SCORE-1))
  rm -rf test

  test "$1" "$2" "test/test/test" || SCORE=$(($SCORE-1))
  rm -rf test

  test "$1" "$2" "test/test/test/test" || SCORE=$(($SCORE-1))
  rm -rf test

  test "$1" "$2" "test" || SCORE=$(($SCORE-1))
  rm -rf test

  echo "$2 tests       $SCORE / 9"
  return 0;
}

function run_tests()
{
  for key in "${order[@]}"; do
    m_test "$key" "${COMMANDS[$key]}"
  done
}

function main()
{
  clear
  echo "#######################################################"
  echo "############### AUTOMATED TESTING #####################"
  echo "############## mkdir-8.2 testing ######################"
  echo "#######################################################"
  echo ""
  echo "starting..."
  echo ""

  run_tests

  echo ""
  echo "test run completed!"
}

main