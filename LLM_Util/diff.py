import subprocess
import difflib
import shutil
import os

# Global variables
original_file_path = ''
debloated_file_path = ''
test_script_path = ''
timeout_value = 2

log_file_path = 'removal_log'
temp_file_path = 'temp_file.c'

# Function to format the original and debloated files
def run_clang_format(filename):
    subprocess.run(["clang-format", "-style={ColumnLimit: 300, AllowShortFunctionsOnASingleLine: All, AllowShortIfStatementsOnASingleLine: true}", "-i", filename], capture_output=True, text=True)

def remove_empty_lines(filename):
    with open(filename, 'r') as file:
        lines = file.readlines()
    with open(filename, 'w') as file:
        for line in lines:
            if line.strip() != "":
                file.write(line)

# Function to run bash script and check test results
def run_tests():
    try:
        result = subprocess.run(['bash', test_script_path], stdout=subprocess.PIPE, stderr=subprocess.PIPE, timeout=timeout_value)
        output = result.stdout.decode('utf-8')
    except Exception as e:
        output = ""
    return "All tests passed successfully." in output

def main():
    # Format the original and debloated files
    run_clang_format(original_file_path)
    run_clang_format(debloated_file_path)
    remove_empty_lines(original_file_path)
    remove_empty_lines(debloated_file_path)
    
    # Read both files
    with open(original_file_path, 'r') as original_file:
        original_lines = original_file.readlines()

    with open(debloated_file_path, 'r') as debloated_file:
        debloated_lines = debloated_file.readlines()

    # Initialize the log
    with open(log_file_path, 'w') as log_file:
        log_file.write("Starting the code block removal process.\n\n")

    # Compare files and identify blocks to remove
    diff = list(difflib.unified_diff(debloated_lines, original_lines, lineterm=''))

    # Reverse the diff list to start from the bottom
    diff.reverse()

    last_modified_line = len(original_lines)
    removed_blocks = set()  # To keep track of removed blocks

    # Iterate through the diff list and remove blocks
    i = 0
    while i < len(diff):
        if diff[i].startswith('+'):
            start = i
            # Find the end of the block
            while i < len(diff) and diff[i].startswith('+'):
                i += 1
            end = i
            
            replace_start = end
            replace_end = end
            while replace_end < len(diff) and diff[replace_end].startswith('-'):
                replace_end += 1
                
            block_to_replace = [line[1:] for line in diff[replace_start:replace_end]]
            block_to_replace.reverse()


            # Calculate line indices to remove from original_lines
            block_to_remove = [line[1:] for line in diff[start:end]]
            block_to_remove.reverse()
            
            block_hash = hash(tuple(block_to_remove))
            if block_hash in removed_blocks:
                i += 1
                continue

            original_temp = original_lines[:]

            found = False
            # Attempt to remove the block from the original lines
            for j in range(last_modified_line - 1, -1, -1):
                if original_temp[j - len(block_to_remove) + 1:j + 1] == block_to_remove:
                    removal_start = j - len(block_to_remove) + 1
                    removal_end = j+1
                    original_temp = original_temp[:removal_start] + block_to_replace + original_temp[removal_end:]
                    found = True
                    break
            last_modified_line = removal_start - 1
            removed_blocks.add(block_hash)
            if not found:
                i += 1
                continue

            # Write to a temporary file and run the tests
            with open(temp_file_path, 'w') as temp_file:
                temp_file.writelines(original_temp)

            # Replace original file with temp file if tests pass
            shutil.copy(temp_file_path, original_file_path)               
            if run_tests():
                original_lines = original_temp[:]
                with open(log_file_path, 'a') as log_file:
                    log_file.write(f"Removed lines {removal_start+1}-{removal_end+1} from the original file.\n")
            else:
                shutil.copy(original_file_path, temp_file_path)
                with open(log_file_path, 'a') as log_file:
                    log_file.write(f"Retained lines {removal_start+1}-{removal_end+1} in the original file as tests did not pass.\n")
        i += 1

    # Final log entry
    with open(log_file_path, 'a') as log_file:
        log_file.write("\nCode block removal process completed.\n")

    # Clean up temp file
    if os.path.exists(temp_file_path):
        os.remove(temp_file_path)

if __name__ == "__main__":
    main()
