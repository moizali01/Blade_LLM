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
    

