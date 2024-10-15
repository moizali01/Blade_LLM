import sys
import clang.cindex

import re

def get_functions(node):
    """Recursively finds and returns a list of functions with their start and end lines."""
    functions = []

    if node.kind == clang.cindex.CursorKind.FUNCTION_DECL:
        start_line = node.extent.start.line
        end_line = node.extent.end.line
        functions.append((node.spelling, start_line, end_line))

    # Recursively visit children nodes
    for child in node.get_children():
        functions.extend(get_functions(child))

    return functions

def get_function_list(code_file):
    # Initialize the Clang Index
    index = clang.cindex.Index.create()

    # Parse the file and generate the AST
    translation_unit = index.parse(code_file)

    # Get the list of functions with their start and end lines
    return get_functions(translation_unit.cursor)

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

def get_function_context(code_path, coverage_path, function_list):
    # code_path = "../LLM_Util/cands/context/context" + "_time_" + str(formatted_time) + ".blade.c"
    # coverage_path = '../LLM_Util/coverage.txt'

    first_line, last_line = analyze_code(code_path)
    
    with open(code_path, 'r') as code_file:
        code_lines = code_file.readlines()
        
    with open(coverage_path, 'r') as coverage_file:
        coverage_lines = coverage_file.readlines()
    
    func_name = None
    func_start = None
    func_end = None

    for f_name, start_line, end_line in function_list:
        if start_line <= first_line <= end_line or start_line <= last_line <= end_line:
            func_name = f_name
            func_start = start_line
            func_end = end_line

    if func_name:
        coverage_data = ''.join(coverage_lines[func_start - 1: func_end])
        cleaned_code = "\n".join([re.sub(r'^\d+\|', '', line) for line in coverage_data.splitlines() if line.strip() != ""])
        return cleaned_code
    return None

def get_function(code_path, function_list):
    first_line, last_line = analyze_code(code_path)
    

    
