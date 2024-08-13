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
cd response_firstpass
rm -rf *.txt
cd ..
cd fifty_text
rm -rf *.c