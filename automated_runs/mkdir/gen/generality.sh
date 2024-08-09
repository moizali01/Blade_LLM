
#!/bin/bash

C_FILE=mkdir.blade.c
mkdir -p bins
rm -rf bins/*
clang -w $C_FILE -o bins/mkdir-ma=r
clang -w $C_FILE -o bins/mkdir-ma=rw
clang -w $C_FILE -o bins/mkdir-ma=rwx
clang -w $C_FILE -o bins/mkdir-pma=rwx
clang -w $C_FILE -o bins/mkdir-pma=rw
clang -w $C_FILE -o bins/mkdir-pma=r

chmod +x test_score.sh
./test_score.sh 
