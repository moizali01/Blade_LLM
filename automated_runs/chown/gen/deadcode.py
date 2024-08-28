
import subprocess
import re
import time
from threading import Thread
import shutil

# global variable
filename = "/Blade_LLM/automated_runs/chown/gen/chown-debloated.c.blade.c"
# filename = input("Enter the filename: ")

def run_cppcheck():
    cmd = rf'cppcheck --enable=unusedFunction --enable=style -D__attribute__\(x\)= {filename} 2>&1 | grep -v "constVariablePointer" | grep -v "variableScope" | grep -v "unreadVariable" | grep -v "uninitvar" | grep -v "missingReturn" | grep {filename} > cppcheck_output.txt'
    subprocess.run(cmd, shell=True, check=True)

def read_cppcheck_output():
    # Read the cppcheck output from the file
    with open("cppcheck_output.txt", "r") as file:
        lines = file.readlines()
    return lines

def find_function_boundaries(lines, start_line):
    brace_count = 0
    function_start = start_line - 1  # Convert to zero-based index
    function_end = function_start

    curly_braces_start = function_start
    while '{' not in lines[curly_braces_start] and curly_braces_start < len(lines):
        curly_braces_start += 1

    for i in range(curly_braces_start, len(lines)):
        line = lines[i]
        brace_count += line.count('{') - line.count('}')
        if brace_count == 0 and i > curly_braces_start:
            function_end = i
            break

    return function_start, function_end+1

def parse_unused_functions(lines):
    unused_functions = []
    pattern = rf'{re.escape(filename)}:(\d+):\d+: style: The function \'([^\']+)\' is never used\. \[unusedFunction\]'
    for line in lines:
        match = re.search(pattern, line)
        if match:
            unused_functions.append((int(match.group(1)), match.group(2)))
    return unused_functions

def parse_unsused_warnings(lines):
    # Parse the cppcheck output to find lines with unused labels, struct members, and variables
    unused_lines = []
    patterns = [
        rf'{re.escape(filename)}:(\d+):\d+: style: Label .* is not used\. \[unusedLabel\]',
        # rf'{re.escape(filename)}:(\d+):\d+: style: Unused variable: .* \[unusedVariable\]',
        # rf'{re.escape(filename)}:(\d+):\d+: style: Variable .* is reassigned a value before the old one has been used\. \[redundantAssignment\]',
        # rf'{re.escape(filename)}:(\d+):\d+: style: Variable .* is not assigned a value\. \[unassignedVariable\]'
    ]
    # for line in lines:
    #     for pattern in patterns:
    #         match = re.search(pattern, line)
    #         if match:
    #             unused_lines.append((int(match.group(1)), "unusedcode"))

    # find out the unused lines within unreachable functions
    unused_functions = parse_unused_functions(lines)
    with open(filename, "r") as file:
        lines = file.readlines()
        for line_number, _ in unused_functions:
            function_start, function_end = find_function_boundaries(lines, line_number)
            unused_lines += [(i, "unusedfunction")for i in range(function_start + 1, function_end + 1)]

    # filter out the common occurances between the unused code and unused lines and place them back as unused functions
    unused_function_lines = {line for line, code in unused_lines if code == 'unusedfunction'}
    filtered_data = [(line, code) for line, code in unused_lines if not (code == 'unusedcode' and line in unused_function_lines)]

    return filtered_data

def modify_file_to_remove_unused_lines(line_numbers, action="remove"):
    # Read the file content
    with open(filename, "r") as file:
        lines = file.readlines()

    # Perform the specified action on the lines
    for line_number, type in sorted(line_numbers, reverse=True):
        if action == "comment":
            if line_number <= len(lines):
                if type == "unusedcode" and any(char in lines[line_number - 1] for char in '{}'):
                    print(f"Skipping line {line_number} as it contains special characters: {lines[line_number - 1]}")
                    continue
                lines[line_number - 1] = "// " + lines[line_number - 1]
        elif action == "remove":
            if line_number <= len(lines):
                if type == "unusedcode" and any(char in lines[line_number - 1] for char in '{}'):
                    print(f"Skipping line {line_number} as it contains special characters: {lines[line_number - 1]}")
                    continue
                lines.pop(line_number - 1)

    # Write the modified content back to the file
    with open(filename, "w") as file:
        file.writelines(lines)

def deadcode_elimination():
    previous_total_lines = 0
    iterations = 0
    while True:
        print(f"Iteration: {iterations}")
        print("Removing the syntax errors due to extern statements...")
        iterations += 1
        with open(filename, "r") as file:
            lines = file.readlines()
            total_lines = len(lines)
            if total_lines == previous_total_lines:
                print("All dead code eliminated!")
                break
            previous_total_lines = total_lines
        
        print("Starting the dead code elimination process...")
        run_cppcheck()
        print("Checking for unused functions, labels, struct members, and variables...")
        lines = read_cppcheck_output()
        unused_lines = parse_unsused_warnings(lines)
        if unused_lines:
            # print("No more unused labels, struct members, and variables found.")
            modify_file_to_remove_unused_lines(unused_lines, action="remove")


        # uncomment the lines we commented out before
        print("Uncommenting out the lines we commented out before...")
        with open(filename, "r") as file:
            lines = file.readlines()
            for i, line in enumerate(lines):
                if line.startswith("//") and "----- this is a temporary automated comment." in line:
                    lines[i] = line[3:]
                    lines[i] = lines[i].replace("----- this is a temporary automated comment.", "")
        with open(filename, "w") as file:
            file.writelines(lines)

    # finally delete the cppcheck output file and run the test script
    subprocess.run("rm cppcheck_output.txt", shell=True)

def remove_cluttered_code(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    modified_lines = []
    i = 0

    previous_colon = False

    while i < len(lines):
        line = lines[i].strip()

        if ':' in line:
                # print("skipping the next line after line", line)
                modified_lines.append(line)
                previous_colon = True
                i += 1
                continue
        else:
            if previous_colon:
                modified_lines.append(line)
                previous_colon = False
                i += 1
                continue
            else:
                previous_colon = False

        # if line == ';' or re.match(r'^\s*/\*.*\*/\s*$', line):
        if line == re.match(r'^\s*/\*.*\*/\s*$', line):
            i += 1
            continue

        if line == '{':
            block_content = ''
            j = i + 1
            while j < len(lines) and lines[j].strip() != '}':
                block_content += lines[j].strip()
                j += 1
            
            if block_content == '/* CIL Label */;' or block_content == '/* CIL Label */':
                i = j + 1
                continue

        modified_lines.append(lines[i])
        i += 1

    with open(file_path, 'w') as file:
        file.writelines(modified_lines)

def remove_insignificant_lines(file_path):
    with open (file_path, 'r') as file:
        lines = file.read()

    lines, count_else = re.subn(
        r'\}\s*else\s*\{\s*\}', '}', lines)
    
    with open (file_path, 'w') as file:
        file.write(lines)

    with open(file_path, 'r') as file:
        lines = file.readlines()

    def remove_empty_blocks(lines):
        modified_lines = []
        skip_next_line = False
        previous_empty_line = False
        previous_colon = False

        for i, line in enumerate(lines):
            stripped_line = line.strip()

            if skip_next_line:
                skip_next_line = False
                continue

            # Skip empty lines, single line braces, and comments
            if stripped_line == '{}' or stripped_line == ':' or stripped_line.startswith('//'):
                continue
            if stripped_line == '' and previous_empty_line:
                continue
            if stripped_line == '':
                previous_empty_line = True
                modified_lines.append(line)
                continue
            else:
                previous_empty_line = False

            if ':' in stripped_line:
                # print("skipping the next line after line", line)
                modified_lines.append(line)
                previous_colon = True
                continue
            else:
                if previous_colon:
                    modified_lines.append(line)
                    previous_colon = False
                    continue
                else:
                    previous_colon = False

                
            # Check for empty if-else or while statements
            if re.match(r'^\s*(if|else|while)\s*(\(.*\))?\s*{?\s*$', line):
                # Look ahead to see if the block is empty
                if i + 1 < len(lines) and re.match(r'^\s*}\s*$', lines[i + 1]):
                    skip_next_line = True
                    continue
                elif stripped_line == 'else':
                    if modified_lines and re.match(r'^\s*else\s*$', modified_lines[-1]):
                        modified_lines.pop()
                    skip_current_block = True
                    continue
                
            modified_lines.append(line)

        return modified_lines

    previous_lines = lines
    current_lines = remove_empty_blocks(previous_lines)

    # Repeat until no more lines can be removed
    while current_lines != previous_lines:
        previous_lines = current_lines
        current_lines = remove_empty_blocks(previous_lines)

    # Write the final lines back to the file
    with open(file_path, 'w') as file:
        file.writelines(current_lines)

def redundant_line_removal():
    print("Running remove_comments...")
    remove_cluttered_code(filename)

    print("Running clang-format...")
    subprocess.run(["clang-format", "-i", filename])

    print("Running remove_ifelse...")
    remove_insignificant_lines(filename)

    print("Running remove_comments again...")
    remove_cluttered_code(filename)

    print("Running clang-format again...")
    subprocess.run(["clang-format", "-i", filename])

    print("Running remove_ifelse again...")
    remove_insignificant_lines(filename)

    # print ("Running remove_semi_colons...")
    # remove_semi_colons()

    run_clang_format()
    print(f"Processing completed for {filename}.")


def run_clang_format():
    subprocess.run(["clang-format", "-style={ColumnLimit: 300, AllowShortFunctionsOnASingleLine: All, AllowShortIfStatementsOnASingleLine: true}", "-i", filename], capture_output=True, text=True)
    
def main():
    run_clang_format()
    deadcode_elimination()
    redundant_line_removal()

if __name__ == "__main__":
    start = time.time()
    main_thread = Thread(target=main)
    main_thread.start()
    while main_thread.is_alive():
        print(f"Time elapsed: {time.time() - start:.2f} seconds", end="\r")
        time.sleep(10)
    print(f"Time elapsed: {time.time() - start:.2f} seconds")
