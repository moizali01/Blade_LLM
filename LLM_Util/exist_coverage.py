def analyze_code(file_path):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    first_line_of_code = None
    last_line_of_code = None

    for index, line in enumerate(lines):
        if line.strip():  # Check if the line is not empty
            if first_line_of_code is None:
                first_line_of_code = index + 1  # Line numbers start from 1

            last_line_of_code = index + 1

    return first_line_of_code, last_line_of_code


def check_coverage(file_path, start_line, end_line):
    with open(file_path, 'r') as file:
        lines = file.readlines()

    in_coverage = False
    code_segment = []

    for index in range(start_line - 1, end_line):
        line = lines[index].strip()
        parts = line.split('|')
        if len(parts) >= 3:
            exec_count = parts[1].strip()
            if exec_count.isdigit():
                exec_count = int(exec_count)
            else:
                exec_count = -1
            code_line = parts[2].strip()
            code_segment.append((exec_count, code_line))
            if exec_count > 0 or exec_count == -1:
                in_coverage = True

    return in_coverage, code_segment

def exist(file_path):
    # Analyze the file to get the first and last lines of code
    first_line, last_line = analyze_code(file_path)

    # Check coverage for the identified code segment
    coverage, _ = check_coverage('../LLM_Util/coverage.txt', first_line, last_line)
    return coverage
    
import re

def update_code_with_coverage(formatted_time):
    # Construct the file path using the provided timestamp
    code_path = "../LLM_Util/cands/context/context" + "_time_" + str(formatted_time) + ".blade.c"
    coverage_path = '../LLM_Util/coverage.txt'
    
    # code_path = "cands/context/" + self.timestamp[:-12]
    # coverage_path = "coverage.txt"

    # Step 1: Get the first and last non-empty line numbers in the code file
    first_line, last_line = analyze_code(code_path)
    
    # Step 2: Read both code file and coverage file contents
    with open(code_path, 'r') as code_file:
        code_lines = code_file.readlines()
        
    with open(coverage_path, 'r') as coverage_file:
        coverage_lines = coverage_file.readlines()

    # Step 3: Replace lines in the code file with the coverage lines
    for i in range(first_line - 1, last_line):
        if i < len(coverage_lines):
            # Replace the line in code with the line from coverage (matching the index)
            code_lines[i] = coverage_lines[i]
    
    # Step 4: Remove just the line numbers at the start and empty lines
    updated_code = ''.join(code_lines)
    # Remove only the line number and the following pipe (|) character
    cleaned_code = "\n".join([re.sub(r'^\d+\|', '', line) for line in updated_code.splitlines() if line.strip() != ""])
    
    return cleaned_code


# print(update_code_with_coverage("18-49-59-982"))