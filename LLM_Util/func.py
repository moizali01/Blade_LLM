import os
import re
import shutil

def is_complete_c_function(text):
    """
    Checks if the text contains a complete C function.
    This function checks for balanced braces in function bodies.
    """
    function_pattern = r'\b[\w\s\*]+[\s\*]+\w+\s*\([^)]*\)\s*{'
    matches = re.finditer(function_pattern, text, re.DOTALL)

    for match in matches:
        start_index = match.end()
        if has_balanced_braces(text[start_index:]):
            return True

    return False

def has_balanced_braces(code):
    """
    Check if the code has balanced braces, indicating a complete function.
    """
    brace_count = 0
    for char in code:
        if char == '{':
            brace_count += 1
        elif char == '}':
            brace_count -= 1
        if brace_count == 0:
            return True
    return False

def process_files(source_directory, destination_directory):
    """
    Processes all .txt files in the source directory to check for complete C functions.
    Copies files containing complete functions to the destination directory.
    """
    if not os.path.exists(destination_directory):
        os.makedirs(destination_directory)

    for filename in os.listdir(source_directory):
        if filename.endswith('.c'):
            filepath = os.path.join(source_directory, filename)
            with open(filepath, 'r') as file:
                content = file.read()

            if is_complete_c_function(content):
                shutil.copy(filepath, destination_directory)
                print(f"Copied {filename} to {destination_directory}")

if __name__ == "__main__":
    # source_directory = input("Enter the path of the source directory: ")
    source_directory = "removed_code"
    # destination_directory = input("Enter the path of the destination directory: ")
    destination_directory = "functions"
    
    process_files(source_directory, destination_directory)
    print("Processing completed.")
