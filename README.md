# LLM BASED DEBLOATING

This repository contains a tool for debloating programs using Language Model (LLM) techniques, aimed at increasing the generality of debloating tools.

## How to Set Up

### Installation
1. Clone this repository.
2. Navigate to the project directory.
3. Install dependencies by running:
    ```bash
    ./install_requirements.sh
    ```
4) Installing LLama
    ```bash
    ollama pull llama3
    ```
5) Install llvm
   ```bash
   sudo apt install llvm
   ```
6) Setup blade by following the readme in src folder

### Running
1. Add the C code in the project directory and rename it as `original.c`.
2. Copy test cases from the test oracle into `coverage_generate.sh`.
   Make sure you add this command before `./$RED_BIN`:
   ```bash
   { timeout -k 0.3 0.3 env LLVM_PROFILE_FILE="default_$count.profraw" ./$RED_BIN ./testfold/hello; } || exit 1 # Before RED_BIN add this line

This will generate a coverage report in the LLM_Util folder.

3. Copy original.c and the test oracle into the test directory, which can be found in the project directory.
4. Run blade with the following command:

```bash
mkdir -p target-program
rm -f target-program/*
cp ../test/Code/test2.c target-program
cp ../test/Test_Oracles/test_oracle_2.sh target-program
python3 blade.py -p target-program/original.c -t target-program/test_oracle.sh -u 3 -d 3
```

### Running on RM (files already setup)
```bash
cd src
make -f test.mk test-4
```

### Adding/Using a Different LLM
1) Navigate to LLM_class.py in the LLM_Util folder in the project directory.
2) In the LLM_chain function, initialize or uncomment your LLM.
3) For Gemini: In the call_LLM function, uncomment the function relevant to you. Comments are already added to aid you in locating them.
4) For LLama: To change Llama model, change the model in the call_ollama function

Note: You must install ollama on your system before running with Llama. If you do not have ollama setup, it is recommend changing to a different LLM from the available options. 

### Automated Running
1) navigate to automated_runs folder in the project directory
2) navigate to the relevant program.
3) run the run_{program}.sh file
4) It will run all processes and generate the debbloated code the project directory
