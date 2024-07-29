import subprocess
import re
import time
from threading import Thread

# global variable
# filename = "sort-llama.c"
filename = input("Enter the filename: ")

def run_cppcheck():
    # Run the cppcheck command and filter the output
    cmd = f'cppcheck --enable=unusedFunction --enable=style {filename} 2>&1 | grep -v "constVariablePointer" | grep -v "variableScope" | grep -v "unreadVariable" | grep -v "uninitvar" | grep -v "missingReturn" | grep {filename} > cppcheck_output.txt'
    subprocess.run(cmd, shell=True, check=True)

def read_cppcheck_output():
    # Read the cppcheck output from the file
    with open("cppcheck_output.txt", "r") as file:
        lines = file.readlines()
    return lines

def parse_syntax_error(lines):
    # Parse the cppcheck output to find the syntax error line number
    for line in lines:
        match = re.search(rf'{re.escape(filename)}:(\d+):\d+: error', line)
        if match:
            return int(match.group(1))
    return None

def comment_out_line_in_file(line_number):
    # Read the file content
    with open(filename, "r") as file:
        lines = file.readlines()

    # Comment out the specified line
    if line_number <= len(lines):
        if lines[line_number - 1].endswith("\n"):
            lines[line_number - 1] = "// " + lines[line_number - 1][:-1] + "----- this is a temporary automated comment.\n"
        else:
            lines[line_number - 1] = "// " + lines[line_number - 1] + "----- this is a temporary automated comment.\n"

    # Write the modified content back to the file
    with open(filename, "w") as file:
        file.writelines(lines)

def find_function_boundaries(lines, start_line):
    brace_count = 0
    function_start = start_line - 1  # Convert to zero-based index
    function_end = function_start

    for i in range(function_start, len(lines)):
        line = lines[i]
        brace_count += line.count('{') - line.count('}')
        if brace_count == 0 and i > function_start:
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
        # rf'{re.escape(filename)}:(\d+):\d+: style: struct member .* is never used\. \[unusedStructMember\]',
        # rf'{re.escape(filename)}:(\d+):\d+: style: Unused variable: .* \[unusedVariable\]',
        # rf'{re.escape(filename)}:(\d+):\d+: style: Variable .* is reassigned a value before the old one has been used\. \[redundantAssignment\]',
        # rf'{re.escape(filename)}:(\d+):\d+: style: Variable .* is not assigned a value\. \[unassignedVariable\]'
    ]
    for line in lines:
        for pattern in patterns:
            match = re.search(pattern, line)
            if match:
                unused_lines.append((int(match.group(1)), "unusedcode"))

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
                    continue
                lines[line_number - 1] = "// " + lines[line_number - 1]
        elif action == "remove":
            if line_number <= len(lines):
                if type == "unusedcode" and any(char in lines[line_number - 1] for char in '{}'):
                    continue
                lines.pop(line_number - 1)


    # Write the modified content back to the file
    with open(filename, "w") as file:
        file.writelines(lines)

def main():
    # read the total number of lines in the file
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
        while True:
            run_cppcheck()
            lines = read_cppcheck_output()
            line_number = parse_syntax_error(lines)
            if line_number is None:
                # print("No more syntax errors found.")
                break
            comment_out_line_in_file(line_number)

        # check for unused functions, labels, struct members, and variables
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

    # finally delete the cppcheck output file
    # subprocess.run("rm cppcheck_output.txt", shell=True)

if __name__ == "__main__":

    start = time.time()
    main_thread = Thread(target=main)
    main_thread.start()
    while main_thread.is_alive():
        print(f"Time elapsed: {time.time() - start:.2f} seconds", end="\r")
        time.sleep(10)
    print(f"Time elapsed: {time.time() - start:.2f} seconds")
