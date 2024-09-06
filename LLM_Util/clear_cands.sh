#!/bin/bash

# rm -rf sec_list.txt 
cd cands
rm -rf *.c 
cd pretext_code
rm -rf *.c
cd ..
cd removed_code
rm -rf *.c
cd ..
cd llm_response
rm -rf *.txt
cd ../context
rm -rf *.c
cd ..
cd fifty_text
rm -rf *.c
cd ../..
rm func_output.txt > /dev/null 2>&1