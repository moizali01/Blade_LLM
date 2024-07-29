.PHONY: all clean test-1 test-2 test-3

all:
	@echo  "Usage: make -f test.mk test-[1,2,3,4,5]"

clean:
	rm -rf target-program/* processing

test-1:
	mkdir -p target-program 
	rm -f target-program/*
	cp ../test/Code/test1.c target-program
	cp ../test/Test_Oracles/test_oracle_1.sh target-program
	python3 blade.py -p target-program/test1.c -t target-program/test_oracle_1.sh -u 3 -d 3 

test-2: 
	mkdir -p target-program
	rm -f target-program/*
	cp ../test/Code/test2.c target-program
	cp ../test/Test_Oracles/test_oracle_2.sh target-program
	python3 blade.py -p target-program/test2.c -t target-program/test_oracle_2.sh -u 3 -d 3
	
test-3: 
	mkdir -p target-program
	rm -f target-program/*
	cp ../test/Code/test3-Calculator.c target-program
	cp ../test/Test_Oracles/test_oracle_3_Calculator.sh target-program
	python3 blade.py -p target-program/test3-Calculator.c -t target-program/test_oracle_3_Calculator.sh -u 1 -d 1 
	
test-4: 
	mkdir -p target-program
	rm -f target-program/*
	cp ../test/Code/test4-RM.c target-program
	cp ../test/Test_Oracles/test_oracle_4_RM.sh target-program
	python3 blade.py -p target-program/test4-RM.c -t target-program/test_oracle_4_RM.sh -u 1 -d 1 
	
test-5: 
	mkdir -p target-program
	rm -f target-program/*
	cp ../test/Code/test5-SORT.c target-program
	cp ../test/Test_Oracles/test_oracle_5_SORT.sh target-program
	python3 blade.py -p target-program/test5-SORT.c -t target-program/test_oracle_5_SORT.sh -u 1 -d 1 

test-6: 
	mkdir -p target-program
	rm -f target-program/*
	cp ../test/Code/test6-Gzip.c target-program
	cp ../test/Test_Oracles/test_oracle_6_Gzip.sh target-program
	python3 blade.py -p target-program/test6-Gzip.c -t target-program/test_oracle_6_Gzip.sh -u 1 -d 1

test-7: 
	mkdir -p target-program
	rm -f target-program/*
	rm original.txt
	rm ../LLM_Util/coverage.txt
	cp ../test/uniq/uniq-8.16-GPT.c target-program
	cp ../test/uniq/uniq-8.16.c.orign.c target-program
	cp ../test/uniq/test_uniq.sh target-program
	cp ../test/uniq/original.txt ./
	cp ../test/uniq/coverage.txt ../LLM_Util/
	python3 blade.py -p target-program/uniq-8.16-GPT.c -t target-program/test_uniq.sh -u 1 -d 1

test-8: 
	mkdir -p target-program
	rm -f target-program/*
	rm original.txt
	rm ../LLM_Util/coverage.txt
	cp ../test/sort/sort-original.c target-program
	cp ../test/sort/sort-8.16.c.orign.c target-program
	cp ../test/sort/sort.sh target-program
	cp ../test/sort/original.txt ./
	cp ../test/sort/coverage.txt ../LLM_Util/
	python3 blade.py -p target-program/sort-8.16.c.origin.c -t target-program/sort.sh -u 1 -d 1
